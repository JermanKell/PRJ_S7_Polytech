/*!
  \author Abdourahman Aden Hassan
  \date 30/12/2013
 */
#include "typeinfo"
#include "Exc.h"
#include "math.h"
#include "dtwcorrespondance.h"
#include <cfloat>
#include <cstring>
#include <cstdlib>
using namespace std;
using namespace calc;


vector<ResultatCorrespondance> *DTWCorrespondance::correspondre(model::Sequence *s1, model::Sequence *s2)
{
    // Initialisation
	vector<ResultatCorrespondance> *vRc = new vector<ResultatCorrespondance>();
    ResultatCorrespondance rc;
    rc.correspondanceT1 = new vector<int>();
    rc.correspondanceT2 = new vector<int>();

    // Parametrage
    if(s1->getSize() != pCparam->getS1Size())
    {
        pCparam->setS1Size(s1->getSize());
    }
    if(s2->getSize() != pCparam->getS2Size())
    {
        pCparam->setS2Size(s2->getSize());
    }
    // Check entrées
    if(s1->getSize()<=0 || s2->getSize()<=0)
    {
        delete rc.correspondanceT1;
        delete rc.correspondanceT2;
        delete vRc;
        exc::SequenceMatchingException::genererException("Size error",PARAMETRE_INVALIDE,__LINE__);
    }
    if(typeid(*s1->getElement(0))!=typeid(*s2->getElement(0)))
    {
        delete rc.correspondanceT1;
        delete rc.correspondanceT2;
        delete vRc;
        exc::SequenceMatchingException::genererException("Type error",PARAMETRE_INVALIDE,__LINE__);
    }
    if(typeid(*s1->getElement(0))==typeid(model::CharacteristicVector))
    {
        model::CharacteristicVector * cv1 = (model::CharacteristicVector *)s1->getElement(0);
        model::CharacteristicVector * cv2 = (model::CharacteristicVector *)s2->getElement(0);
        if(cv1->getSize() != cv2->getSize())
        {
            delete rc.correspondanceT1;
            delete rc.correspondanceT2;
            delete vRc;
            exc::SequenceMatchingException::genererException("Characteristic vector size error",PARAMETRE_INVALIDE,__LINE__);
        }
        if(cv1->getSize()!=pCparam->getVecCaracSize())
        {
            pCparam->setVecCaracSize(cv1->getSize());
        }
    }
    model::Sequence *cs1 = s1->copy();
    model::Sequence *cs2 = s2->copy();
    parametrerVectors(cs1, cs2);
    // Algorithme
    float ** vecValue = new float*[cs1->getSize()+1];
	float ** initDistance = initTabDifference(cs1,cs2);
    int itM = 0;
    int itN = 0;
    while(itM<(cs1->getSize()+1))
    {
		vecValue[itM] = new float[cs2->getSize()+1];
        while(itN<(cs2->getSize()+1))
        {
            vecValue[itM][itN] = 0;
            itN = itN +1;
        }
        itN = 0;
        itM = itM + 1;
    }
    // Initialisation tableaux
    int it = 1;
    int it2 = 1;
    while(it<cs1->getSize()+1)
    {
        vecValue[it][0] = FLT_MAX;
        it = it +1;
    }
    it = 1;
    while(it<cs2->getSize()+1)
    {
        vecValue[0][it] = FLT_MAX;
        it = it +1;
    }


    it = 1;
    it2 = 1;


    //calcul
    while(it<cs1->getSize()+1)
    {
        while(it2<cs2->getSize()+1)
        {
           vecValue[it][it2] = calcTab(initDistance,it-1,it2-1) + min(vecValue[it-1][it2-1], min( vecValue[it][it2-1],vecValue[it-1][it2]));
            it2 = it2 +1;
        }
        it2 = 1;
        it = it + 1;
    }


    // backtrack
    it = cs1->getSize();
    it2 = cs2->getSize();
    rc.correspondanceT1->insert(rc.correspondanceT1->begin(),it-1);
    rc.correspondanceT2->insert(rc.correspondanceT2->begin(),it2-1);
    while(!(it==1 && it2==1))
    {
        if(it == 1)
        {
            rc.correspondanceT1->insert(rc.correspondanceT1->begin(),it-1);
            rc.correspondanceT2->insert(rc.correspondanceT2->begin(),it2-2);
            it2 = it2 -1;

        }
        else if(it2 == 1)
        {
            rc.correspondanceT1->insert(rc.correspondanceT1->begin(),it-2);
            rc.correspondanceT2->insert(rc.correspondanceT2->begin(),it2-1);
            it = it -1;
        }
        else
        {

            if(vecValue[it-1][it2-1] == min(vecValue[it-1][it2-1], min( vecValue[it][it2-1],vecValue[it-1][it2])))
            {
                it = it -1;
                it2 = it2 - 1;
            }
            else if(vecValue[it][it2-1] == min(vecValue[it-1][it2-1], min( vecValue[it][it2-1],vecValue[it-1][it2])))
            {
                it2 = it2 - 1;
            }
            else
            {
                it = it -1;
            }
            rc.correspondanceT1->insert(rc.correspondanceT1->begin(),it-1);
            rc.correspondanceT2->insert(rc.correspondanceT2->begin(),it2-1);

        }
    }
    rc.distance = sqrt(vecValue[cs1->getSize()][cs2->getSize()]);
    // Suppression objets
    itM = 0;
    itN = 0;

    freeTabDifference(initDistance,cs1->getSize(),cs2->getSize());
    while(itM<(s1->getSize()+1))
    {
        delete vecValue[itM];
        itM = itM + 1;
    }
    delete vecValue;
    delete cs1;
    delete cs2;
	vRc->push_back(rc);
	return vRc;

}

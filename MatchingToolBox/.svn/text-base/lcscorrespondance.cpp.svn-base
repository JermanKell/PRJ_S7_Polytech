/*!
  \author Abdourahman Aden Hassan
  \date 30/12/2013
*/
#include "lcscorrespondance.h"
#include "typeinfo"
#include "Exc.h"
#include <cstring>
#include <cstdlib>
using namespace std;
using namespace calc;
#define DIAG 4
#define LEFT 2
#define UP 1

vector<ResultatCorrespondance> *LCScorrespondance::correspondre(model::Sequence *s1, model::Sequence *s2)
{
    // Initialisation
	vector<ResultatCorrespondance> *vRc = new vector<ResultatCorrespondance>();;
    ResultatCorrespondance rc;
    rc.correspondanceT1 = new vector<int>(s1->getSize(),0);
    rc.correspondanceT2 = new vector<int>(s2->getSize(),0);
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
    int ** vecArrow = new int*[cs1->getSize()+1];

    int itM = 0;
    int itN = 0;
    while(itM<(cs1->getSize()+1))
    {
        vecValue[itM] = new float[cs2->getSize()+1];
        vecArrow[itM] = new int[cs2->getSize()+1];

        while(itN<(cs2->getSize()+1))
        {
            vecValue[itM][itN] = 0;
            vecArrow[itM][itN] = 0;
            itN = itN +1;
        }
        itN = 0;
        itM = itM + 1;
    }
    int it = 0;
    int it2 = 0;
    while(it<cs1->getSize()+1)
    {
        while(it2<cs2->getSize()+1)
        {

            it2 = it2 + 1;
        }
        it2 = 0;
        it = it +1;
    }
    //calcul
    it = 1;
    it2 = 1;
    while(it<cs1->getSize()+1)
    {
        while(it2<cs2->getSize()+1)
        {

            if(pCparam->getDistanceWeigh()*cs1->getElement(it-1)->distance(cs1->getElement(it-1),cs2->getElement(it2-1))==0)
            {
                vecValue[it][it2] = vecValue[it-1][it2-1] + pCparam->getMatrixWeight(it-1,it2-1);
                vecArrow[it][it2] = DIAG;

            }
            else
            {
                // Cas distance différente
                if(vecValue[it][it2-1]>vecValue[it-1][it2])
                {
                    vecValue[it][it2] = vecValue[it][it2-1];
                    vecArrow[it][it2] = UP;
                }
                else
                {
                    vecValue[it][it2] = vecValue[it-1][it2];
                    vecArrow[it][it2] = LEFT;
                }

            }
            it2 = it2 + 1;
        }
        it2 = 1;
        it = it +1;
    }


    rc.distance = vecValue[cs1->getSize()][cs2->getSize()];
    // Backtrack
    it = cs1->getSize();
    it2 = cs2->getSize();
    while(!(it == 0 && it2 ==0))
    {
        bool end = false;
        if(it == 0 && !end)
        {
            it2 = it2-1;
            end = true;
        }
        if(it2 == 0 && !end)
        {
            it = it-1;
            end = true;
        }
        if(vecArrow[it][it2] == DIAG && !end)
        {
            rc.correspondanceT1->at(it-1) = 1;
            rc.correspondanceT2->at(it2-1) = 1;
            it2 = it2-1;
            it = it-1;
            end = true;
        }
        if(vecArrow[it][it2]>=LEFT && !end)
        {
            it = it-1;
            end = true;
        }
        if(vecArrow[it][it2]>=UP && !end)
        {
            it2 = it2-1;
            end = true;
        }
    }
    // Suppresion objets
    // Suppression objets
    itM = 0;
    itN = 0;
    while(itM<(cs1->getSize()+1))
    {
        delete vecValue[itM];
        delete vecArrow[itM];
        itM = itM + 1;
    }
    delete vecValue;
    delete vecArrow;
    delete cs1;
    delete cs2;
	vRc->push_back(rc);
    return vRc;
}

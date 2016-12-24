/*!
  \author Abdourahman Aden Hassan
  \date 30/12/2013
 */
#include "levenstheincorrespondance.h"
#include "typeinfo"
#include "Exc.h"
#include "math.h"
#include <cfloat>
#include <cstdlib>
#define HAUT 1
#define GAUCHE 2
#define DIAGONALE 4



using namespace calc;

vector<calc::ResultatCorrespondance> *calc::LevenstheinCorrespondance::correspondre(model::Sequence *s1, model::Sequence *s2)
{
    // Initialisation
	vector<ResultatCorrespondance> *vRc = new vector<ResultatCorrespondance>();
    ResultatCorrespondance rc;
    int itCorr = max(s1->getSize(),s2->getSize());
    rc.correspondanceT1 = new vector<int>();
    rc.correspondanceT2 = new vector<int>();
    itCorr = itCorr-1;
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
    int ** vecCorrespondance = new int*[cs1->getSize()+1];

    int itM = 0;
    while(itM<(cs1->getSize()+1))
    {
		vecValue[itM] = new float[cs2->getSize()+1];
		vecCorrespondance[itM] = new int[cs2->getSize()+1];

        itM = itM + 1;
    }
    // Initialisation tableau
    int it  = 1;
    int it2 = 1;
    vecValue[0][0] = 0;
    vecCorrespondance[0][0] = 0;
    while(it<cs1->getSize()+1)
    {
        vecValue[it][0] = it*fLCaddcost;
        vecCorrespondance[it][0] = HAUT;
        it = it+1;
    }
    it = 1;
    while(it<cs2->getSize()+1)
    {
        vecValue[0][it] = it*fLCdelcost;
        vecCorrespondance[0][it] = GAUCHE;
        it = it+1;
    }
    // Calcul
    it = 1;
    it2 = 1;
    while(it<cs1->getSize()+1)
    {
        while(it2<cs2->getSize()+1)
        {
            vecCorrespondance[it][it2] = 0;
            float vh =pCparam->getMatrixWeight(it-1,it2-1)* vecValue[it][it2-1] + fLCdelcost;
            float vg = pCparam->getMatrixWeight(it-1,it2-1)*vecValue[it-1][it2] + fLCaddcost;
            float dist = pCparam->getDistanceWeigh()* cs1->getElement(it-1)->distance(cs1->getElement(it-1),cs2->getElement(it2-1));
            float vdiag = pCparam->getMatrixWeight(it-1,it2-1)*vecValue[it-1][it2-1];
            if(dist != 0)
            {
                vdiag = vdiag + fLCtranscost;
            }
            float min_val = min(min(vh,vg),vdiag);
            vecValue[it][it2] = min_val;
            if(min_val == vdiag){
                vecCorrespondance[it][it2] += DIAGONALE;
            }
            if(min_val == vh)
            {
                vecCorrespondance[it][it2] += HAUT;
            }
            if(min_val == vg)
            {
                vecCorrespondance[it][it2] += GAUCHE;
            }
            it2 = it2 + 1;
        }
        it2 = 1;
        it = it + 1;
    }

    // Backtrack
    it = cs1->getSize();
    it2 = cs2->getSize();
    while(!(it == 0 && it2 == 0))
    {
        float min = FLT_MAX;
        int isMin = 0;

        int back = vecCorrespondance[it][it2];
        if(it == 0)
        {
            rc.correspondanceT1->insert(rc.correspondanceT1->begin(),NOCHAR);
            rc.correspondanceT2->insert(rc.correspondanceT2->begin(),DEL+it2-1);
            it2 = it2-1;
            back = -1;
            isMin = -1;
        }
        else if(it2 == 0)
        {
            rc.correspondanceT1->insert(rc.correspondanceT1->begin(),ADD+it-1);
            rc.correspondanceT2->insert(rc.correspondanceT2->begin(),NOCHAR);
            it = it-1;
            back = -1;
            isMin = -1;
        }
        // DIAGONALE : TRANS
        if(back>=4)
        {
            min = vecValue[it-1][it2-1];
            isMin = DIAGONALE;
            back = back -4;
        }
        // GAUCHE : ADD
        if(back>=2)
        {
            if(vecValue[it-1][it2]<min)
            {
                min = vecValue[it-1][it2];
                isMin = GAUCHE;
            }
            back = back -2;
        }
        // HAUT : DEL
        if(back>=1)
        {
            if(vecValue[it][it2-1]<min)
            {
                min = vecValue[it][it2-1];
                isMin = HAUT;
            }
        }
        switch(isMin){
            case DIAGONALE :
                             if(vecValue[it-1][it2-1] == vecValue[it][it2])
                             {
                                 rc.correspondanceT1->insert(rc.correspondanceT1->begin(),TRANSEQ+it-1);
                                 rc.correspondanceT2->insert(rc.correspondanceT2->begin(),TRANSEQ+it2-1);
                             }
                             else
                             {
                                 rc.correspondanceT1->insert(rc.correspondanceT1->begin(),TRANS+it-1);
                                 rc.correspondanceT2->insert(rc.correspondanceT2->begin(),TRANS+it2-1);
                             }

                             it = it-1;
                             it2 = it2-1;
                             break;
            case GAUCHE :
                        rc.correspondanceT1->insert(rc.correspondanceT1->begin(),ADD+it-1);
                        rc.correspondanceT2->insert(rc.correspondanceT2->begin(),NOCHAR);
                        it = it-1;
                        break;
            case HAUT :
                            rc.correspondanceT1->insert(rc.correspondanceT1->begin(),NOCHAR);
                            rc.correspondanceT2->insert(rc.correspondanceT2->begin(),DEL+it2-1);
                            it2 = it2-1;
                            break;

            default : break;
        }
    }
    rc.distance = vecValue[s1->getSize()][s2->getSize()];
    // Suppression objets
    itM = 0;
    while(itM<(s1->getSize()+1))
    {
        delete vecValue[itM];
        delete vecCorrespondance[itM];
        itM = itM + 1;
    }
    delete vecValue;
    delete vecCorrespondance;
    delete cs1;
    delete cs2;
	vRc->push_back(rc);
    return vRc;
}

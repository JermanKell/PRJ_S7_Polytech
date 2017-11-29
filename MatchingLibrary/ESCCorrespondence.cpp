/*!
\author Bastien Meunier
\date 01/01/2014
*/

#include "ESCCorrespondence.h"

using namespace std;
using namespace support;


vector<ResultCorrespondence> *ESCCorrespondence::match(model::Sequence *s1, model::Sequence *s2)
{
	//s1 : target
	//s2 : ref
	// Initialisation
	vector<ResultCorrespondence> *vRc = new vector<ResultCorrespondence>();
	vector<int> *j_min;
	if (s1->getSize()<s2->getSize())
	{
		delete vRc;
		exc::SequenceMatchingException::genererException("Size error", PARAMETRE_INVALIDE, __LINE__);
	}
	// Parameters
	if (s1->getSize() != params->getFirstSequenceSize()) {
		params->setFirstSequenceSize(s1->getSize());
	}
	if (s2->getSize() != params->getSecondSequenceSize()) {
		params->setSecondSequenceSize(s2->getSize());
	}
	// Check entrées
	if (s1->getSize() <= 0 || s2->getSize() <= 0)
	{
		delete vRc;
		exc::SequenceMatchingException::genererException("Size error", PARAMETRE_INVALIDE, __LINE__);
	}
	if (typeid(*s1->getElement(0)) != typeid(*s2->getElement(0)))
	{
		delete vRc;
		exc::SequenceMatchingException::genererException("Type error", PARAMETRE_INVALIDE, __LINE__);
	}
	if (typeid(*s1->getElement(0)) == typeid(model::CharacteristicVector))
	{
		model::CharacteristicVector * cv1 = (model::CharacteristicVector *)s1->getElement(0);
		model::CharacteristicVector * cv2 = (model::CharacteristicVector *)s2->getElement(0);
		if (cv1->getSize() != cv2->getSize())
		{
			delete vRc;
			exc::SequenceMatchingException::genererException("Characteristic vector size error", PARAMETRE_INVALIDE, __LINE__);
		}

		if (cv1->getSize() != params->getCharacteristicVectorSize()) {
			params->setCharacteristicVectorSize(cv1->getSize());
		}
	}
	model::Sequence *cs1 = s1->copy();
	model::Sequence *cs2 = s2->copy();
	parametrerVectors(cs2, cs1);
	//Algorithme
	float ** tabDiff = initTabDifference(cs2, cs1);
	int elasticity = getElasticity(cs2->getSize(), cs1->getSize());
	float weight = getWeight();
	float smallSkipCost = getSmallSkipCost(tabDiff, cs2->getSize(), cs1->getSize());
	float skipCost = getSkipCost(tabDiff, cs2->getSize(), cs1->getSize());
	float ** pathCost = new float*[cs2->getSize()];
	int ** pathRow = new int*[cs2->getSize()];
	int ** pathCol = new int*[cs2->getSize()];
	int ** skipableParent = new int*[cs2->getSize()];

	int itT = 0;
	while (itT<(cs2->getSize()))
	{
		pathCost[itT] = new float[cs1->getSize()];
		pathRow[itT] = new int[cs1->getSize()];
		pathCol[itT] = new int[cs1->getSize()];
		skipableParent[itT] = new int[cs1->getSize()];

		itT = itT + 1;
	}

	int i, j, k;
	int leftBound, rightBound, childBoundLeft, childBoundRight;
	float skipValue;
	for (i = 0; i < cs2->getSize(); i++)
	{
		for (j = 0; j < cs1->getSize(); j++)
		{
			pathCost[i][j] = FLT_MAX;
			pathCol[i][j] = INT_MAX;
			pathRow[i][j] = INT_MAX;
			skipableParent[i][j] = INT_MAX;
		}
	}

	for (i = 0; i < cs2->getSize(); i++)
	{
		for (j = 0; j < cs1->getSize(); j++)
		{
			skipableParent[i][j] = 1;
			if (calcTab(tabDiff, i, j) > skipCost)
			{
				tabDiff[i][j] = skipCost*skipCost;
				skipableParent[i][j] = -1;
			}
		}
	}
	pathCost[0][0] = calcTab(tabDiff, 0, 0);
	for (j = 1; j < cs1->getSize(); j++)
	{
		pathCost[0][j] = calcTab(tabDiff, 0, j);
		if (pathCost[0][j - 1] == 0 && skipableParent[0][j - 1] == 1)
		{
			pathRow[0][j] = 0;
			pathCol[0][j] = j - 1;
		}
	}

	for (i = 1; i < cs2->getSize(); i++)
	{
		if (i == 1)
		{
			leftBound = 0;
			rightBound = cs1->getSize() - 1;
		}
		else
		{
			leftBound = std::max(0, (int) (i - 1 - elasticity));
			rightBound = std::min(cs1->getSize() - 1, (int) (i - 1 + elasticity));
		}
		for (k = leftBound; k <= rightBound; k++)
		{
			childBoundLeft = std::max((int) k, 0);
			childBoundRight = std::min(cs1->getSize() - 1, (int) (k + 1 + elasticity - max(0, (int) (k - i + 1))));
			for (j = childBoundLeft; j <= childBoundRight; j++)
			{
				if (j == k)
					skipValue = smallSkipCost;
				else if (j == k + 1)
					skipValue = 0;
				else
					skipValue = skipCost*weight*(j - k - 1);

				if (pathCost[i][j] > pathCost[i - 1][k] + calcTab(tabDiff, i, j) + skipValue)
				{
					if (skipableParent[i - 1][k] == 1)
					{
						pathCost[i][j] = pathCost[i - 1][k] + calcTab(tabDiff, i, j) + skipValue;
						pathRow[i][j] = i - 1;
						pathCol[i][j] = k;
					}
					else
					{
						pathCost[i][j] = pathCost[i - 1][k] + calcTab(tabDiff, i, j) + skipValue;
						pathRow[i][j] = pathRow[i - 1][k];
						pathCol[i][j] = pathCol[i - 1][k];
					}
				}
				if (j > 0)
				{
					if (pathCost[i][j] > pathCost[i][j - 1] + calcTab(tabDiff, i, j) + smallSkipCost)
					{
						pathCost[i][j] = pathCost[i][j - 1] + calcTab(tabDiff, i, j) + smallSkipCost;
						if (skipableParent[i][j - 1] == 1)
						{
							pathRow[i][j] = i;
							pathCol[i][j] = j - 1;
						}
						else
						{
							pathRow[i][j] = pathRow[i][j - 1];
							pathCol[i][j] = pathCol[i][j - 1];
						}
					}
				}
			}
		}
	} 

	freeTabDifference(tabDiff, cs2->getSize(), cs1->getSize());
	int tmp = 0, nbJump = 0;
	bool first = true;
	j_min = getIndexOfMinRow(pathCost, cs2->getSize(), cs1->getSize(), params->getValue(tools::Parameters::FSM_FIRST_COL_FOR_RESULT) > 0);
	int i_first;
	int j_first;
	for (k = 0; k < j_min->size(); k++)
	{
		i_first = cs2->getSize() - 1;
		j_first = j_min->at(k);
		ResultCorrespondence rc;
		rc.correspondanceT1 = new vector<int>();
		rc.correspondanceT2 = new vector<int>();
		i = cs2->getSize() - 1;
		j = j_min->at(k);
		nbJump = 0;
		first = true;
		while ((i >= 0) && (j >= 0) && j < cs1->getSize())
		{
			if (first && skipableParent[i][j] == -1)
			{
				tmp = pathCol[i][j];
				i = pathRow[i][j];
				j = tmp;
				i_first = i;
				j_first = j;
			}
			else
			{
				rc.correspondanceT2->insert(rc.correspondanceT2->begin(), i);
				rc.correspondanceT1->insert(rc.correspondanceT1->begin(), j);

				tmp = pathCol[i][j];
				i = pathRow[i][j];
				if (abs((int) j - tmp) == 0)
					nbJump += 1;
				else if (tmp != INT_MAX)
					nbJump += abs((int) j - tmp);

				j = tmp;
			}
			first = false;
		}

		if (i_first > cs2->getSize() || j_first > cs1->getSize())
		{
			i = 0;
			while (i < cs2->getSize())
			{
				delete pathCost[i];
				delete pathCol[i];
				delete pathRow[i];
				i = i + 1;
			}

			delete pathCol;
			delete pathCost;
			delete pathRow;
			delete cs1;
			delete cs2;
			delete j_min;
			delete vRc;
			exc::SequenceMatchingException::genererException("All element of query are skipped", ERREUR_RESULTAT, __LINE__);
		}
		rc.distance = getResultat(pathCost[i_first][j_first], rc, nbJump);
		vRc->push_back(rc);
	}
	//Fin Algorithme

	i = 0;
	while (i < cs2->getSize())
	{
		delete pathCost[i];
		delete pathCol[i];
		delete pathRow[i];
		i = i + 1;
	}

	delete pathCol;
	delete pathCost;
	delete pathRow;
	delete cs1;
	delete cs2;
	delete j_min;

	return vRc;
}

float ESCCorrespondence::calcTab(float **tabDifference, int it1, int it2)
{
	if (it1 == 0 || it2 == 0)
		return params->getValue(tools::Parameters::WEIGHT_DISTANCE) *(sqrt(tabDifference[it1][it2]));

	return params->getMatrixWeight(it1 - 1, it2 - 1) *
		params->getValue(tools::Parameters::WEIGHT_DISTANCE) *
		(sqrt(tabDifference[it1][it2]));
}
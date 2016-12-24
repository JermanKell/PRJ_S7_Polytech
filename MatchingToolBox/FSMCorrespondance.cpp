/*!
\author Bastien Meunier
\date 01/01/2014
*/

#include "fsmcorrespondence.h"

using namespace support;

vector<ResultatCorrespondence> *FSMCorrespondence::match(model::Sequence *s1,
	model::Sequence *s2) {
	// s1 : target
	// s2 : ref
	// Initialisation
	vector<ResultatCorrespondence> *vRc = new vector<ResultatCorrespondence>();
	vector<int> *j_min;
	if (s1->getSize() < s2->getSize()) {
		delete vRc;
		exc::SequenceMatchingException::genererException(
			"Size error", PARAMETRE_INVALIDE, __LINE__);
	}
	// Parameters
	if (s1->getSize() != params->getFirstSequenceSize()) {
		params->setFirstSequenceSize(s1->getSize());
	}
	if (s2->getSize() != params->getSecondSequenceSize()) {
		params->setSecondSequenceSize(s2->getSize());
	}
	// Check entrées
	if (s1->getSize() <= 0 || s2->getSize() <= 0) {
		delete vRc;
		exc::SequenceMatchingException::genererException(
			"Size error", PARAMETRE_INVALIDE, __LINE__);
	}
	if (typeid(*s1->getElement(0)) != typeid(*s2->getElement(0))) {
		delete vRc;
		exc::SequenceMatchingException::genererException(
			"Type error", PARAMETRE_INVALIDE, __LINE__);
	}
	if (typeid(*s1->getElement(0)) == typeid(model::CharacteristicVector)) {
		model::CharacteristicVector *cv1 =
			(model::CharacteristicVector *)s1->getElement(0);
		model::CharacteristicVector *cv2 =
			(model::CharacteristicVector *)s2->getElement(0);
		if (cv1->getSize() != cv2->getSize()) {
			delete vRc;
			exc::SequenceMatchingException::genererException(
				"Characteristic vector size error", PARAMETRE_INVALIDE, __LINE__);
		}

		if (cv1->getSize() != params->getCharacteristicVectorSize()) {
			params->setCharacteristicVectorSize(cv1->getSize());
		}
	}
	model::Sequence *cs1 = s1->copy();
	model::Sequence *cs2 = s2->copy();
	parametrerVectors(cs2, cs1);
	// Algorithme
	float **tabDiff = initTabDifference(cs2, cs1);
	int elasticity = getElasticity(cs2->getSize(), cs1->getSize());
	float weight = getWeight();
	float smallSkipCost =
		getSmallSkipCost(tabDiff, cs2->getSize(), cs1->getSize());
	float skipCost = getSkipCost(tabDiff, cs2->getSize(), cs1->getSize());
	float **pathCost = new float *[cs2->getSize()];
	int **pathRow = new int *[cs2->getSize()];
	int **pathCol = new int *[cs2->getSize()];

	int itT = 0;
	while (itT < (cs2->getSize())) {
		pathCost[itT] = new float[cs1->getSize()];
		pathRow[itT] = new int[cs1->getSize()];
		pathCol[itT] = new int[cs1->getSize()];

		itT = itT + 1;
	}

	int i, j, k;
	int leftBound, rightBound, childBound;
	float skipValue;
	for (i = 0; i < cs2->getSize(); i++) {
		for (j = 0; j < cs1->getSize(); j++) {
			pathCost[i][j] = FLT_MAX;
			pathCol[i][j] = INT_MAX;
			pathRow[i][j] = INT_MAX;
		}
	}
	pathCost[0][0] = calcTab(tabDiff, 0, 0);
	for (j = 1; j < cs1->getSize(); j++) {
		pathCost[0][j] = calcTab(tabDiff, 0, j);
		if (pathCost[0][j - 1] == 0) {
			pathRow[0][j] = 0;
			pathCol[0][j] = j - 1;
		}
	}

	for (i = 1; i < cs2->getSize(); i++) {
		if (i == 1) {
			leftBound = 0;
			rightBound = cs1->getSize() - 1;
		}
		else {
			leftBound = std::max(0, (i - 1 - elasticity));
			rightBound = std::min(cs1->getSize() - 1, (i - 1 + elasticity));
		}
		for (k = leftBound; k <= rightBound; k++) {
			childBound = std::min(cs1->getSize() - 1,
				(k + 1 + elasticity - max(0, k - i + 1)));
			for (j = k; j <= childBound; j++) {
				if (j == k)
					skipValue = smallSkipCost;
				else if (j == k + 1)
					skipValue = 0;
				else
					skipValue = skipCost * weight * (j - k - 1);

				if (pathCost[i][j] >
					pathCost[i - 1][k] + calcTab(tabDiff, i, j) + skipValue) {
					pathCost[i][j] =
						pathCost[i - 1][k] + calcTab(tabDiff, i, j) + skipValue;
					pathRow[i][j] = i - 1;
					pathCol[i][j] = k;
				}
				if (j > 0) {
					if (pathCost[i][j] >
						pathCost[i][j - 1] + calcTab(tabDiff, i, j) + smallSkipCost) {
						pathCost[i][j] =
							pathCost[i][j - 1] + calcTab(tabDiff, i, j) + smallSkipCost;
						pathRow[i][j] = i;
						pathCol[i][j] = j - 1;
					}
				}
			}
		}
	}

	freeTabDifference(tabDiff, cs2->getSize(), cs1->getSize());
	int tmp = 0, nbJump = 0;
	j_min = getIndexOfMinRow(pathCost, cs2->getSize(), cs1->getSize(), 
		params->getValue(params->FSM_FIRST_COL_FOR_RESULT) > 0);
	for (k = 0; k < j_min->size(); k++) {
		ResultatCorrespondence rc;
		rc.correspondanceT1 = new vector<int>();
		rc.correspondanceT2 = new vector<int>();
		i = cs2->getSize() - 1;
		j = j_min->at(k);
		nbJump = 0;
		while ((i >= 0) && (j >= 0) && j < cs1->getSize()) {
			rc.correspondanceT2->insert(rc.correspondanceT2->begin(), i);
			rc.correspondanceT1->insert(rc.correspondanceT1->begin(), j);

			tmp = pathCol[i][j];
			i = pathRow[i][j];
			if (abs(j - tmp) == 0)
				nbJump += 1;
			else if (tmp != INT_MAX)
				nbJump += abs(j - tmp);

			j = tmp;
		}

		rc.distance =
			getResultat(pathCost[cs2->getSize() - 1][j_min->at(k)], rc, nbJump);
		vRc->push_back(rc);
	}
	// Fin Algorithme

	i = 0;
	while (i < cs2->getSize()) {
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

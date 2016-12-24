/*!
\author Abdourahman Aden Hassan
\date 01/01/2014
*/

#include "MVMCorrespondence.h"

using namespace support;

vector<ResultatCorrespondence> *MVMCorrespondence::match(model::Sequence *s1, model::Sequence *s2) {
	if (s1->getSize() < s2->getSize())
	{
		model::Sequence * sTemp = s1;
		s1 = s2;
		s2 = sTemp;
	}
	// Initialisation
	vector<ResultatCorrespondence> *vRc = new vector<ResultatCorrespondence>();
	ResultatCorrespondence rc;
	rc.correspondanceT1 = new vector<int>();
	rc.correspondanceT2 = new vector<int>();
	// Parameters
	if (s1->getSize() != params->getFirstSequenceSize()) {
		params->setFirstSequenceSize(s1->getSize());
	}
	if (s2->getSize() != params->getSecondSequenceSize()) {
		params->setSecondSequenceSize(s2->getSize());
	}
	// Check entrées
	if (s1->getSize() <= 0 || s2->getSize() <= 0) {
		delete rc.correspondanceT1;
		delete rc.correspondanceT2;
		delete vRc;
		exc::SequenceMatchingException::genererException(
			"Size error 2", PARAMETRE_INVALIDE, __LINE__);
	}
	if (s1->getSize() < s2->getSize()) {
		delete rc.correspondanceT1;
		delete rc.correspondanceT2;
		delete vRc;
		exc::SequenceMatchingException::genererException(
			"Size error", PARAMETRE_INVALIDE, __LINE__);
	}
	if (typeid(*s1->getElement(0)) != typeid(*s2->getElement(0))) {
		delete rc.correspondanceT1;
		delete rc.correspondanceT2;
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
			delete rc.correspondanceT1;
			delete rc.correspondanceT2;
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
	// Initialisation tableaux
	float **tabDiff = initTabDifference(cs2, cs1);
	float **pathCost = new float *[cs2->getSize()];
	int **pathRow = new int *[cs2->getSize()];
	int **pathCol = new int *[cs2->getSize()];
	int **path = new int *[cs2->getSize()];

	int itM = 0;
	while (itM < cs2->getSize()) {
		pathCost[itM] = new float[cs1->getSize()];
		pathCol[itM] = new int[cs1->getSize()];
		pathRow[itM] = new int[cs1->getSize()];
		path[itM] = new int[cs1->getSize()];
		itM = itM + 1;
	}
	// Calcul
	int tmp1 = cs1->getSize() - cs2->getSize();
	int tmp2;
	if (params->getValue(params->MVM_ELASTICITY) > cs1->getSize() - 1) {
		tmp2 = cs1->getSize() - 1;
	} else {
		tmp2 = (int) params->getValue(params->MVM_ELASTICITY);
	}
	int elasticity = (tmp1 == 0) ? tmp2 : tmp1;

	int i = 0;
	int j = 0;
	while (i < cs2->getSize()) {
		while (j < cs1->getSize()) {
			pathCost[i][j] = FLT_MAX;
			pathRow[i][j] = INT_MAX;
			pathCol[i][j] = INT_MAX;
			j = j + 1;
		}
		j = 0;
		i = i + 1;
	}
	j = 0;

	while (j < elasticity + 1) {
		pathCost[0][j] = calcTab(tabDiff, 0, j);
		j = j + 1;
	}

	i = 1;
	j = 0;
	while (i < cs2->getSize()) {
		int stopk = __min(i + elasticity, cs1->getSize() - 1);
		int debk = i - 1;
		int k = debk;
		while (k <= stopk) {
			int stopj = __min(k + 1 + elasticity, cs1->getSize() - 1);
			j = k + 1;
			while (j <= stopj) {
				if (pathCost[i][j] > pathCost[i - 1][k] + calcTab(tabDiff, i, j)) {
					pathCost[i][j] = pathCost[i - 1][k] + calcTab(tabDiff, i, j);
					pathRow[i][j] = i - 1;
					pathCol[i][j] = k;
				}
				j = j + 1;
			}
			k = k + 1;
		}
		i = i + 1;
	}
	int k, tmp, nbJump;
	vector<int> *j_min;
	j_min = getIndexOfMinRow(pathCost, cs2->getSize(), cs1->getSize(), false);
	for (k = 0; k < j_min->size(); k++) {
		ResultatCorrespondence rc;
		rc.correspondanceT1 = new vector<int>();
		rc.correspondanceT2 = new vector<int>();
		i = cs2->getSize() - 1;
		j = j_min->at(k);
		nbJump = 0;
		float result = 0;
		while ((i >= 0) && (j >= 0) && j < cs1->getSize()) {
			rc.correspondanceT2->insert(rc.correspondanceT2->begin(), i);
			rc.correspondanceT1->insert(rc.correspondanceT1->begin(), j);

			result += calcTab(tabDiff, i, j);
			tmp = pathCol[i][j];
			i = pathRow[i][j];
			if (abs(j - tmp) == 0)
				nbJump += 1;
			else if (tmp != INT_MAX)
				nbJump += abs(j - tmp);

			j = tmp;
		}
		// cout << nbJump;
		rc.distance = sqrt(result);
		vRc->push_back(rc);
	}
	// Libération tableaux
	freeTabDifference(tabDiff, cs2->getSize(), cs1->getSize());
	itM = 0;
	while (itM < cs2->getSize()) {
		delete pathCost[itM];
		delete pathCol[itM];
		delete pathRow[itM];
		itM = itM + 1;
	}
	delete path;
	delete pathCost;
	delete pathRow;
	delete pathCol;
	delete cs1;
	delete cs2;
	return vRc;
}

float MVMCorrespondence::calcTab(float **tabDifference, int it1, int it2) {
	return params->getMatrixWeight(it1, it2) *
		params->getValue(params->WEIGHT_DISTANCE) *
		(tabDifference[it1][it2]);
}
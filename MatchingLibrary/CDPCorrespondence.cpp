
/*!
\author Bastien Meunier
\date 01/01/2014
*/

#include "CDPCorrespondence.h"

using namespace support;

/*float CDPCorrespondence::min3(float f1, float f2, float f3) { //supprimé et remplacé par std::min
	float __min = f1;
	if (f2 < __min) __min = f2;
	if (f3 < __min) __min = f3;
	return __min;
}*/

vector<ResultCorrespondence> *CDPCorrespondence::match(model::Sequence *s1,
	model::Sequence *s2) {
	// s1 : target
	// s2 : ref

	// Initialisation
	vector<ResultCorrespondence> *vRc = new vector<ResultCorrespondence>();
	vector<int> *imin;
	if (s1->getSize() < s2->getSize()) {
		model::Sequence *stamp = s2;
		s2 = s1;
		s1 = stamp;
	}
	// Parameters
	if (s1->getSize() != params->getFirstSequenceSize()) {
		params->setFirstSequenceSize(s1->getSize());
	}
	if (s2->getSize() != params->getSecondSequenceSize()) {
		params->setSecondSequenceSize(s2->getSize());
	}
	// Check entries
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

	// Check parameter
	parametrerVectors(cs1, cs2);
	// Algorithme
	// Create difference matrix
	float **tabDiff = initTabDifference(cs1, cs2);

	float **pathCost = new float *[cs1->getSize() + 2];

	int itT = 0;
	int itM = 0;
	while (itT < (cs1->getSize() + 2)) {
		pathCost[itT] = new float[cs2->getSize()];
		itT = itT + 1;
	}
	int j = 0;
	j = 0;
	while (j < cs2->getSize()) {
		pathCost[0][j] = FLT_MAX;
		pathCost[1][j] = FLT_MAX;
		j++;
	}
	int i = 0;
	int k = 2;
	j = 0;
	while (i < cs1->getSize()) {
		j = 0;
		while (j < cs2->getSize()) {
			if (j == 0)
				pathCost[k][j] = 3 * calcTab(tabDiff, i, j);
			else if (j == 1) {
				if (k == 2)
					pathCost[k][j] =
					std::min(std::min(FLT_MAX, pathCost[k - 1][j - 1] + 3 * calcTab(tabDiff, i, j)),
						pathCost[k][j - 1] + 3 * calcTab(tabDiff, i, j));
				else
					pathCost[k][j] =
					std::min(std::min(pathCost[k - 2][j - 1] + 2 * calcTab(tabDiff, i - 1, j) +
						calcTab(tabDiff, i, j),
						pathCost[k - 1][j - 1] + 3 * calcTab(tabDiff, i, j)),
						pathCost[k][j - 1] + 3 * calcTab(tabDiff, i, j));
			}
			else {
				if (k == 2)
					pathCost[k][j] =
					std::min(std::min(FLT_MAX, pathCost[k - 1][j - 1] + 3 * calcTab(tabDiff, i, j)),
						pathCost[k - 1][j - 2] + 3 * calcTab(tabDiff, i, j - 1) +
						3 * calcTab(tabDiff, i, j));
				else
					pathCost[k][j] =
					std::min(std::min(pathCost[k - 2][j - 1] + 2 * calcTab(tabDiff, i - 1, j) +
						calcTab(tabDiff, i, j),
						pathCost[k - 1][j - 1] + 3 * calcTab(tabDiff, i, j)),
						pathCost[k - 1][j - 2] + 3 * calcTab(tabDiff, i, j - 1) +
						3 * calcTab(tabDiff, i, j));
			}
			j = j + 1;
		}
		i = i + 1;
		k = k + 1;
	}
	freeTabDifference(tabDiff, cs1->getSize(), cs2->getSize());

	imin = getIndexOfMinColumn(pathCost, cs1->getSize(), cs2->getSize());

	for (size_t i = 0; i < imin->size(); i++) {
		ResultCorrespondence rc2;
		rc2.correspondanceT1 = new vector<int>();
		rc2.correspondanceT2 = new vector<int>();
		rc2.distance =
			pathCost[imin->at(i) + 2][cs2->getSize() - 1] / (3 * cs2->getSize());
		itT = 0;
		itM = 0;
		while (itT < cs1->getSize()) {
			if (itT > imin->at(i) - cs2->getSize() && itT <= imin->at(i)) {
				rc2.correspondanceT1->push_back(itT);
				rc2.correspondanceT2->push_back(itM);
				itM = itM + 1;
			}
			itT = itT + 1;
		}
		vRc->push_back(rc2);
	}
	itT = 0;
	while (itT < cs1->getSize() + 2) {
		delete pathCost[itT];
		itT = itT + 1;
	}

	delete pathCost;
	delete imin;
	delete cs1;
	delete cs2;

	return vRc;
}
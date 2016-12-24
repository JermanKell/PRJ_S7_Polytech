/*!
\author Abdourahman Aden Hassan
\date 30/12/2013
*/

#include "LCSCorrespondence.h"

using namespace support;

unsigned int support::LCSCorrespondence::tailleMaxElement(model::Sequence * s)
{
	unsigned int it = 0;
	unsigned int tailleMax = 0;
	while (it < (unsigned int)s->getSize()) {
		unsigned int size = s->getElement(it)->toString().size();
		if (size > tailleMax) {
			tailleMax = size;
		}
		it = it + 1;
	}
	return tailleMax;
}

string support::LCSCorrespondence::getSpace(unsigned int size)
{
	stringstream ss;
	unsigned int it = 0;
	while (it < size) {
		ss << " ";
		it = it + 1;
	}
	return ss.str();
}

vector<ResultatCorrespondence> *LCSCorrespondence::match(model::Sequence *s1,
	model::Sequence *s2) {
	// Initialisation
	vector<ResultatCorrespondence> *vRc = new vector<ResultatCorrespondence>();
	;
	ResultatCorrespondence rc;
	rc.correspondanceT1 = new vector<int>(s1->getSize(), 0);
	rc.correspondanceT2 = new vector<int>(s2->getSize(), 0);
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
	parametrerVectors(cs1, cs2);
	// Algorithme

	float **vecValue = new float *[cs1->getSize() + 1];
	int **vecArrow = new int *[cs1->getSize() + 1];

	int itM = 0;
	int itN = 0;
	while (itM < (cs1->getSize() + 1)) {
		vecValue[itM] = new float[cs2->getSize() + 1];
		vecArrow[itM] = new int[cs2->getSize() + 1];

		while (itN < (cs2->getSize() + 1)) {
			vecValue[itM][itN] = 0;
			vecArrow[itM][itN] = 0;
			itN = itN + 1;
		}
		itN = 0;
		itM = itM + 1;
	}
	int it = 0;
	int it2 = 0;
	while (it < cs1->getSize() + 1) {
		while (it2 < cs2->getSize() + 1) {
			it2 = it2 + 1;
		}
		it2 = 0;
		it = it + 1;
	}
	// calcul
	it = 1;
	it2 = 1;
	while (it < cs1->getSize() + 1) {
		while (it2 < cs2->getSize() + 1) {
			if (params->getValue(params->WEIGHT_DISTANCE) *
				cs1->getElement(it - 1)->distance(cs1->getElement(it - 1),
					cs2->getElement(it2 - 1)) ==
				0) {
				vecValue[it][it2] = vecValue[it - 1][it2 - 1] +
					params->getMatrixWeight(it - 1, it2 - 1);
				vecArrow[it][it2] = DIAG;

			}
			else {
				// Cas distance différente
				if (vecValue[it][it2 - 1] > vecValue[it - 1][it2]) {
					vecValue[it][it2] = vecValue[it][it2 - 1];
					vecArrow[it][it2] = UP;
				}
				else {
					vecValue[it][it2] = vecValue[it - 1][it2];
					vecArrow[it][it2] = LEFT;
				}
			}
			it2 = it2 + 1;
		}
		it2 = 1;
		it = it + 1;
	}

	rc.distance = vecValue[cs1->getSize()][cs2->getSize()];
	// Backtrack
	it = cs1->getSize();
	it2 = cs2->getSize();
	while (!(it == 0 && it2 == 0)) {
		bool end = false;
		if (it == 0 && !end) {
			it2 = it2 - 1;
			end = true;
		}
		if (it2 == 0 && !end) {
			it = it - 1;
			end = true;
		}
		if (vecArrow[it][it2] == DIAG && !end) {
			rc.correspondanceT1->at(it - 1) = 1;
			rc.correspondanceT2->at(it2 - 1) = 1;
			it2 = it2 - 1;
			it = it - 1;
			end = true;
		}
		if (vecArrow[it][it2] >= LEFT && !end) {
			it = it - 1;
			end = true;
		}
		if (vecArrow[it][it2] >= UP && !end) {
			it2 = it2 - 1;
			end = true;
		}
	}
	// Suppresion objets
	// Suppression objets
	itM = 0;
	itN = 0;
	while (itM < (cs1->getSize() + 1)) {
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

std::string support::LCSCorrespondence::format(model::Sequence * sTarget, model::Sequence * sRef, ResultatCorrespondence * result)
{
	stringstream ret;
	ret << "Result \nDistance = " << result->distance << endl;
	stringstream ss1;
	stringstream ssq1;
	stringstream ssq2;
	stringstream ss2;
	stringstream seq;
	seq << "{";
	unsigned int it = 0;
	unsigned int tailleMaxSeq1 = tailleMaxElement(sTarget) + 1;
	unsigned int tailleMaxSeq2 = tailleMaxElement(sRef) + 1;
	while (it<result->correspondanceT1->size())
	{
		ss1 << sTarget->getElement(it)->toString() << getSpace(__max(tailleMaxSeq2, tailleMaxSeq1) - sTarget->getElement(it)->toString().size());
		if (result->correspondanceT1->at(it) == 1)
		{
			ssq1 << sTarget->getElement(it)->toString() << getSpace(__max(tailleMaxSeq2, tailleMaxSeq1) - sTarget->getElement(it)->toString().size());
			seq << sTarget->getElement(it)->toString() << " ";
		}
		else
		{
			ssq1 << "-" << getSpace(__max(tailleMaxSeq2, tailleMaxSeq1) - 1);
		}
		it = it + 1;
	}
	it = 0;
	while (it<result->correspondanceT2->size())
	{
		ss2 << sRef->getElement(it)->toString() << getSpace(__max(tailleMaxSeq2, tailleMaxSeq1) - sRef->getElement(it)->toString().size());
		if (result->correspondanceT2->at(it) == 1)
		{
			ssq2 << sRef->getElement(it)->toString() << getSpace(__max(tailleMaxSeq2, tailleMaxSeq1) - sRef->getElement(it)->toString().size());
		}
		else
		{
			ssq2 << "-" << getSpace(__max(tailleMaxSeq2, tailleMaxSeq1) - 1);
		}
		it = it + 1;
	}
	ret << "Correspondance \n" << std::endl;
	ret << ss1.str() << std::endl;
	ret << ssq1.str() << std::endl;
	ret << ssq2.str() << std::endl;
	ret << ss2.str() << std::endl;
	ret << "Longest common sequence : " << seq.str() << "}" << std::endl;
	return (string(ret.str()));
}

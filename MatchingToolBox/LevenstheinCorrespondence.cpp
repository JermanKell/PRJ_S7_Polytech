/*!
\author Abdourahman Aden Hassan
\date 30/12/2013
*/
#include "LevenstheinCorrespondence.h"

#define HAUT 1
#define GAUCHE 2
#define DIAGONALE 4
#define EGAL "="
#define SUB "o"
#define ADDING "+"
#define SUPPRESS "-"
#define NO " "

using namespace support;

vector<ResultatCorrespondence> *LevenstheinCorrespondence::match(model::Sequence *s1, model::Sequence *s2) {
	// Initialisation
	vector<ResultatCorrespondence> *vRc = new vector<ResultatCorrespondence>();
	ResultatCorrespondence rc;
	int itCorr = __max(s1->getSize(), s2->getSize());
	rc.correspondanceT1 = new vector<int>();
	rc.correspondanceT2 = new vector<int>();
	itCorr = itCorr - 1;
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
	int **vecCorrespondance = new int *[cs1->getSize() + 1];

	int itM = 0;
	while (itM < (cs1->getSize() + 1)) {
		vecValue[itM] = new float[cs2->getSize() + 1];
		vecCorrespondance[itM] = new int[cs2->getSize() + 1];

		itM = itM + 1;
	}
	// Initialisation tableau
	int it = 1;
	int it2 = 1;
	vecValue[0][0] = 0;
	vecCorrespondance[0][0] = 0;
	while (it < cs1->getSize() + 1) {
		vecValue[it][0] = it * params->getValue(params->LEVENSHTEIN_ADD_COST);
		vecCorrespondance[it][0] = HAUT;
		it = it + 1;
	}
	it = 1;
	while (it < cs2->getSize() + 1) {
		vecValue[0][it] = it * params->getValue(params->LEVENSHTEIN_DEL_COST);
		vecCorrespondance[0][it] = GAUCHE;
		it = it + 1;
	}
	// Calcul
	it = 1;
	it2 = 1;
	while (it < cs1->getSize() + 1) {
		while (it2 < cs2->getSize() + 1) {
			vecCorrespondance[it][it2] = 0;
			float vh =
				params->getMatrixWeight(it - 1, it2 - 1) * vecValue[it][it2 - 1] + params->getValue(params->LEVENSHTEIN_DEL_COST);
			float vg =
				params->getMatrixWeight(it - 1, it2 - 1) * vecValue[it - 1][it2] +
				params->getValue(params->LEVENSHTEIN_ADD_COST);
			float dist = params->getValue(params->WEIGHT_DISTANCE) *
				cs1->getElement(it - 1)->distance(cs1->getElement(it - 1),
					cs2->getElement(it2 - 1));
			float vdiag =
				params->getMatrixWeight(it - 1, it2 - 1) * vecValue[it - 1][it2 - 1];
			if (dist != 0) {
				vdiag = vdiag + params->getValue(params->LEVENSHTEIN_TRANS_COST);
			}
			float min_val = __min(__min(vh, vg), vdiag);
			vecValue[it][it2] = min_val;
			if (min_val == vdiag) {
				vecCorrespondance[it][it2] += DIAGONALE;
			}
			if (min_val == vh) {
				vecCorrespondance[it][it2] += HAUT;
			}
			if (min_val == vg) {
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
	while (!(it == 0 && it2 == 0)) {
		float __min = FLT_MAX;
		int isMin = 0;

		int back = vecCorrespondance[it][it2];
		if (it == 0) {
			rc.correspondanceT1->insert(rc.correspondanceT1->begin(), NOCHAR);
			rc.correspondanceT2->insert(rc.correspondanceT2->begin(), DEL + it2 - 1);
			it2 = it2 - 1;
			back = -1;
			isMin = -1;
		}
		else if (it2 == 0) {
			rc.correspondanceT1->insert(rc.correspondanceT1->begin(), ADD + it - 1);
			rc.correspondanceT2->insert(rc.correspondanceT2->begin(), NOCHAR);
			it = it - 1;
			back = -1;
			isMin = -1;
		}
		// DIAGONALE : TRANS
		if (back >= 4) {
			__min = vecValue[it - 1][it2 - 1];
			isMin = DIAGONALE;
			back = back - 4;
		}
		// GAUCHE : ADD
		if (back >= 2) {
			if (vecValue[it - 1][it2] < __min) {
				__min = vecValue[it - 1][it2];
				isMin = GAUCHE;
			}
			back = back - 2;
		}
		// HAUT : DEL
		if (back >= 1) {
			if (vecValue[it][it2 - 1] < __min) {
				__min = vecValue[it][it2 - 1];
				isMin = HAUT;
			}
		}
		switch (isMin) {
		case DIAGONALE:
			if (vecValue[it - 1][it2 - 1] == vecValue[it][it2]) {
				rc.correspondanceT1->insert(rc.correspondanceT1->begin(),
					TRANSEQ + it - 1);
				rc.correspondanceT2->insert(rc.correspondanceT2->begin(),
					TRANSEQ + it2 - 1);
			}
			else {
				rc.correspondanceT1->insert(rc.correspondanceT1->begin(),
					TRANS + it - 1);
				rc.correspondanceT2->insert(rc.correspondanceT2->begin(),
					TRANS + it2 - 1);
			}

			it = it - 1;
			it2 = it2 - 1;
			break;
		case GAUCHE:
			rc.correspondanceT1->insert(rc.correspondanceT1->begin(), ADD + it - 1);
			rc.correspondanceT2->insert(rc.correspondanceT2->begin(), NOCHAR);
			it = it - 1;
			break;
		case HAUT:
			rc.correspondanceT1->insert(rc.correspondanceT1->begin(), NOCHAR);
			rc.correspondanceT2->insert(rc.correspondanceT2->begin(),
				DEL + it2 - 1);
			it2 = it2 - 1;
			break;

		default:
			break;
		}
	}
	rc.distance = vecValue[s1->getSize()][s2->getSize()];
	// Suppression objets
	itM = 0;
	while (itM < (s1->getSize() + 1)) {
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

std::string LevenstheinCorrespondence::format(model::Sequence *sTarget, model::Sequence *sRef,
	ResultatCorrespondence *result) {
	stringstream res;
	res << "Result \nDistance = " << result->distance << endl;
	stringstream ss1;
	stringstream ss2;
	stringstream ss;
	unsigned int it = 0;
	unsigned int tailleMaxSeq1 = tailleMaxElement(sTarget) + 1;
	unsigned int tailleMaxSeq2 = tailleMaxElement(sRef) + 1;

	while (it < result->correspondanceT1->size()) {
		// CAS TRANSEQ
		if (result->correspondanceT1->at(it) >= TRANSEQ) {
			ss << EGAL << getSpace(__max(tailleMaxSeq2, tailleMaxSeq1) - 1);
			ss1 << sTarget->getElement(result->correspondanceT1->at(it) - TRANSEQ)
				->toString()
				<< getSpace(
					__max(tailleMaxSeq2, tailleMaxSeq1) -
					sTarget->getElement(result->correspondanceT1->at(it) - TRANSEQ)
					->toString()
					.size());
			ss2 << sRef->getElement(result->correspondanceT2->at(it) - TRANSEQ)
				->toString()
				<< getSpace(
					__max(tailleMaxSeq2, tailleMaxSeq1) -
					sRef->getElement(result->correspondanceT2->at(it) - TRANSEQ)
					->toString()
					.size());
		}
		else if (result->correspondanceT1->at(it) >= TRANS) {
			ss << SUB << getSpace(__max(tailleMaxSeq2, tailleMaxSeq1) - 1);
			ss1 << sTarget->getElement(result->correspondanceT1->at(it) - TRANS)
				->toString()
				<< getSpace(
					__max(tailleMaxSeq2, tailleMaxSeq1) -
					sTarget->getElement(result->correspondanceT1->at(it) - TRANS)
					->toString()
					.size());
			ss2 << sRef->getElement(result->correspondanceT2->at(it) - TRANS)
				->toString()
				<< getSpace(__max(tailleMaxSeq2, tailleMaxSeq1) -
					sRef->getElement(result->correspondanceT2->at(it) - TRANS)
					->toString()
					.size());
		}
		else if (result->correspondanceT1->at(it) >= DEL ||
			result->correspondanceT2->at(it) >= DEL) {
			ss << SUPPRESS << getSpace(__max(tailleMaxSeq2, tailleMaxSeq1) - 1);
			if (result->correspondanceT1->at(it) >= DEL) {
				ss1 << sTarget->getElement(result->correspondanceT1->at(it) - DEL)
					->toString()
					<< getSpace(
						__max(tailleMaxSeq2, tailleMaxSeq1) -
						sTarget->getElement(result->correspondanceT1->at(it) - DEL)
						->toString()
						.size());
				ss2 << NO << getSpace(__max(tailleMaxSeq2, tailleMaxSeq1) - 1);
			}
			else {
				ss1 << NO << getSpace(__max(tailleMaxSeq2, tailleMaxSeq1) - 1);
				ss2 << sRef->getElement(result->correspondanceT2->at(it) - DEL)
					->toString()
					<< getSpace(__max(tailleMaxSeq2, tailleMaxSeq1) -
						sRef->getElement(result->correspondanceT2->at(it) - DEL)
						->toString()
						.size());
			}
		}
		else if (result->correspondanceT1->at(it) >= ADD ||
			result->correspondanceT2->at(it) >= ADD) {
			ss << ADDING << getSpace(__max(tailleMaxSeq2, tailleMaxSeq1) - 1);
			if (result->correspondanceT1->at(it) >= ADD) {
				ss1 << sTarget->getElement(result->correspondanceT1->at(it) - ADD)
					->toString()
					<< getSpace(
						__max(tailleMaxSeq2, tailleMaxSeq1) -
						sTarget->getElement(result->correspondanceT1->at(it) - ADD)
						->toString()
						.size());
				ss2 << NO << getSpace(__max(tailleMaxSeq2, tailleMaxSeq1) - 1);
			}
			else {
				ss1 << NO << getSpace(__max(tailleMaxSeq2, tailleMaxSeq1) - 1);
				ss2 << sRef->getElement(result->correspondanceT2->at(it) - ADD)
					->toString()
					<< getSpace(__max(tailleMaxSeq2, tailleMaxSeq1) -
						sRef->getElement(result->correspondanceT2->at(it) - ADD)
						->toString()
						.size());
			}
		}
		it = it + 1;
	}
	res << "Correspondance \n" << std::endl;
	res << ss1.str() << std::endl;
	res << ss.str() << std::endl;
	res << ss2.str() << std::endl;
	return string(res.str());
}

unsigned int LevenstheinCorrespondence::tailleMaxElement(model::Sequence *s) {
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

string LevenstheinCorrespondence::getSpace(unsigned int size) {
	stringstream ss;
	unsigned int it = 0;
	while (it < size) {
		ss << " ";
		it = it + 1;
	}
	return ss.str();
}
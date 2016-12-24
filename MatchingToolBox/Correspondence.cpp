/*!
\author Abdourahman Aden Hassan
\date 21/12/2013
*/

#include "Correspondence.h"

using namespace tools;

Correspondence::Correspondence(void) {
	params = new Parameters();
	isParametrageExtern = false;
}

Correspondence::Correspondence(Parameters *p) {
	params = p;
	isParametrageExtern = true;
}

Correspondence::~Correspondence() {
	if (!isParametrageExtern) delete params;
}

std::string tools::Correspondence::format(model::Sequence *sTarget, model::Sequence *sRef, ResultatCorrespondence * result)
{
	stringstream ret;
	ret << result->distance << ": ";
	unsigned int it1 = 0;
	while (it1 < result->correspondanceT2->size())
	{
		if (it1 != 0)
			ret << ",";
		ret << result->correspondanceT2->at(it1) << "->" << result->correspondanceT1->at(it1);
		it1 = it1 + 1;
	}
	return string(ret.str());
}

std::string tools::Correspondence::format(model::Sequence *sTarget, model::Sequence *sRef, vector<ResultatCorrespondence>* result)
{
	stringstream ret;
	for (size_t i = 0; i < result->size(); i++)
		ret << format(sTarget, sRef, &(result->at(i))) << endl;

	return string(ret.str());
}

void tools::Correspondence::setParameters(Parameters* p) {
	if (!isParametrageExtern) delete params;
	params = p;
	isParametrageExtern = true;
}

Parameters* tools::Correspondence::getParameters() {
	return params;
}

void Correspondence::parametrerVectors(model::Sequence *s1, model::Sequence *s2) {
	int it = 0;

	if (s1->getSize() != params->getFirstSequenceSize()) {
		std::cout << "First sequence size : " << s1->getSize() 
			<< " Parameters S1 size : " << params->getFirstSequenceSize() << std::endl;
		exc::SequenceMatchingException::genererException(
			"S1 Size size error", PARAMETRE_INVALIDE, __LINE__);
	}

	if (s2->getSize() != params->getSecondSequenceSize()) {
		std::cout << "Second sequence size : " << s2->getSize() << " Parameters S2 size : "
			<< params->getSecondSequenceSize() << std::endl;
		exc::SequenceMatchingException::genererException(
			"S2 Size size error", PARAMETRE_INVALIDE, __LINE__);
	}

	while (it < s1->getSize()) {
		if (typeid(model::CharacteristicVector) == typeid(*s1->getElement(it))) {
			model::CharacteristicVector *cp =
				(model::CharacteristicVector *)s1->getElement(it);
			int it2 = 0;
			if (cp->getSize() != params->getCharacteristicVectorSize()) {
				exc::SequenceMatchingException::genererException(
					"Characteristic vector size error", PARAMETRE_INVALIDE, __LINE__);
			}
			while (it2 < cp->getSize()) {
				cp->setValue(it2, cp->getAt(it2) * params->getCharacteristicVectorWeight(it2) *
					params->getFirstSequenceWeight(it));
				it2 = it2 + 1;
			}
		}
		else if (typeid(model::Numeric) == typeid(*s1->getElement(it))) {
			model::Numeric *cpnu = (model::Numeric *)s1->getElement(it);
			cpnu->setValue(cpnu->getValue() * params->getFirstSequenceWeight(it));
		}
		it = it + 1;
	}

	it = 0;
	while (it < s2->getSize()) {
		if (typeid(model::CharacteristicVector) == typeid(*s2->getElement(it))) {
			model::CharacteristicVector *cp =
				(model::CharacteristicVector *)s2->getElement(it);
			int it2 = 0;
			if (cp->getSize() != params->getCharacteristicVectorSize()) {
				exc::SequenceMatchingException::genererException(
					"Characteristic vector size error", PARAMETRE_INVALIDE, __LINE__);
			}
			while (it2 < cp->getSize()) {
				cp->setValue(it2, cp->getAt(it2) * params->getCharacteristicVectorWeight(it2) *
					params->getSecondSequenceWeight(it));
				it2 = it2 + 1;
			}
		}
		else if (typeid(model::Numeric) == typeid(*s2->getElement(it))) {
			model::Numeric *cpnu = (model::Numeric *)s2->getElement(it);
			cpnu->setValue(cpnu->getValue() * params->getSecondSequenceWeight(it));
		}
		it = it + 1;
	}
}

float **Correspondence::initTabDifference(model::Sequence *s1, model::Sequence *s2) {
	float **tabMCdifference = new float *[s1->getSize()];

	int it1 = 0;
	int it2 = 0;
	model::Element *tamp1;
	model::Element *tamp2;
	while (it1 < s1->getSize()) {
		tabMCdifference[it1] = new float[s2->getSize()];
		tamp1 = s1->getElement(it1);
		while (it2 < s2->getSize()) {
			tamp2 = s2->getElement(it2);
			tabMCdifference[it1][it2] = tamp1->distance(tamp1, tamp2);
			it2 = it2 + 1;
		}
		it2 = 0;
		it1 = it1 + 1;
	}
	return tabMCdifference;
}

float Correspondence::calcTab(float **tabDifference, int it1, int it2) {
	return params->getMatrixWeight(it1, it2) * params->getValue(params->WEIGHT_DISTANCE) *
		(sqrt(tabDifference[it1][it2]));
}

void Correspondence::freeTabDifference(float **tabDifference, int size1, int size2) {
	int it1 = 0;
	while (it1 < size1) {
		delete tabDifference[it1];
		it1 = it1 + 1;
	}
	delete tabDifference;
}

vector<int> *Correspondence::getIndexOfMinColumn(float **path, int sizeC, int sizeR) {
	vector<int> *vMin = new vector<int>();
	int i_min;
	float seuil = params->getValue(params->CDP_THRESHOLD);
	float __min;
	float cost = 0;
	int i = sizeR - 1;
	i_min = i;
	__min = FLT_MAX;
	if (seuil >= 0) __min = seuil;
	while (i < sizeC) {
		cost = path[i + 2][sizeR - 1] / (3 * sizeR);
		if (cost < __min) {
			__min = cost;
			i_min = i;
			if (seuil < 0) {
				vMin->clear();
			}
			else {
				__min = seuil;
			}
			vMin->push_back(i_min);
		}
		else if (cost == __min) {
			i_min = i;
			vMin->push_back(i_min);
		}
		i = i + 1;
	}
	return vMin;
}

vector<int> *Correspondence::getIndexOfMinRow(float **path, int sizeR, int sizeC, bool firstCol) {
	vector<int> *vMin = new vector<int>();
	int j_min;
	float __min;
	float cost = 0;
	int j = 0;
	j_min = j;
	__min = FLT_MAX;
	if (!firstCol) j = sizeR - 1;

	while (j < sizeC) {
		cost = path[sizeR - 1][j];
		if (cost <= __min) {
			__min = cost;
			j_min = j;
		}
		j = j + 1;
	}
	vMin->push_back(j_min);

	return vMin;
}

int Correspondence::getElasticity(int sizeR, int sizeT) {
	int elast = (int) params->getValue(params->FSM_ELASTICITY);
	if (elast < 0) {
		elast = abs(sizeR - sizeT);
	}

	return elast;
}

float Correspondence::getWeight() { 
	return params->getValue(params->FSM_WEIGHT);
}

float Correspondence::getSmallSkipCost(float **tabDiff, int sizeR, int sizeT) {
	float skipValue = params->getValue(params->FSM_SMALL_SKIP_COST);
	if (skipValue < 0) {
		vector<float> tabMin;
		vector<int> tabMinJ;
		float smallAverage, average = 0;
		float __min = FLT_MAX;
		int i, j, k, j_min, size = 0;
		for (i = 0; i < sizeR; i++) {
			__min = FLT_MAX;
			smallAverage = 0;
			tabMinJ.clear();
			for (k = 0; k < params->getValue(params->FSM_NUMBER_ELEMENTS_BY_LINE); k++) {
				__min = FLT_MAX;
				for (j = 0; j < sizeT; j++) {
					if ((calcTab(tabDiff, i, j) < __min) &&
						!(std::find(tabMinJ.begin(), tabMinJ.end(), j) !=
							tabMinJ.end())) {
						__min = calcTab(tabDiff, i, j);
						j_min = j;
					}
				}
				smallAverage += __min;
				tabMinJ.push_back(j_min);
			}
			if (smallAverage != 0) {
				tabMin.push_back(smallAverage / params->getValue(params->FSM_NUMBER_ELEMENTS_BY_LINE));
				average += smallAverage / params->getValue(params->FSM_NUMBER_ELEMENTS_BY_LINE);
				size++;
			}
		}

		if (size == 0)
			skipValue = params->getValue(params->FSM_DEFAULT_SKIP_COST);
		else
			skipValue = average / size;
	}
	return skipValue;
}

float Correspondence::getSkipCost(float **tabDiff, unsigned int sizeR, unsigned int sizeT) {
	float skipValue = params->getValue(params->FSM_SKIP_COST);
	if (skipValue < 0) {
		vector<float> tabMin;
		vector<int> tabMinJ;
		float stdeviation = 0;
		float smallAverage, average = 0;
		float __min = FLT_MAX;
		size_t i, j, k;
		int j_min, size = 0;
		for (i = 0; i < sizeR; i++) {
			__min = FLT_MAX;
			smallAverage = 0;
			tabMinJ.clear();
			for (k = 0; k < params->getValue(params->FSM_NUMBER_ELEMENTS_BY_LINE); k++) {
				__min = FLT_MAX;
				for (j = 0; j < sizeT; j++) {
					if ((calcTab(tabDiff, i, j) < __min) &&
						!(std::find(tabMinJ.begin(), tabMinJ.end(), j) !=
							tabMinJ.end())) {
						__min = calcTab(tabDiff, i, j);
						j_min = j;
					}
				}
				smallAverage += __min;
				tabMinJ.push_back(j_min);
			}
			if (smallAverage != 0) {
				tabMin.push_back(smallAverage / params->getValue(params->FSM_NUMBER_ELEMENTS_BY_LINE));
				average += smallAverage / params->getValue(params->FSM_NUMBER_ELEMENTS_BY_LINE);
				size++;
			}
		}
		if (size == 0)
			return params->getValue(params->FSM_DEFAULT_SKIP_COST);
		else
			average = average / size;

		for (i = 0; i < tabMin.size(); i++) {
			stdeviation += (tabMin.at(i) - average) * (tabMin.at(i) - average);
		}
		stdeviation = std::sqrt((stdeviation / size));
		skipValue =
			average + params->getValue(params->FSM_STANDARD_DEVIATION_NUMBER) * stdeviation;
	}
	return skipValue;
}

float Correspondence::getResultat(float minimun, ResultatCorrespondence rc, int nbJump) {
	switch ((int) params->getValue(params->FSM_TYPE_RESULT)) {
	case 0:
		return minimun / (rc.correspondanceT1->size());
		break;
	case 1:
		return minimun /
			(rc.correspondanceT1->at(rc.correspondanceT1->size() - 1) -
				rc.correspondanceT1->at(0));
		break;
	case 2:
		return minimun / (nbJump);
		break;
	default:
		return minimun / (rc.correspondanceT1->size());
		break;
	}
}



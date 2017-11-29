#include "Parameters.h"

using namespace tools;

const std::string Parameters::SIZE_FIRST_SEQUENCE = "iPsizeS1";
const std::string Parameters::SIZE_SECOND_SEQUENCE = "iPsizeS2";
const std::string Parameters::SIZE_CARACTERISTIC_VECTOR = "iPsizeVecCarac";
const std::string Parameters::WEIGHT_DISTANCE = "vPweigtDistance";
const std::string Parameters::CDP_THRESHOLD = "fPThreshold";
const std::string Parameters::LEVENSHTEIN_ADD_COST = "fPLevenshteinAddCost";
const std::string Parameters::LEVENSHTEIN_DEL_COST = "fPLevenshteinDelCost";
const std::string Parameters::LEVENSHTEIN_TRANS_COST = "fPLevenshteinTransCost";
const std::string Parameters::MVM_ELASTICITY = "iPMvmElastic";
const std::string Parameters::FSM_ELASTICITY = "iPFsmElesticity";
const std::string Parameters::FSM_WEIGHT = "fPFsmWeight";
const std::string Parameters::FSM_SMALL_SKIP_COST = "fPFsmSmallSkipCost";
const std::string Parameters::FSM_SKIP_COST = "fPFsmSkipCost";
const std::string Parameters::FSM_TYPE_RESULT = "iPFsmTypeOfResult";
const std::string Parameters::FSM_NUMBER_ELEMENTS_BY_LINE = "iPFsmNbOfMinByLine";
const std::string Parameters::FSM_FIRST_COL_FOR_RESULT = "bPFsmFirstColForResult";
const std::string Parameters::FSM_DEFAULT_SKIP_COST = "fPFsmDefaultSkipCost";
const std::string Parameters::FSM_STANDARD_DEVIATION_NUMBER = "iPFsmStandartDeviationNumber";

Parameters::Parameters(unsigned int sizeS1, unsigned int sizeS2, unsigned int sizeCharacteresticVector) {
	// Fill default parameters
	putValue(SIZE_FIRST_SEQUENCE, (float) sizeS1);
	putValue(SIZE_SECOND_SEQUENCE, (float) sizeS2);
	putValue(SIZE_CARACTERISTIC_VECTOR, (float) sizeCharacteresticVector);
	vPweightVecCarac = new vector<float>(sizeCharacteresticVector, 1);
	vPweightS1 = new vector<float>(sizeS1, 1);
	vPweightS2 = new vector<float>(sizeS2, 1);
	vPweightMatrice = new vector<vector<float>*>(sizeS1);
	unsigned int iBoucle = 0;
	while (iBoucle < vPweightMatrice->size()) {
		vector<float> * col = new vector<float>(sizeS2, 1);
		vPweightMatrice->at(iBoucle) = col;
		iBoucle = iBoucle + 1;
	}

	// Fill other parameters
	fillParameters();
}

Parameters::Parameters(unsigned int sizeS1, unsigned int sizeS2) : Parameters(sizeS1, sizeS2, 0) {}

Parameters::Parameters() : Parameters(0, 0) {}

Parameters::~Parameters()
{
	int iBoucle = 0;
	int matrixSize = vPweightMatrice->size();
	while (iBoucle < matrixSize)
	{
		vector<float> * p = vPweightMatrice->at(iBoucle);
		delete p;
		iBoucle = iBoucle + 1;
	}
	delete vPweightMatrice;
	delete vPweightS1;
	delete vPweightS2;
	delete vPweightVecCarac;
}

void Parameters::putValue(std::string key, float value) {
	values[key] = value;
}

float Parameters::getValue(std::string key) {
	if (values.find(key) == values.end()){
		exc::SequenceMatchingException::genererException(
			"Parameters : a parameter was not found", ERREUR_FILE, __LINE__);
	}
	return values.at(key);
}

void Parameters::setFirstSequenceWeight(unsigned int index, float value)
{
	unsigned int iPsizeS1 = (unsigned int) getValue(SIZE_FIRST_SEQUENCE);
	if (index >= iPsizeS1) {
		exc::SequenceMatchingException::genererException("setFirstSequenceWeight : Index value error", PARAMETRE_INVALIDE, __LINE__);
	}
	if (value < 0 || value > 1) {
		exc::SequenceMatchingException::genererException("setFirstSequenceWeight : Weight value error", PARAMETRE_INVALIDE, __LINE__);
	}
	vPweightS1->at(index) = value;
}

void Parameters::setSecondSequenceWeight(unsigned int index, float value)
{
	unsigned int iPsizeS2 = (unsigned int) getValue(SIZE_SECOND_SEQUENCE);
	if (index >= iPsizeS2) {
		exc::SequenceMatchingException::genererException("setSecondSequenceWeight : Index value error", PARAMETRE_INVALIDE, __LINE__);
	}
	if (value<0 || value > 1) {
		exc::SequenceMatchingException::genererException("setSecondSequenceWeight : Weight value error", PARAMETRE_INVALIDE, __LINE__);
	}
	vPweightS2->at(index) = value;
}

void Parameters::setCharacteristicVectorWeight(unsigned int index, float value)
{
	unsigned int iPsizeVecCarac = (unsigned int) getValue(SIZE_CARACTERISTIC_VECTOR);
	if (vPweightVecCarac == 0) {
		exc::SequenceMatchingException::genererException("setCharacteristicVectorWeight : No caracteristic vector size defined", PARAMETRE_INVALIDE, __LINE__);
	}
	if (index >= iPsizeVecCarac) {
		exc::SequenceMatchingException::genererException("setCharacteristicVectorWeight : Index value error", PARAMETRE_INVALIDE, __LINE__);
	}
	if (value<0 || value > 1) {
		exc::SequenceMatchingException::genererException("setCharacteristicVectorWeight : Weight value error", PARAMETRE_INVALIDE, __LINE__);
	}
	vPweightVecCarac->at(index) = value;
}

void Parameters::setMatrixWeight(unsigned int index1, unsigned int index2, float value)
{
	unsigned int iPsizeS1 = (unsigned int) getValue(SIZE_FIRST_SEQUENCE);
	unsigned int iPsizeS2 = (unsigned int) getValue(SIZE_SECOND_SEQUENCE);
	if (index1 >= iPsizeS1 || index2 >= iPsizeS2)
	{
		exc::SequenceMatchingException::genererException("setMatrixWeight : Index value error", PARAMETRE_INVALIDE, __LINE__);
	}
	if (value<0 || value > 1)
	{
		exc::SequenceMatchingException::genererException("setMatrixWeight : Weight value error", PARAMETRE_INVALIDE, __LINE__);
	}
	(vPweightMatrice->at(index1))->at(index2) = value;
}

void Parameters::setFirstSequenceSize(unsigned int value)
{
	putValue(SIZE_FIRST_SEQUENCE, (float) value);
	unsigned int iPsizeS1 = (unsigned int) getValue(SIZE_FIRST_SEQUENCE);
	unsigned int iPsizeS2 = (unsigned int) getValue(SIZE_SECOND_SEQUENCE);
	unsigned int it = 0;
	unsigned int __max = vPweightMatrice->size();
	while (it<__max)
	{
		vector<float> * p = vPweightMatrice->at(it);
		delete p;
		it = it + 1;
	}
	delete vPweightMatrice;
	delete vPweightS1;
	delete vPweightS2;
	vPweightS1 = new vector<float>(iPsizeS1, 1);
	vPweightS2 = new vector<float>(iPsizeS2, 1);
	vPweightMatrice = new vector<vector<float>*>(iPsizeS1);
	it = 0;
	while (it<vPweightMatrice->size())
	{
		vector<float> * n = new vector<float>(iPsizeS2, 1);
		vPweightMatrice->at(it) = n;
		it = it + 1;
	}

}

void Parameters::setCharacteristicVectorSize(unsigned int value)
{
	putValue(SIZE_CARACTERISTIC_VECTOR, (float) value);
	unsigned int iPsizeVecCarac = (unsigned int) getValue(SIZE_CARACTERISTIC_VECTOR);
	delete vPweightVecCarac;
	vPweightVecCarac = new vector<float>(iPsizeVecCarac, 1);
}

void Parameters::setSecondSequenceSize(unsigned int value)
{
	putValue(SIZE_SECOND_SEQUENCE, (float) value);

	int iPsizeS1 = (int)getValue(SIZE_FIRST_SEQUENCE);
	int iPsizeS2 = (int)getValue(SIZE_SECOND_SEQUENCE);
	unsigned int it = 0;
	unsigned int __max = vPweightMatrice->size();
	while (it<__max)
	{
		vector<float> * p = vPweightMatrice->at(it);
		delete p;
		it = it + 1;
	}
	delete vPweightMatrice;
	delete vPweightS1;
	delete vPweightS2;
	vPweightS1 = new vector<float>(iPsizeS1, 1);
	vPweightS2 = new vector<float>(iPsizeS2, 1);
	vPweightMatrice = new vector<vector<float>*>(iPsizeS1);
	it = 0;
	while (it<vPweightMatrice->size())
	{
		vector<float> * n = new vector<float>(iPsizeS2, 1);
		vPweightMatrice->at(it) = n;
		it = it + 1;
	}
}

int Parameters::getFirstSequenceSize()
{
	int iPsizeS1 = (int) getValue(SIZE_FIRST_SEQUENCE);
	return iPsizeS1;
}

int Parameters::getSecondSequenceSize()
{
	int iPsizeS2 = (int) getValue(SIZE_SECOND_SEQUENCE);
	return iPsizeS2;
}

int Parameters::getCharacteristicVectorSize()
{
	int iPsizeVecCarac = (int) getValue(SIZE_CARACTERISTIC_VECTOR);
	return iPsizeVecCarac;
}

float Parameters::getFirstSequenceWeight(unsigned int index)
{
	unsigned int iPsizeS1 = (unsigned int) getValue(SIZE_FIRST_SEQUENCE);
	if (index >= iPsizeS1){
		exc::SequenceMatchingException::genererException("getFirstSequenceWeight : Index value error", PARAMETRE_INVALIDE, __LINE__);
	}
	return vPweightS1->at(index);
}

float Parameters::getSecondSequenceWeight(unsigned int index)
{
	unsigned int iPsizeS2 = (unsigned int) getValue(SIZE_SECOND_SEQUENCE);
	if (index > iPsizeS2) {
		exc::SequenceMatchingException::genererException("getSecondSequenceWeight : Index value error", PARAMETRE_INVALIDE, __LINE__);
	}
	return vPweightS2->at(index);
}

float Parameters::getMatrixWeight(unsigned int i1, unsigned int i2)
{
	unsigned int iPsizeS1 = (unsigned int) getValue(SIZE_FIRST_SEQUENCE);
	unsigned int iPsizeS2 = (unsigned int) getValue(SIZE_SECOND_SEQUENCE);
	if (i1 >= iPsizeS1 || i2 >= iPsizeS2) {
		exc::SequenceMatchingException::genererException("getMatrixWeight : Index value error", PARAMETRE_INVALIDE, __LINE__);
	}
	return vPweightMatrice->at(i1)->at(i2);
}

float Parameters::getCharacteristicVectorWeight(unsigned int index) {
	if (vPweightVecCarac == 0) {
		exc::SequenceMatchingException::genererException("No caracteristic vector size defined", PARAMETRE_INVALIDE, __LINE__);
	}
	unsigned int iPsizeVecCarac = (unsigned int) getValue(SIZE_CARACTERISTIC_VECTOR);
	if (index >= iPsizeVecCarac) {
		exc::SequenceMatchingException::genererException("getCharacteristicVectorWeight : Index value error", PARAMETRE_INVALIDE, __LINE__);
	}
	return vPweightVecCarac->at(index);
}

void Parameters::fillParameters() {
	putValue(WEIGHT_DISTANCE, 1);
	putValue(LEVENSHTEIN_ADD_COST, 1.0f);
	putValue(LEVENSHTEIN_DEL_COST, 1.0f);
	putValue(LEVENSHTEIN_TRANS_COST, 1.0f);
	putValue(CDP_THRESHOLD, -1);
	putValue(MVM_ELASTICITY, 10);
	putValue(FSM_ELASTICITY, -1);
	putValue(FSM_WEIGHT, 1);
	putValue(FSM_SMALL_SKIP_COST, -1);
	putValue(FSM_SKIP_COST, -1);
	putValue(FSM_TYPE_RESULT, 0);
	putValue(FSM_NUMBER_ELEMENTS_BY_LINE, 2);
	putValue(FSM_FIRST_COL_FOR_RESULT, 1);
	putValue(FSM_DEFAULT_SKIP_COST, 0.1f);
	putValue(FSM_STANDARD_DEVIATION_NUMBER, 2);
}
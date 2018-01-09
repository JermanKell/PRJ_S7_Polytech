#include "ParamParser.h"
#include "GtestEnvironment.h"

TEST(ParamParserTest, reading_parameters_file) {
	int iBoucle;
	std::string filename = *MyEnvironment::shared_path + "standard_parameters_file.xml";
	inout::ParamParser parser;
	std::vector<tools::Parameters*> *  paramList = (std::vector<tools::Parameters*> *) parser.readFile((void*)filename.c_str());

	tools::Parameters* param = paramList->at(0);

	int size1 = param->getFirstSequenceSize();
	ASSERT_EQ(size1, 2);

	int size2 = param->getSecondSequenceSize();
	ASSERT_EQ(size2, 2);

	int sizeVector = param->getCharacteristicVectorSize();
	ASSERT_EQ(sizeVector, 2);

	float weightDistance = param->getValue(tools::Parameters::WEIGHT_DISTANCE);
	ASSERT_EQ(weightDistance, 2);

	float addCost = param->getValue(tools::Parameters::LEVENSHTEIN_ADD_COST);
	ASSERT_EQ(addCost, 1);

	float delCost = param->getValue(tools::Parameters::LEVENSHTEIN_DEL_COST);
	ASSERT_EQ(delCost, 2);

	float transCost = param->getValue(tools::Parameters::LEVENSHTEIN_TRANS_COST);
	ASSERT_EQ(transCost, 3);

	float cdpThreshold = param->getValue(tools::Parameters::CDP_THRESHOLD);
	ASSERT_EQ(cdpThreshold, 2);

	int mvmElasticity = (int) param->getValue(tools::Parameters::MVM_ELASTICITY);
	ASSERT_EQ(mvmElasticity, 1);

	int fsmElasticity = (int) param->getValue(tools::Parameters::FSM_ELASTICITY);
	ASSERT_EQ(fsmElasticity, 1);

	float fsmWeight = param->getValue(tools::Parameters::FSM_WEIGHT);
	ASSERT_EQ(fsmWeight, 2);

	float fsmSkipCost = param->getValue(tools::Parameters::FSM_SKIP_COST);
	ASSERT_EQ(fsmSkipCost, 1);

	float fsmSmallSkipCost = param->getValue(tools::Parameters::FSM_SMALL_SKIP_COST);
	ASSERT_EQ(fsmSmallSkipCost, 1);

	int fsmTypeOfResult = (int) param->getValue(tools::Parameters::FSM_TYPE_RESULT);
	ASSERT_EQ(fsmTypeOfResult, 1);

	int fsmResultFirstColumn = (int) param->getValue(tools::Parameters::FSM_FIRST_COL_FOR_RESULT);
	ASSERT_EQ(fsmResultFirstColumn, 2);

	int fsmNbMinPerLine = (int) param->getValue(tools::Parameters::FSM_NUMBER_ELEMENTS_BY_LINE);
	ASSERT_EQ(fsmNbMinPerLine, 2);

	float fsmDefaultSkipCost = param->getValue(tools::Parameters::FSM_DEFAULT_SKIP_COST);
	ASSERT_EQ(fsmDefaultSkipCost, 1);

	int fsmStandardDeviation = (int) param->getValue(tools::Parameters::FSM_STANDARD_DEVIATION_NUMBER);
	ASSERT_EQ(fsmStandardDeviation, 1);

	for (iBoucle = 0; iBoucle < size1; iBoucle++) {
		ASSERT_EQ(param->getFirstSequenceWeight(iBoucle), 1);
	}

	for (iBoucle = 0; iBoucle < size2; iBoucle++) {
		ASSERT_EQ(param->getSecondSequenceWeight(iBoucle), 1);

		for (int jBoucle = 0; jBoucle < size1; jBoucle++) {
			ASSERT_EQ(param->getMatrixWeight(jBoucle, iBoucle), 0.8f);
		}
	}

	for (iBoucle = 0; iBoucle < sizeVector; iBoucle++) {
		ASSERT_EQ(param->getCharacteristicVectorWeight(iBoucle), 0.5f);
	}

	delete param;
	delete paramList;
}

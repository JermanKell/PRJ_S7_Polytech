#include "Parameters.h"
#if defined _WIN32 || defined _WIN64
    #include "gtest\gtest.h"
#elif defined __linux__
    #include "gtest/gtest.h"
#endif

TEST(ParametersTest, creating_parameters_objects) {
	tools::Parameters p1;
	int firstSequenceSize = p1.getFirstSequenceSize();
	ASSERT_EQ(firstSequenceSize, 0);
	int secondSequenceSize = p1.getSecondSequenceSize();
	ASSERT_EQ(secondSequenceSize, 0);

	tools::Parameters p2(5, 5);
	firstSequenceSize = p2.getFirstSequenceSize();
	ASSERT_EQ(firstSequenceSize, 5);
	secondSequenceSize = p2.getSecondSequenceSize();
	ASSERT_EQ(secondSequenceSize, 5);

	tools::Parameters p3(2, 2, 2);
	firstSequenceSize = p3.getFirstSequenceSize();
	ASSERT_EQ(firstSequenceSize, 2);
	secondSequenceSize = p3.getSecondSequenceSize();
	ASSERT_EQ(secondSequenceSize, 2);
	int vectorSize = p3.getCharacteristicVectorSize();
	ASSERT_EQ(vectorSize, 2);
}

TEST(ParametersTest, putting_getting_values) {
	std::string key = "parameter";
	tools::Parameters p1;
	p1.putValue(key, 2);
	ASSERT_EQ(p1.getValue(key), 2);
}

TEST(ParametersTest, default_values) {
	size_t i, j;
	unsigned int size = 2;
	tools::Parameters p1(size, size, size);
	for (i = 0; i < size; i++) {
		ASSERT_EQ(p1.getFirstSequenceWeight(i), 1);
		ASSERT_EQ(p1.getSecondSequenceWeight(i), 1);
		ASSERT_EQ(p1.getCharacteristicVectorWeight(i), 1);
		for (j = 0; j < size; j++) {
			ASSERT_EQ(p1.getMatrixWeight(i, j), 1);
		}
	}
	ASSERT_EQ(p1.getValue(tools::Parameters::WEIGHT_DISTANCE), 1);
	ASSERT_EQ(p1.getValue(tools::Parameters::LEVENSHTEIN_ADD_COST), 1);
	ASSERT_EQ(p1.getValue(tools::Parameters::LEVENSHTEIN_DEL_COST), 1);
	ASSERT_EQ(p1.getValue(tools::Parameters::LEVENSHTEIN_TRANS_COST), 1);
	ASSERT_EQ(p1.getValue(tools::Parameters::CDP_THRESHOLD), -1);
	ASSERT_EQ(p1.getValue(tools::Parameters::MVM_ELASTICITY), 10);
	ASSERT_EQ(p1.getValue(tools::Parameters::FSM_ELASTICITY), -1);
	ASSERT_EQ(p1.getValue(tools::Parameters::FSM_WEIGHT), 1);
	ASSERT_EQ(p1.getValue(tools::Parameters::FSM_SMALL_SKIP_COST), -1);
	ASSERT_EQ(p1.getValue(tools::Parameters::FSM_SKIP_COST), -1);
	ASSERT_EQ(p1.getValue(tools::Parameters::FSM_TYPE_RESULT), 0);
	ASSERT_EQ(p1.getValue(tools::Parameters::FSM_NUMBER_ELEMENTS_BY_LINE), 2);
	ASSERT_EQ(p1.getValue(tools::Parameters::FSM_FIRST_COL_FOR_RESULT), 1);
	ASSERT_EQ(p1.getValue(tools::Parameters::FSM_DEFAULT_SKIP_COST), 0.1f);
	ASSERT_EQ(p1.getValue(tools::Parameters::FSM_STANDARD_DEVIATION_NUMBER), 2);
}

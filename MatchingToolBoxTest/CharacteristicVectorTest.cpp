#if defined _WIN32 || defined _WIN64
    #include "CharacteristicVector.h"
    #include "gtest\gtest.h"
#elif defined __linux__
    #include "../MatchingLibrary/CharacteristicVector.h"
    #include "gtest/gtest.h"
#endif

TEST(CharacteristicVectorTest, creating_vector) {
	model::CharacteristicVector vector;
	ASSERT_EQ(vector.getSize(), 0);
}

TEST(CharacteristicVectorTest, adding_values) {
	float v = 5;
	model::CharacteristicVector vector;

	vector.addValue(v);
	ASSERT_EQ(vector.getSize(), 1);
	ASSERT_EQ(vector.getAt(0), v);
}

TEST(CharacteristicVectorTest, setting_values) {
	float v = 4;
	model::CharacteristicVector vector;
	vector.addValue(5);

	vector.setValue(0, v);
	ASSERT_EQ(vector.getSize(), 1);
	ASSERT_EQ(vector.getAt(0), v);

	ASSERT_ANY_THROW(vector.setValue(5, v));
}

TEST(CharacteristicVectorTest, removing_values) {
	float v = 5;
	model::CharacteristicVector vector;
	vector.addValue(v);

	vector.removeValue(0);
	ASSERT_EQ(vector.getSize(), 0);

	ASSERT_ANY_THROW(vector.removeValue(5));
}

TEST(CharacteristicVectorTest, vector_distance) {
	float v = 5, v2 = 4;
	model::CharacteristicVector vector, vector2;
	vector.addValue(v);
	vector2.addValue(v2);

	float distance = vector.distance(&vector, &vector2);
	ASSERT_EQ(distance, 1);
}

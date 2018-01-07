#if defined _WIN32 || defined _WIN64
    #include "Numeric.h"
    #include "gtest\gtest.h"
#elif defined __linux__
    #include "../MatchingLibrary/Numeric.h"
    #include "gtest/gtest.h"
#endif

TEST(NumericTest, setting_getting_value) {
	model::Numeric n(5);
	ASSERT_EQ(n.getValue(), 5);

	n.setValue(4);
	ASSERT_EQ(n.getValue(), 4);
}

TEST(NumericTest, calculating_distance) {
	model::Numeric n1(5);
	model::Numeric n2(4);

	float distance = n1.distance(&n1, &n2);

	ASSERT_EQ(distance, 1.0f);
}

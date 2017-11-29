#include "Numeric.h"
#include "gtest\gtest.h"

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
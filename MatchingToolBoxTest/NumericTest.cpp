#include "Numeric.h"
#include "gtest\gtest.h"

TEST(Numeric, Playing_with_values) {
	model::Numeric n(4);
	ASSERT_EQ(4, n.getValue());
	n.setValue(5);
	ASSERT_NE(4, n.getValue());
	ASSERT_EQ(5, n.getValue());
}

TEST(Numeric, Numeric_distance) {
	model::Numeric* n1 = new model::Numeric(5);
	model::Numeric* n2 = new model::Numeric(5);

	float distance = n1->distance(n1, n2);
	ASSERT_EQ(0, distance);
}
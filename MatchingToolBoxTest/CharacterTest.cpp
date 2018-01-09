#include "Character.h"
#if defined _WIN32 || defined _WIN64
    #include "gtest\gtest.h"
#elif defined __linux__
    #include "gtest/gtest.h"
#endif

TEST(CharacterTest, setting_getting_value) {
	char value = 'a';
	char value2 = 'b';
	model::Character c(value);
	ASSERT_EQ(c.getValue(), value);

	c.setValue(value2);
	ASSERT_EQ(c.getValue(), value2);
}

TEST(CharacterTest, character_distance) {
	char value = 'a';
	char value2 = 'b';
	model::Character c1(value);
	model::Character c2(value2);

	float distance = c1.distance(&c1, &c2);
	ASSERT_EQ(distance, 1);

	c2.setValue(value);
	distance = c1.distance(&c1, &c2);
	ASSERT_EQ(distance, 0);
}

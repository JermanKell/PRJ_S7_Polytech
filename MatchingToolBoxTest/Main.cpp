#include <iostream>
#include "gtest\gtest.h"
//#include "vld.h"

int main(int argc, char *argv[])
{
	int testResult = 0;
	// Runs tests
	::testing::InitGoogleTest(&argc, argv);
	testResult = RUN_ALL_TESTS();
	
	std::getchar();
	return testResult;
}

#include <iostream>
#include "gtest\gtest.h"
#include "vld.h" //Tests fuites mémoire, 4 blocks provoqués par google
#include "Command.h"


int main(int argc, char *argv[])
{
	int testResult = 0;
	// Runs tests
	
	::testing::InitGoogleTest(&argc, argv);
	testResult = RUN_ALL_TESTS();

	std::getchar();
	return testResult;
}

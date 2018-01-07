#include <iostream>
#if defined _WIN32 || defined _WIN64
    #include "Command.h"
    #include "gtest\gtest.h"
    #include "vld.h" //Tests fuites mémoire, 4 blocks provoqués par google
#elif defined __linux__
    #include "gtest/gtest.h"
#endif


int main(int argc, char *argv[])
{
	int testResult = 0;
	// Runs tests

	::testing::InitGoogleTest(&argc, argv);
	testResult = RUN_ALL_TESTS();

	std::getchar();
	return testResult;
}

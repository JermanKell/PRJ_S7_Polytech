#include <iostream>
#include "gtest\gtest.h"
#include "vld.h" //Tests fuites m�moire, 4 blocks provoqu�s par google
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

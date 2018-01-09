#include <iostream>
#include "GtestEnvironment.h"
#if defined _WIN32 || defined _WIN64
    #include "vld.h"
#endif

int main(int argc, char *argv[])
{
	int testResult = 0;
	// Runs tests
	::testing::InitGoogleTest(&argc, argv);
	testing::AddGlobalTestEnvironment(new MyEnvironment);
	testResult = RUN_ALL_TESTS();

	std::getchar();
	return testResult;
}

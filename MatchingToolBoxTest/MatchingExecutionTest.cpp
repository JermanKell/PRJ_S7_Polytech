#if defined _WIN32 || defined _WIN64
    #include "MatchingExecutor.h"
    #include "Support.h"
    #include "gtest\gtest.h"
#elif defined __linux__
    #include "../MatchingLibrary/MatchingExecutor.h"
    #include "../MatchingLibrary/Support.h"
    #include "gtest/gtest.h"
#endif

TEST(MatchingExecutionTest, creating_objects) {
	char* file1 = "..\\TestingMaterial\\target_numeric.csv";
	char* file2 = "..\\TestingMaterial\\ref_numeric.csv";
	char* directory = "..\\TestingMaterial\\simple";
	tools::MatchingExecutor executor(file1, file2, NULL);
	// First constructor
	ASSERT_EQ(executor.getTargetFile(), file1);
	ASSERT_EQ(executor.getReferenceFile(), file2);
	if (executor.getMethod() == NULL) {
		SUCCEED();
	} else {
		FAIL();
	}

	//Second constructor
	tools::MatchingExecutor executor2(file1, file2, NULL, directory);
	ASSERT_EQ(executor2.getResultDirectory(), directory);

	//Last constructor
	tools::MatchingExecutor executor3(file1, file2, NULL, NULL, directory);
	if (executor.getParameters() == NULL) {
		SUCCEED();
	}
	else {
		FAIL();
	}
}

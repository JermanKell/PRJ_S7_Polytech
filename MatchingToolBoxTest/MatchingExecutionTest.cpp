#include "MatchingExecutor.h"
#include "Support.h"
#include "GtestEnvironment.h"

TEST(MatchingExecutionTest, creating_objects) {
	std::string file1 = *MyEnvironment::shared_path + "target_numeric.csv";
	std::string file2 = *MyEnvironment::shared_path + "ref_numeric.csv";
	std::string directory = *MyEnvironment::shared_path + "simple";

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

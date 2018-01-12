#ifndef MVMTEST_FFONCTIONNEL_H
#define MVMTEST_FFONCTIONNEL_H

#include "GtestEnvironment.h"

class MVM_SystemTest : public ::testing::Test {
protected:
	/*!
	*  \brief global SetUpTestCase
	*  Called before the first test in this test case
	*/
	static void SetUpTestCase() {}

	/*!
	*  \brief global TearDownTestCase
	*  Called after the last test in this test case.
	*/
	static void TearDownTestCase() {}

	/*!
	*  \brief SetUp
	*  Called before each test in this test case
	*/
	virtual void SetUp() {}

	/*!
	*  \brief TearDown
	*  Called after each test in this test case
	*/
	virtual void TearDown() {}
};

#endif  // MVMTEST_FFONCTIONNEL_H

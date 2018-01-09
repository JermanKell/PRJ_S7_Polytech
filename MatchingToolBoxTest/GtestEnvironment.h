#ifndef GTESTENVIRONMENT_H
#define GTESTENVIRONMENT_H

#if defined _WIN32 || defined _WIN64
	#include "gtest\gtest.h"
#elif defined __linux__
	#include "gtest/gtest.h"
#endif

class MyEnvironment : public testing::Environment {

	public:
		/*!< resource shared by all tests*/
		static std::string* shared_path;

	private:
		/*!
		*  \brief global SetUp
		*  Called before all the tests
		*/
		virtual void SetUp() {
			#if defined _WIN32 || defined _WIN64
					shared_path = new std::string("..\\TestingMaterial\\");
			#elif defined __linux__
					shared_path = new std::string("../../../VS2015/MatchingToolBox/TestingMaterial/");
			#endif
		}

		/*!
		*  \brief global TearDown
		*  Called after all the tests
		*/
		virtual void TearDown() {
			delete shared_path;
		}
};

#endif  // GTESTENVIRONMENT_H
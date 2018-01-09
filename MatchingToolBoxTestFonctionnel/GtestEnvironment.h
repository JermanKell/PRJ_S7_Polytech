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

        /*!
		*  \brief InitPath
		*  Allow to build the path
		*/
		static void InitPath(char* folder) {
			///////////////////////////////////////////
			///////////////////////////////////////////
			///////////////////////////////////////////
		};

	private:
	    /*!< identify the environment*/
	    std::string environment;

		/*!
		*  \brief global SetUp
		*  Called before all the tests
		*/
		virtual void SetUp() {
			#if defined _WIN32 || defined _WIN64
                environment = "win";
		    #elif defined __linux__
                environment = "lin";
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

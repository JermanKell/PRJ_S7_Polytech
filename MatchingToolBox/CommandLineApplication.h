#pragma once

#include "CommandLine.h"
#include "Support.h"
#include "InOut.h"

#include <cstring>
#include <cstdlib>
#include <cfloat>
#include <string.h>
#include <stdio.h>
#include <omp.h>

// Custom arguments
#define _seq "-sequences"
#define _method "-method"
#define _param "-param"
#define _cost "--costs"
#define _dir "-result"
#define _help "--help"

// Supported methods
#define _m1 "lvn"
#define _m2 "lcs"
#define _m3 "dtw"
#define _m4 "mvm"
#define _m5 "cdp"
#define _m6 "fsm"
#define _m7 "esc"

// Libraries to manipulate directories
#if defined __linux__ || TARGET_OS_MAC
#include <sys/stat.h>
#else
#include <direct.h>// direct.h is not part of gcc so it cannot be found in linux
#endif

namespace commandline {
	class CommandLineApplication : public CommandLine {
	private : 
		/*!< supported matching methods */
		std::map<std::string, tools::Correspondence*> methods;

		void expect();
	public:
		CommandLineApplication(int argc, char *argv[]) : CommandLine(argc, argv) {
			expect();
		};

		/**
		* \brief run
		* Function which run the basic execution of the matching sequences
		*/
		void run();

		void addMethod(std::string name, tools::Correspondence* method) {
			expectValue(_method, name);
			methods[name] = method;
		}

		tools::Correspondence* getMethod(std::string name) {
			return methods.at(name);
		}
	};
}
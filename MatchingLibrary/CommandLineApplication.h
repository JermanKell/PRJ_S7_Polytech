#pragma once
/*!
\author ELMOUTARAJI Mohammed
BOUTBIB Houda
\date 22/12/2016
\package CommandLineApplication
\brief Commandline reads a certain command.
*/

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
#define _parser "-parser"
#define _type "-type"
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

// Supported parsers
#define _csv "csv"
#define _ext "ext"
#define _xml "xml"

// Sequence types
#define _type1 "character"
#define _type2 "numeric"
#define _type3 "vector"

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

		/*!< supported matching methods */
		std::map<std::string, inout::SequenceParser*> parsers;

		/**
		* \brief expect
		* private function where we put our expectations for our command,
		* using the inherited functions expectArgument() and expectValue(). 
		*/
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

		/**
		* \brief addMethod
		* adds a supported method that can be accessed from a command line using a name.
		* \param name the name of the method (matching algorithm)
		* \param method the matching algorithm
		*/
		void addMethod(std::string name, tools::Correspondence* method) {
			expectValue(_method, name);
			methods[name] = method;
		}

		/**
		* \brief getMethod
		* Gets a method using its name
		* \param name the name of the method (matching algorithm)
		* \return the matching algorithm
		*/
		tools::Correspondence* getMethod(std::string name) {
			return methods.at(name);
		}

		/**
		* \brief addParser
		* adds a supported parser that can be accessed from a command line using a name.
		* \param name the name of the parser
		* \param parser
		*/
		void addParser(std::string name, inout::SequenceParser* parser) {
			expectValue(_parser, name);
			parsers[name] = parser;
		}

		/**
		* \brief getParser
		* Gets a parser using its name
		* \param name the name of the parser
		* \return parser
		*/
		inout::SequenceParser* getParser(std::string name) {
			return parsers.at(name);
		}
	};
}
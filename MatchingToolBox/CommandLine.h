#pragma once

#include <vector>
#include <map>

#ifndef COMMANDLINE_H
#define COMMANDLINE_H

namespace commandline {
	class CommandLine {
	protected:
		std::vector<std::string> expectedArguments;
		std::map<std::string, std::vector<std::string>> expectedValues;
		std::vector<std::string> enteredArguments;
		std::map<std::string, std::vector<std::string>> enteredValues;

	public : 
		CommandLine(int argc, char *argv[]);

		void expectArgument(std::string argument);

		void expectValue(std::string argument, std::string value);

		void expectValues(std::string argument, unsigned int nbValues, char* values[]);

		void enterArgument(std::string argument);

		void enterValue(std::string argument, std::string value);

		void enterValues(std::string argument, unsigned int nbValues, char* values[]);

		/*!
		* \brief run
		* run the program
		*/
		virtual void run() = 0;

	private : 
		void prepareCommand(int argc, char *argv[]);
	};
}

#endif
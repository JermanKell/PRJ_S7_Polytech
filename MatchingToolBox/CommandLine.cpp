#include "CommandLine.h"

using namespace commandline;

CommandLine::CommandLine(int argc, char *argv[]) {
	prepareCommand(argc, argv);
}

void CommandLine::expectArgument(std::string argument) {
	expectedArguments.push_back(argument);
}

void CommandLine::expectValue(std::string argument, std::string value) {
	expectedValues[argument].push_back(value);
}

void CommandLine::expectValues(std::string argument, unsigned int nbValues, char* values[]) {
	for (size_t i = 0; i < nbValues; i++) {
		expectValue(argument, values[i]);
	}
}

void CommandLine::enterArgument(std::string argument) {
	enteredArguments.push_back(argument);
}

void CommandLine::enterValue(std::string argument, std::string value) {
	enteredValues[argument].push_back(value);
}

void CommandLine::enterValues(std::string argument, unsigned int nbValues, char* values[]) {
	for (size_t i = 0; i < nbValues; i++) {
		enterValue(argument, values[i]);
	}
}

void CommandLine::prepareCommand(int argc, char *argv[]) {
	std::string* lastArgument = 0;
	for (int i = 1; i < argc; i++) {
		if (argv[i][0] == '-') {
			delete lastArgument;
			lastArgument = new std::string(argv[i]);
			enterArgument(*lastArgument);
		}
		else
		{
			std::string value(argv[i]);
			enterValue(*lastArgument, value);
		}
	}
}

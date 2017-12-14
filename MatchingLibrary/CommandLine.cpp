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

bool CommandLine::isExpected(std::string argument) {
	return find(expectedArguments.begin(), expectedArguments.end(), argument) !=
		expectedArguments.end();
}

bool CommandLine::isExpected(std::string argument, std::string value) {
	return find(expectedValues.at(argument).begin(), expectedValues.at(argument).end(), value) != 
		expectedValues.at(argument).end();
}

bool CommandLine::isEntered(std::string argument) {
	return find(enteredArguments.begin(), enteredArguments.end(), argument) != enteredArguments.end();
}

bool CommandLine::isEntered(std::string argument, std::string value) {
	return find(enteredValues.at(argument).begin(), enteredValues.at(argument).end(), value) !=
		enteredValues.at(argument).end();
}

std::string CommandLine::getEnteredValue(std::string argument, unsigned int position) {
	return enteredValues.at(argument).at(position);
}

void CommandLine::prepareCommand(int argc, char *argv[]) {
	std::string lastArgument = "";	//pointeur string changé en string =>correction fuite de 2 blocks
	for (int i = 1; i < argc; i++) {
		// If a word begins with '-' then it's considered as an argument, or else it's considered a value
		if (argv[i][0] == '-') {
			//delete lastArgument; //delete supprimé
			lastArgument = std::string(argv[i]); //objet, plus un pointeur
			enterArgument(lastArgument);	//passage objet et plus un pointeur
		}
		else
		{
			std::string value(argv[i]);
			enterValue(lastArgument, value); //objet, plus un pointeur
		}
	}
}

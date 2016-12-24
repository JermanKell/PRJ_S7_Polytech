#include "CommandLineApplication.h"

#include <algorithm>
#include <string>

using namespace commandline;

void CommandLineApplication::expect() {
	expectArgument(_seq);
	expectArgument(_method);
	expectArgument(_param);
	expectArgument(_cost);
	expectArgument(_dir);
	expectArgument(_help);
	addMethod(_m1, new support::LevenstheinCorrespondence());
	addMethod(_m2, new support::LCSCorrespondence());
	addMethod(_m3, new support::DTWCorrespondence());
	addMethod(_m4, new support::MVMCorrespondence());
	addMethod(_m5, new support::CDPCorrespondence());
	addMethod(_m6, new support::FSMCorrespondence());
	addMethod(_m7, new support::ESCCorrespondence());
}

void CommandLineApplication::run() {
	bool validHelp = find(enteredArguments.begin(), enteredArguments.end(), _help) != enteredArguments.end();
	bool validSequences = find(enteredArguments.begin(), enteredArguments.end(), _seq) != enteredArguments.end() &&
		enteredValues.at(_seq).size() == 2;
	bool validMethod = find(enteredArguments.begin(), enteredArguments.end(), _method) != enteredArguments.end() &&
		enteredValues.at(_method).size() == 1;
	if (!validHelp && (!validSequences || !validMethod))
	{
		exc::SequenceMatchingException::genererException(
			"A valid command needs either --help or both -sequences and -method with their values", PARAMETRE_INVALIDE, __LINE__);
	}

	// This variable is to indicate if the user GAVE parameters file, by
	// default it's false
	bool userParameters = false;
	// reference file of sequences
	std::string filereference;
	// target file of sequences
	std::string fileTarget = "";
	// Levenshtein default costs
	float cost1 = 1;
	float cost2 = 1;
	float cost3 = 1;
	// This variable is to indicate if the user GAVE a directory where to store
	// the output file, by default it's false
	bool userDirectory = false;
	// The path of the directory where to store the output file
	std::string directoryPath = "";
	// The name of the algorithm
	std::string methodName = "";
	// Parameters if a file was given
	tools::Parameters* parameters = 0;

	for (size_t iBoucle = 0; iBoucle < enteredArguments.size(); iBoucle++) {
		std::string *argument = new std::string(enteredArguments.at(iBoucle));
		// -sequences argument
		if (argument->compare(_seq) == 0) {
			fileTarget = enteredValues.at(_seq).at(0);
			filereference = enteredValues.at(_seq).at(1);
		}
		// -method argument
		else if (argument->compare(_method) == 0) {
			// Check if the entered method is expected/supported
			if (find(expectedValues.at(_method).begin(), expectedValues.at(_method).end(), enteredValues.at(_method).at(0)) ==
				expectedValues.at(_method).end()) {
				exc::SequenceMatchingException::genererException(
					"This method is not supported", PARAMETRE_INVALIDE, __LINE__);
			}
			// Get method that was entered in the command
			for (size_t i = 0; i < expectedValues.at(_method).size(); i++) {
				if (enteredValues.at(_method).at(0).compare(expectedValues.at(_method).at(i)) == 0) {
					methodName = enteredValues.at(_method).at(i);
					break;
				}
			}
		}
		// -param argument
		else if (argument->compare(_param) == 0) {
			if (enteredValues.at(_param).size() < 1) {
				exc::SequenceMatchingException::genererException(
					"-param needs a value", PARAMETRE_INVALIDE, __LINE__);
			}
			std::string parametersFile = enteredValues.at(_param).at(0);
			inout::ParamParser paramParser;
			parameters = (tools::Parameters *) paramParser.readFile((void*) parametersFile.c_str());
			userParameters = true;
		}
		// -result argument
		else if (argument->compare(_dir) == 0) {
			if (enteredValues.at(_dir).size() < 1) {
				exc::SequenceMatchingException::genererException(
					"-result needs a value", PARAMETRE_INVALIDE, __LINE__);
			}
			userDirectory = true;
			directoryPath = enteredValues.at(_dir).at(0);
		}
		// --costs argument
		else if (argument->compare(_cost) == 0) {
			if (enteredValues.at(_cost).size() < 3) {
				exc::SequenceMatchingException::genererException(
					"--costs needs 3 values", PARAMETRE_INVALIDE, __LINE__);
			}
			if (enteredValues.at(_method).at(0).compare(_m1) != 0) {
				exc::SequenceMatchingException::genererException(
					"--costs should be used only with Levenshtein method", PARAMETRE_INVALIDE, __LINE__);
			}
			cost1 = (float)atof(enteredValues.at(_cost).at(0).c_str());
			cost2 = (float)atof(enteredValues.at(_cost).at(1).c_str());
			cost3 = (float)atof(enteredValues.at(_cost).at(2).c_str());

			tools::Parameters* params = methods.at(_m1)->getParameters();
			params->putValue(params->LEVENSHTEIN_ADD_COST, cost1);
			params->putValue(params->LEVENSHTEIN_DEL_COST, cost2);
			params->putValue(params->LEVENSHTEIN_TRANS_COST, cost3);
		}
		// --help argument
		else if (argument->compare(_help) == 0) {
			if (iBoucle != 0) {
				exc::SequenceMatchingException::genererException(
					"--help needs to be the first argument", PARAMETRE_INVALIDE, __LINE__);
			}
			std::cout << "Toolbox parameters : " << std::endl;
			std::cout << "*	" << _help << " : If used it should be the only parameter." << std::endl;
			std::cout << "*	" << _seq << " <target.csv> <reference.csv>: You need to specify a target and a reference file." << std::endl;
			std::cout << "*	" << _method << " {lvn|lcs|dtw|mvm|cdp|fsm|esc} : Defines the algorithm used in sequence matching and it should be after -sequences." << std::endl;
			std::cout << "*	" << _param << " <parameters.xml> : (Optional) Specifies the parameters used for the algorithm." << std::endl;
			std::cout << "*	" << _dir << " </result/path> : (Optional) Defines the directory where the output will be saved." << std::endl;
			std::cout << "*	" << _cost << " <addCost> <delCost> <transCost> : (Optional) costs that are used in Levenshtein algorithm, default is : 1 1 1." << std::endl;

		}

		delete argument;
	}

	// The command is valid to perform sequence matching
	if (!validHelp && validSequences && validMethod) {
			tools::MatchingExecutor* executor = 0;
			if (userDirectory && userParameters) {
				executor = new tools::MatchingExecutor(filereference, fileTarget, methods.at(methodName), parameters, directoryPath);
			}
			else if (userParameters) {
				executor = new tools::MatchingExecutor(filereference, fileTarget, methods.at(methodName), parameters);
			}
			else if (userDirectory) {
				executor = new tools::MatchingExecutor(filereference, fileTarget, methods.at(methodName), directoryPath);
			}
			else {
				executor = new tools::MatchingExecutor(filereference, fileTarget, methods.at(methodName));
			}
			executor->execute();
	}
}


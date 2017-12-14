#include "CommandLineApplication.h"

#include <algorithm>
#include <string>

using namespace commandline;

void CommandLineApplication::expect() {
	// Expected arguments
	expectArgument(_seq);
	expectArgument(_method);
	expectArgument(_parser);
	expectArgument(_type);
	expectArgument(_param);
	expectArgument(_cost);
	expectArgument(_dir);
	expectArgument(_help);
	// Expected methods
	addMethod(_m1, new support::LevenstheinCorrespondence());
	addMethod(_m2, new support::LCSCorrespondence());
	addMethod(_m3, new support::DTWCorrespondence());
	addMethod(_m4, new support::MVMCorrespondence());
	addMethod(_m5, new support::CDPCorrespondence());		
	addMethod(_m6, new support::FSMCorrespondence());
	addMethod(_m7, new support::ESCCorrespondence());
	// Expected parsers
	addParser(_csv, new inout::CSVParser());
	addParser(_ext, new inout::EXTParser());
	addParser(_xml, new inout::XMLParser());
	// Expected types
	expectValue(_type, _type1);
	expectValue(_type, _type2);
	expectValue(_type, _type3);
}

void CommandLineApplication::run() {
	bool validHelp = isEntered(_help);
	bool validSequences = isEntered(_seq) && enteredValues.at(_seq).size() == 2;
	bool validMethod = isEntered(_method) && enteredValues.at(_method).size() == 1;
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
	std::string fileTarget;
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

	// The name of the parser
	std::string parserName = "";

	// The type of the sequences in the files
	std::string typeName = "";

	// Parameters if a file was given
	tools::Parameters* parameters = 0;

	for (size_t iBoucle = 0; iBoucle < enteredArguments.size(); iBoucle++) {
		std::string *argument = new std::string(enteredArguments.at(iBoucle));
		// -sequences argument
		if (argument->compare(_seq) == 0) {
			fileTarget = getEnteredValue(_seq, 0);
			filereference = getEnteredValue(_seq, 1);
		}
		// -method argument
		else if (argument->compare(_method) == 0) {
			// Check if the entered method is expected/supported
			if (!isExpected(_method, enteredValues.at(_method).at(0))) {
				exc::SequenceMatchingException::genererException(
					"This method is not supported", PARAMETRE_INVALIDE, __LINE__);
			}
			// Get method that was entered in the command
			methodName = getEnteredValue(_method, 0);
		}
		// -parser argument
		else if (argument->compare(_parser) == 0) {
			if (enteredValues.at(_parser).size() < 1) {
				exc::SequenceMatchingException::genererException(
					"-parser needs a value", PARAMETRE_INVALIDE, __LINE__);
			}
			// Check if the entered parser is expected/supported
			if (!isExpected(_parser, enteredValues.at(_parser).at(0))) {
				exc::SequenceMatchingException::genererException(
					"This parser is not supported", PARAMETRE_INVALIDE, __LINE__);
			}
			// Get parser that was entered in the command
			parserName = getEnteredValue(_parser, 0);
		}
		// -type argument
		else if (argument->compare(_type) == 0) {
			if (enteredValues.at(_type).size() < 1) {
				exc::SequenceMatchingException::genererException(
					"-parser needs a value", PARAMETRE_INVALIDE, __LINE__);
			}
			// Check if the entered parser is expected/supported
			if (!isExpected(_type, enteredValues.at(_type).at(0))) {
				exc::SequenceMatchingException::genererException(
					"This type is not supported", PARAMETRE_INVALIDE, __LINE__);
			}
			// Get parser that was entered in the command
			typeName = getEnteredValue(_type, 0);
		}
		// -param argument
		else if (argument->compare(_param) == 0) {
			if (enteredValues.at(_param).size() < 1) {
				exc::SequenceMatchingException::genererException(
					"-param needs a value", PARAMETRE_INVALIDE, __LINE__);
			}
			std::string parametersFile = getEnteredValue(_param, 0);
			inout::ParamParser paramParser;
			parameters = ((std::vector<tools::Parameters*> *) paramParser.readFile((void*) parametersFile.c_str())) ->at(0);
			userParameters = true;
		}
		// -result argument
		else if (argument->compare(_dir) == 0) {
			if (enteredValues.at(_dir).size() < 1) {
				exc::SequenceMatchingException::genererException(
					"-result needs a value", PARAMETRE_INVALIDE, __LINE__);
			}
			userDirectory = true;
			directoryPath = getEnteredValue(_dir, 0);
		}
		// --costs argument
		else if (argument->compare(_cost) == 0) {
			if (enteredValues.at(_cost).size() < 3) {
				exc::SequenceMatchingException::genererException(
					"--costs needs 3 values", PARAMETRE_INVALIDE, __LINE__);
			}
			if (enteredValues.at(_method).at(0).compare(_m1) != 0) {
				exc::SequenceMatchingException::genererException(
					"--costs should be used only with Levenshtein (lvn) method", PARAMETRE_INVALIDE, __LINE__);
			}
			cost1 = (float)atof(getEnteredValue(_cost, 0).c_str());
			cost2 = (float)atof(getEnteredValue(_cost, 1).c_str());
			cost3 = (float)atof(getEnteredValue(_cost, 2).c_str());

			tools::Parameters* params = methods.at(_m1)->getParameters();
			params->putValue(tools::Parameters::LEVENSHTEIN_ADD_COST, cost1);
			params->putValue(tools::Parameters::LEVENSHTEIN_DEL_COST, cost2);
			params->putValue(tools::Parameters::LEVENSHTEIN_TRANS_COST, cost3);
		}
		// --help argument
		else if (argument->compare(_help) == 0) {
			if (iBoucle != 0) {
				exc::SequenceMatchingException::genererException(
					"--help needs to be the first argument", PARAMETRE_INVALIDE, __LINE__);
			}
			std::cout << "Toolbox parameters : " << std::endl;
			std::cout << "*	" << _seq << " <target.csv> <reference.csv>: Specifies target and a reference file." << std::endl;
			std::cout << "*	" << _method << " {lvn|lcs|dtw|mvm|cdp|fsm|esc} : Defines the algorithm used in sequence matching and it should be after -sequences." << std::endl;
			std::cout << "*	" << _parser << " {csv|ext|xml} : (Optional) Specifies the parser that would be used to parse the files. Default : csv" << std::endl;
			std::cout << "*	" << _type << " {character|numeric|vector} : (Optional) Specifies the type of sequence in the file. Default : vector" << std::endl;
			std::cout << "*	" << _param << " <parameters.xml> : (Optional) Specifies the parameters used for the algorithm." << std::endl;
			std::cout << "*	" << _dir << " </result/path> : (Optional) Defines the directory where the output will be saved. Default : directory of target file" << std::endl;
			std::cout << "*	" << _cost << " <addCost> <delCost> <transCost> : (Optional) costs that are used with Levenshtein algorithm, default is : 1 1 1." << std::endl;
		}

		delete argument;
	}

	if (!validHelp && validSequences && validMethod) {
			tools::MatchingExecutor* executor = 0;
			if (userDirectory && userParameters) {
				executor = new tools::MatchingExecutor(fileTarget, filereference, methods.at(methodName), parameters, directoryPath);
			}
			else if (userParameters) {
				executor = new tools::MatchingExecutor(fileTarget, filereference, methods.at(methodName), parameters);
			}
			else if (userDirectory) {
				executor = new tools::MatchingExecutor(fileTarget, filereference, methods.at(methodName), directoryPath);
			}
			else {
				executor = new tools::MatchingExecutor(fileTarget, filereference, methods.at(methodName));
			}
			// Sets the parser
			if (parserName.compare("") != 0) {
				if (parserName.compare(_csv) == 0) {////////////////////////////////Conditions if else if else ajouté car fuite lorsque -parser est dans la commande
					inout::CSVParser * parser = new inout::CSVParser();
					executor->setParser(parser);
				}
				else if (parserName.compare(_ext) == 0) {
					inout::EXTParser * parser = new inout::EXTParser();
					executor->setParser(parser);
				}
				else if (parserName.compare(_xml) == 0) {
					inout::XMLParser * parser = new inout::XMLParser();
					executor->setParser(parser);
				}
				//executor->setParser(parsers[parserName]);//Retiré car l'objet inout::SequenceParser était directement envoyé sans être copié ce qui provoquait un crash lors de la libération mémoire plus tard
			}

			if (typeName.compare(_type1) == 0) {
				executor->setType(inout::SEQUENCE_TYPE::CHARACTER);
			}
			else if (typeName.compare(_type2) == 0) {
				executor->setType(inout::SEQUENCE_TYPE::NUMERIC);
			}
			else if (typeName.compare(_type3) == 0) {
				executor->setType(inout::SEQUENCE_TYPE::VECTOR);
			}

			executor->execute();
			delete executor;	//libération ajouté
	}
}

CommandLineApplication::~CommandLineApplication() {	//Destructeur ajouté=>libère les maps methods et parsers
	map<std::string, tools::Correspondence*>::iterator it;
	for (it = methods.begin(); it != methods.end(); ++it)
	{
		delete it->second;
	}
	methods.clear();

	map<std::string, inout::SequenceParser*>::iterator it2;
	for (it2 = parsers.begin(); it2 != parsers.end(); ++it2)
	{
		delete it2->second;
	}
	parsers.clear();
}


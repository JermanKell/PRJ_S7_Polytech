#include "MatchingExecutor.h"

using namespace tools;

MatchingExecutor::MatchingExecutor(std::string tf, std::string rf, Correspondence* m)
{
	referenceFile = rf;
	targetFile = tf;
	method = m;
	parameters = 0;
	parser = 0;
	directory = "";
	type = inout::SEQUENCE_TYPE::VECTOR;
}

MatchingExecutor::MatchingExecutor(std::string tf, std::string rf, Correspondence* m, Parameters *p)
{
	referenceFile = rf;
	targetFile = tf;
	method = m;
	parameters = p;
	parser = 0;
	directory = "";
	type = inout::SEQUENCE_TYPE::VECTOR;
}

MatchingExecutor::MatchingExecutor(std::string tf, std::string rf, Correspondence* m, std::string dir)
{
	referenceFile = rf;
	targetFile = tf;
	method = m;
	parameters = 0;
	parser = 0;
	directory = dir;
	type = inout::SEQUENCE_TYPE::VECTOR;
}

MatchingExecutor::MatchingExecutor(std::string tf, std::string rf, Correspondence* m, Parameters *p, std::string dir)
{
	referenceFile = rf;
	targetFile = tf;
	method = m;
	parameters = p;
	parser = 0;
	directory = dir;
	type = inout::SEQUENCE_TYPE::VECTOR;
}

std::vector<model::Sequence*>* MatchingExecutor::readFile(std::string file)
{
	std::vector<model::Sequence*>* sequences;

	// Default parser : CSVParser
	if (parser == 0) {
		parser = new inout::CSVParser();	
	}

	// Sets the default type of parsing
	parser->setType(type);
	if (parameters != 0) {
		if (parameters->getCharacteristicVectorSize() <= 0) {
			parser->setType(inout::SEQUENCE_TYPE::CHARACTER);
		}
		else if (parameters->getCharacteristicVectorSize() == 1) {
			parser->setType(inout::SEQUENCE_TYPE::NUMERIC);
		}
		else {
			parser->setType(inout::SEQUENCE_TYPE::VECTOR);
		}
	}

	// Parses the file
	sequences = (std::vector<model::Sequence*>*) parser->readFile((void*)file.c_str());
	return sequences;
}

std::vector<std::string> MatchingExecutor::match(std::vector<model::Sequence*>* target, std::vector<model::Sequence*>* ref)
{
	// Gets the sizes of sequences
	size_t firstSequenceSize = ref->size();
	size_t secondSequenceSize = target->size();

	int iBoucle = 0;
	int iBoucle2 = 0;
	std::vector<std::string> tabS;
	std::string str;

	if (parameters != 0) {
		method->setParameters(parameters);
	}

	int numProcess = omp_get_num_procs();
	// matching all the sequences
	for (iBoucle = 0; iBoucle < (int) firstSequenceSize; iBoucle++) {
		str = "";
		#pragma omp parallel for ordered schedule(dynamic) num_threads(numProcess)
		for (iBoucle2 = 0; iBoucle2 < (int) secondSequenceSize; iBoucle2++) {

			vector<tools::ResultCorrespondence>* result;
			std::string resultInFormat("");
			if (method != NULL) {
				// Matches between the two sequences
				result = method->match(target->at(iBoucle2), ref->at(iBoucle));

				// Format the results
				resultInFormat = method->format(target->at(iBoucle2), ref->at(iBoucle), result);
			}

			#pragma omp ordered
			str += resultInFormat;
		}
		tabS.push_back(str);
	}
	return tabS;
}

void MatchingExecutor::writeOutput(std::string& directoryPath, std::vector<std::string> res) {
	// Create the directory and result file
	if (directory.compare("") == 0) {
		// The output will be stored in the same folder of the target file
		directory = targetFile;
		std::string file2 = referenceFile;

		unsigned found = directory.find_last_of("/\\");
		std::string fileTname = directory.substr(found + 1);
		directory = directory.substr(0, found);

		found = fileTname.find_last_of(".");
		fileTname = fileTname.substr(0, found);

		found = file2.find_last_of("/\\");
		std::string fileRname = file2.substr(found + 1);

		found = fileRname.find_last_of(".");
		fileRname = fileRname.substr(0, found);

		parser->getType();

		#if defined _WIN32 || defined _WIN64
			directory += "\\resultat" + fileRname + "_" + fileTname + "\\";
		#elif defined __linux__
			directory +=
				"/resultat" + fileRname + "_" + fileTname + "/";
		#endif
	}

	// Creates a directory
	#if defined _WIN32 || defined _WIN64
		if (directory.at(directory.size() - 1) != '\\')
			directory += "\\";
		_mkdir(directory.c_str());
	#elif defined __linux__
		if (directory.at(directoryPath.size() - 1) != '/')
			directory += "/";
		mkdir(directory.c_str(), 0777);
	#endif

	// writes the result in a file
	for (size_t iBoucle = 0; iBoucle < res.size(); iBoucle++) {
		std::string result = directoryPath + std::to_string(iBoucle + 1) + ".txt";
		std::ofstream outfile(result);
		outfile << res.at(iBoucle) << std::endl;
		outfile.close();
	}
}

std::string MatchingExecutor::execute()
{
	std::vector<model::Sequence*>* referenceSequences, *targetSequences;

	// Reads the second file
	targetSequences = readFile(targetFile);

	// Reads the first file
	referenceSequences = readFile(referenceFile);

	//Matching betweend the sequences
	std::vector<std::string> tabS = match(targetSequences, referenceSequences);

	//Writing the output
	writeOutput(directory, tabS);

	return directory;
}
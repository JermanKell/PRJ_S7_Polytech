#include "MatchingExecutor.h"


using namespace tools;

MatchingExecutor::MatchingExecutor(std::string rf, std::string tf, Correspondence* m)
{
	referenceFile = rf;
	targetFile = tf;
	method = m;
	parameters = 0;
	directory = "";
}

MatchingExecutor::MatchingExecutor(std::string rf, std::string tf, Correspondence* m, Parameters *p)
{
	referenceFile = rf;
	targetFile = tf;
	method = m;
	parameters = p;
	directory = "";
}

MatchingExecutor::MatchingExecutor(std::string rf, std::string tf, Correspondence* m, std::string dir)
{
	referenceFile = rf;
	targetFile = tf;
	method = m;
	parameters = 0;
	directory = dir;
}

MatchingExecutor::MatchingExecutor(std::string rf, std::string tf, Correspondence* m, Parameters *p, std::string dir)
{
	referenceFile = rf;
	targetFile = tf;
	method = m;
	parameters = p;
	directory = dir;
}

std::vector<model::Sequence*>* MatchingExecutor::readFile(std::string file)
{
	inout::SequenceParser* parser = 0;
	void* fileXML;
	// Reads the file and converts it to an XML file
	parser = new inout::CSVParser();
	if (parameters != 0)
	parser->vecteur = parameters->getCharacteristicVectorSize();
	fileXML = parser->readFile((void*)file.c_str());
	// parse the xml file to sequences
	parser = new inout::XMLParser();
	return (std::vector<model::Sequence*>*)parser->readFile(fileXML);
}

std::vector<std::string> MatchingExecutor::match(std::vector<model::Sequence*>* ref, std::vector<model::Sequence*>* target)
{
	// Gets the sizes of sequences
	size_t firstSequenceSize = ref->size();
	size_t secondSequenceSize = target->size();

	size_t iBoucle = 0;
	size_t iBoucle2 = 0;
	std::vector<std::string> tabS;
	std::string str;

	// matching all the sequences
	for (iBoucle = 0; iBoucle < firstSequenceSize; iBoucle++) {
		str = "";
		#pragma omp parallel for ordered schedule(dynamic) num_threads(numProcess)
		for (iBoucle2 = 0; iBoucle2 < secondSequenceSize; iBoucle2++) {

			if (parameters != 0) {
				method->setParameters(parameters);
			}

			vector<tools::ResultatCorrespondence>* result;
			std::string resultInFormat("");
			if (method != NULL) {
				result = method->match(target->at(iBoucle2), ref->at(iBoucle));
				resultInFormat = method->format(target->at(iBoucle2), ref->at(iBoucle), result);
			}

			#pragma omp ordered
			str += resultInFormat;

			delete method;
		}
		tabS.push_back(str);
	}
	return tabS;
}

void MatchingExecutor::writeOutput(std::string directoryPath, std::vector<std::string> res) {
	// write the result in the file
	for (size_t iBoucle = 0; iBoucle < res.size(); iBoucle++) {
		std::string result = directoryPath + std::to_string(iBoucle + 1) + ".txt";
		std::ofstream outfile(result);
		outfile << res.at(iBoucle) << std::endl;
		outfile.close();
	}
}

void MatchingExecutor::execute()
{
	std::vector<model::Sequence*>* firstSequences, *secondSequences;
	#pragma omp parallel sections num_threads(numProcess)
	{
		#pragma omp section
		{
			// Reads the first file
			firstSequences = readFile(referenceFile);
		}

		#pragma omp section
		{
			secondSequences = readFile(targetFile);
		}
	}

	std::vector<std::string> tabS = match(firstSequences, secondSequences);

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

		#if defined _WIN32 || defined _WIN64
			directory += "\\resultat" + fileRname + "_" + fileTname +  "\\";
		#elif defined __linux__
			directory +=
				"/resultat" + fileRname + "_" + fileTname + "/";
		#endif
	}

		#if defined _WIN32 || defined _WIN64
			if (directory.at(directory.size() - 1) != '\\')
				directory += "\\";
			_mkdir(directory.c_str());
		#elif defined __linux__
			if (directory.at(directoryPath.size() - 1) != '/')
				directory += "/";
			mkdir(directory.c_str(), 0777);
		#endif

		//Writing the output
		writeOutput(directory, tabS);
}
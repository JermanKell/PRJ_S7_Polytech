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
	type = inout::VECTOR;
}

MatchingExecutor::MatchingExecutor(std::string tf, std::string rf, Correspondence* m, Parameters *p)
{
	referenceFile = rf;
	targetFile = tf;
	method = m;
	parameters = p;
	parser = 0;
	directory = "";
	type = inout::VECTOR;
}

MatchingExecutor::MatchingExecutor(std::string tf, std::string rf, Correspondence* m, std::string dir)
{
	referenceFile = rf;
	targetFile = tf;
	method = m;
	parameters = 0;
	parser = 0;
	directory = dir;
	type = inout::VECTOR;
}

MatchingExecutor::MatchingExecutor(std::string tf, std::string rf, Correspondence* m, Parameters *p, std::string dir)
{
	referenceFile = rf;
	targetFile = tf;
	method = m;
	parameters = p;
	parser = 0;
	directory = dir;
	type = inout::VECTOR;
}

std::vector<model::Sequence*>* MatchingExecutor::readFile(std::string file)
{
	std::vector<model::Sequence*>* sequences;

	// Default parser : CSVParser //déplacé dans CommandLineApplication
	/*if (parser == 0) {
		parser = new inout::CSVParser();	
	}*/

	// Sets the default type of parsing => déplacé au début de la méthode execute
	//parser->setType(type);

	/*if (parameters != 0) {					//=> Retiré car il semble y avoir une erreur. CharacterisiticVectorSize n'a pas de rapport avec le type
		if (parameters->getCharacteristicVectorSize() <= 0) {	//Ce lot de condition se déclanche que si on utilse un fichier param et changeait le type alors qu'il est déja défini
			parser->setType(inout::SEQUENCE_TYPE::CHARACTER);
		}
		else if (parameters->getCharacteristicVectorSize() == 1) {
			parser->setType(inout::SEQUENCE_TYPE::NUMERIC);
		}
		else {
			parser->setType(inout::SEQUENCE_TYPE::VECTOR);
		}
	}*/

	// Parses the file
	/////////////////////////////		CONDITION IF ELSE AJOUTE. CORRIGE LE BUG EMPÊCHANT D'UTILISER LE TYPE XML 
	//  INITIALLEMENT LIGNE sequences = (std::vector<model::Sequence*>*) parser->readFile((void*)file.c_str()); UNIQUEMENT JUSTE AVANT return sequences
	if (typeid(*parser) == typeid(inout::XMLParser)) {
		rapidxml::file<> xmlFile(file.c_str());
		rapidxml::xml_document<> doc;
		doc.parse<0>(xmlFile.data());
		sequences = (std::vector<model::Sequence *>*) parser->readFile(&doc);
	}
	else {
		sequences = (std::vector<model::Sequence*>*) parser->readFile((void*)file.c_str());
	}
	
	return sequences;
	///////////////////////////////////////////A RETIRER, SERT DE TEST POUR LOCALISER LES FUITES
	/*for (unsigned int uiCount = sequences->size() - 1; uiCount <= 0; uiCount--) {
		delete sequences->at(uiCount);
	}
	delete sequences;
	std::vector<model::Sequence*> * sequences_a_retirer = new std::vector<model::Sequence*>;
	return sequences_a_retirer;
	/////////////////////////////////////FIN A RETIRER//////////////////////////////*/
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

				for (unsigned int uiBoucle = 0; uiBoucle < result->size(); uiBoucle++) {//Ajouté
					delete result->at(uiBoucle).correspondanceT1;
					delete result->at(uiBoucle).correspondanceT2;
				}
				delete result;//Ajouté
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

		string method_name = "";	//ajouté pour spécifier la méthode dans le nom de dossier créé
		if (typeid(*method) == typeid(support::LevenstheinCorrespondence)) {
			method_name = "lvn";
		}
		else if (typeid(*method) == typeid(support::DTWCorrespondence)) {
			method_name = "dtw";
		}
		else if (typeid(*method) == typeid(support::FSMCorrespondence)) {
			method_name = "fsm";
		}
		else if (typeid(*method) == typeid(support::MVMCorrespondence)) {
			method_name = "mvm";
		}
		else if (typeid(*method) == typeid(support::LCSCorrespondence)) {
			method_name = "lcs";
		}
		else if (typeid(*method) == typeid(support::ESCCorrespondence)) {
			method_name = "esc";
		}
		else if (typeid(*method) == typeid(support::CDPCorrespondence)) {
			method_name = "cdp";
		}

		string type_name = "";	//Ajouté pour spécifier le type dans le nom de dossier créé
		if (type == inout::CHARACTER) {
			type_name = "char";
		}
		else if (type == inout::NUMERIC) {
			type_name = "num";
		}
		else if (type == inout::VECTOR) {
			type_name = "vec";
		}

		string parser_name = "";	//ajouté pour spécifier le format dans le nom de dossier créé
		if (typeid(*parser) == typeid(inout::CSVParser)) {
			parser_name = "csv";
		}
		else if (typeid(*parser) == typeid(inout::XMLParser)) {
			parser_name = "xml";
		}
		else if (typeid(*parser) == typeid(inout::EXTParser)) {
			parser_name = "ext";
		}

		#if defined _WIN32 || defined _WIN64
			directory += (string)"\\resultat" + "_" + fileRname + "_" + fileTname + "_" + method_name + "_" + type_name + "_" + parser_name + "\\";
		#elif defined __linux__
			directory += (string)"/resultat" + "_" + fileRname + "_" + fileTname + "_" + method_name + "_" + type_name + "_" + parser_name + "/";
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
	std::vector<model::Sequence*>* referenceSequences, *targetSequences = 0;

	//Set the parser (default = vector) //déplacé depuis readFile
	parser->setType(type);

	// Reads the second file
	targetSequences = readFile(targetFile);

	// Reads the first file
	referenceSequences = readFile(referenceFile);

	//Matching betweend the sequences
	std::vector<std::string> tabS = match(targetSequences, referenceSequences);
	//Writing the output
	writeOutput(directory, tabS);

	for (unsigned int uiCount = 0; uiCount < targetSequences->size(); uiCount++) {//Ajouté->libère les pointeurs sequences du vecteur
		delete targetSequences->at(uiCount);
	}
	for (unsigned int uiCount = 0; uiCount <  referenceSequences->size(); uiCount++) {//Ajouté->libère les pointeurs sequences du vecteur
		delete referenceSequences->at(uiCount);
	}
	delete targetSequences;		//Ajouté
	delete referenceSequences;	//Ajouté

	return directory;
}
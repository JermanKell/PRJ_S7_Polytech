#pragma once

#include <string>
#include <omp.h>

#include "Correspondence.h"
#include "Parameters.h"
#include "InOut.h"

// Libraries to manipulate directories
#if defined __linux__ || TARGET_OS_MAC
#include <sys/stat.h>
#else
#include <direct.h>// direct.h is not part of gcc so it cannot be found in linux
#endif

namespace tools {
	class MatchingExecutor {
	private:
		std::string referenceFile;
		
		std::string targetFile;

		Correspondence* method;

		Parameters* parameters;

		std::string directory;

		std::vector<model::Sequence*>* readFile(std::string file);

		std::vector<std::string> match(std::vector<model::Sequence*>* ref, std::vector<model::Sequence*>* target);

		void writeOutput(std::string directoryPath, std::vector<std::string> res);
	public:
		MatchingExecutor(std::string rf, std::string tf, Correspondence* m);
		
		MatchingExecutor(std::string rf, std::string tf, Correspondence* m, Parameters *p);

		MatchingExecutor(std::string rf, std::string tf, Correspondence* m, std::string dir);

		MatchingExecutor(std::string rf, std::string tf, Correspondence* m, Parameters *p, std::string dir);

		void execute();
	};
}
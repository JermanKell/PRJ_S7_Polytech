#pragma once
/*!
\author EL MOUTARAJI Mohammed
BOUTBIB Houda
\date 24/12/2016
\package CorrespondenceTools
\class MatchingExecutor
\brief This class is used to match between the sequences of 2 files using a provided algorithm.
*/

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
		/* reference file */
		std::string referenceFile;
		
		/* target file */
		std::string targetFile;

		/* The matching method which will be used to match between sequences */
		Correspondence* method;

		/* parameters of the matching method */
		Parameters* parameters;

		/* directory path where to store the output */
		std::string directory;

		/* type of the sequences in the files */
		inout::SEQUENCE_TYPE type;

		/* parser used to parse the files */
		inout::SequenceParser *parser;

	public:
		/*! 
		* \brief Constructor
		* \param rf reference file
		* \param tf target file
		* \param m matching method
		*/
		MatchingExecutor(std::string tf, std::string rf, Correspondence* m);
		
		/*!
		* \brief Constructor
		* \param rf reference file
		* \param tf target file
		* \param m matching method
		* \param p parameters
		*/
		MatchingExecutor(std::string tf, std::string rf, Correspondence* m, Parameters *p);

		/*!
		* \brief Constructor
		* \param rf reference file
		* \param tf target file
		* \param m matching method
		* \param dir directory path
		*/
		MatchingExecutor(std::string tf, std::string rf, Correspondence* m, std::string dir);

		/*!
		* \brief Constructor
		* \param rf reference file
		* \param tf target file
		* \param m matching method
		* \param p parameters
		* \param dir directory path
		*/
		MatchingExecutor(std::string tf, std::string rf, Correspondence* m, Parameters *p, std::string dir);

		/*!
		* \brief Sets reference file
		* \return reference file
		*/
		void setReferenceFile(std::string ref) {
			referenceFile = ref;
		}

		/*!
		* \brief Gets reference file
		* \return reference file
		*/
		std::string getReferenceFile() {
			return referenceFile;
		}

		/*!
		* \brief Sets target file
		* \param target file
		*/
		void setTargetFile(std::string tar) {
			targetFile = tar;
		}

		/*!
		* \brief Gets target file
		* \return target file
		*/
		std::string getTargetFile() {
			return targetFile;
		}

		/*!
		* \brief Sets matching method
		* \param method
		*/
		void setMethod(Correspondence* cor) {
			method = cor;
		}

		/*!
		* \brief Gets matching method
		* \return method
		*/
		Correspondence* getMethod() {
			return method;
		}

		/*!
		* \brief Sets parameters
		* \param parameters
		*/
		void setParameters(Parameters* par) {
			parameters = par;
		}

		/*!
		* \brief Gets parameters
		* \return parameters
		*/
		Parameters* getParameters() {
			return parameters;
		}

		/*!
		* \brief Sets directory where results are stored
		* \param directory path
		*/
		void setResultDirectory(std::string dir) {
			directory = dir;
		}

		/*!
		* \brief Gets directory where results are stored
		* \return directory path
		*/
		std::string getResultDirectory() {
			return directory;
		}

		/*!
		* \brief Sets the type of the sequence in the files
		* \param type
		*/
		void setType(inout::SEQUENCE_TYPE t) {
			type = t;
		}

		/*!
		* \brief Gets the type of the sequence in the files
		* \return type
		*/
		inout::SEQUENCE_TYPE getType() {
			return type;
		}

		/*!
		* \brief Sets parser used to parse the files
		* \param parser
		*/
		void setParser(inout::SequenceParser* p) {
			parser = p;
		}

		/*!
		* \brief Gets parser used to parse the files
		* \return parser
		*/
		inout::SequenceParser* getParser() {
			return parser;
		}

		/*! \brief readFile
		* Reads a CSV file that contains sequences
		* \param file filename
		* \return vector of the sequences
		*/
		std::vector<model::Sequence*>* readFile(std::string file);

		/*! \brief match
		* Matches between 2 vectors of sequences 
		* \param ref sequences of the reference file
		* \param ref sequences of the target file
		* \return results of the matching
		*/
		std::vector<std::string> match(std::vector<model::Sequence*>* target, std::vector<model::Sequence*>* ref);

		/*! \brief writeOutput
		* Writes the results of matching into files
		* \param path directory path
		* \param res results
		*/
		void writeOutput(std::string& path, std::vector<std::string> res);

		/*! \brief execute
		* Executes matching between sequences of the two given files, and stores the results.
		* \return path where the results were stored.
		*/
		std::string execute();
	};
}
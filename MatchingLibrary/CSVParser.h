#pragma once
/*!
* \author Meunier Bastien
* \date 15/12/2014
* \package inout
* \class CSVParser
* \implements SequenceParser
* \brief Read the file which contain sequences in CSV Format.
*/
#ifndef CSVPARSER_H
#define CSVPARSER_H

#include "sequenceparser.h"
#include <string>

namespace inout {
	using namespace std;
	class CSVParser : public SequenceParser {
	public:

		/**
		\brief Constructor
		*/
		CSVParser() : SequenceParser() {}

		/**
		\brief Constructor
		\param type type of the sequence
		*/
		CSVParser(SEQUENCE_TYPE t) : SequenceParser(t) {}
		virtual ~CSVParser() {}

		/*!
		*\brief readFile
		* Read a file, parse it in a RapidXML object
		*\param doc : file name
		*\return the object
		*/
		void* readFile(void* doc);
	};
}
#endif  // CSVPARSER_H

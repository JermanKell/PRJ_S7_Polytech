#pragma once
/*!
* \author Meunier Bastien
* \date 15/12/2014
* \package inout
* \class EXTParser
* \implements SequenceParser
* \brief Read the file which contain sequences
*/
#ifndef CSVPARSER_H
#define CSVPARSER_H

#include "sequenceparser.h"
#include <string>

namespace inout {
	using namespace std;
	class CSVParser : public SequenceParser {
	public:
		CSVParser() : SequenceParser() {}
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

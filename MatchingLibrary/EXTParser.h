#pragma once
/*!
* \author Meunier Bastien
Mohammed EL MOUTARAJI
* \date 15/12/2014
03/01/2017
* \package inout
* \class EXTParser
* \implements SequenceParser
* \brief Read the file which contain sequences
*/
#ifndef EXTPARSER_H
#define EXTPARSER_H

#include "SequenceParser.h"

#include <string>

namespace inout {
	using namespace std;
	class EXTParser : public SequenceParser {
	public:
		/**
		* \brief Constructor
		*/
		EXTParser() : SequenceParser() {}

		/**
		* \brief Constructor
		* \param type type of the sequence int the file
		*/
		EXTParser(SEQUENCE_TYPE t) : SequenceParser(t) {}

		/**
		* \brief Deconstructor
		*/
		virtual ~EXTParser() {}

		/*!
		*\brief readFile
		* Read a file, parse it in a RapidXML object
		*\param doc : file name
		*\return the object
		*/
		void* readFile(void* doc);
	};
}
#endif  // EXTPARSER_H
#pragma once
/*!
\author Abdourahman Aden Hassan
Bastien Meunier
\date 24/12/2013
20/01/2015
\package inout
\class SequenceParser abstract
\brief Class to read and parse a file
*/
#ifndef SEQUENCEPARSER_H
#define SEQUENCEPARSER_H

#include "SequenceMatchingException.h"

#include <iostream>
#include <algorithm>
#include <sstream>

#include "regex.h"
#include "rapidxml-1.13/rapidxml_print.hpp"
#include "rapidxml-1.13/rapidxml_utils.hpp"

#define CASSEP 0
#define CASINT 1
#define CASVAL 2

#ifdef __linux__
#include <uuid/uuid.h>
#endif  // defined


namespace inout {
	
	enum SEQUENCE_TYPE {
			CHARACTER, NUMERIC, VECTOR
	};

	class SequenceParser {

		

	protected:
		/*!
		\brief allocations of strings to be freed when the parsing ends
		*/
		std::vector<char *> listPoubelle;

		/*!
		* if the element of the sequences must be read a vector
		*/
		SEQUENCE_TYPE type;

	public:
		/*!
		\brief Constructor
		*/
		SequenceParser();

		/*!
		\brief Constructor
		*/
		SequenceParser(SEQUENCE_TYPE t) { type = t; }

		/*!
		\bried Deconstructor
		*/
		virtual ~SequenceParser();

		/*!
		* \brief readFile
		read or parse a document in a object instance
		* \param document
		* \return the instance of an object
		*/
		virtual void *readFile(void *document) = 0;

		SEQUENCE_TYPE getType() { return type; }

		void setType(SEQUENCE_TYPE t) { type = t; }
	};
}
#endif  // SEQUENCEPARSER_H

#pragma once
/*!
* \author Abdourahman Aden Hassan
Bastien Meunier
* \date 21/12/2013
20/01/2015
* \package inout
* \class ParamParser
* \implements SequenceParser
* \brief Read the parameter file
*/
#ifndef PARAMPARSER_H
#define PARAMPARSER_H

#include "SequenceParser.h"
#include "Model.h"
#include "CorrespondenceTools.h"
#include "SequenceMatchingException.h"

#include <typeinfo>
#include "rapidxml-1.13/rapidxml_utils.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"

namespace inout {
	class ParamParser : public SequenceParser
	{
	public:
		ParamParser() : SequenceParser() {}
		virtual ~ParamParser() {}

		/*!
		* \brief readFile
		* Read an XML parameter file, parse it in Paramatrage object
		* \param doc : file name
		* \return the object
		*/
		virtual void * readFile(void * document);

		/*!
		* \brief createPattern
		* \param list1 vector of sequences 1
		* \param list2 vector of sequences 2
		* \param filename the file to write the pattern in
		*/
		//void createPattern(std::vector<model::Sequence *> * list1, std::vector<model::Sequence *> * list2, char * filename);
	};
}
#endif // PARAMPARSER_H

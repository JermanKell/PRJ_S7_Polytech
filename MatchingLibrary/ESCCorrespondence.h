#pragma once
/*!
\author Bastien Meunier
\date 03/03/2015
\package calc
\class ESCCorrespondence
\extends Correspondence
\brief Class for matchnig with Exemplary Sequence Cardinality algorithm
*/
#ifndef ESCCORRESPONDANCE_H
#define ESCCORRESPONDANCE_H

#include "Correspondence.h"

#include <climits>
#include <cstdlib>

#define IS_CHAR 0
#define IS_NUM 1
#define IS_CV 2

namespace support {
	using namespace tools;
	class ESCCorrespondence : public Correspondence
	{

	protected:
		float calcTab(float ** tabDifference, int it1, int it2);


	public:
		/**
		* \brief Constructor
		*/
		ESCCorrespondence() : Correspondence() {};

		/**
		* \brief Constructor
		* \param Parameters
		*/
		ESCCorrespondence(Parameters * param) : Correspondence(param) {};

		/**
		* \brief Deconstructor
		*/
		virtual ~ESCCorrespondence() {};

		/**
		* \brief match
		* find the matching between two sequences
		*/
		vector<ResultCorrespondence> *match(model::Sequence * starget, model::Sequence * sRef);
	};
}
#endif

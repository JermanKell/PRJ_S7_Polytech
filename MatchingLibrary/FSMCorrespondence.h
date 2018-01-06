#pragma once
/*!
\author Bastien Meunier
\date 03/03/2015
\package calc
\class FSMCorrespondance
\extends Correspondance
\brief Class for matchnig with Flexible Sequences Matching algorithm
*/
#ifndef FSMCORRESPONDANCE_H
#define FSMCORRESPONDANCE_H

#include "Correspondence.h"

#include <climits>
#include <cstdlib>

#define IS_CHAR 0
#define IS_NUM 1
#define IS_CV 2

namespace support {

	using namespace std;
	using namespace tools;

	class FSMCorrespondence : public Correspondence
	{

	protected:

		float calcTab(float ** tabDifference, int it1, int it2) {
			return Correspondence::calcTab(tabDifference, it1, it2);
		};


	public:
		/**
		\brief Constructor
		*/
		FSMCorrespondence() : Correspondence() {};

		/**
		\brief Constructor
		\param Parameters of the algorithm
		*/
		FSMCorrespondence(Parameters * param) : Correspondence(param) {};

		/**
		\brief Deconstructor
		*/
		virtual ~FSMCorrespondence() {};

		/**
		* \brief match
		* find the matching between two sequences
		*/
		vector<ResultCorrespondence> *match(model::Sequence * starget, model::Sequence * sRef);
	};
}
#endif

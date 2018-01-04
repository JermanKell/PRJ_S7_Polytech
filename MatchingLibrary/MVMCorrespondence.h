#pragma once
/*!
\author Abdourahman Aden Hassan
\date 30/12/2013
\package calc
\class MVMCorrespondence
\extends Correspondence
\brief Class for matchnig with Minimum Variance Matching algorithm
*/
#ifndef MVMCORRESPONDANCE_H
#define MVMCORRESPONDANCE_H

#include "Correspondence.h"
#include "SequenceMatchingException.h"

#include <typeinfo>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <cstdlib>

#define IS_CHAR 0
#define IS_NUM 1
#define IS_CV 2

namespace support {

	using namespace tools;
	using namespace std;

	class MVMCorrespondence : public Correspondence
	{
	//private: //existe déja dans la classe mère =>supprimé
		//int isExternParametrage;
	public:
		/*!
		* \brief Constructor
		*/
		MVMCorrespondence() : Correspondence() {};

		/*!
		* \brief Constructor
		* \param Parameters
		*/
		MVMCorrespondence(Parameters * param) : Correspondence(param) {};

		/*!
		* \brief Deconstructor
		*/
		virtual ~MVMCorrespondence() {};

		/**
		* \brief match
		* find the matching between two sequences
		*/
		vector<ResultCorrespondence> *match(model::Sequence * s1, model::Sequence * s2);

	protected:
		float calcTab(float ** tabDifference, int it1, int it2);
	};
}
#endif // MVMCORRESPONDANCE_H

#pragma once
/*!
\author Abdourahman Aden Hassan
Bastien Meunier
\date 24/12/2013
08/03/2015
\package calc
\class DTWCorrespondence
\extends Correspondence
\brief Class for matchnig with Dynamic Time Warping algorithm
*/

#ifndef DTWCORRESPONDANCE_H
#define DTWCORRESPONDANCE_H

#include "Correspondence.h"

#include <math.h>
#include <cstring>
#include <cstdlib>

namespace support {

	using namespace std;
	using namespace tools;
	class DTWCorrespondence : public Correspondence
	{

	public:

		/**
		\brief Constructor
		*/
		DTWCorrespondence() : Correspondence() {};
		DTWCorrespondence(Parameters * param) : Correspondence(param) {};
		virtual ~DTWCorrespondence() {};

		/**
		* \brief match
		* find the matching between two sequences
		*/
		vector<ResultCorrespondence> *match(model::Sequence * s1, model::Sequence * s2);

	protected:
		float calcTab(float ** tabDifference, int it1, int it2) {
			return Correspondence::calcTab(tabDifference, it1, it2);
		};
	};
}
#endif // DTWCORRESPONDANCE_H

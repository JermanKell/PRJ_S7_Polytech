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

#include "correspondence.h"
#include "SequenceMatchingException.h"

#include <typeinfo>
#include <cmath>
#include <algorithm>
#include <cfloat>
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
		ESCCorrespondence() : Correspondence() {};
		ESCCorrespondence(Parameters * param) : Correspondence(param) {};
		virtual ~ESCCorrespondence() {};

		vector<ResultatCorrespondence> *match(model::Sequence * starget, model::Sequence * sRef);
	};
}
#endif
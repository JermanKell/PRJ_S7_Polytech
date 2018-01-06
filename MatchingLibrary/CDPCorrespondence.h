#pragma once
/*!
\author Bastien Meunier
\date 02/12/2014
\package Calc
\class CDPCorrespondence
\extends Correspondence
\brief Class for matching with Continuous Dynamic Programming algorithm
*/
#ifndef CDPCORRESPONDANCE_H
#define CDPCORRESPONDANCE_H

#include "Correspondence.h"

#include <algorithm>
#include <cstdlib>

#define IS_CHAR 0
#define IS_NUM 1
#define IS_CV 2

namespace support {

	using namespace tools;
	using namespace std;

	class CDPCorrespondence : public Correspondence
	{

	private:
		/*!
		* \brief min3
		*  Get the minimum from 3 float
		* \param f1 :the first number
		* \param f2 :the second number
		* \param f3 :the third number
		* \return the minimum
		*/
		//float min3(float f1, float f2, float f3);//supprimé et remplacé par std::min

	public:
		/*!
		* \brief CDPCorrespondance
		* Class constructors, inherit Correspondance
		*/
		CDPCorrespondence() : Correspondence() {};

		/*!
		* \brief CDPCorrespondance(Parameters *param)
		* Class constructors, inherit Correspondance
		*/
		CDPCorrespondence(Parameters * param) : Correspondence(param) {};

		virtual ~CDPCorrespondence() {};

		/*!
		* \brief match
		*  function for matching two sequences using CDP algorithm
		* \param sTarget the sequence target
		* \param sRef the sequence reference
		* \return res the result of the matching
		*/
		vector<ResultCorrespondence> *match(model::Sequence * sTarget, model::Sequence * sRef);
	protected:
		float calcTab(float ** tabDifference, int it1, int it2) {
			return Correspondence::calcTab(tabDifference, it1, it2);
		};
	};
}
#endif

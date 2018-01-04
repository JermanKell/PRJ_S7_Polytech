#pragma once
/*!
\author Abdourahman Aden Hassan
\date 30/12/2013
\package calc
\class LCSCorrespondence
\extends Correspondence
\brief Class for matchnig with Longest Correspondance SubSequence algorithm
*/
#ifndef LCSCORRESPONDANCE_H
#define LCSCORRESPONDANCE_H

#include "Correspondence.h"
#include "SequenceMatchingException.h"

#include <typeinfo>
#include <cstring>
#include <cstdlib>

#define DIAG 4
#define LEFT 2
#define UP 1

namespace support {

	using namespace tools;

	class LCSCorrespondence : public Correspondence {
	private:
		/*!
		* \brief tailleMaxElement
		* Harmonizes the display depending on the size of the sequences
		* \param s
		* \return
		*/
		unsigned int tailleMaxElement(model::Sequence *s);

		string getSpace(unsigned int size);
	protected:
		//int isExternParametrage; supprimé car existe déja dans la classe mère
		float calcTab(float **tabDifference, int it1, int it2) {
			return Correspondence::calcTab(tabDifference, it1, it2);
		};

	public:
		/**
		* \brief Constructor
		*/
		LCSCorrespondence() : Correspondence() {};

		/**
		* \brief Constructor
		* \param Parameters
		*/
		LCSCorrespondence(Parameters *param) : Correspondence(param) {};

		/**
		* \brief Deconstructor
		*/
		virtual ~LCSCorrespondence() {};

		/**
		* \brief match
		* find the matching between two sequences
		*/
		vector<ResultCorrespondence> *match(model::Sequence *s1, model::Sequence *s2);

		/*!
		* \brief format
		* function for formatting a result
		* \param target sequence
		* \param reference sequence
		* \param result of matching sequences
		* \return format the format of the result based on what algorithm.
		*/
		std::string format(model::Sequence *sTarget, model::Sequence *sRef, ResultCorrespondence * result);
	};
}

#endif  // LCSCORRESPONDANCE_H

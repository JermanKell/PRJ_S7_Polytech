#pragma once
/*!
\author Abdourahman Aden Hassan
\date 30/12/2013
\package calc
\class LevenstheinCorrespondence
\extends Correspondance
\brief Class for matchnig with Levenshtein algorithm
*/
#ifndef LEVENSTHEINCORRESPONDENCE_H
#define LEVENSTHEINCORRESPONDENCE_H

#include "Correspondence.h"

#include <math.h>
#include <cstdlib>

#define NOCHAR 10000
#define ADD 11000
#define DEL 12000
#define TRANS 13000
#define TRANSEQ 14000

namespace support {

	using namespace tools;

	class LevenstheinCorrespondence : public Correspondence {

	private :
		/*!
		* \brief tailleMaxElement
		* Harmonizes the display depending on the size of the sequences
		* \param s
		* \return
		*/
		unsigned int tailleMaxElement(model::Sequence *s);

		string getSpace(unsigned int size);

	protected:
		float fLCdelcost;   /** cost to delete an element*/
		float fLCaddcost;   /** cost to add an element*/
		float fLCtranscost; /** cost to switch an element*/
		//int isExternParametrage; => supprimé car existe déja dans la classe mère
		float calcTab(float **tabDifference, int it1, int it2) {
			return Correspondence::calcTab(tabDifference, it1, it2);
		};

	public:
		/**
		* \brief Constructor
		*/
		LevenstheinCorrespondence() : Correspondence() {
			fLCaddcost = 1.0;
			fLCdelcost = 1.0;
			fLCtranscost = 1.0;
		};

		/**
		* \brief Constructor
		* \param Parameters
		*/
		LevenstheinCorrespondence(Parameters *param) : Correspondence(param) {
			fLCaddcost = (float) param->getValue(param->LEVENSHTEIN_ADD_COST);
			fLCdelcost = (float) param->getValue(param->LEVENSHTEIN_DEL_COST);
			fLCtranscost = (float) param->getValue(param->LEVENSHTEIN_TRANS_COST);
		};

		/**
		* \brief Constructor
		* \param addCost cost of adding
		* \param delCost cost of deleting
		* \param transCost cost of transitioning
		*/
		LevenstheinCorrespondence(float addcost, float delcost, float transcost)
			: Correspondence() {
			fLCaddcost = addcost;
			fLCdelcost = delcost;
			fLCtranscost = transcost;
		};

		/**
		* \brief Constructor
		* \param addCost cost of adding
		* \param delCost cost of deleting
		* \param transCost cost of transitioning
		* \param Parameters
		*/
		LevenstheinCorrespondence(float delcost, float addcost, float transcost, Parameters *p)
			: Correspondence(p) {
			fLCaddcost = addcost;
			fLCdelcost = delcost;
			fLCtranscost = transcost;
			p->putValue(p->LEVENSHTEIN_ADD_COST, addcost);
			p->putValue(p->LEVENSHTEIN_DEL_COST, delcost);
			p->putValue(p->LEVENSHTEIN_TRANS_COST, transcost);
		};

		/**
		* \brief Deconstructor
		*/
		virtual ~LevenstheinCorrespondence() {};

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
#endif  // LEVENSTHEINCORRESPONDANCE_H

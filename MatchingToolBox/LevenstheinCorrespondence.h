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
#include "SequenceMatchingException.h"

#include <typeinfo>
#include <math.h>
#include <cfloat>
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
		int isExternParametrage;
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

		LevenstheinCorrespondence(Parameters *param) : Correspondence(param) {
			fLCaddcost = param->getValue(param->LEVENSHTEIN_ADD_COST);
			fLCdelcost = param->getValue(param->LEVENSHTEIN_DEL_COST);
			fLCtranscost = param->getValue(param->LEVENSHTEIN_TRANS_COST);
		};

		LevenstheinCorrespondence(float delcost, float addcost, float transcost)
			: Correspondence() {
			fLCaddcost = delcost;
			fLCdelcost = addcost;
			fLCtranscost = transcost;
		};

		LevenstheinCorrespondence(float delcost, float addcost, float transcost, Parameters *p)
			: Correspondence(p) {
			fLCaddcost = addcost;
			fLCdelcost = delcost;
			fLCtranscost = transcost;
			p->putValue(p->LEVENSHTEIN_ADD_COST, addcost);
			p->putValue(p->LEVENSHTEIN_DEL_COST, delcost);
			p->putValue(p->LEVENSHTEIN_TRANS_COST, transcost);
		};

		virtual ~LevenstheinCorrespondence() {};

		vector<ResultatCorrespondence> *match(model::Sequence *s1, model::Sequence *s2);

		std::string format(model::Sequence *sTarget, model::Sequence *sRef, ResultatCorrespondence * result);
	};
}
#endif  // LEVENSTHEINCORRESPONDANCE_H

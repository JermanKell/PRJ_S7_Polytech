#pragma once
/*!
\author Abdourahman Aden Hassan
\date 20/12/2013
\package model
\class Sequence
\brief Class to define a sequence
*/
#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "Element.h"
#include "SequenceMatchingException.h"

#include <typeinfo>
#include <vector>

namespace model {
	using namespace std;
	class Sequence {
	protected:
		/*!< a list of element*/
		vector<Element*>* vSlist;
		/*!< the sequence ID*/
		string qSid;

	public:
		/*!
		*  \brief Constructor
		*/
		Sequence();

		/*!
		*  \brief Deconstructor
		*/
		~Sequence();

		/*!
		*  \brief Constructor
		*  Copy a Sequence object
		*  \param copy : the object to copy
		*/
		Sequence(Sequence const& copy);

		/*!
		*  \brief addElement
		*  add an element to the sequence
		*  \param elt the element to add
		*/
		void addElement(Element* elt);

		/*!
		*  \brief insertdElement
		*  insert an element to the sequence
		*  \param elt the element to add
		*  \param index the index to insert
		*/
		void insertElement(Element* elt, int index);

		/*!
		*  \brief removeElement
		*  delete an element from the sequences
		*  \param index the index of the element to remove
		*  \exception if index > size of sequence
		*/
		void removeElement(unsigned int index);

		/*!
		*  \brief getElement
		*  get an element of the sequence
		*  \param index, the index of the wanted element
		*  \return the element at the given position
		*  \exception if index > size of sequence
		*/
		Element* getElement(unsigned int index);
		/*!
		* \brief getSize
		* get the size of the sequence
		* \return the size
		*/
		int getSize();

		/*!
		*  \brief getUid
		*  get the ID of the sequence
		*  \return the id
		*/

		string getUid();

		/*!
		* \brief setUid
		* set the id
		* \param q, the new id
		*/
		void setUid(string q);

		/*!
		* \brief toString
		* get the sequence in a string format
		* \return the string
		*/
		string toString();

		/*!
		* \brief copy
		* copy the current object Sequence
		* \return a the copy of the obect
		*/
		Sequence* copy();
	};
}
#endif  // SEQUENCE_H
#pragma once

/*!
* \author Abdourahman Aden Hassan
* \date 20/12/2013
* \package model
* \class Element abstract
* \brief Define an element of a sequence
*/
#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>

using namespace std;
namespace model {
	class Element {
		/*!
		* \
		*/
	protected:
		/*!< the object id*/
		string quidEid;

	public:
		Element() {}
		virtual ~Element() {}
		/*!
		*  \brief Getter
		*  \return id : the id of the object
		*/
		string getUid() { return quidEid; }

		/*!
		*  \brief Setter
		*  \param id : the new id of the object
		*/
		void setUid(string id) { quidEid = id; }

		/*!
		*\brief abstract methode : distance
		*get the distance between two element
		*\param eOD1 the first element
		*\param eOD2 the seconde element
		*\return ret the distance
		*\exception if the two element are not the same type
		*/
		virtual float distance(Element *eOD1, Element *eOD2) = 0;

		/*!
		* \brief toString
		* get the element in a string format
		* \return the string
		*/
		virtual string toString() = 0;

		/*!
		* \brief copy
		* copy the current object Character
		* \return a the copy of the obect
		*/
		virtual Element *copy() = 0;
	};
}
#endif  // ELEMENT_H
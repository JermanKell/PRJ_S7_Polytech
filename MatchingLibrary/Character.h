#pragma once
/*!
\author Abdourahman Aden Hassan
\date 20/12/2013
\package model
\class Character
\implements Element
\brief Class for element of type character
*/

#ifndef CHARACTER_H
#define CHARACTER_H

#include "Element.h"
#include <typeinfo>
#include "SequenceMatchingException.h"

namespace model {
	class Character : public Element
	{

	protected:
		/*!< The character value of an element in a sequence of type Character*/
		char cCvalue;
	public:
		/*!
		*  \brief Constructor
		*  Default constructor
		*/
		Character();

		/*!
		*  \brief Constructor
		*  Create the class with a value
		*  \param c : the character value
		*/
		Character(char c);

		/*!
		*  \brief Constructor
		*  Copy a Character object
		*  \param copy : the object to copy
		*/
		Character(Character const & copy);

		/*!
		*  \brief Getter
		*  get the value
		*  \return c : the value
		*/
		char getValue();

		/*!
		*  \brief setter
		*  set the value
		*  \param c : the value
		*/
		void setValue(char c);

		/*!
		* \brief abstract methode implementation : distance
		* get the distance between two Character
		* \param eOD1 the first element
		* \param eOD2 the seconde element
		* \return ret the distance
		* \exception if the two element are not Character
		*/
		float distance(Element *eOD1, Element *eOD2);

		/*!
		* \brief toString
		* get the Character in a string format
		* \return the string
		*/
		string toString();

		/*!
		* \brief copy
		* copy the current object Character
		* \return a the copy of the obect
		*/
		Element * copy();
	};
}
#endif // CHARACTER_H

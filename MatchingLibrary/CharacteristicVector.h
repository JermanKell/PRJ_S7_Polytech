#pragma once
/*!
\author Abdourahman Aden Hassan
\date 20/12/2013
\package model
\class CharacteristicVector
\implements Element
\brief Class for element of type vector of float
*/
#ifndef CHARACTERISTICVECTOR_H
#define CHARACTERISTICVECTOR_H

#include "Element.h"
#include "SequenceMatchingException.h"

#include <typeinfo>
#include <math.h>
#include <vector>

namespace model {

	using namespace std;

	class CharacteristicVector : public Element
	{

	protected:
		/*!< the vector of float in a element of a sequences of type Vector*/
		vector<float> * vCVlist;

	public:

		/*!
		*  \brief Constructor
		*  Default constructor
		*/
		CharacteristicVector();

		/*!
		*  \brief Constructor
		*  Copy a Character object
		*  \param copy : the object to copy
		*/
		CharacteristicVector(CharacteristicVector const & copy);

		/*!
		*  \brief Deconstructor
		*/
		~CharacteristicVector();

		/*!
		* \brief Getter
		* Get the value at the position id in the vCVlist
		* \param id : the index
		* \return the value
		*/
		float getAt(unsigned int id);

		/*!
		\brief addValue(float elt)
		Add a float to vCVlist
		\param elt the float to add
		*/
		void addValue(float elt);

		/*!
		\brief removeValue(int index)
		remove the value at position index
		\param index the position of the value to be remove
		\exception Invalid Index
		*/
		void removeValue(unsigned int index);

		/*!
		\brief Setter
		Set the value of a  float element
		\param index the position of the element
		\param value the new value
		\exception Invalide Index
		*/
		void setValue(unsigned int index, float value);

		/*!
		\brief getSize()
		\return ret the size of vCVlist
		*/
		int getSize();

		/*!
		\brief abstract method "distance"
		Get the distance between two CharacteristicVector
		\param eOD1 the first element
		\param eOD2 the second element
		\return ret la valeur de la distance de comparaison
		\exception if the two element are not CharacteristicVector
		\exception if the two CharacteristicVector have not the same size
		*/
		float distance(Element *eOD1, Element *eOD2);

		/*!
		* \brief toString
		* get the CharacteristicVector in a string format
		* \return the string
		*/
		string toString();

		/*!
		* \brief copy
		* copy the current CharacteristicVector
		* \return a copy
		*/
		Element * copy();
	};
}
#endif // CHARACTERISTICVECTOR_H

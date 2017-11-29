#pragma once
/*!
\author Mohammed ELMOUTARAJI
Houda BOUTBIB
\date 21/12/2016
\package CorrespondenceTools
\class Parameters
\brief Class for the parameters for the matching algoritm
*/

#ifndef PARAMETERS_H
#define PARAMETERS_H

#include "Model.h"
#include "SequenceMatchingException.h"

#include <vector>
#include <map>

namespace tools {
	class Parameters {
	private :
		/*!< simple parameters are stored in a key-value dictionary */
		map<std::string, float> values;

		/*!< Weight applied to the elements of the first sequence, 1 for each by default*/
		vector<float> *vPweightS1;

		/*!< Weight applied to an element of the second sequence, 1 for each by default*/
		vector<float> *vPweightS2;

		/*!< Weight applied to a value of a CaracteristicVector, 1 for each by default*/
		vector<float> *vPweightVecCarac;

		/*!< Weight applied to the distance matrix, 1 by default, 1 for each par défaut*/
		vector<vector<float> *> *vPweightMatrice;

	public :
		/*!< key of the size of the sequence 1 */
		static const std::string SIZE_FIRST_SEQUENCE;

		/*!< key of the size of the sequence 2 */
		static const std::string SIZE_SECOND_SEQUENCE;

		/*!< The size of the CaracteristicVector, -1 if not a vector*/
		static const std::string SIZE_CARACTERISTIC_VECTOR;

		/*!< Weight applied to the distance, 1 par défaut*/
		static const std::string WEIGHT_DISTANCE;

		/*!<The threshold used for the CDP __min value, -1 by default*/
		static const std::string CDP_THRESHOLD;

		/*!<THe cost for a Levenshtein mouvement, 1 by default*/
		static const std::string LEVENSHTEIN_ADD_COST;
		static const std::string LEVENSHTEIN_DEL_COST;
		static const std::string LEVENSHTEIN_TRANS_COST;

		/*!<The MVM elasticity value, 10 by default*/
		static const std::string MVM_ELASTICITY;

		/*!<The FSM elasticity value, -1 by default*/
		static const std::string FSM_ELASTICITY;

		/*!<The value of the weight of a jump in FSM, 1 by default*/
		static const std::string FSM_WEIGHT;

		/*!<The value of the small skip cost of a jump in FSM, -1 by default*/
		static const std::string FSM_SMALL_SKIP_COST;

		/*!<The value of the skip cost of a jump in FSM, -1 by default*/
		static const std::string FSM_SKIP_COST;

		/*!<The value of result wanted for the FSM, 0 by default*/
		static const std::string FSM_TYPE_RESULT;

		/*!<The number of elements taken for each line in the calcul of the skipcost
		* in the FSM, 2 by default*/
		static const std::string FSM_NUMBER_ELEMENTS_BY_LINE;

		/*!<Defined if the minimum must be search at the begining of the sequence or
		* not, 0 by default
		* 0 : Look at the beginning
		* 1 : Look at the size of the reference
		*/
		static const std::string FSM_FIRST_COL_FOR_RESULT;

		/*!<The value of default skip cost for the FSM, 0.1 by default*/
		static const std::string FSM_DEFAULT_SKIP_COST;

		/*!<The number of standart deviation taken in the calcul of the skip cost for
		* the FSM, 2 by default*/
		static const std::string FSM_STANDARD_DEVIATION_NUMBER;

		/*!
		\brief Constructor
		Create the parameter object.
		*/
		Parameters();

		/*!
		\brief Constructor
		Create the parameter object.
		\param sizeS1 the size of the first sequence
		\param sizeS2 the size of the seconde sequence
		*/
		Parameters(unsigned int sizeS1, unsigned int sizeS2);

		/*!
		\brief Constructor
		Create the parameter object.
		\param sizeS1 the size of the first sequence
		\param sizeS2 the size of the seconde sequence
		*/
		Parameters(unsigned int sizeS1, unsigned int sizeS2, unsigned int sizeCharacteresticVector);

		/*!
		\brief Deconstructor
		*/
		~Parameters();

		/*!
		\brief putValue puts a parameter
		\param key key of the parameter
		\param value the value of the parameter
		*/
		void putValue(std::string key, float value);

		/*!
		\brief getValue gets a parameter
		\param key key of the parameter
		\return value of the parameter
		\exception parameter was not found
		*/
		float getValue(std::string key);

		/*!
		\brief setS1Size
		set the size of the first sequence
		\param value the new size
		*/
		void setFirstSequenceSize(unsigned int value);

		/*!
		* \brief getS1Size
		get the size of the first sequence
		* \return the size
		*/
		int getFirstSequenceSize();

		/*!
		\brief setS2Size
		set the size of the second sequence
		\param value the new size
		*/
		void setSecondSequenceSize(unsigned int value);

		/*!
		* \brief getS2Size
		get the size of the second sequence
		* \return the size
		*/
		int getSecondSequenceSize();

		/*!
		\brief setVecCaracSize
		set the size of a vector
		\param value the new size
		*/
		void setCharacteristicVectorSize(unsigned int value);

		/*!
		* \brief getVecCaracSize
		get the size of the caracteristic vector
		* \return the size
		*/
		int getCharacteristicVectorSize();

		/*!
		\brief setFirstSequenceWeight
		set the weight for an element of the first sequence
		\param index element index
		\param valuethe new weight
		\exception if index > size of the sequences
		\exception if 0 > value or value > 1
		*/
		void setFirstSequenceWeight(unsigned int index, float value);

		/*!
		* \brief getS1Weight
		* \param index
		* \return the value of the weight for the index
		*/
		float getFirstSequenceWeight(unsigned int index);

		/*!
		\brief setSecondSequenceWeight
		set the weight for an element of the second sequence
		\param index element index
		\param valuethe new weight
		\exception if index > size of the sequences
		\exception if 0 > value or value > 1
		*/
		void setSecondSequenceWeight(unsigned int index, float value);

		/*!
		* \brief getS2Weight
		* \param index
		* \return the value of the weight for the index
		*/
		float getSecondSequenceWeight(unsigned int index);

		/*!
		\brief setS2Weight
		set the weight for an element of a carateristique vector
		\param index element index
		\param valuethe new weight
		\exception if index > iPsizeVecCarac
		\exception if 0 > value or value > 1
		\exception if iPsizeVecCarac is not defined
		*/
		void setCharacteristicVectorWeight(unsigned int index, float value);

		/*!
		* \brief getVecCarac
		* \param index
		* \return the weight of an element of a caracteristic vector
		*/
		float getCharacteristicVectorWeight(unsigned int index);

		/*!
		\brief setMatrixWeight
		set the weight of an element in the distance matrix
		\param index1 index of the element in the first sequence
		\param index2 index of the element in the second sequence
		\param value new weight value
		\exception if index > size of the sequences
		\exception if 0 > value or value > 1
		*/
		void setMatrixWeight(unsigned int index1, unsigned int index2, float value);

		/*!
		* \brief getMatrixWeight
		* \param i1 the index of th fisrt element
		* \param i2, the index of the second element
		* \return the value of the weight between the two element
		*/
		float getMatrixWeight(unsigned int i1, unsigned int i2);


	protected:

		/*!
		\brief fillParameters a function that's called in the constructor
		to fill the parameters
		*/
		void fillParameters();
	};
}

#endif // !PARAMETERS_H

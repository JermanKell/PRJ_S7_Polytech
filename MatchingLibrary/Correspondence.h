#pragma once
/*!
* \author Abdourahman Aden Hassan
*		  Bastien Meunier
* \date 21/12/2013
*		02/04/2015
* \package CorrespondenceTools
* \class Correspondance abstract
* \brief Base class for the matching algorithm
*/
#ifndef CORRESPONDENCE_H
#define CORRESPONDENCE_H

#include "Parameters.h"
#include "Model.h"
#include "SequenceMatchingException.h"

#include <vector>
#include <typeinfo>
#include <cfloat>
#include <climits>
#include <cmath>
#include <algorithm>

#define IS_CHAR 0
#define IS_NUM 1
#define IS_CV 2

using namespace std;
namespace tools {
	/*!
	* \struct ResultCorrespondence
	* \brief Data structure of a result of a matching between two sequences
	* Given 2 sequences target and reference of size n and m :
	* 2 dynamic array :
	* correspondanceT1 contain the index of target which match with reference
	* correspondanceT2 contain the index of reference which match with target
	* target[correspondanceT1[i]] is match with reference[correspondanceT2[i]]
	* the distance between the two sequence depending of the algorithm
	*/
	typedef struct {
		vector<int> *correspondanceT1;
		vector<int> *correspondanceT2;
		float distance;
	} ResultCorrespondence;

	class Correspondence {
	protected:
		/** Tell if the parameter object is extern et intern*/
		bool isParametrageExtern;

		/** object parameter*/
		Parameters *params;

		/*!
		* \brief parametrerVectors
		* check if the given sequences have the good parameter
		* \param s1 : the first sequence
		* \param s2 : the seconde sequence
		*/
		void parametrerVectors(model::Sequence *s1, model::Sequence *s2);

		/*! \brief initTabDifference
		* Create an array of the difference between the element of the sequences
		* d(i,j) = (s1[i] - s2[j])^2
		* \param s1 the first sequence
		* \param s2 the second sequence
		* \return the array of difference
		*/
		float **initTabDifference(model::Sequence *s1, model::Sequence *s2);

		/*!
		* \brief calcTab
		* calculate the difference between tho element of the sequences
		* \param tabDifference the array of difference
		* \param it1 the index of the element in the sequence1
		* \param it2 the array in the element in the sequence2
		* d[i][j] = sqrt(tabDifference[i][j]*param)
		* \return the distance equilibrate by the param weight
		*/
		virtual float calcTab(float **tabDifference, int it1, int it2);

		/*!
		* \brief freeTabDifference
		* Free an array
		* \param tabDifference
		* \param size1
		* \param size2
		* tabDifference[size1][size2]
		*/
		void freeTabDifference(float **tabDifference, int size1, int size2);

		/*!
		* \brief getIndexOfMin
		*  Get the line index(es) of the minimum(s) value(s) in the last column of a
		* matrix
		* \param path :the matrix to look for (path[1..size1][1..size2])
		* \param size1 :the number of line in the matrix
		* \param size2 :the number of column in the matrix
		*  \return an array of index(es)
		*/
		vector<int> *getIndexOfMinColumn(float **path, int size1, int size2);

		/*!
		*\brief getIndexOfRow
		* Get the row index(es) of the minimum(s) value(s) in the last line of a matrix
		*\param path :the matrix to look for (path[1..size1][1..size2])
		*\param size1 :the number of line in the matrix
		*\param size2 :the number of column in the matrix
		* \param firstCol : tell if the search must begin at the first column or not
		* \return an array of index(es)
		*/
		vector<int> *getIndexOfMinRow(float **path, int size1, int size2,
			bool firstCol);

		/**
		* \brief getElasticity
		* get the elasticity needed for the FSM from :
		* - the parametrage object
		* - |sizeR - sizeT|
		* \param sizeR, size of the reference
		* \param sizeT, size of the target
		* \return the elasticity
		*/
		int getElasticity(int sizeR, int sizeT);

		/**
		* \brief getWeight
		* get the weight needed for the FSM from :
		* - the parametrage object
		* - 1
		* \return the weight
		*/
		float getWeight();

		/**
		* \brief getSmallSkipCost
		* get the small skip cost needed for the FSM from :
		* - the parametrage object
		* - . get M[] the mean of the __min for each line of the distance value,
		the number of __min taken is a parametrage value
		. smallskipCost = mean(M) or a default value if 0
		* \param tabDiff, the array of difference betwee two sequences
		* \param sizeR, size of the reference
		* \param sizeT, size of the target
		* \return the smallSkipCost
		*/
		float getSmallSkipCost(float **tabDiff, int sizeR, int sizeT);

		/**
		* \brief getSkipCost
		* get the skip cost needed for the FSM from :
		* - the parametrage object
		* - . get M[] the mean of the __min for each line of the distance value,
		the number of __min taken is a parametrage value
		. skipCost = mean(M) + 2*std(M) or a default value if 0
		* \param tabDiff, the array of difference betwee two sequences
		* \param sizeR, size of the reference
		* \param sizeT, size of the target
		* \return the SkipCost
		*/
		float getSkipCost(float **tabDiff, unsigned int sizeR, unsigned int sizeT);

		/**
		* \brief getResultat
		* get the distance of the matching depending of the type of distance wanted.
		* - distance = (__min of last line)/(number matching node)
		* - distance = (__min of last line)/(last matching index of target - first
		* matching index of target)
		* - distance = (__min of last line)/(number of cost deplacement for matching =
		* number of node + number of jump)
		*/
		float getResultat(float minimun, ResultCorrespondence rc, int nbJump);

	public:
		/**
		\brief Constructor
		*/
		Correspondence();

		/**
		\brief Constructor
		\param parameters
		*/
		Correspondence(Parameters *param);


		/**
		\brief Deconstructor
		*/
		virtual ~Correspondence();

		/*!
		* \brief match
		* Abstract function for matching two sequences
		* \param sTarget the sequence target
		* \param sRef the sequence reference
		* \return res the result of the matching
		*/
		virtual vector<ResultCorrespondence> *match(model::Sequence *sTarget, model::Sequence *sRef) = 0;

		/*!
		* \brief format
		* Abstract function for formatting a result
		* \param target sequence
		* \param reference sequence
		* \param result of matching sequences
		* \return format the format of the result based on what algorithm.
		*/
		virtual std::string format(model::Sequence *sTarget, model::Sequence *sRef, ResultCorrespondence * result);

		/*!
		* \brief format
		* function for formatting the results
		* \param target sequence
		* \param reference sequence
		* \param result of matching sequences
		* \return format the format of the result based on what algorithm.
		*/
		std::string format(model::Sequence *sTarget, model::Sequence *sRef, vector<ResultCorrespondence> * result);

		/*!
		* \brief setParameters
		* setter for parameters
		* \param Parameters*
		*/
		void setParameters(Parameters* params);

		/*!
		* \brief getParameters
		* getter for parameters
		* \return Parameters*
		*/
		Parameters* getParameters();

	};
}
#endif  // CORRESPONDENCE_H

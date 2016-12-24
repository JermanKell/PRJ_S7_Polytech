/*!
\author Bastien Meunier
\date 20/01/2015
*/

#include "ParamParser.h"

using namespace inout;
using namespace std;

/*!
* \brief readFile
* Reads an XML parameter file, parse it into Paramatrage objects
* \param doc : file name
* \return the object
*/
void *ParamParser::readFile(void *document) {
	char *filename = (char *)document;
	// Opening the file
	rapidxml::xml_document<> docr;
	std::ifstream ifs(filename);
	if (!ifs.is_open()) {
		exc::SequenceMatchingException::genererException(
			"Parameters XML Reading error : Unable to open the file", ERREUR_FILE,
			__LINE__);
	}
	vector<char> buffer((istreambuf_iterator<char>(ifs)),
		istreambuf_iterator<char>());
	buffer.push_back('\0');
	docr.parse<0>(&buffer[0]);

	tools::Parameters *parameters = 0;

	rapidxml::xml_node<> *list_node;
	if ((list_node = docr.first_node("Lists")) == 0) {
		exc::SequenceMatchingException::genererException(
			"Parameters XML Reading error : Lists node was not found", ERREUR_FILE,
			__LINE__);
	}
	// Take the root
	rapidxml::xml_node<> *comp_node;
	comp_node = list_node->first_node("Comparaison");
	if (comp_node == 0) {
		exc::SequenceMatchingException::genererException(
			"Parameters XML Reading error : Comparaison node was not found",
			ERREUR_FILE, __LINE__);
	}
	// Création objets parametrage
	int vecsize = 0;
	int it1 = 0;
	int itvec = 0;
	// Création noeuds des attributs
	rapidxml::xml_attribute<> *id1_comp_attr =
		comp_node->first_attribute("size1");
	int size1Par = atoi(id1_comp_attr->value());
	rapidxml::xml_attribute<> *id2_comp_attr =
		comp_node->first_attribute("size2");
	int size2Par = atoi(id2_comp_attr->value());
	rapidxml::xml_attribute<> *isVector_comp_attr =
		comp_node->first_attribute("isVector");
	int isVector = atoi(isVector_comp_attr->value());

	if (isVector == 1) {
		rapidxml::xml_attribute<> *vecsize_comp_attr =
			comp_node->first_attribute("sizeVector");
		vecsize = atoi(vecsize_comp_attr->value());
		parameters = new tools::Parameters(size1Par, size2Par, (vecsize <= 0) ? 1 : vecsize);
	}
	else {
		parameters = new tools::Parameters(size1Par, size2Par);
	}

	// Weight distance
	rapidxml::xml_attribute<> *wd_comp_attr =
		comp_node->first_attribute("weightDistance");
	float weightDistanceValue = (float)atof(wd_comp_attr->value());
	parameters->putValue(parameters->WEIGHT_DISTANCE, weightDistanceValue);

	// Levenshtein Param
	rapidxml::xml_node<> *levenshtein_node =
		comp_node->first_node("LevenshteinParam");
	if (levenshtein_node != 0) {
		rapidxml::xml_attribute<> *addcost_lev_attr =
			levenshtein_node->first_attribute("addCost");
		float addCost = (float)atof(addcost_lev_attr->value());
		rapidxml::xml_attribute<> *delcost_lev_attr =
			levenshtein_node->first_attribute("delCost");
		float delCost = (float)atof(delcost_lev_attr->value());
		rapidxml::xml_attribute<> *transcost_lev_attr =
			levenshtein_node->first_attribute("transCost");
		float transCost = (float)atof(transcost_lev_attr->value());
		parameters->putValue(parameters->LEVENSHTEIN_ADD_COST, addCost);
		parameters->putValue(parameters->LEVENSHTEIN_DEL_COST, delCost);
		parameters->putValue(parameters->LEVENSHTEIN_TRANS_COST, transCost);
	}

	// CDP Param
	rapidxml::xml_node<> *cdp_node = comp_node->first_node("CdpParam");
	if (cdp_node != 0) {
		rapidxml::xml_attribute<> *threshold_cdp_attr =
			cdp_node->first_attribute("threshold");
		float threshold = (float)atof(threshold_cdp_attr->value());
		parameters->putValue(parameters->CDP_THRESHOLD, threshold);
	}

	// MVM Param
	rapidxml::xml_node<> *mvm_node = comp_node->first_node("MvmParam");
	if (mvm_node != 0) {
		rapidxml::xml_attribute<> *divelastic_mvm_attr =
			mvm_node->first_attribute("divElast");
		int elastic = (int)atoi(divelastic_mvm_attr->value());
		parameters->putValue(parameters->MVM_ELASTICITY, elastic);
	}

	// FSM Param
	rapidxml::xml_node<> *fsm_node = comp_node->first_node("FsmParam");
	if (fsm_node != 0) {
		rapidxml::xml_attribute<> *elasticity_fsm_attr =
			fsm_node->first_attribute("Elasticity");
		if (elasticity_fsm_attr != 0) {
			int elasticity = (int)atoi(elasticity_fsm_attr->value());
			parameters->putValue(parameters->FSM_ELASTICITY, elasticity);
		}
		rapidxml::xml_attribute<> *weight_fsm_attr =
			fsm_node->first_attribute("Weight");
		if (weight_fsm_attr != 0) {
			float weight = (float)atof(weight_fsm_attr->value());
			parameters->putValue(parameters->FSM_WEIGHT, weight);
		}
		rapidxml::xml_attribute<> *skipCost_fsm_attr =
			fsm_node->first_attribute("SkipCost");
		if (skipCost_fsm_attr != 0) {
			float skipCost = (float)atof(skipCost_fsm_attr->value());
			parameters->putValue(parameters->FSM_SKIP_COST, skipCost);
		}
		rapidxml::xml_attribute<> *smallSkipCost_fsm_attr =
			fsm_node->first_attribute("SmallSkipCost");
		if (smallSkipCost_fsm_attr != 0) {
			float smallSkipCost = (float)atof(smallSkipCost_fsm_attr->value());
			parameters->putValue(parameters->FSM_SMALL_SKIP_COST, smallSkipCost);
		}
		rapidxml::xml_attribute<> *typeOfResult_fsm_attr =
			fsm_node->first_attribute("TypeOfResult");
		if (typeOfResult_fsm_attr != 0) {
			int typeofResult = (int)atoi(typeOfResult_fsm_attr->value());
			parameters->putValue(parameters->FSM_TYPE_RESULT, typeofResult);
		}
		rapidxml::xml_attribute<> *nbFirstColRes_fsm_attr =
			fsm_node->first_attribute("ResultFirstColumn");
		if (nbFirstColRes_fsm_attr != 0) {
			int firstColRes = (int)atoi(nbFirstColRes_fsm_attr->value());
			parameters->putValue(parameters->FSM_FIRST_COL_FOR_RESULT, firstColRes);
		}

		rapidxml::xml_attribute<> *nbMinPerLine_fsm_attr =
			fsm_node->first_attribute("NbMinPerLine");
		if (nbMinPerLine_fsm_attr != 0) {
			int minperline = (int)atoi(nbMinPerLine_fsm_attr->value());
			parameters->putValue(parameters->FSM_NUMBER_ELEMENTS_BY_LINE, minperline);
		}

		rapidxml::xml_attribute<> *defaultSkipCost_fsm_attr =
			fsm_node->first_attribute("DefaultSkipCost");
		if (defaultSkipCost_fsm_attr != 0) {
			float defaultskipCost = (float)atof(defaultSkipCost_fsm_attr->value());
			parameters->putValue(parameters->FSM_DEFAULT_SKIP_COST, defaultskipCost);
		}

		rapidxml::xml_attribute<> *standartDeviationNumber_fsm_attr =
			fsm_node->first_attribute("StandardDeviation");
		if (standartDeviationNumber_fsm_attr != 0) {
			int standardDev = (int)atoi(standartDeviationNumber_fsm_attr->value());
			parameters->putValue(parameters->FSM_STANDARD_DEVIATION_NUMBER,
				standardDev);
		}
	}

	// Weight values
	rapidxml::xml_node<> *wv_node = comp_node->first_node("WeightNode");
	if (wv_node != 0) {
		// Créer vecteur 1
		rapidxml::xml_node<> *sw1_node;
		sw1_node = wv_node->first_node("sequenceWeight1");
		if (sw1_node == 0) {
			delete parameters;
			exc::SequenceMatchingException::genererException(
				"Param XML Reading error : Invalid file format", ERREUR_FILE,
				__LINE__);
		}
		rapidxml::xml_node<> *v1_node;
		v1_node = sw1_node->first_node("sequenceElement");
		if (v1_node == 0) {
			delete parameters;
			exc::SequenceMatchingException::genererException(
				"Param XML Reading error : Invalid file format", ERREUR_FILE,
				__LINE__);
		}
		while (it1 < size1Par) {
			rapidxml::xml_attribute<> *w1_attr = v1_node->first_attribute("value");
			float vals1 = (float)atof(w1_attr->value());
			parameters->setFirstSequenceWeight(it1, vals1);
			it1 = it1 + 1;
			v1_node->next_sibling();
		}
		// Creer vecteur 2
		rapidxml::xml_node<> *sw2_node;
		sw2_node = wv_node->first_node("sequenceWeight2");
		if (sw2_node == 0) {
			delete parameters;
			exc::SequenceMatchingException::genererException(
				"Param XML Reading error : Invalid file format", ERREUR_FILE,
				__LINE__);
		}
		rapidxml::xml_node<> *v2_node;
		v2_node = sw2_node->first_node("sequenceElement");
		if (v2_node == 0) {
			delete parameters;
			exc::SequenceMatchingException::genererException(
				"Param XML Reading error : Invalid file format", ERREUR_FILE,
				__LINE__);
		}
		it1 = 0;
		while (it1 < size2Par) {
			rapidxml::xml_attribute<> *w2_attr = v2_node->first_attribute("value");
			float vals2 = (float)atof(w2_attr->value());
			parameters->setSecondSequenceWeight(it1, vals2);
			it1 = it1 + 1;
			v2_node = v2_node->next_sibling();
		}
		// Creer vecteur carac
		if (isVector == 1) {
			rapidxml::xml_node<> *vec_w;
			vec_w = wv_node->first_node("vectorWeights");
			if (vec_w == 0) {
				delete parameters;
				exc::SequenceMatchingException::genererException(
					"Param XML Reading error : Invalid file format", ERREUR_FILE,
					__LINE__);
			}
			rapidxml::xml_node<> *vec_node;
			vec_node = vec_w->first_node("sequenceVectorElement");
			if (vec_node == 0) {
				delete parameters;
				exc::SequenceMatchingException::genererException(
					"Param XML Reading error : Invalid file format", ERREUR_FILE,
					__LINE__);
			}
			while (itvec < vecsize && vec_node != 0) {
				rapidxml::xml_attribute<> *vec_attr =
					vec_node->first_attribute("value");
				float vecv = (float)atof(vec_attr->value());
				parameters->setCharacteristicVectorWeight(itvec, vecv);
				itvec = itvec + 1;
				vec_node = vec_node->next_sibling();
			}
		}
		// Créer vecteur matrice
		int itSeq1 = 0;
		int itSeq2 = 0;
		rapidxml::xml_node<> *sm_node;
		sm_node = wv_node->first_node("sequenceMatrix");
		if (sm_node == 0) {
			delete parameters;
			exc::SequenceMatchingException::genererException(
				"Param XML Reading error : Invalid file format", ERREUR_FILE,
				__LINE__);
		}
		rapidxml::xml_node<> *mat_node;
		mat_node = sm_node->first_node("sequenceMatrixElement");
		if (mat_node == 0) {
			delete parameters;
			exc::SequenceMatchingException::genererException(
				"Param XML Reading error : Invalid file format", ERREUR_FILE,
				__LINE__);
		}
		while (itSeq1 < size1Par && mat_node != 0) {
			while (itSeq2 < size2Par && mat_node != 0) {
				// Ajout matrice element
				rapidxml::xml_attribute<> *vec_attr =
					mat_node->first_attribute("value");
				float vecm = (float)atof(vec_attr->value());
				parameters->setMatrixWeight(itSeq1, itSeq2, vecm);
				mat_node = mat_node->next_sibling();
				itSeq2 = itSeq2 + 1;
			}
			itSeq1 = itSeq1 + 1;
			itSeq2 = 0;
		}
	}

	return (void *)parameters;
}
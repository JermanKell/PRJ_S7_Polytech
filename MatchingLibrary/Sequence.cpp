/*!
\author Abdourahman Aden Hassan
\date 22/12/2013
*/

#include "Sequence.h"

using namespace model;

Sequence::Sequence() {
	vSlist = new vector<Element *>();
	qSid = "";
}

Sequence::~Sequence() {
	unsigned int it = 0;
	while (it < vSlist->size()) {
		Element *v = vSlist->at(it);
		delete v;
		it = it + 1;
	}
	delete vSlist;
}

Sequence::Sequence(const Sequence &copy) {
	qSid = copy.qSid;
	vSlist = new vector<Element *>();
	int it = 0;
	int __max = copy.vSlist->size();
	while (it < __max) {
		vSlist->insert(vSlist->begin(), copy.vSlist->at(it));
		it = it + 1;
	}
}

void Sequence::addElement(Element *elt) {
	if (vSlist->size() > 0) {
		Element* e = vSlist->at(0);
		if (typeid(*e) != typeid(*elt)) {
			exc::SequenceMatchingException::genererException(
				"Heterogen List", PARAMETRE_INVALIDE, __LINE__);
		}
	}
	vSlist->push_back(elt->copy());
}

void Sequence::insertElement(Element *elt, int index) {
	if (vSlist->size() > 0) {
		if (typeid(*vSlist->at(0)) != typeid(*elt)) {
			exc::SequenceMatchingException::genererException(
				"Heterogen List", PARAMETRE_INVALIDE, __LINE__);
		}
	}
	vSlist->insert(vSlist->begin() + index, elt->copy());
}

void Sequence::removeElement(unsigned int index) {
	if (index >= vSlist->size()) {
		exc::SequenceMatchingException::genererException(
			"Size error", PARAMETRE_INVALIDE, __LINE__);
	}
	vSlist->erase(vSlist->begin() + index);
}

Element *Sequence::getElement(unsigned int index) {
	if (index >= vSlist->size()) {
		exc::SequenceMatchingException::genererException(
			"Size error", PARAMETRE_INVALIDE, __LINE__);
	}
	return vSlist->at(index);
}

int Sequence::getSize() { return vSlist->size(); }

string Sequence::getUid() { return qSid; }

void Sequence::setUid(string q) { qSid = q; }

string Sequence::toString() {
	string s = "";
	unsigned int it = 0;
	while (it < vSlist->size()) {
		s = s + vSlist->at(it)->toString() + " ";
		it = it + 1;
	}
	return s;
}

Sequence *Sequence::copy() {
	int it = 0;
	Sequence *n = new Sequence();
	while (it < this->getSize()) {
		n->addElement(this->getElement(it)/*->copy()*/);	//modifié car fuite mémoire: Sequence::addElement(Element *elt) effectue déja une copie
		it = it + 1;
	}
	return n;
}

/*!
\author Abdourahman Aden Hassan
\date 20/12/2013
*/
#include "Character.h"

using namespace model;

Character::Character() {
	Element::quidEid = "";
	cCvalue = 0;
}

Character::Character(char c) {
	Element::quidEid = "";
	cCvalue = c;
}

char Character::getValue() { return this->cCvalue; }

void Character::setValue(char c) { this->cCvalue = c; }

Character::Character(Character const &copy) : cCvalue(copy.cCvalue) {
	this->Element::quidEid = copy.quidEid;
}

float Character::distance(Element *eOD1, Element *eOD2) {
	Character a;
	if (typeid(*eOD1) != typeid(*eOD2) || typeid(*eOD2) != typeid(a)) {
		exc::SequenceMatchingException::genererException(
			"Typing error", PARAMETRE_INVALIDE, __LINE__);
	}
	Character *c1 = (Character *)eOD1;
	Character *c2 = (Character *)eOD2;
	return (c1->getValue() == c2->getValue()) ? (float)(0) : (float)(1);
}

string Character::toString() {
	stringstream ss;
	ss << cCvalue;
	return ss.str();
}

Element *Character::copy() {
	Character *a = new Character();
	a->setUid(this->getUid());
	a->setValue(this->getValue());
	return a;
}

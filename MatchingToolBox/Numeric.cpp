/*!
\author Abdourahman Aden Hassan
\date 22/12/2013
*/

#include "Numeric.h"

using namespace model;

Numeric::Numeric()
{
	Element::quidEid = "";
}

Numeric::Numeric(float value)
{
	Element::quidEid = "";
	fNvalue = value;
}


Numeric::Numeric(Numeric const & copy)
	:fNvalue(copy.fNvalue)
{
	Element::quidEid = copy.quidEid;
}

float Numeric::getValue()
{
	return fNvalue;
}

void Numeric::setValue(float value)
{
	fNvalue = value;
}

float Numeric::distance(Element *eOD1, Element *eOD2)
{

	Numeric a;
	if (typeid(*eOD1) != typeid(*eOD2) || typeid(*eOD2) != typeid(a)) {
		exc::SequenceMatchingException::genererException("Typing error", PARAMETRE_INVALIDE, __LINE__);
	}
	Numeric *c1 = (Numeric*)eOD1;
	Numeric *c2 = (Numeric*)eOD2;
	float f = powf(c1->getValue() - c2->getValue(), 2);
	return f;
}

string Numeric::toString()
{
	std::stringstream ss;
	std::string s;
	ss << fNvalue;
	s = ss.str();
	return s;
}

Element *Numeric::copy()
{
	Numeric *a = new Numeric();
	a->setUid(this->getUid());
	a->setValue(this->getValue());
	return a;
}

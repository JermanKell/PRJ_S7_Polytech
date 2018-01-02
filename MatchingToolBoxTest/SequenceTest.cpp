#include "Sequence.h"
#include "Numeric.h"
#include "Character.h"
#include "gtest\gtest.h"

TEST(SequenceTest, creating_sequence) {
	model::Sequence sequence;
	ASSERT_EQ(sequence.getSize(), 0);
}

TEST(SequenceTest, adding_elements) {
	float value = 5;
	int cValue = 'a';
	model::Sequence sequence;
	model::Numeric n1(value);

	sequence.addElement(&n1);
	ASSERT_EQ(sequence.getSize(), 1);

	model::Numeric* n2 = (model::Numeric*) sequence.getElement(0);
	ASSERT_EQ(n2->getValue(), value);
	
	model::Character c(cValue);
	ASSERT_ANY_THROW(sequence.addElement(&c));

}

TEST(SequenceTest, inserting_elements) {
	float value = 5;
	int cValue = 'a';
	model::Sequence sequence;
	model::Numeric n1(value);
	sequence.addElement(&n1);

	value = 4;
	model::Numeric n2(value);
	sequence.insertElement(&n2, 0);
	model::Numeric* n = (model::Numeric*) sequence.getElement(0);
	ASSERT_EQ(n->getValue(), value);
	ASSERT_EQ(sequence.getSize(), 2);

	model::Character c(cValue);
	ASSERT_ANY_THROW(sequence.insertElement(&c, 0));
}

TEST(SequenceTest, removing_elements) {
	float value = 5;
	int cValue = 'a';
	model::Sequence sequence;
	model::Numeric n1(value);
	value = 4;
	model::Numeric n2(value);
	sequence.addElement(&n1);
	sequence.addElement(&n2);

	sequence.removeElement(0);
	ASSERT_EQ(sequence.getSize(), 1); 
	
	model::Numeric* n = (model::Numeric*) sequence.getElement(0);
	ASSERT_EQ(n->getValue(), value);
}
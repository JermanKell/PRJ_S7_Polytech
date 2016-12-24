/*!
  \author Abdourahman Aden Hassan
  \date 22/12/2013
 */
#if defined __linux__
#include "modeltest.h"
#include <math.h>
using namespace test;

CppUnit::Test *ModelTest::suite()
{
        CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "ModelTest" );
        suiteOfTests->addTest( new CppUnit::TestCaller<ModelTest>(
                                       "character_copy",
                                       &ModelTest::character_copy ) );
        suiteOfTests->addTest( new CppUnit::TestCaller<ModelTest>(
                                       "character_distance",
                                       &ModelTest::character_distance ) );
        suiteOfTests->addTest( new CppUnit::TestCaller<ModelTest>(
                                       "numeric_copy",
                                       &ModelTest::numeric_copy ) );
        suiteOfTests->addTest( new CppUnit::TestCaller<ModelTest>(
                                       "numeric_distance",
                                       &ModelTest::numeric_distance ) );
        suiteOfTests->addTest( new CppUnit::TestCaller<ModelTest>(
                                       "characteristicvector_copy",
                                       &ModelTest::characteristicvector_copy ) );
        suiteOfTests->addTest( new CppUnit::TestCaller<ModelTest>(
                                       "characteristicvector_removevalue",
                                       &ModelTest::characteristicvector_removevalue ) );
        suiteOfTests->addTest( new CppUnit::TestCaller<ModelTest>(
                                       "characteristicvector_distance",
                                       &ModelTest::characteristicvector_distance ) );
        suiteOfTests->addTest( new CppUnit::TestCaller<ModelTest>(
                                       "sequence_copy",
                                       &ModelTest::sequence_copy ) );
        suiteOfTests->addTest( new CppUnit::TestCaller<ModelTest>(
                                       "sequence_add",
                                       &ModelTest::sequence_add ) );
        suiteOfTests->addTest( new CppUnit::TestCaller<ModelTest>(
                                       "sequence_remove",
                                       &ModelTest::sequence_remove ) );
        return suiteOfTests;
}


void ModelTest::setUp()
{
}

void ModelTest::tearDown()
{
}

void ModelTest::character_copy()
{
    model::Character c1('a');
    model::Character c2(c1);
    CPPUNIT_ASSERT(c2.getValue()==c1.getValue());
    CPPUNIT_ASSERT(c2.getUid().compare(c1.getUid()) == 0);
}

void ModelTest::character_distance()
{
    model::Character * c1 = new model::Character('a');
    model::Character * c2 = new model::Character('b');
    model::Numeric * n2 = new model::Numeric(1.0);
    CPPUNIT_ASSERT_THROW(c1->distance(c1,n2), exc::SequenceMatchingException);
    CPPUNIT_ASSERT_NO_THROW(c1->distance(c1,c2));
    CPPUNIT_ASSERT(c1->distance(c1,c2) == 1);
    delete c1;
    delete c2;
    delete n2;
}

void ModelTest::characteristicvector_copy()
{
    model::CharacteristicVector cv1;
    cv1.addValue(12.0);
    model::CharacteristicVector cv2(cv1);
    CPPUNIT_ASSERT(cv2.getSize()==cv1.getSize());
    CPPUNIT_ASSERT(cv2.getAt(0) == 12.0);
    CPPUNIT_ASSERT(cv2.getUid().compare(cv1.getUid()) == 0);
}

void ModelTest::characteristicvector_distance()
{

    model::Numeric * n1= new model::Numeric(1);
    model::CharacteristicVector *  cv1 = new model::CharacteristicVector;
    cv1->addValue(4.0);
    cv1->addValue(5.0);
    model::CharacteristicVector *  cv2 = new model::CharacteristicVector;
    cv2->addValue(5.0);
    cv2->addValue(4.0);
    CPPUNIT_ASSERT_THROW(cv1->distance(cv1,n1), exc::SequenceMatchingException);
    CPPUNIT_ASSERT_EQUAL(cv1->distance(cv1,cv2),(float)sqrt(2.0));
    delete n1;
    delete cv1;
    delete cv2;
}


void ModelTest::characteristicvector_removevalue()
{
    model::CharacteristicVector *  cv1 = new model::CharacteristicVector;
    CPPUNIT_ASSERT_THROW(cv1->removeValue(0), exc::SequenceMatchingException);
    CPPUNIT_ASSERT_THROW(cv1->removeValue(-1), exc::SequenceMatchingException);
    cv1->addValue(12.0);
    CPPUNIT_ASSERT_NO_THROW(cv1->removeValue(0));
    delete cv1;
}

void ModelTest::numeric_copy()
{
    model::Numeric n1(1);
    model::Numeric n2(n1);
    CPPUNIT_ASSERT(n2.getValue()==n1.getValue());
    CPPUNIT_ASSERT(n2.getUid().compare(n1.getUid()) == 0);
}

void ModelTest::numeric_distance()
{
    model::Character * c1 = new model::Character('a');
    model::Numeric * n1 = new model::Numeric(5.0);
    model::Numeric * n2 = new model::Numeric(4.0);
    CPPUNIT_ASSERT_THROW(n1->distance(c1,n2), exc::SequenceMatchingException);
    CPPUNIT_ASSERT_NO_THROW(n1->distance(n1,n2));
    CPPUNIT_ASSERT(n1->distance(n1,n2) == 1);
    delete c1;
    delete n1;
    delete n2;
}

void ModelTest::sequence_copy()
{
    model::Sequence s1;
    model::Sequence s2(s1);
    CPPUNIT_ASSERT(s2.getUid()==s1.getUid());
}

void ModelTest::sequence_add()
{
    model::Sequence * s1 = new model::Sequence();
    model::Character * c1 = new model::Character('a');
    model::Numeric * n1 = new model::Numeric(12.0);
    CPPUNIT_ASSERT_NO_THROW(s1->addElement(c1));
    CPPUNIT_ASSERT_THROW(s1->addElement(n1), exc::SequenceMatchingException);
    delete s1;
}

void ModelTest::sequence_remove()
{
    model::Sequence * s1 = new model::Sequence();
    model::Character * c1 = new model::Character('a');
    CPPUNIT_ASSERT_THROW(s1->removeElement(0), exc::SequenceMatchingException);
    CPPUNIT_ASSERT_THROW(s1->removeElement(-1), exc::SequenceMatchingException);
    s1->addElement(c1);
    CPPUNIT_ASSERT_NO_THROW(s1->removeElement(0));
    delete c1;
    delete s1;
}


#endif

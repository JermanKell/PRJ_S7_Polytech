/*!
  \author Abdourahman Aden Hassan
  \date 22/12/2013
 */
#if defined __linux__
#ifndef MODELTEST_H
#define MODELTEST_H
#include "Model.h"
#include "Exc.h"
#include <cppunit/TestCase.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestSuite.h>
namespace test{
class ModelTest : public CppUnit::TestFixture
{
    /*!
     * \class ModelTest
     * \brief Cette classe comprends les tests unitaires du package modèle
     * \package test
     */
public:
    /*!
     * \brief setUp
     */
    void setUp();
    /*!
     * \brief tearDown
     */
    void tearDown();
    /*!
     * \brief do_all_test
     * Méthode qui lance tous les tests
     */
    static CppUnit::Test *suite();

private:


    /*!
     * \brief character_copy
     * Test du constructeur de recopie pour la classe character
     */
    void character_copy();
    /*!
     * \brief character_distance
     * Test de la fonction distance pour la classe character
     */
    void character_distance();
    /*!
     * \brief characteristicvector_copy
     * Test du constructeur de recopie pour la classe characteristicvector
     */
    void characteristicvector_copy();
    /*!
     * \brief characteristicvector_distance
     * Test de la fonction distance pour la classe characteristicvector
     */
    void characteristicvector_distance();
    /*!
     * \brief characteristicvector_removevalue
     * Test de la fonction de suppression de valeur pour la classe characteristicvector
     */
    void characteristicvector_removevalue();
    /*!
     * \brief numeric_copy
     * Test du constructeur de recopie pour la classe numeric
     */
    void numeric_copy();
    /*!
     * \brief numeric_distance
     * Test de la fonction distance pour la classe numeric
     */
    void numeric_distance();
    /*!
     * \brief sequence_copy
     * Test du constructeur de recopie pour la classe séquence
     */
    void sequence_copy();
    /*!
     * \brief sequence_add
     * Test de la fonction d'ajout d'un élément à la séquence
     */
    void sequence_add();
    /*!
     * \brief sequence_remove
     * Test de la fonction de suppression d'un élément de la séquence
     */
    void sequence_remove();

};


}

#endif // MODELTEST_H
#endif

#include "TestField.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TestField);

#include "Field.hpp"
#include "TypeOf.hpp"
#include "Film.h"

void TestField::setUp()
{
//	fieldYear = reflect::BuiltinField::create("_year", &Film::_year);
}

void TestField::tearDown()
{
	delete fieldYear;
}

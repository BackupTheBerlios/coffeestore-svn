#ifndef TEST_FIELD_H
#define TEST_FIELD_H

#include <cppunit/extensions/HelperMacros.h>

namespace reflect
{
	class BuiltinField;
} // namespace reflect

class TestField : public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE(TestField);
	CPPUNIT_TEST_SUITE_END();
public:
	void setUp();
	void tearDown();

	reflect::BuiltinField* fieldYear;
};

#endif

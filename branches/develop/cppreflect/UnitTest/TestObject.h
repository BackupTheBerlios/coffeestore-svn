#ifndef TEST_OBJECT_H
#define TEST_OBJECT_H

#include <cppunit/extensions/HelperMacros.h>

class TestObject : public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE(TestObject);
	CPPUNIT_TEST(testDtorCalled);
	CPPUNIT_TEST(testDtorNotCalled);
	CPPUNIT_TEST_SUITE_END();
public:
	void testDtorCalled();
	void testDtorNotCalled();
};

#endif


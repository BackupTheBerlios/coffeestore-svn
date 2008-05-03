#ifndef TEST_OBJ_HOLDER_H
#define TEST_OBJ_HOLDER_H

#include <cppunit/extensions/HelperMacros.h>

class TestObjHolder : public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE(TestObjHolder);
	CPPUNIT_TEST(testBuiltinConcreteType);
	CPPUNIT_TEST(testBuiltinGet);
	CPPUNIT_TEST(testBuiltinGetFail);
	CPPUNIT_TEST(testRefCount);
	CPPUNIT_TEST(testDeleteHeld);
	CPPUNIT_TEST(testNotDeleteHeld);
	CPPUNIT_TEST_SUITE_END();
public:
	void testBuiltinConcreteType();
	void testBuiltinGet();
	void testBuiltinGetFail();
	void testRefCount();
	void testDeleteHeld();
	void testNotDeleteHeld();
};

#endif


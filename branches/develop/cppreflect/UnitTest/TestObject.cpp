#include "TestObject.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TestObject);

#include "Object.hpp"
#include "FakeObjDeleteHeld.hpp"

void TestObject::testDtorCalled()
{
	FakeObjDeleteHeld::DTor dtor;
	{
	FakeObjDeleteHeld* held = new FakeObjDeleteHeld(dtor);
	reflect::Object obj(*held, true);
	}
	CPPUNIT_ASSERT(dtor.called);
}

void TestObject::testDtorNotCalled()
{
	FakeObjDeleteHeld::DTor dtor;
	FakeObjDeleteHeld* fakeObj = new FakeObjDeleteHeld(dtor);
	{
	reflect::Object obj(*fakeObj);
	}
	CPPUNIT_ASSERT(!dtor.called);
	delete fakeObj;
}

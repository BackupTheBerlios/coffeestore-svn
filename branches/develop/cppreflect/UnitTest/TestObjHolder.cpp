#include "TestObjHolder.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TestObjHolder);

#include "ObjHolder.hpp"
#include "Exception.hpp"
#include "FakeObjDeleteHeld.hpp"

void TestObjHolder::testBuiltinConcreteType()
{
	int data = 1;
	reflect::ObjHolderTmpl<int> obj(&data, false, false);
	bool areEqual = obj.abstractType() == obj.concreteType();
	CPPUNIT_ASSERT(areEqual);
}

void TestObjHolder::testBuiltinGet()
{
	int data = 1;
	reflect::ObjHolderTmpl<int> obj(&data, false, false);
	CPPUNIT_ASSERT_EQUAL(data, obj.get<int>());
}

void TestObjHolder::testBuiltinGetFail()
{
	int data = 1;
	reflect::ObjHolderTmpl<int> obj(&data, false, false);
	try
	{
	obj.get<float>();
	CPPUNIT_FAIL("BadCastException not thrown");
	}
	catch (reflect::BadCastException&) {}
}

void TestObjHolder::testRefCount()
{
	reflect::ObjHolderTmpl<int> obj(0, false, false);
	CPPUNIT_ASSERT(!obj.canDelete());
	obj.incrRef();
	CPPUNIT_ASSERT(!obj.canDelete());
	obj.decrRef();
	CPPUNIT_ASSERT(!obj.canDelete());
	obj.decrRef();
	CPPUNIT_ASSERT(obj.canDelete());
}

void TestObjHolder::testDeleteHeld()
{
	FakeObjDeleteHeld::DTor dtor;
	FakeObjDeleteHeld* fakeObj = new FakeObjDeleteHeld(dtor);
	{
	reflect::ObjHolderTmpl<FakeObjDeleteHeld> fakeObjHolder(fakeObj, true, false);
	}
	CPPUNIT_ASSERT(dtor.called);
}

void TestObjHolder::testNotDeleteHeld()
{
	FakeObjDeleteHeld::DTor dtor;
	FakeObjDeleteHeld* fakeObj = new FakeObjDeleteHeld(dtor);
	{
	reflect::ObjHolderTmpl<FakeObjDeleteHeld> fakeObjHolder(fakeObj, false, false);
	}
	CPPUNIT_ASSERT(!dtor.called);
	delete fakeObj;
}

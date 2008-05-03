#ifndef FAKE_OBJ_DELETE_HELD
#define FAKE_OBJ_DELETE_HELD

#include "TypeOf.hpp"

class FakeObjDeleteHeld
{
public:
	struct DTor
	{
		DTor() : called(false) {}
		bool called;
	};

	FakeObjDeleteHeld(DTor& dtor)
		:	_dtor(dtor)
	{

	}
	~FakeObjDeleteHeld()
	{
		_dtor.called = true;
	}

public:
	DTor& _dtor;
};

namespace reflect {

template<>
class TypeOf<FakeObjDeleteHeld>
{
public:
	static const reflect::Type& get() { return *static_cast<const reflect::Type*>(NULL); }
};

} // namesapce reflect

#endif

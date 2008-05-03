#include "ObjHolder.hpp"

namespace reflect {

ObjHolder::ObjHolder() 
	:	_ref(1) 
{

}

ObjHolder::~ObjHolder() 
{

}

void ObjHolder::incrRef() 
{ 
	_ref++; 
}

void ObjHolder::decrRef() 
{ 
	_ref--; 
}

bool ObjHolder::canDelete() const 
{ 
	return 0 == _ref; 
}

} // namespace reflect

#include "Object.hpp"

namespace reflect {

Object::Object(const Object& object)
{
	_objHolder->incrRef();
}

Object& Object::operator = (const Object& object)
{
	if (this != &object)
		_objHolder->incrRef();

	return *this;
}

Object::~Object()
{
	_objHolder->decrRef();
	if (_objHolder->canDelete())
		delete _objHolder;
}

const Type& Object::abstractType() const
{
	return _objHolder->abstractType();
}

const Type& Object::concreteType() const
{
	return _objHolder->concreteType();
}

bool Object::isConst() const
{
	return _objHolder->isConst();
}

} // namespace reflect

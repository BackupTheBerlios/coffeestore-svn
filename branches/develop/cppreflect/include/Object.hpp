#ifndef _REFLECT_OBJECT_H_
#define _REFLECT_OBJECT_H_

#include "ObjHolder.hpp"

namespace reflect {

class Object
{
public:
	template <typename T> Object(T& held, bool deleteHeld = false);

	Object(const Object& object);
	Object& operator = (const Object& object);
	~Object();

	const Type& abstractType() const;
	const Type& concreteType() const;

	template <typename T> T& get() const;
	template <typename T> operator T& () const;

	bool isConst() const;

private:
	ObjHolder* _objHolder;
};

template <typename T>
Object::Object(T& held, bool deleteHeld)
:	_objHolder(new ObjHolderTmpl<StripCVQualifiers<T>::Result>(const_cast<StripCVQualifiers<T>::Result*>(&held), deleteHeld, IsConst<T>::result))
{

}

template <typename T> 
T& Object::get() const
{
	return _objHolder->get<T>();
}

template <typename T> 
Object::operator T& () const
{
	return _objHolder->get<T>();
}

} // namespace reflect

#endif

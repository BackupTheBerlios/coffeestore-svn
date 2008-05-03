#ifndef _REFLECT_OBJ_HOLDER_H_
#define _REFLECT_OBJ_HOLDER_H_

#include "TypeOf.hpp"
#include "TypeRegistry.hpp"
#include "Exception.hpp"
#include "StripCVQualifiers.hpp"

namespace reflect {

class ObjHolder : reflect::NonCopyable
{
public:
	ObjHolder();
	virtual ~ObjHolder();
	virtual const Type& abstractType() const = 0;
	virtual const Type& concreteType() const = 0;

	template <typename T> T& get() const;

	virtual bool isConst() const = 0;

	void incrRef();
	void decrRef();
	bool canDelete() const;
public:
	int _ref;
};

template <typename T>
class ObjHolderTmpl : public ObjHolder
{
public:
	ObjHolderTmpl(T* held, bool deleteHeld, bool isConst)
		:	_held(held), _deleteHeld(deleteHeld), _isConst(isConst)
	{
	
	}

	~ObjHolderTmpl()
	{
		if (_deleteHeld)
			delete _held;
	}

	const Type& abstractType() const
	{
		return TypeOf<T>::get();
	}

	const Type& concreteType() const
	{
		const std::type_info& typeInfo = typeid(*_held);
		const char* name = typeInfo.name();
		const Type* type = TypeRegistry::getInstance().find(typeInfo);

		if (!type)
			throw UnresolvedConcreteTypeException(abstractType(), typeInfo);

		return *type;
	}

	T* held() const
	{
		return _held;
	}

	bool isConst() const
	{
		return _isConst;
	}

private:
	T* _held;
	bool _deleteHeld;
	bool _isConst;
};

template <typename T> T& ObjHolder::get() const
{
	typedef typename StripCVQualifiers<T>::Result To;
	const ObjHolderTmpl<To>* self = dynamic_cast<const ObjHolderTmpl<To>*>(this);
	if (!self)
		throw BadCastException(abstractType(), TypeOf<To>::get());

	return *self->held();
}

} // namespace reflect

#endif

#ifndef _REFLECT_TYPE_OF_H_
#define _REFLECT_TYPE_OF_H_

// local
#include "Type.hpp"
#include "TypeRegistry.hpp"
#include "Singleton.hpp"

#define REFLECT_TYPEOF_BUILTIN_DEF(T) \
	template <> \
	class TypeOf<T> \
	{ \
	public: \
		static Type& get() \
		{ \
			return _instance; \
		} \
	private: \
		static BuiltinTypeTmpl<T> _instance; \
	};

#define REFLECT_TYPEOF_BUILTIN_REG(T) \
	BuiltinTypeTmpl<T> TypeOf<T>::_instance(#T);

namespace reflect {

template <typename T>
class ClassTypeTmpl;

template <typename T>
class TypeOf
{
public:
	static ClassType& get()
	{
		return ClassTypeTmpl<T>::getInstance();
	}
};

template <typename T>
class BuiltinTypeTmpl : public Type
{
public:
	BuiltinTypeTmpl(const std::string& name)
		:	Type(name)
	{
		TypeRegistry::getInstance().add(typeid(T), *this);
	}
};

class StringType : public Type, public Singleton<StringType, details::StaticInstance<StringType> >
{
public:
	StringType();
};

template <>
class TypeOf<std::string>
{
public:
	static Type& get();
};

REFLECT_TYPEOF_BUILTIN_DEF(bool)
REFLECT_TYPEOF_BUILTIN_DEF(char)
REFLECT_TYPEOF_BUILTIN_DEF(int)
REFLECT_TYPEOF_BUILTIN_DEF(float)
REFLECT_TYPEOF_BUILTIN_DEF(double)

} // namespace reflect

#endif

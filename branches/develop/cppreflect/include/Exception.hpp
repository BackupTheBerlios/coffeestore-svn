#ifndef _REFLECT_EXCEPTION_H_
#define _REFLECT_EXCEPTION_H_

#include <exception>
#include <typeinfo>
#include <string>

namespace reflect {

class Type;
class Field;

class Exception : public std::runtime_error
{
public:
	Exception(const std::string& message);
};

class UnresolvedConcreteTypeException : public Exception
{
public:
	UnresolvedConcreteTypeException(const Type& type, const std::type_info& typeInfo);
};

class BadCastException : public Exception
{
public:
	BadCastException(const Type& from, const Type& to);
};

class FieldCastException : public Exception
{
public:
	FieldCastException();
};

class ClassTypeCastException : public Exception
{
public:
	ClassTypeCastException();
};

class ConstFieldSetException : public Exception
{
public:
	ConstFieldSetException(const Field& field);
};

class ConstObjectException : public Exception
{
public:
	ConstObjectException();
};

} // namespace

#endif

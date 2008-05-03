#include "Exception.hpp"
#include "Type.hpp"
#include "Field.hpp"

namespace reflect {

Exception::Exception(const std::string& message)
	:	std::runtime_error(message)
{
	
}

UnresolvedConcreteTypeException::UnresolvedConcreteTypeException(const Type& type, const std::type_info& typeInfo)
	:	Exception("UnresolvedConcreteTypeException: " + type.name() + " => " + typeInfo.name())
{
	
}

BadCastException::BadCastException(const Type& from, const Type& to)
	:	Exception("BadCastException: " + from.name() + " => " + to.name())
{

}


FieldCastException::FieldCastException()
	:	Exception("FieldCastException")
{

}

ClassTypeCastException::ClassTypeCastException()
	:	Exception("ClassTypeCastException")
{

}

ConstFieldSetException::ConstFieldSetException(const Field& field)
	:	Exception("ConstFieldSetException: fieldName: " + field.name() + " fieldOf: " + field.fieldOf().name())
{

}

ConstObjectException::ConstObjectException()
	:	Exception("ConstObjectException")
{

}

} // namespace reflect

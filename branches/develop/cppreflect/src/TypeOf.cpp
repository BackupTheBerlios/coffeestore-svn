#include "TypeOf.hpp"

namespace reflect {

REFLECT_TYPEOF_BUILTIN_REG(bool)
REFLECT_TYPEOF_BUILTIN_REG(char)
REFLECT_TYPEOF_BUILTIN_REG(int)
REFLECT_TYPEOF_BUILTIN_REG(float)
REFLECT_TYPEOF_BUILTIN_REG(double)

StringType::StringType()
	:	Type("std::string")
{
	TypeRegistry::getInstance().add(typeid(std::string), *this);
}

Type& TypeOf<std::string>::get()
{
	return StringType::getInstance();
}

} // namespace reflect


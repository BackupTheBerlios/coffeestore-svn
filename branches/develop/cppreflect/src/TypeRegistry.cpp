#include "TypeRegistry.hpp"

namespace reflect {

void TypeRegistry::add(const std::type_info& typeInfo, const Type& type)
{
	_registry.insert(std::make_pair(&typeInfo, &type));
}

const Type* TypeRegistry::find(const std::type_info& typeInfo) const
{
	Registry::const_iterator resFind = _registry.find(&typeInfo);
	return (resFind != _registry.end()) ? resFind->second : 0;
}

} // namespace reflect

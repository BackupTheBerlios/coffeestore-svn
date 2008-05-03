#ifndef _REFLECT_TYPE_REGISTRY_H_
#define _REFLECT_TYPE_REGISTRY_H_

// local
#include "Singleton.hpp"

// standard
#include <map>
#include <typeinfo>

namespace reflect {

class Type;

class TypeRegistry : public Singleton<TypeRegistry>
{
	typedef std::map<const std::type_info*, const Type*> Registry;
public:
	void add(const std::type_info& typeInfo, const Type& type);
	const Type* find(const std::type_info& typeInfo) const;
private:
	Registry _registry;
};

} // namespace

#endif

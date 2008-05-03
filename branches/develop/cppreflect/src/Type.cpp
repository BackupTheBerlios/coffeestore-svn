#include "Type.hpp"
#include "Field.hpp"

namespace reflect {

Type::Type(const std::string& name)
	:	_name(name)
{

}

Type::~Type()
{

}

bool Type::operator==(const Type& type) const
{
	return this == &type;
}

const std::string& Type::name() const
{
	return _name;
}

bool Type::isClassType() const
{
	return false;
}

const ClassType& Type::asClassType() const
{
	throw ClassTypeCastException();
}

ClassType::ClassType(const std::string& name)
	:	Type(name)
{

}

bool ClassType::isClassType() const
{
	return true;
}

const ClassType& ClassType::asClassType() const
{
	return * static_cast<const ClassType*>(this);
}

bool ClassType::addField(const Field& field)
{
	if (_fields.insert(std::make_pair(field.name(), &field)).second)
		return true;

	return false;
}

const Field& ClassType::findField(const std::string& fieldName) const
{
	FieldMap::const_iterator resFind = _fields.find(fieldName);
	return *resFind->second;
}

ClassType::FieldsIterator::FieldsIterator(const FieldMap::const_iterator& internalIterator)
	:	_internalIterator(internalIterator)
{

}

bool ClassType::FieldsIterator::operator == (const FieldsIterator& fieldsIterator) const
{
	return _internalIterator == fieldsIterator._internalIterator;
}

bool ClassType::FieldsIterator::operator != (const FieldsIterator& fieldsIterator) const
{
	return _internalIterator != fieldsIterator._internalIterator;
}

ClassType::FieldsIterator& ClassType::FieldsIterator::operator ++ ()
{
	++_internalIterator;
	return *this;
}

ClassType::FieldsIterator& ClassType::FieldsIterator::operator ++ (int)
{
	_internalIterator++;
	return *this;
}

const Field& ClassType::FieldsIterator::operator * () const
{
	return *_internalIterator->second;
}

const Field* ClassType::FieldsIterator::operator -> () const
{
	return _internalIterator->second;
}

ClassType::FieldsIterator ClassType::fieldsBegin() const
{
	return _fields.begin();
}

ClassType::FieldsIterator ClassType::fieldsEnd() const
{
	return _fields.end();
}

} // namespace reflect

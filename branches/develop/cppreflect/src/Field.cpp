#include "Field.hpp"

namespace reflect {

Field::Field(const Type& type, const std::string& name, const ClassType& fieldOf)
	:	_type(type), _name(name), _fieldOf(fieldOf)
{

}

Field::~Field()
{

}

const Type& Field::type() const
{
	return _type;
}

const std::string& Field::name() const
{
	return _name;
}

bool Field::isBuiltinField() const
{
	return false;
}

const BuiltinField& Field::asBuiltinField() const
{
	throw FieldCastException();
}

bool Field::isStringField() const
{
	return false;
}

const StringField& Field::asStringField() const
{
	throw FieldCastException();
}

bool Field::isCompositeField() const
{
	return false;
}

const CompositeField& Field::asCompositeField() const
{
	throw FieldCastException();
}

const ClassType& Field::fieldOf() const
{
	return _fieldOf;
}

BuiltinField::BuiltinField(const Type& type, const std::string& name, const ClassType& fieldOf)
	:	Field(type, name, fieldOf)
{

}

bool BuiltinField::isBuiltinField() const
{
	return true;
}

const BuiltinField& BuiltinField::asBuiltinField() const
{
	return * static_cast<const BuiltinField*>(this);
}

bool BuiltinField::getBool(const Object& obj) const
{
	bool& res = get(obj);
	return res;
}

void BuiltinField::setBool(const Object& obj, bool value) const
{
	Object objValue(value, false);
	set(obj, objValue);
}

char BuiltinField::getChar(const Object& obj) const
{
	char& res = get(obj);
	return res;
}

void BuiltinField::setChar(const Object& obj, char value) const
{
	Object objValue(value, false);
	set(obj, objValue);
}

int BuiltinField::getInt(const Object& obj) const
{
	int& res = get(obj);
	return res;
}

void BuiltinField::setInt(const Object& obj, int value) const
{
	Object objValue(value, false);
	set(obj, objValue);
}

float BuiltinField::getFloat(const Object& obj) const
{
	float& res = get(obj);
	return res;
}

void BuiltinField::setFloat(const Object& obj, float value) const
{
	Object objValue(value, false);
	set(obj, objValue);
}

double BuiltinField::getDouble(const Object& obj) const
{
	double& res = get(obj);
	return res;
}

void BuiltinField::setDouble(const Object& obj, double value) const
{
	Object objValue(value, false);
	set(obj, objValue);
}


StringField::StringField(const Type& type, const std::string& name, const ClassType& fieldOf)
	:	Field(type, name, fieldOf)
{

}

bool StringField::isStringField() const
{
	return true;
}

const StringField& StringField::asStringField() const
{
	return * static_cast<const StringField*>(this);
}

const std::string& StringField::getString(const Object& obj) const
{
	std::string& res = get(obj);
	return res;
}

void StringField::setString(const Object& obj, const std::string& value) const
{
	Object objValue(value, false);
	set(obj, objValue);
}

CompositeField::CompositeField(const Type& type, const std::string& name, const ClassType& fieldOf)
	:	Field(type, name, fieldOf)
{

}

bool CompositeField::isCompositeField() const
{
	return true;
}

const CompositeField& CompositeField::asCompositeField() const
{
	return * static_cast<const CompositeField*>(this);
}

} // namespace reflect

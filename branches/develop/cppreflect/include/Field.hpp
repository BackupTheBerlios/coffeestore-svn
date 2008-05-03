#ifndef _REFLECT_FIELD_H_
#define _REFLECT_FIELD_H_

// standard
#include <string>

// local
#include "NonCopyable.hpp"
#include "Object.hpp"

namespace reflect {

class Type;
class BuiltinField;
class StringField;
class CompositeField;

//! Field descriptor.
class Field : NonCopyable
{
public:
	//! To create new field
	/*!
	\param type the Type of the described field.
	\param name the name of the described field.
	\param name the class type which contains this field.
	*/
	Field(const Type& type, const std::string& name, const ClassType& fieldOf);

	//! Destroy a type.
	virtual ~Field();
	
	//! Returns the Type of the described field.
	const Type& type() const;

	//! Returns the name of the described field.
	const std::string& name() const;

	//! Returns the type which contains this field.
	const ClassType& fieldOf() const;

	//! Returns the field value given the relative object.
	/*!
	\param obj the object.
	\return the field value.
	*/
	virtual const Object get(const Object& obj) const = 0;

	//! Set the field value given the relative object and its new value.
	/*!
	\param obj the object.
	\param value the value.
	*/
	virtual void set(const Object& obj, const Object& value) const = 0;

	//! Returns whether the field type is a BuiltinField.
	virtual bool isBuiltinField() const;

	//! Cast this object to BuiltinField type.
	virtual const BuiltinField& asBuiltinField() const;

	//! Returns whether the field type is a StringField.
	virtual bool isStringField() const;

	//! Cast this object to StringField type.
	virtual const StringField& asStringField() const;

	//! Returns whether the field type is a CompositeField.
	virtual bool isCompositeField() const;

	//! Cast this object to CompositeField type.
	virtual const CompositeField& asCompositeField() const;

private:
	const Type& _type;
	std::string _name;

	const ClassType& _fieldOf;
};

//! BuiltinField descriptor.
class BuiltinField : public Field
{
public:
	BuiltinField(const Type& type, const std::string& name, const ClassType& fieldOf);

	bool isBuiltinField() const;
	const BuiltinField& asBuiltinField() const;

	template <typename C, typename F>
	static BuiltinField& create(F C::* p2m, const char* name);

	virtual bool isBool() const = 0;
	bool getBool(const Object& obj) const;
	void setBool(const Object& obj, bool value) const;

	virtual bool isChar() const = 0;
	char getChar(const Object& obj) const;
	void setChar(const Object& obj, char value) const;

	virtual bool isInt() const = 0;
	int getInt(const Object& obj) const;
	void setInt(const Object& obj, int value) const;

	virtual bool isFloat() const = 0;
	float getFloat(const Object& obj) const;
	void setFloat(const Object& obj, float value) const;

	virtual bool isDouble() const = 0;
	double getDouble(const Object& obj) const;
	void setDouble(const Object& obj, double value) const;
};

//! StringField descriptor.
class StringField : public Field
{
public:
	StringField(const Type& type, const std::string& name, const ClassType& fieldOf);

	bool isStringField() const;
	const StringField& asStringField() const;

	template <typename C, typename F>
	static StringField& create(F C::* p2m, const char* name);

	const std::string& getString(const Object& obj) const;
	void setString(const Object& obj, const std::string& value) const;
};

//! CompositeField descriptor.
class CompositeField : public Field
{
public:
	CompositeField(const Type& type, const std::string& name, const ClassType& fieldOf);

	bool isCompositeField() const;
	const CompositeField& asCompositeField() const;

	template <typename C, typename F>
	static CompositeField& create(F C::* p2m, const char* name);
};

} // namespace reflect

#include "FieldTmpl.hpp"

#endif

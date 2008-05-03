#ifndef _REFLECT_TYPE_H_
#define _REFLECT_TYPE_H_

// standard
#include <string>
#include <map>

// local
#include "NonCopyable.hpp"

namespace reflect {

class Field;
class ClassType;

//! Type descriptor. One instance for each type.
class Type : NonCopyable
{
public:
	//! Create a new Type.
	/*!
	\param name the name of the described type.
	*/
	Type(const std::string& name);

	//! Destroy a type.
	virtual ~Type();
	
	//! Compares two instances of Type for equality.
	bool operator==(const Type& type) const;
	
	//! Returns the name of the described type.
	const std::string& name() const;

	//! Returns whether this object represents a ClassType object;
	virtual bool isClassType() const;
	
	//! Cast this object to ClassType type.
	virtual const ClassType& asClassType() const;

private:
	std::string _name;
};

//! Type descriptor for class types. One instance for each type.
class ClassType : public Type
{
	typedef std::map<std::string, const Field*> FieldMap;
public:
	//! Create a new ClassType
	/*!
	\param name the name of the described class.
	*/
	ClassType(const std::string& name);

	bool isClassType() const;
	const ClassType& asClassType() const;

	//! Find a field object given its name.
	const Field& findField(const std::string& fieldName) const;

	class FieldsIterator
	{
	public:
		FieldsIterator(const FieldMap::const_iterator& internalIterator);
	
		bool operator == (const FieldsIterator& fieldsIterator) const;
		bool operator != (const FieldsIterator& fieldsIterator) const;

		FieldsIterator& operator ++ ();
		FieldsIterator& operator ++ (int);

		const Field& operator * () const;
		const Field* operator -> () const;

	private:
		FieldMap::const_iterator _internalIterator;
	};

	//! Returns the begin iterator of fields container.
	FieldsIterator fieldsBegin() const;

	//! Returns the begin iterator of fields container.
	FieldsIterator fieldsEnd() const;

protected:
	//! Add a field to class descriptor.
	/*!
	\param field an instance of a derived of Field.
	*/
	bool addField(const Field& field);

private:
	FieldMap _fields;
};

} // namespace reflect

#endif

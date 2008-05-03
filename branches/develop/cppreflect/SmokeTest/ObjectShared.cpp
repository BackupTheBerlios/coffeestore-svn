#include "Field.hpp"
#include "TypeOf.hpp"
#include "TypeRegistry.hpp"
using namespace reflect;

#include <string>
#include <iostream>
using namespace std;

#include "macro.hpp"

class MyClass
{
	REFLECT_ALLOW(MyClass)
public:
	MyClass(double myDouble, int myInt, char myChar)
		:	_myDouble(myDouble), _myInt(myInt), _myChar(myChar)
	{

	}
	~MyClass()
	{
		std::cout << "DTOR" << std::endl;
	}

private:
	double _myDouble;
	int _myInt;
	char _myChar;

	std::string _myStr;
};

REFLECT_BEGIN(MyClass)
REFLECT_FIELD(_myDouble)
REFLECT_FIELD(_myInt)
REFLECT_FIELD(_myChar)
REFLECT_FIELD(_myStr)
REFLECT_END()

class MyComposition
{
	REFLECT_ALLOW(MyComposition)
public:
	MyComposition(const MyClass& myClass)
		:	_myClass(myClass)
	{

	}

	const MyClass& getMyClass() { return _myClass; }

private:
	MyClass _myClass;
};

REFLECT_BEGIN(MyComposition)
REFLECT_FIELD(_myClass)
REFLECT_END()

void printObject(const Object& obj)
{
	const Type& t = obj.concreteType();
	if (!t.isClassType())
		return;

	const ClassType& type = t.asClassType();

	for (ClassType::FieldsIterator it = type.fieldsBegin(); it != type.fieldsEnd(); ++it)
	{
		const Field& field = *it;
		std::cout << it->name() << " : " << (*it).type().name() << std::endl;

		if (field.isBuiltinField())
		{
			std::cout << "\tbuiltin ";
			const BuiltinField& builtin = field.asBuiltinField();
			if (builtin.isBool())
				std::cout << builtin.getBool(obj);

			if (builtin.isChar())
				std::cout << builtin.getChar(obj);

			if (builtin.isInt())
				std::cout << builtin.getInt(obj);

			if (builtin.isFloat())
				std::cout << builtin.getFloat(obj);

			if (builtin.isDouble())
				std::cout << builtin.getDouble(obj);

			std::cout << std::endl;
		}

		else if (field.isStringField())
		{
			const StringField& str = field.asStringField();
			std::cout << "\tstring " << str.getString(obj) << std::endl;
		}

		else if (field.isCompositeField())
		{
			std::cout << "\tcomposite" << std::endl;
			const CompositeField& composite = field.asCompositeField();

			printObject(composite.get(obj));
		}
		else 
		{
			std::cout << "INTERNAL ERROR" << std::endl;
		}
	}
}

int main()
{
	MyClass myObj(12.23f, 11, 'a');
	Object object(myObj, false);

	const BuiltinField& field_myDouble =  TypeOf<MyClass>::get().findField("_myDouble").asBuiltinField();
	const BuiltinField& field_myInt =  TypeOf<MyClass>::get().findField("_myInt").asBuiltinField();
	const BuiltinField& field_myChar = TypeOf<MyClass>::get().findField("_myChar").asBuiltinField();
	const StringField& field_myStr = TypeOf<MyClass>::get().findField("_myStr").asStringField();

	std::cout << field_myDouble.getDouble(object) << std::endl;
	std::cout << field_myInt.getInt(object) << std::endl;
	std::cout << field_myChar.getChar(object) << std::endl;

	try
	{
		std::cout << field_myDouble.getInt(object) << std::endl;
	}
	catch (const BadCastException& e)
	{
		cout << e.what() << endl;
	}

	try
	{
		std::cout << field_myInt.getDouble(object) << std::endl;
	}
	catch (const BadCastException& e)
	{
		cout << e.what() << endl;
	}

	try
	{
		std::cout << field_myChar.getInt(object) << std::endl;
	}
	catch (const BadCastException& e)
	{
		cout << e.what() << endl;
	}

	try
	{

	field_myDouble.setDouble(object, 21.32f);
	field_myInt.setInt(object, 123);
	field_myChar.setChar(object, 'b');

	std::cout << field_myDouble.getDouble(object) << std::endl;
	std::cout << field_myInt.getInt(object) << std::endl;
	std::cout << field_myChar.getChar(object) << std::endl;

	field_myStr.setString(myObj, "mickey");
	std::cout << field_myStr.getString(object) << std::endl;
	Object obj = field_myStr.get(object);
	std::cout << obj.get<std::string>() << std::endl;

	std::string newStr = "mouse";
	Object valueStr(newStr, false);
	field_myStr.set(object, valueStr);
	std::cout << field_myStr.getString(object) << std::endl;
	field_myStr.setString(object, "mickey");
	std::cout << field_myStr.getString(object) << std::endl;
	
	}
	catch (Exception& e)
	{
		cout << "Unexpected " << e.what() << endl;
	}

	const MyClass myConstObj(11.2, 12, '2');
	Object constObject(myConstObj);

	cout << constObject.abstractType().name() << endl;
	cout << constObject.concreteType().name() << endl;

	cout << TypeRegistry::getInstance().find(typeid(bool))->name() << endl;

	MyComposition myComp(myConstObj);
	cout << TypeRegistry::getInstance().find(typeid(MyComposition))->name() << endl;

	printObject(myComp);

	try
	{
		const MyClass myObj(12.23f, 11, 'a');
		Object object(myObj, false);
		field_myStr.setString(object, "pippo");
	}
	catch (Exception& e)
	{
		cout << e.what() << endl;
	}

	system("pause");
	return 0;
}

#ifndef _REFLECT_FIELD_TMPL_H_
#define _REFLECT_FIELD_TMPL_H_

// standard
#include <sstream>

// local
#include "TypeOf.hpp"
#include "BuiltinTypeTraits.h"

namespace reflect {

template <typename C, typename F>
class P2MHelper
{
public:
	typedef F C::* init_type;
	typedef C class_type;
	typedef F field_type;

	P2MHelper(F C::* p2m)
		:	_p2m(p2m)
	{
	
	}

	const F& get(const C& obj) const
	{
		return obj.*_p2m;
	}

	F& get(C& obj) const
	{
		return obj.*_p2m;
	}

private:
	F C::* _p2m;
};

namespace details {

template <typename FieldType>
struct FieldGetHelper
{
	template <typename AccessorHelper>
	static Object apply(const AccessorHelper& accessorHelper, const Object& obj)
	{
		typedef typename AccessorHelper::class_type class_type;
		typedef typename AccessorHelper::field_type field_type;

		class_type& objTyped = obj;
		const field_type& fieldValue = accessorHelper.get(objTyped);
		return fieldValue;
	}
};

template <typename FieldType>
struct FieldSetByAssignmentHelper
{
	template <typename AccessorHelper>
	static void apply(const Field& self, const AccessorHelper& accessorHelper, const Object& obj, const Object& value)
	{
		typedef typename AccessorHelper::class_type class_type;
		typedef typename AccessorHelper::field_type field_type;

		if (obj.isConst())
			throw ConstObjectException();

		class_type& objTyped = obj;
		field_type& dst = accessorHelper.get(objTyped);
		const field_type& src = value;
		dst = src;
	}
};

template <typename FieldType>
struct FieldSetByAssignmentHelper<const FieldType>
{
	template <typename AccessorHelper>
	static void apply(const Field& self, const AccessorHelper& accessorHelper, const Object& obj, const Object& value)
	{
		throw ConstFieldSetException(self);
	}
};

} // namespace details

template <typename C, typename F>
class BuiltinFieldTmpl : public BuiltinField
{
	typedef P2MHelper<C, F> AccessorHelper;
public:
	BuiltinFieldTmpl(const Type& type, const std::string& name, const ClassType& fieldOf, typename AccessorHelper::init_type value)
		:	BuiltinField(type, name,fieldOf), _accessorHelper(value)
	{
	
	}

	const Object get(const Object& obj) const
	{
		return details::FieldGetHelper<F>::apply(_accessorHelper, obj);
	}

	void set(const Object& obj, const Object& value) const
	{
		details::FieldSetByAssignmentHelper<F>::apply(*this, _accessorHelper, obj, value);
	}

	bool isBool() const
	{
		return BuiltinTypeTraits<F>::isBool();
	}

	bool isChar() const
	{
		return BuiltinTypeTraits<F>::isChar();
	}

	bool isInt() const
	{
		return BuiltinTypeTraits<F>::isInt();
	}

	bool isFloat() const
	{
		return BuiltinTypeTraits<F>::isFloat();
	}

	bool isDouble() const
	{
		return BuiltinTypeTraits<F>::isDouble();
	}

private:
	AccessorHelper _accessorHelper;
};

template <typename C, typename F>
BuiltinField& BuiltinField::create(F C::* p2m, const char* name)
{
	typedef typename StripCVQualifiers<F>::Result StrippedFieldType;
	return * new BuiltinFieldTmpl<C, F>(TypeOf<StrippedFieldType>::get(), name, TypeOf<C>::get(), p2m);
}

template <typename C, typename F>
class StringFieldTmpl : public StringField
{
	typedef P2MHelper<C, F> AccessorHelper;
public:
	StringFieldTmpl(const Type& type, const std::string& name, const ClassType& fieldOf, typename AccessorHelper::init_type value)
		:	StringField(type, name, fieldOf), _accessorHelper(value)
	{

	}

	const Object get(const Object& obj) const
	{
		return details::FieldGetHelper<F>::apply(_accessorHelper, obj);
	}

	void set(const Object& obj, const Object& value) const
	{
		details::FieldSetByAssignmentHelper<F>::apply(*this, _accessorHelper, obj, value);
	}

private:
	AccessorHelper _accessorHelper;
};

template <typename C, typename F>
static StringField& StringField::create(F C::* p2m, const char* name)
{
	typedef typename StripCVQualifiers<F>::Result StrippedFieldType;
	return * new StringFieldTmpl<C, F>(TypeOf<StrippedFieldType>::get(), name, TypeOf<C>::get(), p2m);
}

template <typename C, typename F>
class CompositeFieldTmpl : public CompositeField
{
	typedef P2MHelper<C, F> AccessorHelper;
public:
	CompositeFieldTmpl(const Type& type, const std::string& name, const ClassType& fieldOf, typename AccessorHelper::init_type value)
		:	CompositeField(type, name,fieldOf), _accessorHelper(value)
	{

	}

	const Object get(const Object& obj) const
	{
		return details::FieldGetHelper<F>::apply(_accessorHelper, obj);
	}

	void set(const Object& obj, const Object& value) const
	{
		details::FieldSetByAssignmentHelper<F>::apply(*this, _accessorHelper, obj, value);
	}

private:
	AccessorHelper _accessorHelper;
};

template <typename C, typename F>
CompositeField& CompositeField::create(F C::* p2m, const char* name)
{
	typedef typename StripCVQualifiers<F>::Result StrippedFieldType;
	return * new CompositeFieldTmpl<C, F>(TypeOf<StrippedFieldType>::get(), name, TypeOf<C>::get(), p2m);
}

namespace details 
{

	template <typename T>
	struct SelectFieldCategory
	{
		typedef CompositeField Result;
	};

	template <>
	struct SelectFieldCategory<bool>
	{
		typedef BuiltinField Result;
	};

	template <>
	struct SelectFieldCategory<char>
	{
		typedef BuiltinField Result;
	};

	template <>
	struct SelectFieldCategory<int>
	{
		typedef BuiltinField Result;
	};

	template <>
	struct SelectFieldCategory<float>
	{
		typedef BuiltinField Result;
	};

	template <>
	struct SelectFieldCategory<double>
	{
		typedef BuiltinField Result;
	};

	template <>
	struct SelectFieldCategory<std::string>
	{
		typedef StringField Result;
	};

} // namespace details

template <typename C, typename F>
Field& createField(F C::* ptom, const char* fieldName)
{
	typedef typename StripCVQualifiers<F>::Result StrippedFieldType;
	typedef typename details::SelectFieldCategory<StrippedFieldType>::Result FieldCategory;
	return FieldCategory::create(ptom, fieldName);
}

} // namespace reflect

#endif

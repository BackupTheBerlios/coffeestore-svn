#ifndef _REFLECT_BUILTIN_TYPE_TRAITS_H_
#define _REFLECT_BUILTIN_TYPE_TRAITS_H_

namespace reflect
{

template <typename T>
class BuiltinTypeTraits
{
	template <typename U>
	struct IsBool
	{
		enum { value = false };
	};

	template <>
	struct IsBool<bool>
	{
		enum { value = true };
	};

	template <typename U>
	struct IsChar
	{
		enum { value = false };
	};

	template <>
	struct IsChar<char>
	{
		enum { value = true };
	};


	template <typename U>
	struct IsInt
	{
		enum { value = false };
	};

	template <>
	struct IsInt<int>
	{
		enum { value = true };
	};

	template <typename U>
	struct IsFloat
	{
		enum { value = false };
	};

	template <>
	struct IsFloat<float>
	{
		enum { value = true };
	};

	template <typename U>
	struct IsDouble
	{
		enum { value = false };
	};

	template <>
	struct IsDouble<double>
	{
		enum { value = true };
	};

public:
	static bool isBool()
	{
		return IsBool<T>::value;
	}

	static bool isChar()
	{
		return IsChar<T>::value;
	}

	static bool isInt()
	{
		return IsInt<T>::value;
	}

	static bool isFloat()
	{
		return IsFloat<T>::value;
	}

	static bool isDouble()
	{
		return IsDouble<T>::value;
	}
};

} // namespace reflect

#endif

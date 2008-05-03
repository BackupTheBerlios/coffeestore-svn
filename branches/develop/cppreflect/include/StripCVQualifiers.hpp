#ifndef _REFLECT_STRIP_CV_QUALIFIERS_CONST_H_
#define _REFLECT_STRIP_CV_QUALIFIERS_CONST_H_

namespace reflect
{
	template <typename T>
	struct IsConst
	{
		enum { result = false };
	};

	template <typename T>
	struct IsConst<const T>
	{
		enum { result = true };
	};

	template <typename T>
	struct StripCVQualifiers
	{
		typedef T Result;
	};

	template <typename T>
	struct StripCVQualifiers<const T>
	{
		typedef typename StripCVQualifiers<T>::Result Result;
	};

	template <typename T>
	struct StripCVQualifiers<volatile T>
	{
		typedef typename StripCVQualifiers<T>::Result Result;
	};

} // namespace reflect

#endif

#ifndef _REFLECT_SINGLETON_H_
#define _REFLECT_SINGLETON_H_

#include "NonCopyable.hpp"

namespace reflect
{

namespace details {

template <typename T>
class StaticInstance
{
public:
	static T& getInstance()
	{
		return _instance;
	}
private:
	static T _instance;
};

template <typename T>
T StaticInstance<T>::_instance;

template <typename T>
class DynamicInstance
{
public:
	static T& getInstance()
	{
		if (!_instance)
			_instance = new T;

		return *_instance;
	}
private:
	static T* _instance;
};

template <typename T>
T* DynamicInstance<T>::_instance = 0;

} // namespace details

template <typename T, typename InstancePolicy = details::DynamicInstance<T> >
class Singleton : NonCopyable, public InstancePolicy {};

} // namespace reflect 

#endif

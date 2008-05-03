#ifndef _REFLECT_MACRO_H_
#define _REFLECT_MACRO_H_

#define REFLECT_ALLOW(T) \
	friend class ClassTypeTmpl<T>;

#define REFLECT_BEGIN(T) \
	namespace reflect { \
		template <> \
		class ClassTypeTmpl<T> : public ClassType, public Singleton<ClassTypeTmpl<T>, details::StaticInstance<ClassTypeTmpl<T> > > { \
			typedef T _Type; \
		public: \
			ClassTypeTmpl() : ClassType(#T) { \
				TypeRegistry::getInstance().add(typeid(_Type), *this);

#define REFLECT_END() } }; }

#define REFLECT_FIELD(f) addField(createField(&_Type::f, #f));

#endif

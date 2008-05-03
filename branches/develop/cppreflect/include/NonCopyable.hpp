#ifndef _REFLECT_NON_COPYABLE_H_
#define _REFLECT_NON_COPYABLE_H_

namespace reflect {

//! Inherit this class if you want to disallow assignment operator and copy constructor.
class NonCopyable
{
protected:
	//! Disallow the creation of this class.
	NonCopyable();

private:
	//! Avoid the copy constructor to be called.
	NonCopyable(const NonCopyable&);

	//! Avoid the assignment operator to be called.
	NonCopyable& operator=(const NonCopyable&);
};

} // namespace reflect

#endif

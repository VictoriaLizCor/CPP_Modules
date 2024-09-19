#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include "Utils.hpp"
# ifndef DEBUG
#  define DEBUG 0
# endif

template <typename T>
void swap(T& a, T& b)
{
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
const T& max(T const& a, T const& b)
{
	return (a > b ? a : b);
}

template <typename T>
const T& min(T const& a, T const& b)
{
	return (a < b ? a : b);
}

template <typename T>
std::string checkType(T const& ax, T const& bx, T const& value)
{
	std::stringstream ss;
	ss << value;
	if (DEBUG > 1)
	{
		std::cout << "\nValue address: " << &value << std::endl;
		std::cout << "a address: " << &ax << std::endl;
		std::cout << "b address: " << &bx << std::endl;
		std::cout<< std::boolalpha;
		std::cout << "a == value: " << (&ax == &value) << std::endl;
		std::cout << "b == value: " << (&bx == &value) << std::endl;
	}
	if (&value == &ax)
		return (getColorStr(FGREEN, ss.str()));
	else if (&value == &bx)
		return (getColorStr(FYELLOW, ss.str()));
	else
		return getColorStr(FRED, ss.str()); 
}
#endif // WHATEVER_HPP
/**
 * @NOTES: 
 * - When [`a`]and [`b`] are equal ([`a == b`] the condition [`a < b`]
     evaluates to `false`.
 * - Since the condition is `false`, the ternary operator returns the
     value after the colon (`:`), which is [`b`]

 */


/**
 * @NOTES:
 * In C++, the `::` operator is known as the scope resolution
   operator. It is used to specify the scope in which a function or
   variable resides. Here are the main differences between calling a
   function with `::` and without it:

1. **Global Scope vs. Local Scope**:
   - **Without `::`**: When you call a function without the `::`
     operator, the compiler looks for the function in the current
     scope. If it doesn't find it, it will look in the enclosing
     scopes.
   - **With `::`**: When you call a function with the `::` operator,
     you are explicitly telling the compiler to look for the function
     in the global scope or a specific namespace.

2. **Namespace Resolution**:
   - **Without `::`**: The compiler will look for the function in the
     current namespace or class.
   - **With `::`**: You can specify a particular namespace or class to
     look for the function. For example, `std::max` explicitly calls
     the [`max`] function from the [`std`] namespace.

3. **Class Member Functions**:
   - **Without `::`**: When calling a member function from within the
     same class, you don't need to use the `::` operator.
   - **With `::`**: When calling a static member function or accessing
     a static member variable, you can use the
     `ClassName::functionName` syntax.



### Summary

- **Without `::`**: The function is looked up in the current scope and
  then in the enclosing scopes.
- **With `::`**: The function is looked up in the specified scope,
  which can be the global scope, a namespace, or a class.

Using the `::` operator helps in disambiguating function calls and
specifying exactly which function you want to call, especially when
there are functions with the same name in different scopes.
 * 
 */
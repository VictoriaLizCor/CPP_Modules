#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <Utils.hpp>
#include "Mix.hpp"

# ifndef DEBUG
#  define DEBUG 0
# endif

typedef unsigned int u_int;

template<typename T>
class Array
{
	private:
		T*					_array;
		u_int				_size;
		static u_int		_instanceCount;
		u_int				_instanceId;
		std::string const	_colorIdStr;

		std::string			setColorInstance(std::type_info const& type);
	public:
		explicit Array(u_int const& size = 0);
		Array<T>& operator=(Array<T> const& rhs);
		Array(Array<T> const& rhs);
		T& operator[](int index);
		T const& operator[](int index) const;
		virtual ~Array();

		u_int			size(void) const;
		std::string		getInfo(void) const;
		void			init(void);
		static void		getInstanceCount(void);
		void			display(void);
};

template<typename T>
std::ostream& operator << (std::ostream& os, Array<T>& rhs);

#include "Array.tpp"

static std::string getType(std::type_info const& type);

template <typename T>
void runTest()
{
	Array<T>::getInstanceCount();
	u_int len = static_cast<u_int>((getRandomVal<size_t>(10)));
	printTitle(getType(typeid(T)), 60, '*');
	std::cout << "size: " << len << std::endl;
	{
		Array<T> numbers(len);
		numbers.init();
		std::cout << numbers << std::endl;
		numbers.display();
		try
		{
			int idx = getRandomVal<int>(len);
			std::cout << "value in [" << idx << "]: " << numbers[idx] << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	nl(1);
}

template <typename U, typename T>
void runTestMIX()
{
	u_int len = static_cast<u_int>(getRandomVal<size_t>(10));
	printTitle(getType(typeid(MIX<U, T>)), 60, '*');
	std::cout << "size: " << len << std::endl;
	{
		Array< MIX<U, T> > numbers(len);
		std::cout << numbers << std::endl;
		numbers.display();
	}
	nl(1);
}
#endif // ARRAY_HPP

/**
 * NOTES:
 * The subscript operator `[]` in C++ is used to access elements of an
   array or a container (like `std::vector`, `std::array`, etc.) by
   their index. It allows you to read or modify the value at a
   specific position in the array or container.


In this example:
1. The [`Array`]class has a constructor that initializes the array
   with a given size.
2. The subscript operator `[]` is overloaded to provide access to the
   elements of the array.
3. The non-const version of the subscript operator allows modification
   of the elements.
4. The const version of the subscript operator allows read-only access
   to the elements.
5. The `size` method returns the size of the array.

This allows you to use the [`Array`] class with the subscript operator
just like a built-in array.
 * 
*/
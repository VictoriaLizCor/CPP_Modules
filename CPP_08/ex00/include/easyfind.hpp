#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <string>
# include <typeinfo>
# include <algorithm>
# include <stdexcept>
# include <vector>
# include <deque>
# include <list>
# include "Utils.hpp"
# include <limits>
# ifndef DEBUG
#  define DEBUG 0
# endif


static std::string getType(std::type_info const& type);

template <typename T>
typename T::iterator easyfind(T& con, int value)
{
	typename T::iterator it = std::find(con.begin(), con.end(), value);
	if (it == con.end())
		throw std::out_of_range(error("Value " + toStr(value) + " not found in container", 0));
	return it;
}

template <typename T>
void print(const T& val)
{
	std::cout << val << " ";
}

template <typename T, typename Container>
void processContainer(Container& con, T value, bool ran)
{
	nl(1);
	printTitle(getType(typeid(con)), 60, '*');
	std::size_t len = getRandomVal<std::size_t>(10);
	std::cout << "size: " << len << std::endl;
	std::cout << "to find: " << value << std::endl;
	for (size_t i = 0; ran && i < len; ++i)
			con.push_back(getRandomVal<T>(10));
	std::cout << "values : ";
	std::for_each(con.begin(), con.end(), print<T>);
	typename Container::iterator it = easyfind(con, static_cast<int>(value));
	std::cout << "\nFound value: " << *it ;
	std::cout << " at position " << std::distance( con.begin(), it ) << std::endl;
}

template <typename T>
void runTest()
{
	std::size_t containerType = getRandomVal<std::size_t>(3);
	std::list<T> listCon;
	std::vector<T> vectorCon;
	std::deque<T> dequeCon;

	try
	{
		T value = getRandomVal<T>(10);
		if (containerType == 0)
			processContainer<T>(vectorCon, value, 1);
		else if (containerType == 1)
			processContainer<T>(dequeCon, value, 1);
		else
			processContainer<T>(listCon, value, 1);
	}
	catch (const std::exception& e)
	{
		std::cerr << std::endl << e.what() << std::endl;
	}
	nl(1);
}

#endif // EASYFIND_HPP
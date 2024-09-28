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

template <typename Container>
void processContainer(Container& con, const std::string& type, int value)
{
	printTitle(type, 60, '*');
	std::for_each(con.begin(), con.end(), print<int>);
	typename Container::iterator it = easyfind(con, value);
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

	std::size_t len = getRandomVal<std::size_t>(10);
	for (size_t i = 0; i < len; ++i)
	{
		if (containerType == 0)
			vectorCon.push_back(getRandomVal<T>(10));
		else if (containerType == 1)
			dequeCon.push_back(getRandomVal<T>(10));
		else
			listCon.push_back(getRandomVal<T>(10));
	}
		
	std::cout << "size: " << len << std::endl;
	try
	{
		std::size_t value = getRandomVal<std::size_t>(10);
		if (containerType == 0)
			processContainer(vectorCon, getType(typeid(vectorCon)), value);
		else if (containerType == 1)
			processContainer(dequeCon, getType(typeid(dequeCon)), value);
		else
			processContainer(listCon, getType(typeid(listCon)), value);
		nl(1);
	}
	catch (const std::exception& e)
	{
		std::cerr << std::endl << e.what() << std::endl;
	}
	nl(1);
}

#endif // EASYFIND_HPP
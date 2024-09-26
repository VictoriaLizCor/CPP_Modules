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
# include "containers.hpp"
# include <limits>
# ifndef DEBUG
#  define DEBUG 0
# endif

static std::string getType(std::type_info const& type);

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::out_of_range("Value not found in container");
	return it;
}

template <typename T>
void print(const T& val)
{
	std::cout << val << " ";
}

template <typename T>
void runTest()
{
	typedef typename RandomContainer<T>::type RandomContainerType;
	RandomContainerType container;
	std::size_t len = RandomContainer<T>::containerSize;
	for (std::size_t i = 0; i < len; ++i)
		container.push_back(getRandomVal<T>(std::numeric_limits<T>::max()));
		
	printTitle(getType(typeid(container)), 60, '*');
	std::cout << "size: " << len << std::endl;
	try
	{
		std::for_each(container.begin(), container.end(), print<T>);
		nl(1);
		typename RandomContainerType::iterator it = easyfind(container, 3);
		std::cout << "Found value: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	nl(1);
}

#endif // EASYFIND_HPP
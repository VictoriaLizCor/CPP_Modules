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
	std::size_t index = getRandomVal<std::size_t>(3);
	std::list<T> listCon;
	std::vector<T> vectorCon;
	std::deque<T> dequeCon;

	switch (index)
	{
		case 1:
			getContainer(index, vectorCon);
			break;
		case 2:
			getContainer(index, dequeCon);
			break;
		default:
			getContainer(index, listCon);
			break;
	}
	std::size_t len = getRandomVal<std::size_t>(10);
	for (size_t i = 0; i < len; ++i)
	{
		if (index == 0)
			vectorCon.push_back(getRandomVal<T>(std::numeric_limits<T>::max()));
		else if (index == 1)
			dequeCon.push_back(getRandomVal<T>(std::numeric_limits<T>::max()));
		else
			listCon.push_back(getRandomVal<T>(std::numeric_limits<T>::max()));
	}
		
	std::cout << "size: " << len << std::endl;
	try
	{
		if (index == 0)
		{
			std::for_each(vectorCon.begin(), vectorCon.end(), print<T>);
			typename std::vector<T>::iterator it = easyfind(vectorCon, 3);
			std::cout << "Found value: " << *it << std::endl;
		}
		else if (index == 1)
		{
			std::for_each(dequeCon.begin(), dequeCon.end(), print<T>);
			typename std::deque<T>::iterator it = easyfind(dequeCon, 3);
			std::cout << "Found value: " << *it << std::endl;
		}
		else
		{
			std::for_each(listCon.begin(), listCon.end(), print<T>);
			typename  std::list<T>::iterator it = easyfind(listCon, 3);
			std::cout << "Found value: " << *it << std::endl;
		}
		nl(1);
		;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	nl(1);
}

#endif // EASYFIND_HPP
#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <Utils.hpp>
# include <utility> 

# ifndef DEBUG
#  define DEBUG 0
# endif

std::string getType(std::string type);

template <typename T>
static T getRandomNum(size_t num)
{
	static bool seeded = false;
	if (!seeded)
	{
		srand(static_cast<unsigned int>(time(0)));
		seeded = true;
	}
	if (std::is_integral<T>::value)
		return static_cast<T>(rand() % num);
	else if (std::is_floating_point<T>::value)
		return static_cast<T>(static_cast<float>(rand()) / RAND_MAX * num);
	return T();
}

template <typename T>
static std::pair<T*, size_t> createArray()
{
	std::string typeName = typeid(T).name();
	size_t len = getRandomNum<size_t>(100) + 1;
	T* array = new T[len];
	for(size_t i = 0; i < len; ++i)
	{
		if (getType(typeName) == "string")
		{
			std::stringstream ss;
			ss << getRandomNum<int>(1000);
			array[i] = ss.str();
		}
		else
			array[i] = getRandomNum<T>(1000);
	}
	return (std::make_pair(array, len));
}

template <typename T>
void iter(T* it, size_t len, void(*fun )(T&) )
{
	for(size_t i = 0; i < len; ++i )
		fun(it[i]);
	nl(1);
}

template <typename T>
void printValue(T& val)
{
	std::cout << val << " ";
}

template <typename T>
void power(T& val)
{
	std::cout << val * val << " ";
}

template <>
void power<std::string>(std::string& val)
{
	(void)val;
	std::cout << "Operation not supported for std::string" << " ";
}

template <typename T>
void sum(T& val)
{
	std::cout << val + val << " ";
}


template <typename T>
void min(T& val)
{
	static T min;
	if (min > val)
		val = min;
	std::cout << val + val << " ";
}


template <typename T>
void runTest()
{
	std::string typeName = typeid(T).name();
	printTitle(getType(typeName), 20, '*');
	std::pair<T*, size_t> intArrayPair = createArray<T>();
	T* array = intArrayPair.first;
	size_t len = intArrayPair.second;

	iter(array, len, printValue<T>);
	delete array;
	nl(2);
}


// std::ostream& operator << (std::ostream& os, iter& rhs);

#endif // ITER_HPP
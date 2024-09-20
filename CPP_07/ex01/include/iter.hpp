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
static void initSeed();

template <typename T>
struct FuncPtr
{
	typedef void(*type)(T&);
};

template <typename T>
void printValue(T& val)
{
	std::cout << val << " ";
}

template <typename T>
void power(T& val)
{
	std::cout << (val * val) << " ";
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
	std::cout << (val + val) << " ";
}

template <typename T>
void increment(T& val)
{
	val+=1;
	std::cout << val << " ";
}

template <>
void increment<std::string>(std::string& val)
{
	static std::string newVal;
	newVal+=val;
	std::cout << newVal << " ";
}

template <typename T>
void min(T& val)
{
	static T min;
	if (min > val)
		min = val;
	std::cout << min << " ";
}

template <typename T>
T getRandomVal(size_t num)
{
	initSeed();
	double randomValue = static_cast<double>(rand()) / RAND_MAX * 2 * static_cast<double>(num) - static_cast<double>(num);
	return (static_cast<T>(randomValue));

}

template <>
size_t getRandomVal<size_t>(size_t num)
{
	initSeed();
	return (static_cast<size_t>(rand()) % num);
}


template <>
std::string getRandomVal<std::string>(size_t num)
{
	std::string randomStr= "";
	size_t strLen;

	if (num > 1)
		strLen = getRandomVal<size_t>(num) + 1;
	else
		strLen = 1;
	initSeed();
	for(size_t i = 0; i < strLen; i++)
	{
		char random_char = 'a' + static_cast<char>(rand() % 26);
		randomStr += random_char;
	}
	return (randomStr);
}

template <typename T>
std::pair<T*, size_t> createArray()
{
	size_t len = getRandomVal<size_t>(20) + 1;
	T* array = new T[len];
	for(size_t i = 0; i < len; ++i)
	{
		array[i] = getRandomVal<T>(1000);
	}
	return std::make_pair(array, len);
}

template <>
std::pair<std::string*, size_t> createArray<std::string>()
{
	size_t len = getRandomVal<size_t>(20) + 1;
	std::string* array = new std::string[len];

	for(size_t i = 0; i < len; ++i)
	{
		array[i] = getRandomVal<std::string>(10);
	}
	return (std::make_pair(array, len));
}

template <>
std::pair<char*, size_t> createArray<char>()
{
	size_t len = getRandomVal<size_t>(20) + 1;
	char* array = new char[len];

	for(size_t i = 0; i < len; ++i)
	{
		array[i] = getRandomVal<std::string>(1)[0];
	}
	return (std::make_pair(array, len));
}

template <typename T>
void iter(T* it, size_t len, typename FuncPtr<T>::type fun)
// void iter(T* it, size_t len, FuncPtr<T> )
{
	for(size_t i = 0; i < len; ++i )
		fun(it[i]);
	nl(1);
}

template <typename T>
void runTest()
{
	std::string typeName = typeid(T).name();
	std::string functionName("Using function ");

	typename FuncPtr<T>::type functions[5] = {min<T>, increment<T>, sum<T>, power<T>, printValue<T>};
	size_t idx = getRandomVal<size_t>(5);
	std::pair<T*, size_t> intArrayPair = createArray<T>();
	T* array = intArrayPair.first;
	size_t len = intArrayPair.second;

	printTitle(getType(typeName), 60, '*');
	std::cout << "values:\n";
	iter(array, len, printValue<T>);
	switch (idx)
	{
		case 0: functionName += "min"; break;
		case 1: functionName += "increment"; break;
		case 2: functionName += "sum"; break;
		case 3: functionName += "power"; break;
		default: functionName += "printValue"; break;
	}
	nl(1);
	printTitle(functionName, 30, '*');
	iter(array, len, functions[idx]);
	nl(2);
	iter(array, len, increment<T>);
	delete[] array;
	nl(2);
}


// std::ostream& operator << (std::ostream& os, iter& rhs);

#endif // ITER_HPP
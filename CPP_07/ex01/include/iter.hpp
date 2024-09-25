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
	static bool status;
	(void)val;
	if(status == 0)
	{
		status = 1;
		std::cout << "Operation not supported for std::string" << " ";
	}
}

template <>
void power<char>(char& val)
{
	static bool status;
	(void)val;
	if(status == 0)
	{
		status = 1;
		std::cout << "Operation not supported for char" << " ";
	}
}

template <typename T>
void sum(T& val)
{
	static T sum;
	sum += val;
	std::cout << "\r\033[K" << "Total sum: ";
	std::cout << sum << " ";
}

template <>
void sum<char>(char& val)
{
	static bool status;
	(void)val;
	if(status == 0)
	{
		status = 1;
		std::cout << "Operation not supported for char" << " ";
	}
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
	for (size_t i =0; i < val.size(); ++i)
	{
		if (val[i] == 'z')
			val[i] = 'a';
		else
			val[i] = static_cast<char>(val[i] + 1);
		std::cout << val[i];
	}
	std::cout << " ";
}

template <>
void increment<char>(char& val)
{
	if (val == 126)
		val = 32;
	else
		val += 1;
	std::cout << val << " ";
}


template <typename T>
void min(T& val)
{
	static bool stat;
	static T min;
	if (stat == 0)
	{
		stat = 1;
		min = val;
	}
	else if (min > val)
		min = val;
	std::cout << "\r\033[K" << "Min value: ";
	std::cout << getColorFmt(FWHITE) << min << " " << C_END;
}

template <typename T>
void max(T& val)
{
	static bool stat;
	static T max;
	if (stat == 0)
	{
		stat = 1;
		max = val;
	}
	else if (max < val)
		max = val;
	std::cout << "\r\033[K" << "Max value: ";
	std::cout << getColorFmt(FWHITE) << max << " " << C_END;
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

	strLen = getRandomVal<size_t>(num) + 1;
	for(size_t i = 0; i < strLen; i++)
	{
		char random_char = 'a' + static_cast<char>(rand() % 26);
		randomStr += random_char;
	}
	return (randomStr);
}

template <>
char getRandomVal<char>(size_t num)
{
	initSeed();
	char randomValue = 32 + std::rand() % (126 - 32 + num);
	return (randomValue);
}

template <typename T>
std::pair<T*, size_t> createArray()
{
	size_t len = getRandomVal<size_t>(5) + 1;
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
	size_t len = getRandomVal<size_t>(5) + 1;
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
		array[i] = getRandomVal<char>(1);
	}
	return (std::make_pair(array, len));
}

template <typename T>
void iter(T* it, size_t len, void (*fun)(T&))
{
	for(size_t i = 0; i < len; ++i )
		fun(it[i]);
	nl(1);
}

template <typename T>
void iter(T* it, size_t len, void (*fun)(T const&))
{
	for(size_t i = 0; i < len; ++i )
		fun(it[i]);
	nl(1);
}


template <typename T>
void runTest()
{
	typedef void (*FuncPtr)(T&);
	std::string typeName = typeid(T).name();
	std::string functionName("Using function ");

	FuncPtr functions[6] = {min<T>, max<T>, increment<T>, sum<T>, power<T>, printValue<T>};
	size_t idx = getRandomVal<size_t>(6);
	std::pair<T*, size_t> intArrayPair = createArray<T>();
	T* array = intArrayPair.first;
	size_t len = intArrayPair.second;

	printTitle(getType(typeName), 60, '*');
	std::cout << "size: " << len << std::endl;
	std::cout << "values:\n";
	iter(array, len, printValue<T>);
	switch (idx)
	{
		case 0: functionName += getColorStr(FGREEN, "min"); break;
		case 1: functionName += getColorStr(FYELLOW, "max"); break;
		case 2: functionName += getColorStr(FCYAN, "increment"); break;
		case 3: functionName += getColorStr(FRED, "sum"); break;
		case 4: functionName += getColorStr(FMAGENTA, "power"); break;
		default: functionName += getColorStr(FWHITE, "printValue"); break;
	}
	nl(1);
	printTitle(functionName, 40, '*');
	iter(array, len, functions[idx]);
	delete[] array;
	nl(1);
}


// std::ostream& operator << (std::ostream& os, iter& rhs);

#endif // ITER_HPP
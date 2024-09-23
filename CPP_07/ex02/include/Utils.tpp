#ifndef UTILS_TPP
# define UTILS_TPP

# include "Utils.hpp"
# include <cstdlib>
# include <ctime>
# include <string>

# ifndef DEBUG
#  define DEBUG 0
# endif

template <typename T>
inline T getRandomVal(size_t num)
{
	initSeed();
	double randomValue = static_cast<double>(rand()) / RAND_MAX * 2 * static_cast<double>(num) - static_cast<double>(num);
	return (static_cast<T>(randomValue));

}

template <>
inline size_t getRandomVal<size_t>(size_t num)
{
	initSeed();
	return (static_cast<size_t>(rand()) % num);
}


template <>
inline std::string getRandomVal<std::string>(size_t num)
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
inline char getRandomVal<char>(size_t num)
{
	initSeed();
	num = 1;
	unsigned int randomValue = 32 + (static_cast<unsigned int>(std::rand()) % (126 - 32 + static_cast<unsigned int>(num)));

	return (static_cast<char>(randomValue));
}

#endif // TUTILS_HPP
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <cstdlib>
# include <cctype>
# include <cfloat>
# include <limits>
# include <float.h> 
# include <climits>
# include <iomanip>
# include <cmath>
# include <stdexcept>
# include <Utils.hpp>
# include <cstring>
# include <iostream>
#include <cerrno>
# include <cstdio>



# ifndef DEBUG
#  define DEBUG 0
# endif

struct EscapeSequence
{
	const char*	seq;
	char		ch;
};

class ScalarConverter
{
	private:
		ScalarConverter();
		// ScalarConverter& operator=(ScalarConverter const& rhs);
		ScalarConverter(ScalarConverter const& rhs);
		~ScalarConverter();
		// static void callHandler(long double value);
		static std::string reinterpretate(std::string const& str);

		template <typename T>
		static void callHandler(T value);

		template <typename T>
		static bool isType(long double originalValue, const std::string& type);

		template <typename T>
		static void toType(long double value, const std::string& type);
	protected:
		
	public:
		static void convert(std::string const& literal);
};


// std::ostream& operator << (std::ostream& os, ScalarConverter& rhs);

template<typename T, typename U>
struct is_same;

#include "ScalarConverter.tpp" 

#endif // SCALARCONVERTER_HPP
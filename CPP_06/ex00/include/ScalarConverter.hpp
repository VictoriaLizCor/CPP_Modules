/**
 * @file ScalarConverter.hpp
 * @author lilizarr (lilizarr@student.42wolfsburg.de)
 * @brief 
 * @version 0.1
 * @date 2024-09-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <string>
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

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter& operator=(ScalarConverter const& rhs);
		ScalarConverter(ScalarConverter const& rhs);
		~ScalarConverter();
		// static void callHandler(long double value);
		struct EscapeSequence
		{
			const char*	seq;
			char		ch;
		};

		static std::string reinterpretate(std::string const& str);

		template <typename T>
		static void callHandler(T value);

		template <typename T>
		static bool isType(long double originalValue, const std::string& type);

		template <typename T>
		static void toType(long double value, const std::string& type);
		
		template <typename T>
		static bool precisionLost(long double originalValue);

	public:
		static void convert(std::string const& literal);
};


// std::ostream& operator << (std::ostream& os, ScalarConverter& rhs);

#include "ScalarConverter.tpp" 

#endif // SCALARCONVERTER_HPP
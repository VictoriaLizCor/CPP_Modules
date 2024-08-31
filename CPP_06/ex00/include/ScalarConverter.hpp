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
# include <cmath>
# include <stdexcept>
# include <Utils.hpp>

# ifndef DEBUG
#  define DEBUG 0
# endif


enum varType
{
	INT,
	FLOAT,
	DOUBLE,
	CHAR
};

class ScalarConverter
{
	private:

		ScalarConverter();
		// ScalarConverter& operator=(ScalarConverter const& rhs);
		ScalarConverter(ScalarConverter const& rhs);
		~ScalarConverter();

		static void printChar(long double c);
		static void printInt(long double i);
		static void printFloat(long double f);
		static void printDouble(long double d);
		static void printAll(long double value);
		 static bool isChar(const std::string& literal);
		static bool isInt(const std::string& literal);
		static bool isFloat(const std::string& literal);
		static bool isDouble(const std::string& literal);
		std::string classify(double value);
	protected:
		
	public:
		static void convert(std::string const& literal);
		template <typename T>
		static varType determineType(T value);
};


// std::ostream& operator << (std::ostream& os, ScalarConverter& rhs);


#include "ScalarConverter.tpp" 

#endif // SCALARCONVERTER_HPP
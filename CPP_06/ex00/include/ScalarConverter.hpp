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
# include <cmath>
# include <Utils.hpp>

# ifndef DEBUG
#  define DEBUG 0
# endif

#define FLOAT_MIN		-std::numeric_limits<float>::max()
#define FLOAT_UNDERFLOW std::numeric_limits<float>::min()
#define FLOAT_MAX		std::numeric_limits<float>::max()

#define DOUBLE_MIN		-std::numeric_limits<double>::max()
#define DOUBLE_UNDERFLOW std::numeric_limits<double>::min()
#define DOUBLE_MAX		std::numeric_limits<double>::max()


class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter& operator=(ScalarConverter const& rhs);
		ScalarConverter(ScalarConverter const& rhs);
		~ScalarConverter();

		static void printChar(char c);
		static void printInt(int i);
		static void printFloat(float f);
		static void printDouble(double d);
	protected:
		
	public:
		static void convert(std::string const& literal);
};

std::ostream& operator << (std::ostream& os, ScalarConverter& rhs);

#endif // SCALARCONVERTER_HPP
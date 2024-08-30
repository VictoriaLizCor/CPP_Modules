#include "ScalarConverter.hpp"

void ScalarConverter::printChar(char c)
{
	if (std::isprint(c))
	{
		std::cout << "char: '" << c << "'" << std::endl;
	} else {
		std::cout << "char: Non displayable" << std::endl;
	}
}

void ScalarConverter::printInt(int i)
{
	std::cout << "int: " << i << std::endl;
}

void ScalarConverter::printFloat(float f)
{
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double d)
{
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "double: " << d << std::endl;
}

void classifyFloat(float value)
{
	switch (std::fpclassify(value)) {
		case FP_INFINITE:
			std::cout << "Value is infinite" << std::endl;
			break;
		case FP_NAN:
			std::cout << "Value is NaN" << std::endl;
			break;
		case FP_NORMAL:
			std::cout << "Value is normal" << std::endl;
			break;
		case FP_SUBNORMAL:
			std::cout << "Value is subnormal" << std::endl;
			break;
		case FP_ZERO:
			std::cout << "Value is zero" << std::endl;
			break;
		default:
			std::cout << "Unknown classification" << std::endl;
			break;
	}
}

void ScalarConverter::convert(std::string const &literal)
{
	try
	{
		// Try to detect and convert to char
		if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
		{
			char c = literal[0];
			printChar(c);
			printInt(static_cast<int>(c));
			printFloat(static_cast<float>(c));
			printDouble(static_cast<double>(c));
			return;
		}

		int i = std::atoi(literal.c_str());
		std::stringstream ss;
		ss << i;
		if (ss.str() == literal)
		{
			printChar(static_cast<char>(i));
			printInt(i);
			printFloat(static_cast<float>(i));
			printDouble(static_cast<double>(i));
			return;
		}

		// Try to detect and convert to float
		if (literal[literal.size() - 1] == 'f')
		{
			float f = std::strtof(literal.c_str(), NULL);
			printChar(static_cast<char>(f));
			printInt(static_cast<int>(f));
			printFloat(f);
			printDouble(static_cast<double>(f));
			return;
		}

		// Try to detect and convert to double
		double d = std::strtod(literal.c_str(), NULL);
		printChar(static_cast<char>(d));
		printInt(static_cast<int>(d));
		printFloat(static_cast<float>(d));
		printDouble(d);
	} catch (...)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}

/*
how can i use ostream operator if i dont save any value in ScalarConverter class I want to do something like
```
void ScalarConverter::printFloat(double f)
{
	std::cout << f;
}

void ScalarConverter::convert(std::string const &literal)
{
	try
	{
		std::ostream x; 
		double d = std::strtod(literal.c_str(), NULL);
		x << *this << d;

}
std::ostream& operator << (std::ostream& os, ScalarConverter& rhs)
{
	std::ostream o = std::cout;
	o << "char:" << os.str());
	o << "int:" << os;
	o << "float:" << rhs.printFloat(o);
	o << "double:" << rhs.printDouble(o);
	return (o);
};

*/
#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter(){};

void ScalarConverter::printChar(long double value)
{
	if (value < CHAR_MIN || value > CHAR_MAX || std::isnan(value))
			std::cout << "char: impossible" << std::endl;
	else
	{
		char c = static_cast<char>(value);
		std::cout << std::fixed  << std::setprecision(1) << std::endl;
		if (std::isprint(c))
		{
			std::cout << "char: '" << c << "'" << std::endl;
		}
		else
		{
			std::cout << "char: Non displayable" << std::endl;
		}
	}
}

void ScalarConverter::printInt(long double value)
{
	if (value < INT_MIN || value > INT_MAX || std::isnan(value))
		std::cout << "int: impossible" << std::endl;
	else
	{
		int i = static_cast<int>(value);
		std::cout << "int: " << i << std::endl;
	}
}

void ScalarConverter::printFloat(long double f)
{
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;
}

void ScalarConverter::printDouble(long double d)
{
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::printAll(long double value)
{
	printChar(value);
	printInt(static_cast<int>(value));
	printFloat(static_cast<float>(value));
	printDouble(value);
}
void ScalarConverter::convert(std::string const &literal)
{
	try
	{
		double value;
		std::stringstream ss(literal);

		std::cout << "\nstr: " << ss.str() << std::endl;
		ss >> value;
		// if (ss.fail() || !ss.eof())
		// {
		// 	char* end;
		// 	value = std::strtod(literal.c_str(), &end);
		// 	std::cout << "vale" << value << "|" << *end << std::endl;
		// 	if (*end != '\0' && *end != 'f' )
		// 		throw (std::invalid_argument(""));
		// }
		if (isChar(literal))
		{
			double c = literal[0];
			printAll(c);
		}
		else if (isInt(literal))
		{
			int i = std::atoi(literal.c_str());
			printAll(static_cast<double>(i));
		}
		else if (isFloat(literal))
		{
			float f = std::strtof(literal.c_str(), NULL);
			printAll(static_cast<double>(f));
		}
		else if (isDouble(literal))
		{
			double d = std::strtod(literal.c_str(), NULL);
			printAll(d);
		}

	}
	catch (...)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}

bool ScalarConverter::isChar(const std::string& literal)
{
	return literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]);
}

bool ScalarConverter::isInt(const std::string& literal)
{
	char* end;
	long val = std::strtol(literal.c_str(), &end, 10);
	return *end == '\0' && val >= INT_MIN && val <= INT_MAX;
}

bool ScalarConverter::isFloat(const std::string& literal)
{
	char* end;
	float val = std::strtof(literal.c_str(), &end);
	std::cout << "is float" << std::endl;
	return *end == 'f' && *(end + 1) == '\0';
}

bool ScalarConverter::isDouble(const std::string& literal)
{
	char* end;
	std::strtod(literal.c_str(), &end);
	return *end == '\0';
}
// template ScalarConverter::varType ScalarConverter::determineType<int>(int);
// template ScalarConverter::varType ScalarConverter::determineType<float>(float);
// template ScalarConverter::varType ScalarConverter::determineType<double>(double);
// template ScalarConverter::varType ScalarConverter::determineType<char>(char);

// 		Try to detect and convert to char

// 		if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
// 		//
// 		{
// 			double c = literal[0];
// 			printChar(c);
// 			printInt(static_cast<int>(c));
// 			printFloat(static_cast<float>(c));
// 			printDouble(static_cast<double>(c));
// 			return;
// 		}

// 		int i = std::atoi(literal.c_str());
// 		std::stringstream ss;
// 		ss << i;
// 		if (ss.str() == literal)
// 		//
// 		{
// 			printChar(static_cast<char>(i));
// 			printInt(i);
// 			printFloat(static_cast<float>(i));
// 			printDouble(static_cast<double>(i));
// 			return;
// 		}

// 		Try to detect and convert to float
// 		if (literal[literal.size() - 1] == 'f')
// 		//
// 		{
// 			float f = std::strtof(literal.c_str(), NULL);
// 			printChar(static_cast<char>(f));
// 			printInt(static_cast<int>(f));
// 			printFloat(f);
// 			printDouble(static_cast<double>(f));
// 			return;
// 		}

// 		Try to detect and convert to double
// 		double d = std::strtod(literal.c_str(), NULL);
// 		printChar(static_cast<char>(d));
// 		printInt(static_cast<int>(d));
// 		printFloat(static_cast<float>(d));
// 		printDouble(d);
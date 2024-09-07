#ifndef SCALARCONVERTER_TPP
#define SCALARCONVERTER_TPP

#include "ScalarConverter.hpp"
#include <cstdlib> 

template<typename T, typename U>
struct is_same
{
	static const bool value = false;
};

template<typename T>
struct is_same<T, T>
{
	static const bool value = true;
};

template <typename T>
bool isType(long double originalValue, std::string const& type)
{

	T newValue = static_cast<T>(originalValue);
	long double recasting = static_cast<long double>(newValue);
	if (DEBUG == 10)
	{
		printTitle(type, 30);
		std::cout << getColorFmt(FLYELLOW);
		std::cout << "Compare\nOriginal: " << originalValue  << std::endl;
		std::cout << "New: " << newValue  << std::endl;
		std::cout << "Recasted: " << recasting  << std::endl;
		std::cout << "is equal?:" << std::boolalpha << (originalValue == recasting) << std::endl;
		std::cout << C_END  << std::endl;
		
	}

	return (originalValue == recasting);
}

// template <typename T>
// void toChar(T value)
// {
// 	std::cout << std::setw(5) << "char: ";
// 	if (value < CHAR_MIN || value > CHAR_MAX || std::isnan(value))
// 		std::cout << "impossible" << std::endl;
// 	else if (std::isprint(static_cast<char>(value)))
// 		std::cout << static_cast<char>(value) << std::endl;
// 	else
// 		std::cout << "Non displayable" << std::endl;
// }

// template <typename T>
// void toInt(T value)
// {
// 	std::cout << std::setw(5) << "int: ";
// 	if (static_cast<double>(value) >=  static_cast<double>(INT_MIN) && 
// 	static_cast<double>(value)  <= static_cast<double>(INT_MAX))
// 		std::cout << static_cast<int>(value) << std::endl;
// 	else
// 		std::cout << "impossible" << std::endl;
// }

// template <typename T>
// void toFloat(T value)
// {
	
// 	std::cout << std::setw(5) << "float: ";
// 	if (value >= F_MIN && value <= F_MAX)
// 	{
// 		float floatValue = static_cast<float>(value);
// 		if (std::fabs(value - floatValue) < F_EPS * std::fabs(value))
// 			std::cout << floatValue << "f" << std::endl;
// 		else
// 			std::cout << "impossible" << std::endl;
// 	}
// 	else
// 		std::cout << "impossible" << std::endl;
// }

template <typename T>
void toType(long double value, std::string const& type)
{
	long double max;
	long double min;
	if (isType<char>(value, "CHAR") && isascii(static_cast<char>(value)))
	{
		max = CHAR_MAX;
		min = 0;
	}
	else
	{
		max = std::numeric_limits<T>::max();
		min = -std::numeric_limits<T>::min();
	}
	std::cout << min << " | " << max << std::endl;
	if (type == "float" || type == "double")
		std::cout << std::fixed << std::setprecision(1);
	std::cout << std::setw(6) << type << ": ";
	if (value >= min && value <= max)
	{
		if (isType<char>(value, "CHAR") && !std::isprint(static_cast<char>(value)))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << static_cast<T>(value) << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
}

// void printAll(long double  value)
// {
// 	std::cout << std::fixed << std::setprecision(10);
// 	toType<char>(value, "char");
// 	toType<int>(value, "int");
// 	toType<float>(value, "float");
// 	toType<double>(value, "double");
// }

template <typename T>
void callHandler(const std::string& literal)
{
	T value;
	std::stringstream ss(literal);
	ss >> value;
	// if (is_same<T, char>::value)
	// 	value = literal[0];
	// else if (is_same<T, int>::value)
	// {
	// 	long newValue;
	// 	newValue = std::strtol(literal.c_str(), NULL, 10);
	// 	printAll(newValue);
	// 	return ;
	// }
	// else if (is_same<T, float>::value)
	// 	value = std::strtof(literal.c_str(), NULL);
	// else if (is_same<T, double>::value)
	// 	value = std::strtod(literal.c_str(), NULL);
	if (ss.fail())
	{
		long double newValue;
		ss >> newValue;
	}
	std::cout << std::fixed << std::setprecision(10);
	toType<char>(value, "char");
	toType<int>(value, "int");
	toType<float>(value, "float");
	toType<double>(value, "double");
}


#endif // SCALARCONVERTER_TPP
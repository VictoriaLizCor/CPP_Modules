#ifndef SCALARCONVERTER_TPP
#define SCALARCONVERTER_TPP

#include "ScalarConverter.hpp"
// #include <cstdlib> 


template <typename T>
long double customRound(long double value)
{
	// long double decimals = std::numeric_limits<T>::digits10 * 10;
	long double decimals = 1 * 10;
	long double scaledValue = value * decimals;

	long double  roundedValue;
	if (value >= 0.0)
		roundedValue = std::floor(scaledValue + 0.5);
	else
		roundedValue = std::ceil(scaledValue - 0.5);
	return (roundedValue / decimals);
}

template <typename T>
static void setLimits(long double& min, long double& max, std::string const& type)
{
	max = std::numeric_limits<T>::max();
	min = -(std::numeric_limits<T>::max() + 1);
	if (type == "char")
		min = 0;
	if (DEBUG > 3)
	{
		std::cout << "min: " << min << std::endl;
		std::cout << "max: " << max << std::endl;
	}
}

template <typename T>
bool ScalarConverter::isType(long double originalValue, std::string const& type)
{
	T newValue = static_cast<T>(originalValue);
	long double recasting = static_cast<long double>(newValue);
	if (DEBUG >= 2)
	{
		printTitle(type, 30);
		std::cout << getColorFmt(FLYELLOW);
		std::cout << std::fixed << std::setprecision(std::numeric_limits<T>::digits10);
		std::cout << "Original: " << originalValue  << std::endl;
		std::cout << "New: " << newValue  << std::endl;
		std::cout << "Recasted: " << recasting  << std::endl;
		std::cout << "Original: " << customRound<T>(originalValue)  << std::endl;
		std::cout << "New: " << customRound<T>(newValue) << std::endl;
		std::cout << "Recasted: " <<  customRound<T>(newValue) << std::endl;
		std::cout << "original == recasted?:" << std::boolalpha << (customRound<T>(originalValue) == customRound<T>(recasting)) << std::endl;
		std::cout << C_END;
	}
	if ((std::isnan(originalValue) || std::isinf(originalValue)) && (type == "double" || type == "float"))
		return (true);
	return (customRound<T>(originalValue) == customRound<T>(recasting));
}

template <typename T>
bool ScalarConverter::precisionLost(long double originalValue)
{
	T newValue = static_cast<T>(originalValue);
	long double recasting = static_cast<long double>(newValue);
	if ((std::isnan(originalValue) || std::isinf(originalValue)))
		return (false);
	return (customRound<T>(originalValue) != customRound<T>(recasting));
}

template <typename T>
void ScalarConverter::toType(long double value, std::string const& type)
{
	long double max;
	long double min;
	bool notPossible = true;
	const bool isFloatOrDouble = (type == "float" || type == "double");
	setLimits<T>(min, max, type);
	std::cout << getColorFmt(FWHITE) << std::setw(6) << type << ": " << C_END;
	if (isFloatOrDouble)
	{
		std::cout << std::fixed << std::setprecision(1);
		if (DEBUG)
			std::cout << std::fixed << std::setprecision(std::numeric_limits<T>::digits10);
	}
	if ((value >= min && value <= max) || (isFloatOrDouble && (std::isnan(value) || std::isinf(value))))
	{
		if (type == "char" && !std::isprint(static_cast<char>(value)))
			std::cout << getColorStr(FYELLOW, "Non displayable");
		else if (isFloatOrDouble && precisionLost<T>(value))
			std::cout << getColorFmt(FYELLOW) << static_cast<T>(value);
		else
		{
			if (type == "char")
				std::cout << getColorFmt(FGREEN) << "'" << static_cast<T>(value) << "'";
			else
				std::cout << getColorFmt(FGREEN) << static_cast<T>(value);
		}
		if (type == "float")
			std::cout << "f";
		notPossible = false;
		std::cout << C_END;
	}

	if (notPossible)
		std::cout << getColorStr(FRED, "impossible");

	std::cout << std::endl;
}

template <typename T>
void ScalarConverter::callHandler(T value)
{
	toType<char>(value, "char");
	toType<int>(value, "int");
	toType<float>(value, "float");
	toType<double>(value, "double");
}

#endif // SCALARCONVERTER_TPP
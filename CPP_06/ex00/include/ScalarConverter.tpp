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
long double customRound(long double value)
{
	long double decimals = std::numeric_limits<T>::digits10 * 10;
	long double scaledValue = value * decimals;

	long double  roundedValue;
	if (value >= 0.0)
		roundedValue = std::floor(scaledValue + 0.5);
	else
		roundedValue = std::ceil(scaledValue - 0.5);
	return (roundedValue / decimals);
}

template <typename T>
bool ScalarConverter::isType(long double originalValue, std::string const& type)
{
	T newValue = static_cast<T>(originalValue);
	long double recasting = static_cast<long double>(newValue);
	if (DEBUG > 0)
	{
		printTitle(type, 30);
		std::cout << getColorFmt(FLYELLOW);
		std::cout << std::fixed << std::setprecision(20);
		std::cout << "Original: " << originalValue  << std::endl;
		std::cout << "New: " << newValue  << std::endl;
		std::cout << "Recasted: " << recasting  << std::endl;
		std::cout << "Original: " << customRound<T>(originalValue)  << std::endl;
		std::cout << "New: " << customRound<T>(newValue) << std::endl;
		std::cout << "Recasted: " <<  customRound<T>(newValue) << std::endl;
		std::cout << "original == recasted?:" << std::boolalpha << (customRound<T>(originalValue) == customRound<T>(recasting)) << std::endl;

		long double max = std::numeric_limits<T>::max();
		long double min = -(std::numeric_limits<T>::max() + 1);
		std::cout << "min: " << min << std::endl;
		std::cout << "max: " << max << std::endl;
		std::cout << C_END  << std::endl;
		
	}
	if ((std::isnan(originalValue) || std::isinf(originalValue)) && (type == "double" || type == "float"))
		return (true);
	return (customRound<T>(originalValue) == customRound<T>(recasting));
}

template <typename T>
bool detectPrecisionIssues(T originalValue)
{
	long double newValue = static_cast<long double>(originalValue);
	T recasting = static_cast<T>(newValue);
	long double epsilon = std::numeric_limits<T>::epsilon();

	if (DEBUG > 0)
	{
		std::cout << getColorFmt(FLYELLOW);
		std::cout << std::fixed << std::setprecision(20);
		std::cout << "Original: " << originalValue << std::endl;
		std::cout << "New: " << newValue << std::endl;
		std::cout << "Recasted: " << recasting << std::endl;
		std::cout << "Original: " << customRound<T>(originalValue) << std::endl;
		std::cout << "New: " << customRound<T>(newValue) << std::endl;
		std::cout << "Recasted: " << customRound<T>(recasting) << std::endl;
		std::cout << "original == recasted?:" << std::boolalpha << (std::abs(customRound<T>(originalValue) - customRound<T>(recasting)) < epsilon) << std::endl;
		std::cout << C_END << std::endl;
	}

	if (std::isnan(originalValue) || std::isinf(originalValue))
		return (true);

	return (std::abs(customRound<T>(originalValue) - customRound<T>(recasting)) >= epsilon);
}
template <typename T>
void ScalarConverter::toType(long double value, std::string const& type)
{
	long double max;
	long double min;

	max = std::numeric_limits<T>::max();
	min = -(std::numeric_limits<T>::max() + 1);
	std::cout << getColorFmt(FWHITE)<< std::setw(6) << type << ": " << C_END;
	if (type == "float" || type == "double")
	{
		int decimals = std::numeric_limits<T>::digits10;
		std::cout << std::fixed << std::setprecision(decimals);
	}
	if ((value >= min && value <= max) || (((type == "float" || type == "double") && (std::isnan(value) || std::isinf(value)))))
	{
		if (type == "char" && !std::isprint(static_cast<char>(value)))
			std::cout << getColorStr(FYELLOW, "Non displayable");
		else if ((type == "float" || type == "double") && detectPrecisionIssues(value))
			std::cout << getColorFmt(FYELLOW) << static_cast<T>(value);
		else
			std::cout << getColorFmt(FGREEN) << static_cast<T>(value);
		if (type == "float")
			std::cout << "f";
		std::cout << C_END << std::endl;
	}
	else
		std::cout << getColorStr(FRED,"impossible") << std::endl;
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
#ifndef SCALARCONVERTER_TPP
#define SCALARCONVERTER_TPP

#include "ScalarConverter.hpp"
// #include <cstdlib> 


/**
 * @brief Rounds a given long double value to the nearest integer
 * value.
 *
 * This function takes a long double value and rounds it to the
 * nearest integer value using a custom rounding mechanism. The
 * rounding is performed by scaling the value, applying floor or ceil
 * operations based on the sign of the value, and then scaling it
 * back.
 *
 * @tparam T The type used to determine the number of decimal places
 * for scaling.
 * @param value The long double value to be rounded.
 * @return The rounded long double value.
 */
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

/**
 * @brief Sets the minimum and maximum limits for a given type.
 *
 * This function sets the minimum and maximum limits for a specified
 * type T. The limits are stored in the provided references `min` and
 * `max`. If the type is "char", the minimum limit is set to 0. If the
 * DEBUG level is greater than 3, the function will print the limits
 * to the console.
 *
 * @tparam T The type for which the limits are being set.
 * @param min Reference to store the minimum limit.
 * @param max Reference to store the maximum limit.
 * @param type A string representing the type for special handling
 * (e.g., "char").
 */
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

/**
 * @brief Checks if the original value can be accurately represented
 * as the specified type.
 *
 * This function attempts to cast the original long double value to
 * the specified type T, then recasts it back to a long double to
 * check if the value remains the same after the round-trip
 * conversion. If the DEBUG level is set to 2 or higher, it will print
 * detailed information about the conversion process.
 *
 * @tparam T The type to which the original value will be cast.
 * @param originalValue The original long double value to be checked.
 * @param type A string representing the type name (e.g., "double",
 * "float").
 * @return true if the original value can be accurately represented as
 *         the specified type, false otherwise.
 */
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

/**
 * @brief Checks if precision is lost when converting a long double to
 * a specified type.
 *
 * This function takes an original long double value and converts it
 * to a specified type T. It then converts the value back to a long
 * double and compares the rounded values to determine if any
 * precision was lost during the conversion.
 *
 * @tparam T The type to which the original value will be converted.
 * @param originalValue The original long double value to be checked
 * for precision loss.
 * @return true if precision is lost during the conversion, false
 * otherwise.
 */
template <typename T>
bool ScalarConverter::precisionLost(long double originalValue)
{
	T newValue = static_cast<T>(originalValue);
	long double recasting = static_cast<long double>(newValue);
	if ((std::isnan(originalValue) || std::isinf(originalValue)))
		return (false);
	return (customRound<T>(originalValue) != customRound<T>(recasting));
}

/**
 * @brief Converts a given long double value to a specified type and
 * prints the result.
 *
 * This function attempts to convert the provided long double value to
 * the type specified by the string parameter `type`. It handles
 * conversions to various types including "char", "float", and
 * "double". The function also ensures that the value is within the
 * limits of the target type and handles special cases such as
 * non-displayable characters, precision loss, and special
 * floating-point values (NaN, infinity).
 *
 * @tparam T The target type to which the value will be converted.
 * @param value The long double value to be converted.
 * @param type A string representing the target type ("char", "float",
 * "double", etc.).
 */
template <typename T>
void ScalarConverter::toType(long double value, std::string const& type)
{
	long double max;
	long double min;
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
		{
			std::cout << getColorStr(FYELLOW, "Non displayable") << std::endl;
			return ;
		}
		else if (isFloatOrDouble && precisionLost<T>(value))
		{
			std::cout << getColorFmt(FYELLOW) << static_cast<T>(value) << std::endl;
			return ;
		}
		if (type == "char")
			std::cout << getColorFmt(FGREEN) << "'" << static_cast<T>(value) << "'";
		else
			std::cout << getColorFmt(FGREEN) << static_cast<T>(value);
		if (type == "float")
			std::cout << "f";
		std::cout << C_END << std::endl;
		return ;
	}
	std::cout << getColorStr(FRED, "impossible") << std::endl;
}

/**
 * @brief Converts the given value to multiple scalar types.
 *
 * This template function takes a value of any type and converts it to
 * char, int, float, and double types by calling the toType function
 * for each respective type.
 *
 * @tparam T The type of the input value.
 * @param value The value to be converted to different scalar types.
 */
template <typename T>
void ScalarConverter::callHandler(T value)
{
	toType<char>(value, "char");
	toType<int>(value, "int");
	toType<float>(value, "float");
	toType<double>(value, "double");
}

#endif // SCALARCONVERTER_TPP
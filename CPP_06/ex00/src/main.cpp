#include "ScalarConverter.hpp"
#include "Utils.hpp"
#include <iostream>

static std::string toFloat(float f)
{
	std::stringstream ss;
	ss << f << "f";
	return (ss.str());
}

static std::string toDouble(double f)
{
	std::stringstream ss;
	ss << f;
	return (ss.str());
}

static void deepTest(void)
{
	ScalarConverter::convert("'!'");
	ScalarConverter::convert("'1'");
	ScalarConverter::convert("'\\'");
	ScalarConverter::convert("1");
	ScalarConverter::convert(" ");
	ScalarConverter::convert("\\");
	ScalarConverter::convert("a");
	ScalarConverter::convert("Z");
	ScalarConverter::convert("");
	ScalarConverter::convert("''");
	ScalarConverter::convert("'ab'");
	ScalarConverter::convert("''''");

	ScalarConverter::convert("123");
	ScalarConverter::convert("-123");
	ScalarConverter::convert("0");
	ScalarConverter::convert("2147483647");
	ScalarConverter::convert("-2147483648");
	ScalarConverter::convert("2147483648");
	ScalarConverter::convert("-2147483649");
	ScalarConverter::convert("");
	ScalarConverter::convert("hi");
	ScalarConverter::convert("-1.23");
	ScalarConverter::convert("0.f");
	ScalarConverter::convert("0.0");
	ScalarConverter::convert("--0");
	ScalarConverter::convert("nan");

	ScalarConverter::convert("0F");
	ScalarConverter::convert("1.23f");
	ScalarConverter::convert("nanf");
	ScalarConverter::convert("inff");
	ScalarConverter::convert("+inff");
	ScalarConverter::convert("-inff");
	ScalarConverter::convert("0.0f");
	ScalarConverter::convert("-.5f");
	ScalarConverter::convert("1.0e-4f");
	ScalarConverter::convert("-1-f");
	ScalarConverter::convert("10e5ef");
	ScalarConverter::convert("e1f");
	ScalarConverter::convert("nan");
	ScalarConverter::convert("1.2.3f");
	ScalarConverter::convert("1.23ff");
	ScalarConverter::convert("abcf");
	ScalarConverter::convert("");
	ScalarConverter::convert("f");

	ScalarConverter::convert("0");
	ScalarConverter::convert("1.23");
	ScalarConverter::convert("nan");
	ScalarConverter::convert("inf");
	ScalarConverter::convert("+inf");
	ScalarConverter::convert("-inf");
	ScalarConverter::convert("0.0");
	ScalarConverter::convert("-.5");
	ScalarConverter::convert("1.0e-4");
	ScalarConverter::convert("3.14");
	ScalarConverter::convert("+0.0");
	ScalarConverter::convert("12345.6789");
	ScalarConverter::convert("1.0e-6");
	ScalarConverter::convert("-1.23");
	ScalarConverter::convert("1e10");
	ScalarConverter::convert("1");
	ScalarConverter::convert("-inf");
	ScalarConverter::convert("3.14f");
	ScalarConverter::convert("1ff");
	ScalarConverter::convert("1.23.4f");
	ScalarConverter::convert("-inff");
	ScalarConverter::convert("nanf");
	ScalarConverter::convert("");
	ScalarConverter::convert("1a2.34f");
	ScalarConverter::convert("1.23.4f");
	ScalarConverter::convert("4.3f5");

	std::cout << getColorStr(FGREEN, "All tests passed!") << std::endl;
}


template <typename T>
bool isType(double originalValue)
{
	T newValue = static_cast<T>(originalValue);
	double recasting = static_cast<double>(newValue);
	std::cout << "Compare(Original | ): " << originalValue << " | "
	<< newValue << "|" << (originalValue != recasting) << std::endl;
	return (originalValue == recasting);
}
// Custom type traits for C++98
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
void printAll(T value)
{
	std::cout << "char: ";
	if (value < CHAR_MIN || value > CHAR_MAX || std::isnan(value))
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(static_cast<char>(value)))
		std::cout << static_cast<char>(value) << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	std::cout << "int: ";
	if (value >= INT_MIN && value <= INT_MAX)
		std::cout << static_cast<int>(value) << std::endl;
	else
		std::cout << "impossible" << std::endl;

	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

template <typename T>
void callHandler(const std::string& literal)
{
	T value;
	if (is_same<T, char>::value)
	{
		std::cout << "char: " << std::endl;
		value = literal[0];
	}
	else if (is_same<T, int>::value)
	{
		std::cout << "int: " << std::endl;
		value = std::strtol(literal.c_str(), NULL, 10);
	}
	else if (is_same<T, float>::value)
	{
		std::cout << "float: " << std::endl;
		value = std::strtof(literal.c_str(), NULL);
	}
	else if (is_same<T, double>::value)
	{
		std::cout << "double: " << std::endl;
		value = std::strtod(literal.c_str(), NULL);
	}
	printAll(value);
}


// Function to determine the type and call the appropriate handler
void handleLiteral(const std::string& literal)
{
	try
	{
		double value;
		if (literal.length() == 1)
			value = literal[0];
		else
		{
			char* end;
			value = std::strtod(literal.c_str(), &end);
			std::cout << "char end: " << *end << " | ";
			if (*end != '\0' && *end != 'f' )
				throw (std::invalid_argument(""));
		}
		std::cout << "value:" << value << std::endl;
		if (isType<char>(value))
			callHandler<char>(literal);
		else if (isType<int>(value))
			callHandler<int>(literal);
		else if (isType<int>(value))
			callHandler<float>(literal);
		else
			callHandler<double>(literal);
	}
	catch (...)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}
	// if (literal.length() == 1 && !std::isdigit(literal[0]))
	// {
	// 	char value = literal[0];
	// 	printAll<char>(value);
	// }
	// else {
	// 	char* end;
	// 	long intVal = std::strtol(literal.c_str(), &end, 10);
	// 	if (*end == '\0' && intVal >= INT_MIN && intVal <= INT_MAX)
	// 	{
	// 		int value = callHandler<int>(literal);
	// 		printAll(value);
	// 	}
	// 	else {
	// 		float floatVal = std::strtof(literal.c_str(), &end);
	// 		if (*end == 'f' && *(end + 1) == '\0')
	// 		{
	// 			float value = callHandler<float>(literal);
	// 			printAll(value);
	// 		}
	// 		else {
	// 			double doubleVal = std::strtod(literal.c_str(), &end);
	// 			if (*end == '\0')
	// 			{
	// 				double value = callHandler<double>(literal);
	// 				printAll(value);
	// 			}
	// 			else {
	// 				std::cout << "char: impossible" << std::endl;
	// 				std::cout << "int: impossible" << std::endl;
	// 				std::cout << "float: impossible" << std::endl;
	// 				std::cout << "double: impossible" << std::endl;
	// 			}
	// 		}
	// 	}
	// }
// }

std::string reinterpretate(const std::string& str)
{
	std::string result = str;
	struct EscapeSequence
	{
		const char* seq;
		char ch;
	};

	EscapeSequence escapeSequences[] = {
		{"\\n", '\n'},
		{"\\t", '\t'},
		{"\\r", '\r'},
		{"\\0", '\0'},
		{"\\b", '\b'},
		{"\\e", '\x1B'}, // \x1B is the escape character
		{"\\a", '\a'},   // Alert (bell)
		{"\\f", '\f'},   // Form feed
		{"\\v", '\v'}	// Vertical tab
	};

	for (int i = 0; i < sizeof(escapeSequences) / sizeof(EscapeSequence); ++i) {
		size_t pos = 0;
		while ((pos = result.find(escapeSequences[i].seq, pos)) != std::string::npos) {
			result.replace(pos, 2, 1, escapeSequences[i].ch);
			pos += 1; // Move past the replaced character
		}
	}

	return (result);
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::ostringstream ss;
		ss << "Usage: " << argv[0] << " <literal>" << std::endl;
		std::cerr << error(ss.str(), 0);
		return (1);
	}
	if (DEBUG == 0)
	{
		handleLiteral(reinterpretate(argv[1]));
		// // Example with a string
		// std::string str = "123.45";
		// ScalarConverter::convert(str);

		// // Example with an invalid string
		// std::string invalidStr = "abc";
		// ScalarConverter::convert(invalidStr);
		// ScalarConverter::convert(argv[1]);
		// ScalarConverter::convert(argv[1]);
	}
	else
	{
		std::cout.precision(10);
		double value = 0;
		{
			value = std::numeric_limits<double>::infinity();
			if (isType<double>(value))
				std::cout << "Overflow detected!" << std::endl;
			else 
				std::cout << "No overflow." << std::endl;
			printTitle("LINE", 30);
		}
		{
			if (isType<char>(32))
				std::cout << "Overflow detected!" << std::endl;
			else 
				std::cout << "No overflow." << std::endl;
			printTitle("LINE", 30);
		}
		// deepTest();
	}
	return (0);
}

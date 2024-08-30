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
	ScalarConverter::convert(toFloat(FLOAT_MAX / 1.0001f));
	ScalarConverter::convert(toFloat(FLOAT_MIN / 1.0001f));
	ScalarConverter::convert(toFloat(FLOAT_UNDERFLOW * 1.0001f));
	ScalarConverter::convert(toFloat(FLOAT_MAX * 1.0001f));
	ScalarConverter::convert(toFloat(FLOAT_MIN * 1.0001f));
	ScalarConverter::convert(toFloat(FLOAT_UNDERFLOW / 1.0001f));
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
	ScalarConverter::convert(toDouble(DOUBLE_MAX / 1.0001));
	ScalarConverter::convert(toDouble(DOUBLE_MIN / 1.0001));
	ScalarConverter::convert(toDouble(DOUBLE_UNDERFLOW * 1.0001));
	ScalarConverter::convert(toDouble(DOUBLE_MAX * 1.0001));
	ScalarConverter::convert(toDouble(DOUBLE_MIN * 1.0001));
	ScalarConverter::convert(toDouble(DOUBLE_UNDERFLOW / 1.0001));
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


bool isOverflowing(double originalValue) {
    float floatValue = static_cast<float>(originalValue);
    double float2double = static_cast<double>(floatValue);
	int intValue = static_cast<int>(originalValue);
    double int2double = static_cast<double>(intValue);
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "original:\t" << originalValue << std::endl
	 		<< "float:\t\t" << floatValue << std::endl
			<< "float2double:\t" << float2double << std::endl
			<< "intValue:\t" << intValue << std::endl
			<< "int2double:\t" << int2double << std::endl;

    return originalValue != float2double;
	printTitle("LINE", 30);
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
		double value = std::numeric_limits<double>::quiet_NaN();
		if (isOverflowing(value)) {
			std::cout << "Overflow detected!" << std::endl;
		} else {
			std::cout << "No overflow." << std::endl;
		}
		std::stringstream ss(argv[1]);
		ss >> value;
		if (isOverflowing(value)) {
			std::cout << "Overflow detected!" << std::endl;
		} else {
			std::cout << "No overflow." << std::endl;
		}
		ScalarConverter::convert(argv[1]);

	}
	else
		deepTest();
	return (0);
}

/*
./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0
./convert nan
char: impossible
int: impossible
float: nanf
double: nan
./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0

*/
#include "ScalarConverter.hpp"
#include "Utils.hpp"
#include <iostream>


static void deepTest(void)
{

	{
		ScalarConverter::convert("\n");
		ScalarConverter::convert("!");
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
		//precision issues
		ScalarConverter::convert("3213213212312.31652426719665527344");
		ScalarConverter::convert("340282346638528859811704183484516925440.00000000000000000000");
		ScalarConverter::convert("214748365023452345.5");
		ScalarConverter::convert("179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0");
		ScalarConverter::convert("2147483647");
		ScalarConverter::convert("2147483649");
		std::cout << getColorStr(FGREEN, "\nDONE with all tests!") << std::endl;
	}

}


int main(int ac, char* argv[])
{
	if (DEBUG != 0)
		std::cout << "ac: " << ac<< std::endl;
	if (ac != 2)
	{
		std::ostringstream ss;
		ss << "Usage: " << argv[0] << " <literal>" << std::endl;
		std::cerr << error(ss.str(), 0);
		return (1);
	}
	if (DEBUG == 0)
		ScalarConverter::convert(argv[1]);
	else
	{
		if (DEBUG == 1)
			deepTest();
		else
		{
			ScalarConverter::convert(argv[1]);
		}
	}
	return (0);
}

			// std::cout << "float: "<< static_cast<float>(0.f) << std::endl;
			// std::cout << "float: "<< static_cast<float>(0.0f) << std::endl;
			// std::cout << "float: "<< static_cast<float>(.1f) << std::endl;
			// std::cout << "float: "<< static_cast<float>(0.1F) << std::endl;

			// std::cout << "float: "<< static_cast<float>(12.31652429999999999975) << std::endl;
			// std::cout << std::fixed << std::setprecision(20) << "float: "<< static_cast<float>(2147483647) << std::endl;
			// std::cout << std::fixed << std::setprecision(20) << "float: "<< static_cast<float>(+1.5154) << std::endl;
			// std::cout << std::fixed << std::setprecision(20) << "double: "<< static_cast<double>(2147483647) << std::endl;
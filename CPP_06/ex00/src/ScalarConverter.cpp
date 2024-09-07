#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter(){}

void ScalarConverter::convert(std::string const& str)
{
	try
	{
		std::string literal(reinterpretate(str));
		long double value;
		
		char* end;
		value = std::strtold(literal.c_str(), &end);
		if (DEBUG > 0)
		{
			std::cout << getColorFmt(FLCYAN);
			std::cout << "\nliteral: '" << literal << "'"<< std::endl;
			std::cout << "len: [" << literal.length() << "]" << std::endl;
			std::cout << "value:" << value << std::endl;
			std::cout << C_END << std::endl;
		};
		
		if (literal.length() > 1)
		{		
			if (*end != '\0' && (*end != 'f' || *(end + 1) != '\0'))
				throw (std::invalid_argument(""));
		}
		std::cout << "literal:" << literal << std::endl;
			std::cout << "value:" << value << std::endl;
		if (isType<char>(value, "CHAR") && literal.length() == 1)
			callHandler<char>(literal);
		else if (isType<int>(value, "INT") && literal.find(".")== std::string::npos)
			callHandler<int>(literal);
		else if (isType<float>(value, "FLOAT"))
			callHandler<float>(literal);
		else if(isType<double>(value, "DOUBLE"))
			callHandler<double>(literal);
	}
	catch (...)
	{
		std::cout << getColorFmt(FRED);
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		std::cout << C_END << std::endl;
	}
}


std::string ScalarConverter::reinterpretate(const std::string& str)
{
	std::string result = str;
	EscapeSequence escapeSequences[] =
	{
		{"\\n", '\n'},
		{"\\t", '\t'},
		{"\\r", '\r'},
		{"\\0", '\0'},
		{"\\b", '\b'},
		{"\\e", '\x1B'},
		{"\\a", '\a'},
		{"\\f", '\f'},
		{"\\v", '\v'}
	};

	for (size_t i = 0; i < sizeof(escapeSequences) / sizeof(EscapeSequence); ++i)
	{
		size_t pos = 0;

		while ((pos = result.find(escapeSequences[i].seq, pos)) != std::string::npos)
		{
			result.replace(pos, 2, 1, escapeSequences[i].ch);
			pos += 1;
		}
	}

	return (result);
}
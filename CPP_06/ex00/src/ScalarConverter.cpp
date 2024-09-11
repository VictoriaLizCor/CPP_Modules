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
		};
		if (literal.length() > 1)
		{
			// if (((*end == 'F' || *end == 'f')) && *(end + 1) == '\0')
			// {
			// 	std::cout << "isfloat\n";
			// 	value = std::strtof(literal.c_str(), NULL);
			// }
			// else if (*end != '\0')
			if (*end != '\0' && ((*end != 'f' || *end != 'F') && *(end + 1) != '\0'))
				throw (std::invalid_argument(literal));
		}
		else if(!std::isdigit(literal[0]))
			value = literal[0];
		else // check if digit
			// value = (literal.c_str()[0]);
			value = std::atoi(literal.c_str());
		if (DEBUG > 0)
			std::cout << "value: " << value << C_END << std::endl;
		if (literal.length() == 1 && isType<char>(value, "char"))
			callHandler<char>(static_cast<char>(value));
		else if (literal.find_first_not_of("+-0123456789") == std::string::npos && \
		isType<int>(value, "int"))
			callHandler<int>(static_cast<int>(value));
		else if (isType<float>(value, "float"))
			callHandler<float>(std::strtof(literal.c_str(), NULL));
		else if(isType<double>(value, "double"))
			callHandler<double>(std::strtod(literal.c_str(), NULL));
		else if(isType<long double>(value, "double"))
			callHandler<long double>(std::strtold(literal.c_str(), NULL));
		if (DEBUG > 0)
			std::cout << "---------------" << std::endl;
	}
	catch (...)
	{
		callHandler<long double>(std::numeric_limits<long double>::max());
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
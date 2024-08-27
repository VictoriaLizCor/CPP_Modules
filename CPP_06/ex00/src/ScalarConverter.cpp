#include "ScalarConverter.hpp"

void ScalarConverter::printChar(char c) {
	if (std::isprint(c)) {
		std::cout << "char: '" << c << "'" << std::endl;
	} else {
		std::cout << "char: Non displayable" << std::endl;
	}
}

void ScalarConverter::printInt(int i) {
	std::cout << "int: " << i << std::endl;
}

void ScalarConverter::printFloat(float f) {
	std::cout << "float: " << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double d) {
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(std::string const &literal) {
	try {
		// Try to detect and convert to char
		if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
			char c = literal[0];
			printChar(c);
			printInt(static_cast<int>(c));
			printFloat(static_cast<float>(c));
			printDouble(static_cast<double>(c));
			return;
		}

		// Try to detect and convert to int
		int i = std::atoi(literal.c_str());
		std::stringstream ss;
		ss << i;
		if (ss.str() == literal) {
			printChar(static_cast<char>(i));
			printInt(i);
			printFloat(static_cast<float>(i));
			printDouble(static_cast<double>(i));
			return;
		}

		// Try to detect and convert to float
		if (literal[literal.size() - 1] == 'f') {
			float f = std::strtof(literal.c_str(), NULL);
			printChar(static_cast<char>(f));
			printInt(static_cast<int>(f));
			printFloat(f);
			printDouble(static_cast<double>(f));
			return;
		}

		// Try to detect and convert to double
		double d = std::strtod(literal.c_str(), NULL);
		printChar(static_cast<char>(d));
		printInt(static_cast<int>(d));
		printFloat(static_cast<float>(d));
		printDouble(d);
	} catch (...) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}
#include <iostream>
#include "BitcoinExchange.hpp"
#include "Utils.hpp"

int main(int argc, char* argv[])
{
	int status = 0;
	if (argc == 2)
		BitcoinExchange btc(argv[1]);
	else
	{
		std::ostringstream os;

		os << std::endl << getColorStr(FWHITE,"Usage: ") << argv[0] << " <input_file>" << std::endl;
		std::cerr << error("\n", 1) << os.str();
	}
	nl(1);
	return (status);
}
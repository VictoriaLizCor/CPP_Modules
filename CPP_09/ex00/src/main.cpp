#include <iostream>
#include "BitcoinExchange.hpp"
#include "Utils.hpp"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::ostringstream os;

		os << std::endl << "Usage: " << argv[0] << " <input_file>" << std::endl;
		std::cerr << getColorStr(FRED, "ERROR:") << os.str();
		return (1);
	}
	
	BitcoinExchange btc(argv[1]);

	return (0);
}
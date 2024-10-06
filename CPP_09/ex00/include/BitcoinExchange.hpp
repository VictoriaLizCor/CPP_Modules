#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <sstream>
# include <fstream>
# include <string>
# include <sys/stat.h>
# include <typeinfo>
# include <unistd.h>
# include <Utils.hpp>
# include <stdexcept>
# include <map>
# include <algorithm>

# ifndef DEBUG
#  define DEBUG 0
# endif

class BitcoinExchange
{
	private:
		std::map <std::string, float> _dataBase;
		//debug
		std::string const	_colorIdStr;

		BitcoinExchange& operator=(BitcoinExchange const& rhs);
		BitcoinExchange(BitcoinExchange const& rhs);

		void			readFile(std::string const& fileName, std::string const& delimiter);
		//file handler
		void checkTargetStatus(std::string const& target, std::stringstream& ss);
		void checkStreamFlags(std::ifstream& file, std::string const&fileName);

	public:
		BitcoinExchange(std::string const& name);
		~BitcoinExchange();

		std::string		getName(std::string name);
		void			getInfo(std::ostream& os);

};

std::ostream& operator << (std::ostream& os, BitcoinExchange& rhs);

#endif // BITCOINEXCHANGE_HPP
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
# include <ctime>
# include <algorithm>
# include <cstring>

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

		//file handler
		void			readFile(std::string const& fileName, std::string const& delimiter);
		void checkTargetStatus(std::string const& target, std::stringstream& ss);
		void 			checkStreamFlags(std::ifstream& file, std::string const&fileName);
		// fill map
		float 			strToFloat(std::string const& strValue);
		std::string		checkDate(std::string const& date);

	public:
		BitcoinExchange(std::string const& name);
		~BitcoinExchange();

		std::string		getName(std::string name);
		void			getInfo(std::ostream& os);

};

std::ostream& operator << (std::ostream& os, BitcoinExchange& rhs);

#endif // BITCOINEXCHANGE_HPP
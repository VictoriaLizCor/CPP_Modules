#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <sstream>
# include <fstream>
# include <string>
# include <typeinfo>
# include <Utils.hpp>
# include <stdexcept>
# include <map>

# ifndef DEBUG
#  define DEBUG 0
# endif

class BitcoinExchange
{
	private:
		std::map <std::string, float> dataBase;
		//debug
		std::string const	_colorIdStr;

		BitcoinExchange& operator=(BitcoinExchange const& rhs);
		BitcoinExchange(BitcoinExchange const& rhs);

		void			fillDB(std::stringstream &info);
		void			readFile(std::string const& fileName, std::stringstream &info);

	public:
		BitcoinExchange(std::string const& name);
		~BitcoinExchange();

		std::string		getName(std::string name);
		void			getInfo(std::ostream& os);
};

std::ostream& operator << (std::ostream& os, BitcoinExchange& rhs);

#endif // BITCOINEXCHANGE_HPP
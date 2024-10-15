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
		float 			strToFloat(std::string const& strValue, std::string const& line);
		bool			checkInvalidDate(std::string& date, std::tm& tm);
		float			getExchangeRate(std::string& date);

	public:
		BitcoinExchange(std::string const& name);
		~BitcoinExchange();

		std::string		getName(std::string name);
		void			getInfo(std::ostream& os);

};

std::ostream& operator << (std::ostream& os, BitcoinExchange& rhs);

#endif // BITCOINEXCHANGE_HPP

/** @NOTES:
 * To avoid iterating through the entire database, you can use binary
   search techniques to quickly determine if the input date is lower
   than the middle value of the database. This can help you decide
   whether to search in the first half or the second half of the
   database.

 * However, since `std::map` is typically implemented as a balanced
   binary search tree (e.g., Red-Black Tree), it already provides
   logarithmic time complexity for operations like [`lower_bound`
   function is already efficient and does not require iterating
   through the entire database.

 */
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <map>
# include <ctime>
# include <stdexcept>
# include <sys/stat.h>
# include <unistd.h>
# include <iomanip>
# include <algorithm>
# include "Utils.hpp"
# include "DateUtils.hpp"

# ifndef DEBUG
#  define DEBUG 0
# endif

typedef std::map<std::string, float>::iterator ite;
class BitcoinExchange
{
	public:
		BitcoinExchange(std::string const& inputFile);
		BitcoinExchange& operator=(BitcoinExchange const& rhs);
		BitcoinExchange(BitcoinExchange const& rhs);
		~BitcoinExchange(void);

		void readFile(std::string const& fileName, std::string const& delimiter);
		std::pair<float, std::string>	getExchangeRate(std::string& date);
		std::string						getName(std::string name);
		void							getInfo(std::ostream& os);
	private:
		void	processLine(const std::string& line, const std::string& delimiter);
		void	processExchangeRate(std::string& key, double value, const std::string& line);
		void	checkFileStreamFlags(std::ifstream& file, std::string const& fileName);
		void	checkFileStatus(std::string const& target, std::stringstream& ss);

		std::pair<float, std::string> handleDateBeyondDB(std::string const& date, std::tm& inputDate, ite it);
		std::map<std::string, float> _dataBase;
		std::string _colorIdStr;
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
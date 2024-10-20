#include "BitcoinExchange.hpp"

/**
 * @brief Constructs a BitcoinExchange object.
 *
 * This constructor initializes a BitcoinExchange object by reading
 * data from a specified input file and a default data file. It also
 * assigns a random color format to the object.
 *
 * @param inputFile The path to the input file containing Bitcoin
 * exchange data.
 */
BitcoinExchange::BitcoinExchange(std::string const& inputFile):
_colorIdStr(getRandomColorFmt(1))
{
	if (DEBUG)
		std::cout << getName(__func__) << getColorStr(FGRAY, " was Created\n");
	readFile("data/data.csv", ",");
	if (DEBUG > 1)
		std::cout << "DB: " << *this << std::endl;
	readFile(inputFile, " | ");
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& rhs)
{
	if (&rhs == this)
		return (*this);
	if (DEBUG)
		std::cout << getName(__func__) << getColorStr(FGRAY, " copy was Created\n");
	return (*this);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& rhs):
_colorIdStr(getRandomColorFmt(1))
{
	*this = rhs;
}

BitcoinExchange::~BitcoinExchange(void)
{
	if (DEBUG)
		std::cout << getName(__func__) << getColorStr(FGRAY, " was Destroyed\n");
}


/**
 * @brief Converts a string to a floating-point number.
 *
 * This function attempts to convert the given string to a double. It
 * throws an exception if the string contains invalid characters or if
 * the resulting value is negative.
 *
 * @param strValue The string representation of the number to convert.
 * @return The converted floating-point number.
 * @throws std::invalid_argument If the string contains invalid
 * characters.
 * @throws std::out_of_range If the resulting value is negative.
 */
static double strToFloat(std::string const& strValue)
{
	char* end;
	double value = std::strtod(strValue.c_str(), &end);

	if (*end != '\0' && ((*end != 'f' && *end != 'F') || *(end + 1) != '\0'))
		throw std::invalid_argument(errorFmt("Invalid Value input") + strValue);
	if (value < 0)
		throw std::out_of_range(errorFmt("Not a positive value") + strValue);
	return (value);
}


/**
 * @brief Handles dates that are beyond the database range.
 *
 * This function processes a given date and determines the appropriate
 * value and color formatting based on the date's relation to the last
 * date in the database and the current date.
 *
 * @param date The input date as a string.
 * @param inputDate The input date as a std::tm structure.
 * @param it An iterator pointing to the position in the database map.
 * @return A pair containing the float value associated with the date
 * and a string representing the color format.
 * @throws std::runtime_error If the date conversion to std::time_t
 * fails or if the date is in the future.
 */
std::pair<float, std::string> BitcoinExchange::handleDateBeyondDB(std::string const& date, std::tm& inputDate, ite it)
{
	std::tm lastDate, current;
	std::time_t inputTime, lastDateTime, currentTime, monthAheadTime;
	std::map<std::string, float>::iterator tmp = it;
	--tmp;
	std::string lastDateStr = tmp->first;

	checkParseDate(lastDateStr, lastDate);
	monthAheadTime = getMonthAheadTime(lastDate);
	lastDateTime = std::mktime(&lastDate);
	inputTime = std::mktime(&inputDate);
	if (inputTime == -1 || lastDateTime == -1)
		throw std::runtime_error(errorFmt("Failed to convert to std::time_t"));
	getCurrentTime(currentTime, current);
	if (inputTime < monthAheadTime)
		return std::make_pair(tmp->second, getColorFmt(FYELLOW));
	else if (inputTime < currentTime)
		return std::make_pair(tmp->second, FORANGE);
	else
		throw std::runtime_error(errorFmt("Date in the future") + date);
}

/**
 * @brief Retrieves the exchange rate for Bitcoin on a given date.
 *
 * This function searches the internal database for the exchange rate
 * of Bitcoin on the specified date. If the exact date is not found,
 * it returns the closest preceding date's exchange rate. If the date
 * is before the earliest date in the database, an error is thrown.
 *
 * @param date The date for which the exchange rate is requested, in
 * string format.
 * @return A pair containing the exchange rate (float) and a formatted
 * string (std::string).
 * @throws std::runtime_error If the date is before the earliest date
 * in the database.
 */
std::pair<float, std::string> BitcoinExchange::getExchangeRate(std::string& date)
{
	std::tm inputDate;

	checkParseDate(date, inputDate);
	ite it = _dataBase.lower_bound(date);
	if (it == _dataBase.end() || it->first != date)
	{
		if (it == _dataBase.begin())
		{
			std::stringstream ss;
			ss << errorFmt("Not comparable in DB") << date;
			if (DEBUG)
				ss << std::endl << "Bitcoin started at: " << it->first;
			throw std::runtime_error(ss.str());
		}
		if (it == _dataBase.end())
			return handleDateBeyondDB(date, inputDate, it);
		--it;
	}
	return (std::make_pair(it->second, getColorFmt(FWHITE)));
}

/**
 * @brief Reads a file and processes its content line by line.
 *
 * This function attempts to open and read a file specified by the
 * given file name. It checks the file status and stream flags, and
 * processes each line of the file using the specified delimiter. If
 * any error occurs during these operations, an exception is caught
 * and an error message is printed.
 *
 * @param fileName The name of the file to be read.
 * @param delimiter The delimiter used to process each line of the
 * file.
 * @throws std::runtime_error If there is an issue with the file
 * status.
 * @throws std::exception If any other error occurs during file
 * operations.
 */
void BitcoinExchange::readFile(std::string const& fileName, std::string const& delimiter)
{
	std::ifstream tempFile;
	try
	{
		std::ifstream tempFile;
		std::stringstream ss;
		std::string line;
		
		checkFileStatus(fileName, ss);
		if (!ss.str().empty())
			throw(std::runtime_error(ss.str()));
		tempFile.open(fileName.c_str());
		checkFileStreamFlags(tempFile, fileName);
		
		std::getline(tempFile, line);
		while(std::getline(tempFile, line))
			processLine(line, delimiter);
		
		tempFile.clear();
		tempFile.close();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	nl(1);
}

/**
 * @brief Processes a line of input to either update the database or
 * calculate exchange rates.
 *
 * This function takes a line of input and a delimiter, then processes
 * the line to either update the internal database with new values or
 * calculate exchange rates based on the provided data.
 *
 * @param line The input line to be processed.
 * @param delimiter The delimiter used to split the input line into
 * key and value.
 *
 * @throws std::runtime_error If the input line does not contain the
 * delimiter.
 * @throws std::out_of_range If the value extracted from the input
 * line is greater than 1000.
 */
void BitcoinExchange::processLine(const std::string& line, const std::string& delimiter)
{
	if (line.empty())
		return ;
	try
	{
		size_t pos = line.find(delimiter);
		
		if (pos == std::string::npos)
			throw std::runtime_error(errorFmt("Bad input") + line);
		
		std::string key = line.substr(0, pos);
		std::string strValue = line.substr(pos + delimiter.length());
		double value = strToFloat(strValue);
		
		if (delimiter == ",")
			_dataBase[key] = static_cast<float>(value);
		else
			processExchangeRate(key, value, line);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

/**
 * @brief Processes the exchange rate for Bitcoin.
 *
 * This function takes a key and a value, retrieves the exchange rate
 * for the key, and calculates the result of the exchange. If the
 * value exceeds 1000, an exception is thrown. The result is then
 * printed in a formatted manner.
 *
 * @param key The key representing the currency or date for which the
 * exchange rate is needed.
 * @param value The amount to be exchanged.
 * @param line The original line of input, used for error reporting.
 *
 * @throws std::out_of_range If the value exceeds 1000.
 */
void BitcoinExchange::processExchangeRate(std::string& key, double value, const std::string& line)
{
	if (value > 1000)
		throw std::out_of_range(errorFmt("Value over 1000") + line);

	std::pair<float, std::string> tmp = getExchangeRate(key);
	float result = tmp.first * static_cast<float>(value);

	std::cout << tmp.second
			  << formatValue(key, 42, 0) << " => "
			  << formatValue(value, 4, 0)
			  << " = " << std::fixed << std::setprecision(2)
			  << formatValue(result, 7, 0) << C_END << std::endl;
}

/**
 * @brief Retrieves the name of the BitcoinExchange instance,
 * formatted with color codes.
 *
 * This function constructs a formatted string that includes the name
 * of the instance, potentially modified by a tilde ('~') character,
 * and applies color codes to it.
 *
 * @param name A string representing the name to be processed. If the
 *             string contains a tilde ('~'), the part after the tilde
 *             will be used as the name. If the string is empty, the
 *             class name of the instance will be used.
 * @return A formatted string with the instance name and color codes
 * applied.
 */
std::string BitcoinExchange::getName(std::string name)
{
	std::ostringstream os;
	static std::string _name;
	size_t pos = name.find("~");

	if (name.empty())
		name = className(typeid(*this).name());
	if (_name.empty() || pos != std::string::npos)
		_name = name;
	os << _colorIdStr << _name << C_END;
	if (pos != std::string::npos)
		_name = name.substr(pos + 1);
	return (os.str());
}


/**
 * @brief Outputs the Bitcoin exchange information to the provided
 * output stream.
 *
 * This function prints the name and values of the Bitcoin exchange to
 * the given output stream. If debugging is enabled, it iterates
 * through the internal database and prints each entry using a
 * functor.
 *
 * @param os The output stream to which the information will be
 * written.
 */
void BitcoinExchange::getInfo(std::ostream& os)
{
	os << getName("") << " values:" << std::endl ;
	nl(1);
	if (DEBUG)
		std::for_each(_dataBase.begin(), _dataBase.end(), PrintFunctor<std::map<std::string, float> >(os, _dataBase));
}

std::ostream& operator << (std::ostream& os, BitcoinExchange& rhs)
{
	rhs.getInfo(os);
	return (os);
}

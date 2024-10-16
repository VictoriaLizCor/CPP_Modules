#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string const& inputFile):
_colorIdStr(getRandomColorFmt(1))
{
	if (DEBUG)
		std::cout << getName(__func__) << getColorStr(FGRAY, " was Created\n");
	readFile("data/data.csv", ",");
	if (DEBUG > 1)
		std::cout << *this << std::endl;
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

static bool isLeap(int year)
{
	if (year % 4 != 0)
		return (false);
	if (year % 100 != 0)
		return (true);
	if (year % 400 != 0)
		return (false);
	return (true);
}

static bool isValidDate(int year, int month, int day)
{
	if ((month < 1 || month > 12) || day < 1)
		return (false);

	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (isLeap(year))
		daysInMonth[1] = 29;

	return (day <= daysInMonth[month - 1]);
}

//  if (date.size() != 10 || date[4] != '-' || date[7] != '-')
// 	throw std::runtime_error(errorFmt("Failed to parse date: ")) + line);
bool BitcoinExchange::checkInvalidDate(std::string & date, std::tm& tm)
{
	std::memset(&tm, 0, sizeof(std::tm));
	std::string format = "%Y-%m-%d";
	std::stringstream ss(date);


	char dash1, dash2;
	if (!(ss >> tm.tm_year >> dash1 >> tm.tm_mon >> dash2 >> tm.tm_mday) || dash1 != '-' || dash2 != '-')
		return (1);
	if (!isValidDate(tm.tm_year, tm.tm_mon, tm.tm_mday))
		return (1);
	ss.str("");
	ss.clear();
	ss << (tm.tm_year) << "-" 
	<< std::setw(2) << std::setfill('0') << tm.tm_mon << "-"
	<< std::setw(2) << std::setfill('0') << tm.tm_mday;
	date = ss.str();
	return (0);
}

float BitcoinExchange::strToFloat(std::string const& strValue, std::string const& line)
{
	char* end;
	float value = std::strtof(strValue.c_str(), &end);

	if (*end != '\0' && ((*end != 'f' && *end != 'F') || *(end + 1) != '\0'))
		throw std::invalid_argument(errorFmt("Invalid Value input") + line);
	if (value < 0)
		throw std::out_of_range(errorFmt("Not a positive value") + line);
	return (value);
}

float BitcoinExchange::getExchangeRate(std::string& date)
{
	std::tm inputDate;

	if (checkInvalidDate(date, inputDate))
		throw std::runtime_error(errorFmt("Invalid date") + date);
	std::map<std::string, float>::iterator it = _dataBase.lower_bound(date);
	if (it == _dataBase.end() || it->first != date)
	{
		if (it == _dataBase.begin())
		{
			std::stringstream ss;
			ss << errorFmt("Unable to compare in database") << date;
			if (DEBUG)
				ss << std::endl << "Bitcoin started at: " << it->first;
			throw std::runtime_error(ss.str());
		}
		if (it == _dataBase.end())
		{
			std::tm lastDate;
			std::time_t currentTime = std::time(0);
			std::map<std::string, float>::iterator tmp = _dataBase.end();
			--tmp;
			std::string lastDateStr = tmp->first;
			(void)checkInvalidDate(lastDateStr, lastDate);
			std::time_t lastDateTime = std::mktime(&lastDate);
			std::time_t inputTime = std::mktime(&inputDate);
			if (inputTime == -1 || lastDateTime == -1)
				throw std::runtime_error(errorFmt("Failed to convert to std::time_t"));
			std::tm* tMonthAhead = std::localtime(&lastDateTime);
			tMonthAhead->tm_mon += 1;
			std::time_t monthAhead = std::mktime(tMonthAhead);
			if (inputTime < monthAhead)
				return (-1 * tmp->second);
			{// To Delete
				std::cout << getColorStr(FLCYAN, lastDateStr) << std::endl;
				std::cout << getColorStr(FLYELLOW, date) << std::endl;
			}
			//toCHeck
			char buffer[11];
			std::time_t t = std::time(0);
			std::tm* current = std::localtime(&t);
			std::string currentDate;
			std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", current);
			currentDate = std::string(buffer);
			if (inputTime < currentTime)
				 throw std::runtime_error(errorFmt("Date ahead") + date);
			if (inputTime > currentTime)
				throw std::runtime_error(errorFmt("Date in the future") + date);
		}
		--it;
	}
	return (it->second);
}
// std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", current);

void BitcoinExchange::readFile(std::string const& fileName, std::string const& delimiter)
{
	std::ifstream tempFile;
	try
	{
		std::ifstream tempFile;
		std::stringstream ss;
		std::string line;
		
		checkTargetStatus(fileName, ss);
		if (!ss.str().empty())
			throw(std::runtime_error(ss.str()));
		tempFile.open(fileName.c_str());
		checkStreamFlags(tempFile, fileName);
		std::getline(tempFile, line);
		while(std::getline(tempFile, line))
		{
			try
			{
				size_t pos = line.find(delimiter);
				if (line.empty())
					continue;
				if (pos == std::string::npos)
					throw std::runtime_error(errorFmt("Bad input") + line);
				std::string key = line.substr(0, pos);
				std::string strValue = line.substr(pos + delimiter.length());
				float value = strToFloat(strValue, line);
				if (delimiter == ",")
					_dataBase[key] = value;
				else
				{
					if (value > 1000)
						throw std::out_of_range(errorFmt("Value over 1000") + line );
					float result = value * getExchangeRate(key);
					if (result < 0)
					{
						std::cout << getColorFmt(FYELLOW);
						result *= -1;
					}
					else
						std::cout << getColorFmt(FWHITE) ;
					std::cout << key << " => " << std::setw(6) 
					<< std::setfill(' ') << value << " = " << 
					std::setw(6) << std::setfill(' ') << result << C_END << std::endl;
				}
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
		tempFile.clear();
		tempFile.close();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	nl(1);
}

void BitcoinExchange::checkStreamFlags(std::ifstream& file, std::string const& fileName)
{
	std::stringstream ss;

	if (!file.good())
		std::cout << "*-----checkStreamFLAGS------" << std::endl;
	if (file.peek() == std::fstream::traits_type::eof())
	{
		ss.str("");
		ss << errorFmt("File " + fileName + " is empty");
	}
	if (file.fail())
		ss << error("A I/O error has occurred ", 0) << std::endl;
	if (file.bad())
		ss << error("A critical I/O error has occurred: ", 0) << std::endl;
	if (!ss.str().empty())
		throw std::runtime_error(ss.str());
}

void BitcoinExchange::checkTargetStatus(std::string const& target, std::stringstream& ss)
{
	struct stat st;
	std::string strTarget(getColorFmt(FRED) + "File '" + target + "' ");
	bool isDirectory = (false);
	bool status = (false);

	if (stat(target.c_str(), &st) == 0)
	{
		if (access(target.c_str(), R_OK) == -1)
			ss << strTarget << "has no reading permissions\n";
		if (access(target.c_str(), W_OK) == -1)
			ss << strTarget << "has no writing permissions\n";
		isDirectory = S_ISDIR(st.st_mode);
		status = (true);
	}
	if (!status)
		ss << strTarget << "does not exist" << C_END;
	else if (isDirectory)
		ss << strTarget << "is a Directory"<< C_END;
}

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

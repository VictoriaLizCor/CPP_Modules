#include "BitcoinExchange.hpp"

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

//  if (date.size() != 10 || date[4] != '-' || date[7] != '-')
// 	throw std::runtime_error(errorFmt("Failed to parse date: ")) + line);
void BitcoinExchange::checkInvalidDate(std::string & date, std::tm& tm)
{
	char buffer[11];
	std::memset(&tm, 0, sizeof(std::tm));
	std::stringstream ss(date);


	char dash1, dash2;
	if (!(ss >> tm.tm_year >> dash1 >> tm.tm_mon >> dash2 >> tm.tm_mday) || dash1 != '-' || dash2 != '-')
		throw std::runtime_error(errorFmt("Invalid date") + date);
	if (!isValidDate(tm.tm_year, tm.tm_mon, tm.tm_mday))
		throw std::runtime_error(errorFmt("Invalid date") + date);
	tm.tm_year -= 1900;
	tm.tm_mon -= 1;
	std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", &tm);
	
	date = std::string(buffer);
}

void BitcoinExchange::getCurrentTime(std::time_t& currentTime, std::tm& current)
{
	char buffer[11];
	currentTime = std::time(0);
	current = *std::localtime(&currentTime);
	std::string currentDate;
	std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", &current);
	currentDate = std::string(buffer);
	checkInvalidDate(currentDate, current);
	currentTime = std::mktime(&current);
}

std::pair<float, std::string> BitcoinExchange::getExchangeRate(std::string& date)
{
	std::tm inputDate;

	checkInvalidDate(date, inputDate);
	std::map<std::string, float>::iterator it = _dataBase.lower_bound(date);
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
		{
			std::tm lastDate, current, monthAhead;
			std::time_t inputTime, lastDateTime, currentTime;
			std::map<std::string, float>::iterator tmp = it;
			--tmp;
			std::string lastDateStr = tmp->first;
			checkInvalidDate(lastDateStr, lastDate);
			lastDateTime = std::mktime(&lastDate);
			inputTime = std::mktime(&inputDate);
			if (inputTime == -1 || lastDateTime == -1)
				throw std::runtime_error(errorFmt("Failed to convert to std::time_t"));
			monthAhead = lastDate;
			monthAhead.tm_mon += 1;
			getCurrentTime(currentTime, current);
			if (inputTime < std::mktime(&monthAhead))
				return (std::make_pair(tmp->second , getColorFmt(FYELLOW)));
			if (inputTime > std::mktime(&monthAhead))
			{
				if (inputTime < currentTime)
					return (std::make_pair(tmp->second , FORANGE));
				if (inputTime > currentTime)
					throw std::runtime_error(errorFmt("Date in the future") + date);
			}
		}
		--it;
	}
	return (std::make_pair(it->second, getColorFmt(FWHITE)));
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
		
		checkFileStatus(fileName, ss);
		if (!ss.str().empty())
			throw(std::runtime_error(ss.str()));
		tempFile.open(fileName.c_str());
		checkFileStreamFlags(tempFile, fileName);
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
					std::pair<float, std::string> tmp = getExchangeRate(key);
					float result = tmp.first * value;
					std::cout << tmp.second
					<< formatValue(key, 42, 0) << " => " 
					<< formatValue(value, 4, 0) 
					<< " = " << std::fixed << std::setprecision(2) 
					<< formatValue(result, 7, 0) << C_END << std::endl;
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

void BitcoinExchange::checkFileStreamFlags(std::ifstream& file, std::string const& fileName)
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

void BitcoinExchange::checkFileStatus(std::string const& target, std::stringstream& ss)
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

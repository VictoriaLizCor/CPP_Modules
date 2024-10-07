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

std::string BitcoinExchange::checkDate(std::string const& date)
{
	std::tm tm;
	std::memset(&tm, 0, sizeof(std::tm));
	std::string format = "%Y-%m-%d";
	std::stringstream ss(date);

	 if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		throw std::runtime_error("Failed to parse date: " + date);

	char dash1, dash2;
	if (!(ss >> tm.tm_year >> dash1 >> tm.tm_mon >> dash2 >> tm.tm_mday) || dash1 != '-' || dash2 != '-')
		throw std::runtime_error("Failed to parse date: " + date);
	tm.tm_year -= 1900;
	tm.tm_mon -= 1;
	ss.str("");
	ss.clear();
	ss << (tm.tm_year + 1900) << "-" << (tm.tm_mon + 1) << "-" << tm.tm_mday;
	return (ss.str());
}

float BitcoinExchange::strToFloat(std::string const& strValue)
{
	char* end;
	errno = 0;
	float value = std::strtof(strValue.c_str(), &end);

	if (*end != '\0' && ((*end != 'f' && *end != 'F') || *(end + 1) != '\0'))
		throw std::invalid_argument(error("No conversion could be performed: ", 1) + strValue);
	if (errno == ERANGE)
		throw std::out_of_range(error("Value out of range: ", 1) + strValue);
	if (value < 0)
		throw std::out_of_range(error("not a positive number.", 1));
	return value;
}

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
		std::cout << fileName;
		nl(2);
		tempFile.open(fileName.c_str());
		checkStreamFlags(tempFile, fileName);
		std::getline(tempFile, line);
		while(std::getline(tempFile, line))
		{
			try
			{
				size_t pos = line.find(delimiter);
				if (pos != std::string::npos)
				{
					std::string key = line.substr(0, pos);
					std::string strValue = line.substr(pos + delimiter.length());
					float value = strToFloat(strValue);
					if (delimiter == ",")
						_dataBase[key] = value;
					else
					{
						std::cout << checkDate(key) << std::endl;
						if (value > 1000)
							throw std::out_of_range(error("Value over 1000", 1));
						std::cerr << line << std::endl;
					}
				}
				else
					throw std::runtime_error(error("bad input ", 1) + line);
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
		ss << error("File " + fileName + " is empty", 1);
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
	bool isDirectory = false;
	bool status = false;

	if (stat(target.c_str(), &st) == 0)
	{
		if (access(target.c_str(), R_OK) == -1)
			ss << strTarget << "has no reading permissions\n";
		if (access(target.c_str(), W_OK) == -1)
			ss << strTarget << "has no writing permissions\n";
		isDirectory = S_ISDIR(st.st_mode);
		status = true;
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

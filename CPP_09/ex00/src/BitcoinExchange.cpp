#include "BitcoinExchange.hpp"

void BitcoinExchange::fillDB(std::stringstream &info)
{
	(void)info;
}

BitcoinExchange::BitcoinExchange(std::string const& inputFile):
_colorIdStr(getRandomColorFmt(1))
{
	std::stringstream info;
	// readFile("data/data.csv", info);
	readFile(inputFile, info);
	// fillDB(info);
	if (DEBUG)
		std::cout << getName(__func__) << getColorStr(FGRAY, " was Created\n");
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

void BitcoinExchange::readFile(std::string const& fileName, std::stringstream &info)
{
	std::ifstream tempFile;

	try
	{
		std::string line;

		tempFile.exceptions(std::ifstream::failbit | 
		std::ifstream::badbit);
		
		std::cout << fileName << std::endl;
		tempFile.open(fileName.c_str());
		!tempFile.eof() && std::getline(tempFile, line);
		while(!tempFile.eof() && std::getline(tempFile, line))
		{
			info << line;
			std::cerr << line << std::endl;
		}
		std::cerr << "line" << std::endl;
		tempFile.clear();
		tempFile.close();
	}
	catch(const std::exception& e)
	{
		if (typeid(e) == typeid(std::ifstream::failure))
			std::cerr << error("File is Empty", 0) << std::endl;
		else
			std::cerr << error(e.what(), 0) << std::endl;
	}


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
	os << getName("") ;// << " size: " << this->size() << std::endl;
	// if (this->size())
	// {
	// 	os << "values: ";
	// 	std::for_each(this->begin(), this->end(), PrintFunctor< MutantStack<T> >(os, *this));
	// 	os << std::endl;
	// }
}
std::ostream& operator << (std::ostream& os, BitcoinExchange& rhs)
{
	rhs.getInfo(os);
	return (os);
}

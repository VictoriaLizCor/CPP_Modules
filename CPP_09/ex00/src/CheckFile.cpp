#include "BitcoinExchange.hpp"

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

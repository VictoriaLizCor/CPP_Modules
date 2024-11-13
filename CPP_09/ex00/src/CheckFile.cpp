#include "BitcoinExchange.hpp"

/**
 * @brief Checks the status flags of a file stream and throws an exception if any error is detected.
 *
 * This function examines the status flags of the provided file stream to determine if any errors
 * have occurred. It checks for the following conditions:
 * - If the file stream is not in a good state.
 * - If the file is empty.
 * - If an I/O error has occurred.
 * - If a critical I/O error has occurred.
 *
 * If any of these conditions are met, an appropriate error message is constructed and a 
 * std::runtime_error is thrown with the error message.
 *
 * @param file The file stream to check.
 * @param fileName The name of the file associated with the file stream.
 *
 * @throws std::runtime_error If any error is detected in the file stream.
 */
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

/**
 * @brief Checks the status of a file and updates the provided stringstream with the results.
 * 
 * This function checks if the specified file exists, and if it does, it verifies the read and write permissions.
 * It also checks if the specified path is a directory. The results of these checks are appended to the provided
 * stringstream.
 * 
 * @param target The path to the file to be checked.
 * @param ss The stringstream to which the results will be appended.
 */
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

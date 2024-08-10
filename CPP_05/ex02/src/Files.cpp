#include "Files.hpp"
#include "Utils.hpp"


// /**
//  * @brief Default constructor for the Files class.
//  *
//  * This constructor initializes a new instance of the Files class. It does not
//  * take any parameters and does not perform any operations.
//  */
// Files::Files(){return ;}

/**
 * @brief Constructs a Files object with the specified file name and open mode.
 *
 * @param fileName The name of the file to be opened.
 * @param mode The open mode for the file( std::ios::in | std::ios::out |
 * std::ios::app | std::ios::ate | std::ios::binary | std::ios::trunc).
 */
Files::Files(std::string const& fileName, std::ios_base::openmode mode):
_fileName(fileName), _fileMode(mode), _file()
{
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Created\n");
	if (!_fileName.empty() && _fileMode != 0)
		openFile();
	else
		debug(FWHITE, "Waiting for file to be open...\n");
}


/**
 * @brief Constructs a Files object with the given file name.
 *
 * @param fileName The name of the file to be associated with the Files object.
 */
// Files::Files(const char* fileName): _file(), _fileName(fileName)
// {
// 	openFile(std::ios::in | std::ios::out | std::ios::trunc);
// 	return ;
// }

/**
 * @brief Copy constructor for the Files class.
 * 
 * @param file The Files object to be copied.
 */
Files::Files(Files& file): _fileName(file._fileName + "_cpy"), _file()
{
	openFile(std::ios::in | std::ios::out | std::ios::trunc);
	copyFile(file);
}


/**
 * @brief Destructor for the Files class.
 *
 * This destructor is responsible for closing the file associated with the Files
 * object. It calls the closeFile() function to close the file.
 */
Files::~Files()
{
	closeFile();
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Destroyed\n");
}

/**
 * @brief Opens a file with the specified file name and mode.
 *
 * This function first closes any previously opened file, then attempts to open
 * a new file with the name and mode stored in the _fileName and _fileMode
 * member variables, respectively. After opening the file, it checks if the file
 * is successfully opened.
 */
void Files::openFile()
{
	closeFile();
	printTitle("Opening", 20);
	_file.open(_fileName.c_str(), _fileMode);
	printTitle("Info", 20);
	fileInfo();
}
/**
 * @brief Opens a file with the specified file name and mode.
 *
 * This function first closes any previously opened file, then attempts to open
 * a new file with the name and mode stored in the _fileName and _fileMode
 * member variables, respectively. After opening the file, it checks if the file
 * is successfully opened.
 */
void Files::openFile(const char* fileName, std::ios_base::openmode mode)
{
	_fileName = fileName;
	_fileMode = mode;
	closeFile();
	printTitle("Opening", 20);
	_file.open(_fileName.c_str(), mode);
	printTitle("Info", 20);
	fileInfo();
}

/**
 * @brief Opens a file with the specified mode.
 *
 * This function opens a file with the specified mode. If a file is already
 * open, it will be closed before opening the new file.
 *
 * @param mode The mode to open the file in (e.g., std::ios_base::in,
 * std::ios_base::out, std::ios_base::app, etc.).
 */
void Files::openFile(std::ios_base::openmode mode)
{
	_fileMode = mode;
	closeFile();
	printTitle("Opening", 20);
	_file.open(_fileName.c_str(), mode);
	printTitle("Info", 20);
	fileInfo();
}

/**
 * @brief Closes the file if it is open.
 * 
 * This function checks if the file is open and closes it if it is. 
 * If the file is not open, this function does nothing.
 */
void Files::closeFile()
{
	if (this->_file.is_open())
	{
		_file.clear();
		this->_file.close();
		if (this->_file.fail())
			throw (FileError(" Failed to close the file " + this->_fileName));
		std::cout << getColorStr(FGRAY, "File " + this->_fileName + " closed successfully.") << std::endl;
	}
}

bool Files::checkEnv(std::string const& path, std::stringstream& ss)
{
	ss << std::getenv(toUpperCase(path).c_str());
	if (ss.str().empty())
	{
		debug(FLYELLOW, "Path not fount in ENV\n");
		return (0);
	}
	debug(DEFAULT, std::string(toUpperCase(path) + ":" + ss.str() + "\n"));
	return (1);
	
}

std::streampos  Files::contentSize(void)
{
	_file.seekg(0, std::ios::end);
	std::streampos fileSize = _file.tellg();

	return (fileSize);
}

std::string Files::getPath(std::string const& path)
{
	std::stringstream ss;

	if (checkEnv(path, ss))
		return (ss.str());
	else
	{
		std::string tempFileName = "pathFile.txt";
		std::string currentDirectory;
		std::string command = "pwd > " + tempFileName;
		int status = system(command.c_str());
		if (status == 0)
		{
			std::ifstream tempFile(tempFileName.c_str());

			if (tempFile.is_open())
			{
				std::getline(tempFile, currentDirectory);
				tempFile.close();
			}
			std::remove(tempFileName.c_str());
		}
		else
			debug(FRED, "Error in System '" + command + "' execution");
		if (path.empty())
		{
			debug(DEFAULT, "Returning working directory:\n");
			return (currentDirectory);
		}
		return (currentDirectory + "/" + path);
	}
}

bool Files::readLineInFile(std::string& line, std::streampos& lastPosition)
{
	if(!_file.is_open())
	{
		std::string msg;
		msg = error("File " + _fileName + " is not open\n", 1);
		throw (FileError(msg));
	}
	_file.seekp(lastPosition);
	if (std::getline(_file, line))
	{
		lastPosition = (_file.tellg());
		return (true);
	}
	if(_file.peek() == std::fstream::traits_type::eof())
		return (false);
	return (false);
}

bool Files::writeAtPosition(std::string const& data, std::streampos& position)
{
	if (!_file.is_open())
	{
		std::string msg;
		msg = error("File " + _fileName + " is not open\n", 1);
		throw (FileError(msg));
	}
	_file.clear();
	_file.seekp(static_cast<std::streamoff>(position));
	if (_file.fail())
		return (false);
	_file << data;
	if (_file.fail())
		return (false);
	return (true);
}

void Files::write(std::stringstream const& buffer)
{
	if(_file.is_open())
	{
		_file.clear();
		_file.seekp(0, std::ios::beg);
		_file << buffer.str();
		closeFile();
	}
	else
		throw(FileError(error("'" + _fileName + "' file not Open", 0)));
}

/**
 * @brief Copies the content of one file to another.
 *
 * @param in Reference to the file to be copied from.
 *
 * This function seeks to the beginning of the input file, copies its content
 * to the current file object, and then closes the current file.
 * The `rdbuf` function is a member function of `std::basic_istream` and
 *  `std::basic_ostream` classes in C++. It returns a pointer to the internal file
 *  buffer.
**/
void Files::copyFile(Files& in)
{
	std::stringstream ss;

	if (_file.peek() == std::fstream::traits_type::eof())
	{
		ss.str("");
		ss << error("File " + _fileName + " is empty\n", 1);
		throw (FileError(ss.str()));
	}
	in._file.seekg(0); 
	_file << in._file.rdbuf();
	in.closeFile();
}

static void fileMode(std::ios_base::openmode& fileMode, std::stringstream& ss, int& i)
{
	std::stringstream tmp;

	if (i == 0 && fileMode & std::ios::in)
		tmp << getColorStr(FLBLUE, "READ");
	if (i == 1 && fileMode & std::ios::out)
		tmp << getColorStr(FLGREEN, "WRITE");
	if (i == 2 && fileMode & std::ios::trunc)
		tmp << getColorStr(FLMAGENTA, "TRUNCATE");
	if (i == 3 && fileMode & std::ios::app)
		tmp << getColorStr(FLMAGENTA, "APPEND");
	if (i == 4 && fileMode & std::ios::ate)
		tmp << getColorStr(FGRAY, "APPEND at the END");
	if (i == 5 && fileMode & std::ios::binary)
		tmp << getColorStr(FLWHITE, " BINARY");
	if (!tmp.str().empty() && !ss.str().empty())
		ss << " | ";
	
	ss << tmp.str();
}
/**
 * @brief Checks if a file is open and reports the file mode.
 *
 * This function checks if the file specified by the _fileName member variable
 * is open. If the file is not open, it throws a runtime error with a message
 * indicating the failure. If the file is open, it reports the mode in which the
 * file is open (read, write, truncate, append, append at the end, binary) by
 * checking the _fileMode member variable.
 *
 * The function uses the setColor function to colorize the output based on the
 * file mode.
 */
void Files::fileInfo()
{
	std::stringstream ss;

	if (DEBUG)
	{
		std::stringstream s2;

		ss << "FileName: ['" << _fileName << "']\n";
		ss << "Opening mode as: [ ";
		if (_fileMode == 0)
			s2 << getColorStr(FWHITE, "Default");
		else
		{
			for (int i = 0; i < 6 ; ++i)
				fileMode(_fileMode, s2, i);
		}
		std::cout << ss.str() << s2.str() << " ]\n";
	}
	ss.clear();
	ss.str("");
	checkStreamFlags(*this);
}

// 	if (status && ss.str().find("is a Directory") != std::string::npos)
// 	{
// 		status = 0;
// 		throw(FileError(getColorStr(FRED, ss.str())));
// 	}
// 	if (ss.str().find("does not exist") != std::string::npos)
// 		status = 0;
// }

/**
 * @brief Checks the status flags of a file stream.
 *
 * @param file The Files object containing the file stream to check.
 *
 * This function checks the status flags (good, fail, bad, eof) of the file
 * stream in the provided Files object. If any of the flags are set, it prints
 * an appropriate message to the standard output.
 *
 * The function uses the setColor function to colorize the output based on the
 * status of the file stream.
 *
 * If the DEBUG constant is set to 0, the function returns immediately without
 * checking the status flags.
 */
void Files::checkStreamFlags(Files& file)
{
	std::stringstream ss;

	if (!file._file.good())
		std::cout << "*-----checkStreamFLAGS------" << std::endl;
	if (file._file.fail())
		ss << error("A I/O error has occurred ", 0) << std::endl;
	if (file._file.bad())
		ss << error("A critical I/O error has occurred: ", 0) << std::endl;
	if (file._file.eof())
		ss << error("End of file has been reached", 0) << std::endl;
	checkTargetStatus(_fileName, ss);
	if (ss.str().find("does not exist") != std::string::npos)
		throw(FileError(getColorStr(FRED, ss.str())));
	if (ss.str().find("is a Directory") != std::string::npos)
	{
		throw(FileError(getColorStr(FRED, "ERROR: " + ss.str())));
	}
}

/**
 * @brief Checks the status flags of a file stream.
 *
 * @param file The Files object containing the file stream to check.
 *
 * This function checks the status flags (good, fail, bad, eof) of the file
 * stream in the provided Files object. If any of the flags are set, it prints
 * an appropriate message to the standard output.
 *
 * The function uses the setColor function to colorize the output based on the
 * status of the file stream.
 *
 * If the DEBUG constant is set to 0, the function returns immediately without
 * checking the status flags.
 */
void Files::showContent()
{
	std::stringstream ss;

	_file.clear();
	openFile(std::ios::in);
	printTitle("File '" + _fileName + "' Content", 30);
	_file.seekg(0);
	ss << _file.rdbuf();
	printTitle("End of '" + _fileName + "' Content", 30);
	std::cout << getColorStr(FGREEN, ss.str()) << std::endl;
}

void Files::checkTargetStatus(std::string const& target, std::stringstream& ss)
{
	struct stat st;
	std::string strTarget(getColorFmt(FRED) + "Target '" + target + "' ");
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
		ss << strTarget << "does not exist";
	else if (isDirectory)
		ss << strTarget << "is a Directory";
	ss << C_END;
}

std::string Files::getInfo()
{
	std::ostringstream os;

	os << getColorFmt(FGRAY);
	os << className(typeid(*this).name());
	os << " " << _fileName;
	os << C_END;
	return (os.str());
}

std::ostream& operator << (std::ostream& os, Files& rhs)
{
	os << rhs.getInfo();
	return (os);
}

Files::FileError::FileError(std::string const& msg):
std::runtime_error(msg) {}
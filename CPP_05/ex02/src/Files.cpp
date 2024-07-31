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
	out(std::cout << *this << getColorStr(FGRAY, " was Created"));
	if (!_fileName.empty() && _fileMode != 0)
	{
		std::stringstream ss;
		if (!checkFileStatus(ss))
		{
			fileInfo();
			throw(FileError(ss.str()));
		}
		openFile();
	}
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
	out(std::cout << *this << getColorStr(FGRAY, " was Destroyed"));
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
		checkStreamFlags(*this);
		_file.clear();
		this->_file.close();
		if (this->_file.fail())
			throw (FileError(" Failed to close the file " + this->_fileName));
		std::cout << getColorStr(FGRAY, "File " + this->_fileName + " closed successfully.") << std::endl;
	}
	else
		std::cout << "File not open\n";
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


void Files::write(std::stringstream const& buffer)
{
	// openFile()
	_file << buffer.str();
	closeFile();
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
	if (_file.fail())
	{
		ss.clear();
		ss.str("");
		ss << error("Failed to open file " + _fileName, 0) << std::endl;
		throw (FileError("\n" + ss.str()));
		debug(FRED, ss.str());
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
void Files::checkStreamFlags(Files& file)
{
	std::stringstream ss;

	if (DEBUG == 0)
		return ;
	if (!file._file.good())
		std::cout << "*-----checkStreamFLAGS------" << std::endl;
	if (file._file.fail())
		ss << error("A I/O error has occurred in ", 0) << file._fileName << std::endl;
	if (file._file.bad())
		ss << error("A critical I/O error has occurred in ", 0) << file._fileName << std::endl;
	if (file._file.eof())
		ss << error("End of file has been reached in ", 0) << file._fileName << std::endl;
	std::cout << ss.str();
	if (!file._file.good())
		std::cout << "-----------*" << std::endl;
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

	if (checkFileStatus(ss) == 0)
		return ;
	_file.clear();
	openFile(std::ios::in);
	printTitle("File '" + _fileName + "' Content", 30);
	_file.seekg(0);
	ss << _file.rdbuf();
	printTitle("End of '" + _fileName + "' Content", 30);
	std::cout << getColorStr(FGREEN, ss.str()) << std::endl;
}

bool Files::checkDirectoryStatus(std::string const& path, std::stringstream& ss)
{
	struct stat st;
	bool status = false;

	if (stat(path.c_str(), &st) == 0)
	{
		if (access(path.c_str(), R_OK) == -1)
			ss << "No read permissions\n";
		if (access(path.c_str(), W_OK) == -1)
			ss << "No write permissions\n";
		status = S_ISDIR(st.st_mode);
	}
	if (status == 0)
		ss << "Directory does not exist\n";
	debug(DEFAULT, ss.str() + "\n");
	return (status);
}

bool Files::checkFileStatus(std::stringstream &ss)
{
	struct stat	st;
	bool		status = 0;

	if(stat(_fileName.c_str(), &st) == 0)
	{
		if (access(_fileName.c_str(), R_OK) == -1)
			ss << "No read permissions\n";
		if (access(_fileName.c_str(), W_OK) == -1)
			ss << "No write permissions\n";
		status = !checkDirectoryStatus(_fileName, ss);
	}
	if (status == 0)
	{
		ss << getColorStr(FLRED, "File '" + _fileName);
		ss << getColorStr(FLRED, "' does not exist or it is a Directory\n");
	}
	return (status);
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
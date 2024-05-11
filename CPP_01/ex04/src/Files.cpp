
#include "Files.hpp"

//filename, std::ios::in | std::ios::out
Files::Files()
{
	return ;
}

Files::Files(const char* fileName, std::ios_base::openmode mode): _file(fileName, mode), _fileName(fileName)
{
	fileExists();
	return ;
}


Files::Files(const char* fileName): _file(), _fileName(fileName)
{
	return ;
}

Files::Files(const Files &file): _file(), _fileName(file._fileName + ".replace")
{
	return ;
}

Files::Files(Files& file, const char* s1, const char* s2): _file(), _fileName(file._fileName + ".replace")
{
	openFile(std::ios::out);
	replaceInFile(file, s1, s2);
	return ;
}


Files::~Files()
{
	closeFile();
}

void Files::closeFile()
{
	if (_file.is_open())
		_file.close();
}

void Files::openFile(std::ios_base::openmode mode)
{
	closeFile();
	_file.open(_fileName.c_str(), mode);
	fileExists();
}

bool Files::fileExists()
{
	if (!_file.is_open())
		std::cout << "Failed to open the file.\n";
	return (1);
}

void Files::replaceInFile(Files& in, const std::string &s1, const std::string &s2)
{
	std::string line;

	
	 while (std::getline(in._file, line))
	{
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
			pos += s2.length();
		}
		_file << line << '\n';
	}
	closeFile();
}

void Files::replaceInFile(const std::string &s1, const std::string &s2)
{
	std::string			line;
	std::stringstream	buffer;
	
	openFile(std::ios::in);
	_file.clear();
	_file.seekg(0);
	while (std::getline(_file, line))
	{
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
			pos += s1.length();
		}
		buffer << line << '\n';
	}
	closeFile();
	_fileName.append(".replace2");
	openFile(std::ios::out | std::ios::trunc);
	_file << buffer.str();
}

void Files::copyFile(Files& in)
{
	
	in._file.seekg(0); // Go to the beginning of the file
	_file << in._file.rdbuf(); // Copy the content to the new file
	_file.close();
}


// std::ofstream ofs("file.txt");
// std::streambuf* original_cout_buffer = std::cout.rdbuf();  // save original buffer
// std::cout.rdbuf(ofs.rdbuf());  // redirect cout to file.txt

// std::cout << "This will be written to file.txt";

// std::cout.rdbuf(original_cout_buffer);  // restore original buffer
# ifndef FILES_HPP
#  define FILES_HPP
# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <sys/stat.h>
# include <unistd.h>

# ifndef DEBUG
#  define DEBUG 0
# endif


class Files
{
	private:
		std::string				_fileName;
		std::ios_base::openmode _fileMode;
		std::fstream			_file;
	public:
		// Files(void);
		//  Files(char* const& fileName="");
		explicit Files(std::string const& fileName = "", std::ios_base::openmode mode = static_cast<std::ios_base::openmode>(0));
		Files(Files& file);
		~Files();
		void			fileInfo(void);
		void			openFile(void);
		void			openFile(std::ios_base::openmode mode);
		void			openFile(const char* fileName, std::ios_base::openmode mode);
		std::string		getPath(std::string const& path);
		bool			checkEnv(std::string const& path, std::stringstream& ss);
		void			checkTargetStatus(std::string const& path, std::stringstream& ss);
		std::streampos	FileIsEmpty(std::fstream& file);
		void			write(std::stringstream const& buffer);
		void			closeFile(void);
		void			copyFile(Files& in);
		void			checkStreamFlags(Files& file);
		void			showContent(void);
		std::string		getInfo();
		class FileError : public std::runtime_error
		{
			public:
				explicit FileError(std::string const& msg);
		};
};

std::ostream& operator << (std::ostream& os, Files& rhs);
# endif
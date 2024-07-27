/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Files.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:09:22 by lilizarr          #+#    #+#             */
/*   Updated: 2024/07/27 16:21:51 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		std::fstream			_file;
		std::string				_fileName;
		std::ios_base::openmode _fileMode;
	public:
		Files(const char* fileName);
		Files(const char* fileName, std::ios_base::openmode mode);
		Files(Files& file);
		~Files();
		void fileIsOpen();
		void openFile();
		void openFile(std::ios_base::openmode mode);
		void openFile(const char* fileName, std::ios_base::openmode mode);
		void write(std::stringstream const& buffer);
		void closeFile();
		void copyFile(Files& in);
		void checkStreamFlags(Files& file);
		void showContent();
		void checkFileStatus(std::stringstream& ss);

		class FileError : public std::runtime_error
		{
			public:
				explicit FileError(std::string const& msg);
		};
};

# endif
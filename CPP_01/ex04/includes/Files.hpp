/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Files.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:09:22 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/15 15:33:21 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#pragma once
# ifndef FILES_HPP
#  define FILES_HPP
# include <iostream>
# include <fstream>
# include <sstream>
# include <string>

typedef enum eColor
{
	DEFAULT			= 0,
	FLBLACK			= 30,
	FLRED			= 31,
	FLGREEN			= 32,
	FLYELLOW		= 33,
	FLBLUE			= 34,
	FLMAGENTA		= 35,
	FLCYAN			= 36,
	FLGRAY			= 37,
	FLRGB			= 38, //\033[38;2;r;g;bm (rgb:from 0 to 255).
	FDEFAULT		= 39,
	FDARKGRAY		= 90,
	FRED			= 91,
	FGREEN			= 92,
	FYELLOW			= 93,
	FBLUE			= 94,
	FMAGENTA		= 95,
	FCYAN			= 96,
	FWHITE			= 97,
	COLOR_COUNT	 	= 27,
} t_color;

class Files
{
	private:
		std::fstream			_file;
		std::string				_fileName;
		std::ios_base::openmode _fileMode;
		bool					_status;
	public:
		Files();
		Files(const char* fileName, std::ios_base::openmode mode);
		Files(const char* fileName);
		Files(const Files& file);
		Files(Files& file, const char* s1, const char* s2);
		~Files();
		static std::string setColor(std::string msg, int color, int err);
		bool fileExists();
		void openFile(std::ios_base::openmode mode);
		void closeFile();
		void copyFile(Files& in);
		void replaceInFile(Files& in, const std::string &s1, const std::string &s2);
		void replaceInFile(const std::string &s1, const std::string &s2);
};

# endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Files.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:09:22 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/11 15:29:45 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#pragma once
# ifndef FILES_HPP
#  define FILES_HPP
# include <iostream>
# include <fstream>
# include <sstream>
# include <string>

class Files
{
	private:
		std::fstream	_file;
		std::string		_fileName;
	public:
		Files();
		Files(const char* fileName, std::ios_base::openmode mode);
		Files(const char* fileName);
		Files(const Files& file);
		Files(Files& file, const char* s1, const char* s2);
		~Files();
		bool fileExists();
		void openFile(std::ios_base::openmode mode);
		void closeFile();
		void copyFile(Files& in);
		void replaceInFile(Files& in, const std::string &s1, const std::string &s2);
		void replaceInFile(const std::string &s1, const std::string &s2);
};

# endif
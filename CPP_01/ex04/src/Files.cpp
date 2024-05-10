/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Files.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:09:42 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/10 17:52:34 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Files.hpp"

Files::Files()
{
}

Files::~Files()
{
}

void Files::replaceInFile(const std::string &fn, const std::string &s1, const std::string &s2)
{
	std::ifstream inFile(fn.c_str());
	std::ofstream outFile((fn + ".replace").c_str());
	std::string line;

	if (!inFile)
	{
		std::cerr << "Unable to open input file.\n";
		return;
	}
	if (!outFile)
	{
		std::cerr << "Unable to open output file.\n";
		return;
	}
	while (std::getline(inFile, line))
	{
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
			pos += s2.length();
		}
		outFile << line << '\n';
	}
}
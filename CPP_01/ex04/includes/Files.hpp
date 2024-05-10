/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Files.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:09:22 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/10 17:51:40 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#pragma once
# ifndef FILES_HPP
#  define FILES_HPP
# include <iostream>
# include <fstream>
# include <string>

class Files
{
	private:
		std::string _name;
	public:
		Files();
		~Files();
		void replaceInFile(const std::string& fn, const std::string& s1, const std::string& s2);
};

# endif
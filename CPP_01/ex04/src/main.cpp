/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:07:44 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/16 15:17:04 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Files.hpp"




int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << Files::setColor("Usage: ./replace filename s1 s2\n", FRED, 1);
		return (1);
	}
	else if (std::string(av[2]).empty() || std::string(av[3]).empty())
	{
		std::cerr << Files::setColor("s1 and s2 must not be empty.\n", FRED, 1);
		return (1);
	}
	else
	{
		{
			//Creates a Files object
			Files f1(av[1], std::ios::in);
			
			// //Reads from Files instances, creates another one 
			// // and writes to another file, adding ".replace" to the name
			Files f2(f1, av[2], av[3]);

		}
		{
			// Files f3(av[1]);
			// f3.replaceInFile(av[2], av[3]);
		}
		{
		// 	Files f3(av[1], std::ios::in | std::ios::out);
			// Files f4(av[1]);
			// // Creates a Files object with the same name as f1
			// Files f5(f4);
			
		}
		return (0);
	}
}

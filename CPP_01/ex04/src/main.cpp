/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:07:44 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/17 16:01:44 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Files.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
		std::cerr << Files::setColor("Usage: ./replace filename s1 s2\n", FRED, 1);
	else if (std::string(av[2]).empty() || std::string(av[3]).empty())
		std::cerr << Files::setColor("s1 and s2 must not be empty.\n", FRED, 1);
	else try 
	{
		{
			std::cout << "-------Ex 1--------------" << std::endl;
			// Creates a Files object
			Files f1(av[1], std::ios::in);
			// Reads from Files instances, creates another one 
			// and writes to another file, adding ".replace" to the name
			Files f2(f1, av[2], av[3]);
			
		}
		{
			std::cout << "----------Ex 2-----------" << std::endl;
			// Open File with open mode(read, write)
			Files f3(av[1]);
			f3.replaceInFile(av[2], av[3]);
		}
		{
			std::cout << "--------Ex 3-------------" << std::endl;
			// Creates a Files object and open files wirth open mode(read, write)
			Files f4(av[1]);
			// Creates a Files object with the same name as f1
			Files f5(f4);
			f5.replaceInFile(av[2], av[3]);
		}
		{
			std::cout << "--------Ex 4-------------" << std::endl;
			Files f6;
			f6.replaceInFile(av[1], av[2], av[3]);
		}
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
	return (1);
}


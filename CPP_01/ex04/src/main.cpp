/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:12:14 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/17 17:14:45 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Files.hpp"

int main(int ac, char **av)
{
	int exceptionCount = 0;

	if (ac != 4)
		std::cerr << Files::setColor("Usage: ./replace filename s1 s2\n", FRED, 1);
	else if (std::string(av[2]).empty() || std::string(av[3]).empty())
		std::cerr << Files::setColor("s1 and s2 must not be empty.\n", FRED, 1);
	else
	{
		try
		{
			std::cout << "-------Ex 1--------------" << std::endl;
			Files f1(av[1], std::ios::in);
			Files f2(f1, av[2], av[3]);
		}
		catch (const std::runtime_error& e)
		{
			std::cerr << "Exception in block 1: " << e.what() << std::endl;
			exceptionCount++;
		}

		try 
		{
			std::cout << "----------Ex 2-----------" << std::endl;
			Files f3(av[1]);
			f3.replaceInFile(av[2], av[3]);
		}
		catch (const std::runtime_error& e)
		{
			std::cerr << "Exception in block 2: " << e.what() << std::endl;
			exceptionCount++;
		}

		try 
		{
			std::cout << "--------Ex 3-------------" << std::endl;
			Files f4(av[1]);
			Files f5(f4);
			f5.replaceInFile(av[2], av[3]);
		}
		catch (const std::runtime_error& e)
		{
			std::cerr << "Exception in block 3: " << e.what() << std::endl;
			exceptionCount++;
		}

		try 
		{
			std::cout << "--------Ex 4-------------" << std::endl;
			Files f6;
			f6.replaceInFile(av[1], av[2], av[3]);
		}
		catch (const std::runtime_error& e)
		{
			std::cerr << "Exception in block 4: " << e.what() << std::endl;
			exceptionCount++;
		}
		return (exceptionCount > 0 ? \
		(std::cerr << Files::setColor("No Files object created\n", FRED, 1), 1) : 0);
	}
}


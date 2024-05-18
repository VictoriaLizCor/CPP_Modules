/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:12:14 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/18 15:18:21 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Files.hpp"

static void checkStrings(std::string s1, std::string s2)
{
	std::stringstream ss;
	if (s2.find(s1) != std::string::npos)
	{
		ss << Files::setColor("Warning: S2 '" + s2 + "' contains S1'" + s1 + "'\n", FLYELLOW, 0);
		std::cout << ss.str();
		ss.clear();
	}
}

int main(int ac, char **av)
{
	bool eFlag = 0;

	if (ac != 4)
		std::cerr << Files::setColor("Usage: ./replace filename s1 s2\n", FRED, 1);
	else if (std::string(av[2]).empty() || std::string(av[3]).empty())
		std::cerr << Files::setColor("s1 and s2 must not be empty.\n", FRED, 1);
	else
	{
		checkStrings(av[2], av[3]);
		try
		{
			std::cout << "-------Ex 1--------------" << std::endl;
			Files f1(av[1], std::ios::in);
			Files f2(f1, av[2], av[3]);
		}
		catch (const std::runtime_error& e)
		{
			std::cerr << e.what() << std::endl;
			eFlag = 1;
		}

		try 
		{
			std::cout << "----------Ex 2-----------" << std::endl;
			Files f3(av[1]);
			f3.replaceInFile(av[2], av[3]);
		}
		catch (const std::runtime_error& e)
		{
			std::cerr << e.what() << std::endl;
			eFlag = 1;
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
			std::cerr << e.what() << std::endl;
			eFlag = 1;
		}

		try 
		{
			std::cout << "--------Ex 4-------------" << std::endl;
			Files f6;
			f6.replaceInFile(av[1], av[2], av[3]);
		}
		catch (const std::runtime_error& e)
		{
			std::cerr << e.what() << std::endl;
			eFlag = 1;
		}
		if (eFlag)
			std::cerr << "\n" <<Files::setColor("A problem happened during Object creation\n", FLRED, 1);
		return (eFlag ?  1 : 0);
	}
	return (1);
}


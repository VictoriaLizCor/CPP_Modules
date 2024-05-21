/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:32:05 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/21 14:03:58 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <cstdlib>
#include <ctime>

int	main()
{
	Harl		harl;
	std::string	types[Harl::N_TYPE] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			randomTest;
	std::string randomStr;
	int			strLen = 0;
	int			randomNum;

	srand(time(0));
	randomTest = rand() % 8 + 3;
	std::cout << "\033[1;39mThis will run Harl::complain for " << randomTest << " times \033[0m" << std::endl;
	strLen = rand() % 10 + 1;
	for(int i = 0; i < strLen; i++)
	{
		char random_char = 'a' + rand() % 26; // generate a random character between 'a' and 'z'
		randomStr += random_char;
	}
	randomStr = "\033[1;39m" + randomStr + "\033[0m";
	std::cout << "Random string is : " << randomStr << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < randomTest; i++)
	{
		randomNum = rand() % 5;
		if (randomNum < Harl::N_TYPE)
			harl.complain(types[randomNum]);
		else
			harl.complain(randomStr);
	}
	return (0);
}
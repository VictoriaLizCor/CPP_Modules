/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:22:17 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/03 17:37:05 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#if (DEBUG == 1)
#include <cstdlib> 
static std::string	rColorRGB(int red, int green, int blue)
{
	std::stringstream ss;

	ss << C_FMT<< "1;" << FLRGB << ";2;";
	ss << red << ";" << green << ";" << blue << "m";
	return (ss.str());
}

static int ft_rand()
{
	return (rand() % 128 + 128);
}
std::string rColor(std::string msg, int bold)
{
	std::stringstream strColor;
	std::string	fmt;

	fmt = C_FMT;
	if (bold)
		fmt = fmt + "1;";
	strColor << fmt << rColorRGB(ft_rand(), ft_rand(), ft_rand());
	return (strColor.str() + msg + C_DEFAULT);
}

int	main(void)
{
	std::srand(std::time(0));
	
	Zombie z1;
	Zombie z3(rColor("Robb", 1));
	Zombie z2(rColor("Ned", 1));
	Zombie* z4 = newZombie(rColor("Rick", 1));
	randomChump(rColor("Cate", 1));
	{
		Zombie* z5 = newZombie(rColor("HEAP", 1));
		delete z5;
		z4->announce();
		delete z4;
	}
	// delete z5;
	{
		Zombie z6(rColor("STACK", 1));
		z6.announce();
	}
	// z6.announce();
	return (0);
}
#else
int	main(void)
{	
	Zombie z1;
	Zombie z3("Robb");
	Zombie z2("Ned");
	Zombie* z4 = newZombie("Rick");
	randomChump("Cate");
	z1.announce();
	{
		Zombie* z5 = newZombie("HEAP");
		delete z5;
	}
	// delete z5;
	{
		Zombie z6("STACK");
		z6.announce();
		Zombie*	z7 = newZombie("HEAP2");
		z7->announce();
		delete z7;
	}
	delete z4;
	// z6.announce();
	return (0);
}
#endif
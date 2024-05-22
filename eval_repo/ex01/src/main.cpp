/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:22:17 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/07 17:27:11 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
//
int	main(void)
{
	int N = 3;
#if (DEBUG == 1)
	std::srand(time(0));

	std::cout << "********** Z2 **************"<< std::endl;
	
	Zombie* z2 = zombieHorde2(N, "Jofrey");
	for (int i = 0; i < N; i++)
		z2[i].announce();
	delete[] z2;
	{
		std::cout << "********** Z3 **************"<< std::endl;
		
		Zombie** z3 = ptrzombieHorde(N, "Tywin");

		for (int i = 0; i < N; i++)
		{
			z3[i]->announce();
			delete z3[i];
		}
		delete[] z3;
	}
#else
	std::cout << "********** Z1 ************"<< std::endl;
	Zombie* z1;

	z1 = zombieHorde(N, "Cersei");
	{
		{
			std::cout << "********** Z1 ************"<< std::endl;
			for (int i = 0; i < N; i++)
				z1[i].announce();
			delete[] z1;
		}
	}
	// z1[0].announce();
#endif
	std::cout << "************************"<< std::endl;
	return (0);
}
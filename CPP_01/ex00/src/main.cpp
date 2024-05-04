/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:22:17 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/04 14:12:54 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
#if (DEBUG == 1)
	std::srand(time(0));
#endif
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
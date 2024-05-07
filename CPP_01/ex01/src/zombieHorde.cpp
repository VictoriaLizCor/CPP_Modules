/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:35:45 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/07 17:34:21 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	std::ostringstream newName;

	Zombie *z = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		newName << name << "-" << i + 1;
		z[i].setName(newName.str()); 
		newName.str("");
	}
	return (z);
}

#if (DEBUG != 0)

Zombie* zombieHorde2(int N, std::string name)
{

	Zombie *z = new Zombie[N];
	// COPY CONSTRUCTOR EXAMPLE
	// Zombie z= Zombie("Unknown2");
	for (int i = 0; i < N; i++)
	{
		{
			std::ostringstream	newName;

			std::cout << "********** stack"<< std::endl;
			Zombie stack(name + "0");
			//copy assigment operator giving by the compiler
			z[i] = stack;
			newName << name << "-" << i + 1;
			z[i].setName(newName.str()); 	
		}
	}
	std::cout << "********** "<< std::endl;
	return (z);
}

Zombie** ptrzombieHorde(int N, std::string name)
{
	std::ostringstream newName;

	Zombie **z = new Zombie*[N];

	for (int i = 0; i < N; i++)
	{
		newName << name << "-" << i + 1;
		z[i] = new Zombie(newName.str());
		newName.str("");
	}
	return (z);
}
#endif

// The Zombie Class has a default constructor.
// There is a zombieHorde() function prototyped as: [ Zombie* zombieHorde( int N, std::string name ); ]
// It allocates N zombies on the heap explicitly using new[].
// After the allocation, there is an initialization of the objects to set their name.
// It returns a pointer to the first zombie.
// There are enough tests in the main to prove the previous points.
// Like: calling announce() on all the zombies.
// Last, all the zombies should be deleted at the same time in the main.
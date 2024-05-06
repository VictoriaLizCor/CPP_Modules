/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:35:45 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/06 17:02:19 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	std::stringstream newName;

	Zombie *horde = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		newName << name << i + 1;
		horde[i] = Zombie(newName.str());
		horde[i].announce();
		newName.str("");
	}
	return (horde);
}
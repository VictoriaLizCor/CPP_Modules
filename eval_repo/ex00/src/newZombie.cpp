/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:21:41 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/06 12:24:20 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Creates a new Zombie object with the given name.
 * 
 * @param name The name of the Zombie.
 * @return A pointer to the newly created Zombie object.
*/
Zombie* newZombie(std::string name)
{
	Zombie*	z;
	
	z = new Zombie(name);
	return (z->announce(), z);
}

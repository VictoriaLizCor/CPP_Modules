/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:21:17 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/10 14:47:57 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Creates a Zombie object with the given name and announces it.
 * 
 * @param name The name of the Zombie.
 */
void	randomChump(std::string name)
{
	Zombie z(name);
	z.announce();
}

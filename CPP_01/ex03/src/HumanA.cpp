/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:09:04 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/10 14:47:10 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/**
 * @brief Destructor for the HumanA class.
 *
 * This destructor is responsible for cleaning up any resources allocated by the
 * HumanA class. It is automatically called when an instance of the HumanA class
 * is destroyed.
 */
HumanA::~HumanA()
{
}

/**
 * @brief Performs an attack action using the weapon of the HumanA object.
 * 
 * This function prints a message indicating that the HumanA object is attacking
 * with its weapon.
 */
void	HumanA::attack()
{
	std::cout << _name << " attacks with his " << _weapon.getType() << std::endl;
}

	
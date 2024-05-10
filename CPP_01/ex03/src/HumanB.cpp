/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:09:01 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/10 14:46:03 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/**
 * @brief Destructor for the HumanB class.
 * 
 * This destructor is responsible for cleaning up any resources
 * allocated by the HumanB class.
 */
HumanB::~HumanB()
{
}

/**
 * @brief Performs an attack action.
 *
 * If the HumanB has a weapon, it attacks using the weapon's type. If the HumanB
 * does not have a weapon, it attacks with its unarmed hands.
 */
void	HumanB::attack()
{
	if (_weapon == NULL)
		std::cout << _name << " strikes with his unarmed hands(most likely, will die)" << std::endl;
	else
		std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
}

/**
 * @brief Sets the weapon for the HumanB object.
 * 
 * This function sets the weapon for the HumanB object by assigning the address
 * of the weapon object to the _weapon member variable.
 *
 * @param weapon The weapon object to be set.
 */
void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:10:30 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/10 14:46:46 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/**
 * @brief Destructor for the Weapon class.
 * 
 * This destructor is responsible for cleaning up any resources
 * allocated by the Weapon class.
 */
Weapon::~Weapon()
{
}

/**
 * @brief Get the type of the weapon.
 * 
 * @return const std::string& The type of the weapon.
 */
const	std::string &Weapon::getType()
{
	return _type;
}

/**
 * @brief Sets the type of the weapon.
 * 
 * This function sets the type of the weapon to the specified value.
 * 
 * @param type The type of the weapon.
 */
void	Weapon::setType(std::string type)
{
	_type = type;
}
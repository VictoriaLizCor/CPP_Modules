/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:32:54 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/21 09:02:24 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# ifndef HUMANB_HPP
#  define HUMANB_HPP
# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB
{
	private:
		std::string _name;
		Weapon		*_weapon;

	public:
		HumanB(std::string name);
		~HumanB();
		void	setWeapon(Weapon &weapon);
		void	attack();
};

# endif
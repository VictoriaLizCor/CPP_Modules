/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:35:51 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/08 16:25:09 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# ifndef WEAPON_HPP
#  define WEAPON_HPP
# include <iostream>
# include <string>

class Weapon
{
	private:
		std::string _type;

	public:
		Weapon(std::string type):_type(type){};
		~Weapon();
		
};

# endif
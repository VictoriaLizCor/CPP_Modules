/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UtilsFunctions.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:56:07 by lilizarr          #+#    #+#             */
/*   Updated: 2024/04/18 13:48:57 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILSFUNCTIONS_H
# define UTILSFUNCTIONS_H
# pragma once
# include <iostream>
# include <string>

typedef enum eColor
{
	DEFAULT		= 0,
	FRED		= 31,
	FGREEN		= 32,
	FBLUE		= 34,
	FDEFAULT	= 39,
	BRED		= 41,
	BGREEN		= 42,
	BBLUE		= 44,
	BDEFAULT	= 49
} t_color;

void		println(std::string str);
std::string	color(std::string msg, int color, bool err);
bool		checkInput(const std::string& str, int (*check_type)(int));

#endif

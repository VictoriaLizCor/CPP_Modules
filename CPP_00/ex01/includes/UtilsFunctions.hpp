/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UtilsFunctions.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:56:07 by lilizarr          #+#    #+#             */
/*   Updated: 2024/04/17 13:16:44 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILSFUNCTIONS_H
# define UTILSFUNCTIONS_H
# pragma once
# include <iostream>
# include <string>

void	println(std::string str);
bool	checkInput(const std::string& str, int (*func)(int));

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:32:05 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/22 10:10:01 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl		harl;

	if (ac != 2)
	{
		harl.complain(harl.checkType(harl.ERROR));
		std::cout << "\033[A Usage: " << av[0] << " \"string\" \n" << std::endl;
		return (1);
	}
	harl.complain(av[1]);
	return (0);
}
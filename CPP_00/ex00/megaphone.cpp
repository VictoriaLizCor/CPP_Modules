/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:55:53 by lilizarr          #+#    #+#             */
/*   Updated: 2024/04/10 16:33:16 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include <cstring>

void	ft_str(char *str)
{
	std::string s(str);
}

int	main(int argc, char *argv[])
{
	if (argc != 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			ft_str(argv[i]);
		}
	}
	return (0);
}


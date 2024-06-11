/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 09:49:47 by lilizarr          #+#    #+#             */
/*   Updated: 2024/06/11 16:47:38 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

int main(void)
{
#if (DEBUG == 0)
{
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;
	
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	
	return (0);
}
#else
{
	Fixed a;
	println("-----------");
	Fixed b(a);
	println("-----------");
	Fixed c;
	println("-----------");
	
	std::cout << "a " << a.getRawBits() << std::endl;
	println("-----------");
	a.setRawBits(42.50);
	c = a;
	std::cout << "a " << a.getRawBits() << std::endl;
	println("-----------");
	std::cout << "b " <<b.getRawBits() << std::endl;
	std::cout << "c " <<c.getRawBits() << std::endl;
	return (0);
}
#endif
}

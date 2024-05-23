/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 09:49:47 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/23 12:58:39 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

int main(void)
{
#if (DEFAULT == 0)
{
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;
	
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
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
	a.setRawBits(52);
	c = a;
	std::cout << "a " << a.getRawBits() << std::endl;
	println("-----------");
	std::cout << "b " <<b.getRawBits() << std::endl;
	std::cout << "c " <<c.getRawBits() << std::endl;
}
#endif
	return (0);
}
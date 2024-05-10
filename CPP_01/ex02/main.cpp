/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:44:44 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/10 14:01:13 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/**
 * `std::string *stringPTR = &str;` - This line declares a pointer to a
 * `std::string` named `stringPTR`. It is initialized with the address of `str`,
 * so it points to `str`.
 *
 * `std::string &stringREF = str;` - This line declares a reference to a
 * `std::string` named `stringREF`. Here, `stringREF` is an alias for existing
 * `str`. Any changes made to `stringREF` will directly affect `str`, and vice
 * versa, because they are the SAME OBJECT.
 * A reference is just an alias for an existing variable, so it doesn't have
 * its own memory address. When you take the address of a reference, you're 
 * actually getting the address of the original variable it refers to.
*/
int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;
	
	std::cout << "Memory addres of str variable: \t\t" << &str << std::endl;
	std::cout << "Memory addres held by stringPTR: \t" << stringPTR << std::endl;
#if (DEBUG == 1)
	std::cout << "Memory addres of stringPTR variable: \t" << &stringPTR << std::endl;
#endif
	std::cout << "Memory addres held by stringPTR: \t" << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "Value of str variable: \t\t" << str << std::endl;
	std::cout << "Value pointed by stringPTR: \t" << *stringPTR << std::endl;
	std::cout << "Value pointed by stringREF: \t" << stringREF << std::endl;
#if (DEBUG == 1)
	std::cout << std::endl;
	str = "HI THIS IS BRAIN 2";
	std::cout << "New value pointed by stringREF: \t" << stringREF << std::endl;
	stringREF = "HI THIS IS BRAIN 3";
	std::cout << "New value of str variable: \t\t" << str << std::endl;
#endif
	return (0);
}
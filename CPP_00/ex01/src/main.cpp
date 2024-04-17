/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:26:55 by lilizarr          #+#    #+#             */
/*   Updated: 2024/04/17 12:03:11 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Phonebook.hpp>

int main()
{
	PhoneBook	phonebook;
	
	phonebook.showMenu();
	return (0);
}


/*
void set_contact(int i, const std::string& value) {
		if (i >= 0 && i < NFields) {
			set_value(static_cast<InfoField>(i), value);
		}
		else {
			// handle error, e.g., throw an exception or return an error code
		}
	}

	while(i < Contact::NFields)
	{
		std::cout << "Enter " << c.InfoFieldToString(i) << ": " << std::endl;
		std::getline(std::cin, str);
		if (str.empty())
			std::cout <<"Field cannot be empty." << std::endl;
		else
			c.set_contact(i++, str);
	}

	
*/
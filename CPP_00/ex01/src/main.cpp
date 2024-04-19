/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:26:55 by lilizarr          #+#    #+#             */
/*   Updated: 2024/04/19 16:40:56 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Phonebook.hpp>


int main()
{
#if (DEBUG == 0)
	PhoneBook	phonebook;
else
	Contact contacts[8] = {
	Contact("John Doe", "1234567890", "johndoe@example.com"),
	Contact("Jane Doe", "0987654321", "janedoe@example.com"),
	};
	PhoneBook phonebook(contacts);
#endif
	phonebook.showPhonebookMenu();
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
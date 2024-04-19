/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:26:55 by lilizarr          #+#    #+#             */
/*   Updated: 2024/04/19 17:26:24 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Phonebook.hpp>

#ifndef DEBUG
# define DEBUG 0
#endif

int main()
{
#if (DEBUG == 0)
	PhoneBook	phonebook;
#else
	std::string info1[Contact::N_FIELDS] = {"Victoria", "Lizarraga", "Vicki", "1234567890", "adfasdfasdfasdf"};
	std::string info2[Contact::N_FIELDS] = {"Diane", "Ruge", "Dian", "09871234", "zxfsdfasdfasdfewr"};
	Contact contacts[2] = {Contact(info1), Contact(info2)};
	PhoneBook phonebook(contacts, 2);
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
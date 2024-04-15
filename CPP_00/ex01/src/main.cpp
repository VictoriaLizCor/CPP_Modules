/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:46:15 by lilizarr          #+#    #+#             */
/*   Updated: 2024/04/15 16:47:10 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <Phonebook.hpp>

std::string InfoFieldToString(Contact::InfoField field) {
	switch(field)
	{
		case Contact::FirstName: return "First Name";
		case Contact::LastName: return "Last Name";
		case Contact::Nickname: return "Nickname";
		case Contact::PhoneNumber: return "Phone Number";
		case Contact::DarkestSecret: return "Darkest Secret";
		default: return "Unknown";
	}
}

int main() {
	Contact c;
	std::string str;
	int i = 0;

	while(i < Contact::NFields)
	{
		std::cout << "Enter " << InfoFieldToString(static_cast<Contact::InfoField>(i)) << ": " << std::endl;
		std::getline(std::cin, str);
		if (str.empty())
			std::cout <<"Field cannot be empty." << std::endl;
		else
			c.set_contact_value(static_cast<Contact::InfoField>(i++), str);
	}
	i = 0;
	while(i < Contact::NFields)
	{
		std::cout << InfoFieldToString(static_cast<Contact::InfoField>(i)) << ": " \
		<< c.get_contact_value(static_cast<Contact::InfoField>(i)) << std::endl;
		i++;
	}

	return 0;
}
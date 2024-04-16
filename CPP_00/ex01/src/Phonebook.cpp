/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:35:04 by lilizarr          #+#    #+#             */
/*   Updated: 2024/04/16 16:08:06 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Phonebook.hpp"

//*****************************PUBLIC**************************************//
PhoneBook::PhoneBook(void)
{
	std::cout << "PhoneBook constructor called" << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook destructor called" << std::endl;
	return ;
}


bool check_value(const std::string& str, int (*func)(char))
{
	std::string::const_iterator it;
	
	it = str.begin();
	while (it != str.end())
	{
		if (!func(*it))
			return false;
		it++;
	}
	return true;
}
// check_value (str, isalpha);
// check_value (str, isdigit);

// void PhoneBook::_add(Contact* contact)
// {
// 	if (PhoneBook::_contactCount < 8) {
// 		this->_contacts[PhoneBook::_contactCount++] = *contact;
// 	} else {
// 		printOut("Phonebook is full, first contact will be replaced");
// 		this->_contacts[0] = *contact;
// 	}
// }

// void PhoneBook::addContact()
// {
// 	Contact contact;

// 	_getInfo("First name", contact);
// 	_getInfo("Last name", contact);
// 	_getInfo("Nickname", contact);
// 	_getInfo("Phone number", contact);
// 	_getInfo("Darkest secret", contact);

// 	this->_add(&contact);
// }

// void PhoneBook::_getInfo(const std::string& fieldName, Contact& contact)
// {
// 	std::string buffer;
// 	while (buffer.empty()) {
// 		printOut("Enter " + fieldName + ": ");
// 		std::getline(std::cin, buffer);
// 		if (buffer.empty()) {
// 			printOut("Field cannot be empty");
// 		}
// 	}
// 	contact.setValue(fieldName, buffer);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:05:49 by lilizarr          #+#    #+#             */
/*   Updated: 2024/04/24 12:46:27 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

//*****************************PRIVATE**************************************//
void	PhoneBook::_checkAdd(Contact& contact)
{
	if (_contactIndex < _MAX_CONTACTS)
	{
		_contacts[_contactIndex++] = contact;
	}
	else
	{
		println(color("Phonebook is full, last added contact will be replaced", FRED, 1));
		_contacts[_MAX_CONTACTS - 1] = contact;
	}
}

//*****************************PUBLIC**************************************//

PhoneBook::PhoneBook(void)
{
	_contactIndex = 0;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void PhoneBook::addContact()
{
	std::string	str;
	Contact		contact;
	int			i;
	int			err;

	i = 0;
	contact.updateIndex(_contactIndex + 1);
	while(i < Contact::N_FIELDS)
	{
		err = 0;
		println(color("Enter " + contact.fieldToString(i) + ": ", FBLUE, 0));
		std::getline(std::cin, str);
		if (str.empty() || isOnlySpaces(str))
		{
			err = 1;
			str = contact.fieldToString(i) + " field cannot be empty.";
		}
		else
			AddContactExt(i, contact, str, err);
		if (err)
		{
			str = "Contact [" + toString(contact.index) + "]: " + str;
			println(color(str , FRED, 1));
		}
		else
			i++;
	}
	_checkAdd(contact);
}

void	PhoneBook::displayPhonebook(int size)
{
	std::string	contactFieldsArray[size];
	std::string	contactValuesArray[size];
	int			i;

	i = 0;
	fieldToStringArray(contactFieldsArray, size, _contacts[0], &Contact::fieldToString);
	println("");
	formatedText( FDEFAULT, "Index", size, contactFieldsArray);
	while(i < _contactIndex)
	{
		fieldToStringArray(contactValuesArray, size, _contacts[i], &Contact::getValue);
		formatedText( DEFAULT, toString(i + 1), size, contactValuesArray);
		i++;
	}
}

void	PhoneBook::searchContact()
{
	std::string	index;
	int			err;
	int			idx;

	err = 0;
	idx = 0;
	if (_contactIndex == 0)
	{
		index = color("\nPhonebook empty. Please add a contact first.", FDEFAULT, 0);
		println(index);
		return ;
	}
	while (1)
	{
		displayPhonebook(Contact::NICKNAME + 1);
		std::cout << "\nEnter contact index to display: ";
		std::getline(std::cin, index);
		println("");
		searchContactExt(index, idx, err, _contactIndex);
		if (err)
			println(color("Invalid choice. Please try again.", FRED, 1));
		else
		{
			showContactInfo(_contacts[idx], Contact::N_FIELDS, index);
			break;
		}
	}
}

void	PhoneBook::showPhonebookMenu()
{
	std::string	choice;

	while (1)
	{
		menuOptions();
		std::cout << "\nEnter your choice: ";
		std::getline(std::cin, choice);
		println("");
		if (choice == ADD)
			addContact();
		else if (choice == SEARCH)
			searchContact();
		else if (choice == EXIT)
			break;
		else
			println(color("Invalid choice. Please try again.", FRED, 1));
	}
	println(color("GOOD BYE!", FBLUE, 0));
	println(color("PS: No data was stored\n", FBLUE, 0));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:05:49 by lilizarr          #+#    #+#             */
/*   Updated: 2024/04/26 16:48:30 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

//*****************************PRIVATE**************************************//
void	PhoneBook::_checkAdd(Contact& contact)
{	
	std::string	str;

	if (_contactIndex < _MAX_CONTACTS)
	{
		int	tmp;

		tmp = _contactIndex;
		_contacts[_contactIndex++] = contact;
		_contacts[tmp].updateIndex(_contactIndex);
		str = color("Contact [" + toString(_contacts[tmp].index) + "]", FLCYAN, 0);
		str = str + color(" added succesfully", FLBLUE, 0);
		println(str);
	}
	else
	{
		_contacts[_MAX_CONTACTS - 1] = contact;
		str = color("Contact [" + toString(_contactIndex) + "]", FLCYAN, 0);
		str = str + color(" updated succesfully", FLBLUE, 0);
		println(str);
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
	if (_contactIndex >= 0 && _contactIndex < _MAX_CONTACTS)
		contact.updateIndex(_contactIndex + 1);
	else
		contact.updateIndex(_contactIndex);
	while(i < Contact::N_FIELDS)
	{
		err = 0;
		std::cout<< color("Enter " + contact.fieldToString(i) + ": ", FLCYAN, 0);
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
	println("");
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
		formatedText(DEFAULT, toString(i + 1), size, contactValuesArray);
		i++;
	}
}

bool	PhoneBook::_checkEmpyPhonebook()
{
	if (_contactIndex == 0)
	{
		println(color("\nPhonebook empty. Please add a contact first.", FDEFAULT, 0));
		return (true);
	}
	return (false);
}

void	PhoneBook::searchContact()
{
	std::string	index;
	int			err;
	int			idx;

	err = 0;
	idx = 0;
	if (_checkEmpyPhonebook())
		return ;
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

bool	PhoneBook::_checkFullPhonebook()
{
	std::string	choice;

	if (_contactIndex == _MAX_CONTACTS)
	{
		println(color("\nWarning: Phonebook is full, last added contact will be replaced\n", FYELLOW, 0));
		while(true)
		{
			std::cout << color("Continue yes/no (y/n))? ", FDEFAULT, 0);
			std::getline(std::cin, choice);
			println("");
			for (int i = 0; choice[i]; i++)
				choice[i] = std::tolower(choice[i]);
			if (choice == "yes" || choice == "y")
				return (true);
			else if (choice == "no" || choice == "n")
				return (false);
		}
	}
	return (true);
}

void	PhoneBook::showPhonebookMenu()
{
	std::string	choice;

	while (choice != EXIT)
	{
		menuOptions();
		std::cout << "\nEnter your choice: ";
		std::getline(std::cin, choice);
		println("");
		if (choice == ADD)
		{
			if (_checkFullPhonebook())
				addContact();
		}
		else if (choice == SEARCH)
			searchContact();
		else if (choice != EXIT)
			println(color("Invalid choice. Please try again.", BRED, 1));
	}
	println(color("GOOD BYE!", FBLUE, 0));
	println(color("PS: No data was stored\n", FBLUE, 0));
}

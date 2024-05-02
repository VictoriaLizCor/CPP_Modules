/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:05:49 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/02 14:35:34 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

//*****************************PRIVATE**************************************//
/**
 * @brief Checks and adds a new contact to the phone book.
 *
 * This method takes a reference to a Contact object as input and adds it to the
 * phone book. If the phone book is not full, the contact is added and its index
 * is updated. If the phone book is full, the contact replaces the last contact
 * in the book. After the contact is added or updated, a success message is
 * printed.
 *
 * @param contact The Contact object to be added or updated in the phone book.
 */
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
		_contacts[_updatedIndex] = contact;
		str = color("Contact [" + toString(_updatedIndex + 1) + "]", FLCYAN, 0);
		str = str + color(" updated succesfully", FLBLUE, 0);
		_updatedIndex++;
		if (_updatedIndex == _MAX_CONTACTS)
			_updatedIndex = 0;
		println(str);
	}
}

//*****************************PUBLIC**************************************//

/**
 * @brief Default constructor for the PhoneBook class.
 */
PhoneBook::PhoneBook(void)
{
	_contactIndex = 0;
	_updatedIndex = 0;
}

/**
 * @brief Destructor for the PhoneBook class.
 * 
 * This destructor is responsible for cleaning up any resources
 * allocated by the PhoneBook class.
 * called with delete operator if the object was created with new operator
 */
PhoneBook::~PhoneBook(void)
{
	return ;
}

/**
 * @brief Adds a new contact to the phone book.
 *
 * This method prompts the user to enter details for a new contact. The details
 * are then used to create a Contact object, which is added to the phone book.
 * If the phone book is already full, the oldest contact is replaced with the
 * new one. If a field is left empty or contains only spaces, an error message
 * is displayed and the user is prompted to enter the field again.
 */
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
		contact.updateIndex(_updatedIndex + 1);
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

/**
 * @brief Displays the contacts in the phone book.
 *
 * This method takes an integer size as input, which represents the number of
 * fields in a contact. It creates two arrays of strings, one for the field
 * names and one for the field values. It then prints the field names and the
 * values for each contact in the phone book. The contacts are printed in the
 * order they were added, with the index of each contact displayed first.
 *
 * @param size The number of fields in a contact.
 */
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

/**
 * @brief Checks if the phone book is empty.
 *
 * This method checks if there are any contacts in the phone book. If the phone
 * book is empty (i.e., no contacts have been added), it prints a message to the
 * user and returns true. If the phone book is not empty, it returns false.
 *
 * @return true if the phone book is empty, false otherwise.
 */
bool	PhoneBook::_checkEmpyPhonebook()
{
	if (_contactIndex == 0)
	{
		println(color("\nPhonebook empty. Please add a contact first.", FDEFAULT, 0));
		return (true);
	}
	return (false);
}

/**
 * @brief Searches for a contact in the phone book.
 *
 * This method prompts the user to enter the index of a contact to display.
 * If the entered index is valid, it displays the details of the contact.
 * If the entered index is not valid, it prints an error message and prompts
 * the user to enter the index again.
 * If the phone book is empty, it returns without doing anything.
 */
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

/**
 * @brief Checks if the phone book is full.
 *
 * This method checks if the phone book has reached its maximum capacity.
 * If it is full, it warns the user that the last added contact will be
 * replaced and asks for confirmation to proceed. If the user confirms,
 * it returns true; otherwise, it returns false. If the phone book is not
 * full, it returns true without asking for confirmation.
 *
 * @return true if the user confirms to proceed or the phone book is not
 * full, false otherwise.
 */
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

/**
 * @brief Displays the phone book menu and handles user input.
 *
 * This method displays the phone book menu options and prompts the user
 * to enter a choice. Depending on the user's choice, it calls the
 * appropriate method to add a contact or search for a contact. If the
 * user's choice is not recognized, it prints an error message and
 * prompts the user to enter a choice again. The menu loop continues
 * until the user chooses to exit. When the user exits, it prints a
 * goodbye message and a note that no data was stored.
 */

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

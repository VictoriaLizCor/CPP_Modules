/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:29:22 by lilizarr          #+#    #+#             */
/*   Updated: 2024/04/29 15:41:26 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

#if (DEBUG != 0)

/**
 * @brief Constructs a PhoneBook object with the given array of contacts and size.
 * 
 * @param contacts The array of contacts.
 * @param size The size of the array.
 */
PhoneBook::PhoneBook(Contact contacts[], int size)
{
	int		i;

	_contactIndex = 0;
	for (i = 0; i < size; i++)
	{
		if (_checkFullPhonebook())
			addContact(contacts[i]);
	}
}

/**
 * @brief Adds a new contact to the phone book.
 *
 * This method takes a Contact object as input and adds it to the phone book.
 * Before adding the contact, it checks each field of the contact for validity.
 * If a field is empty or contains only spaces, an error message is printed and
 * the contact is not added. If all fields are valid, the contact is added to
 * the phone book.
 *
 * @param contact The Contact object to be added to the phone book.
 */
void PhoneBook::addContact(Contact contact)
{
	std::string	str;
	int		i;
	int		err;
	bool	exitFlag;
	
	i = 0;
	exitFlag = false;
	contact.updateIndex(_contactIndex + 1);
	while(i < Contact::N_FIELDS)
	{
		err = 0;
		str = contact.getValue(i);
		if (str.empty() || isOnlySpaces(str))
		{
			err = true;
			str = contact.fieldToString(i) + " field cannot be empty.";
		}
		else
			AddContactExt(i, contact, str, err);
		if (err)
		{
			str = "Contact [" + toString(contact.index) + "]: " + str;
			println(color(str , FRED, 1));
			exitFlag = true;
		}
		i++;
	}
	if (exitFlag)
	{
		str = "Contact [" + toString(contact.index) + "] not added";
		println(color(str + ". Please add manually.", FDEFAULT, 0));
	}
	else
		_checkAdd(contact);
}
#endif
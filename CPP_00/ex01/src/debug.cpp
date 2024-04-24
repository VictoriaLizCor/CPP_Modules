/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:29:22 by lilizarr          #+#    #+#             */
/*   Updated: 2024/04/24 12:38:06 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

#if (DEBUG != 0)
PhoneBook::PhoneBook(Contact contacts[], int size)
{
	int		i;

	_contactIndex = 0;
	for (i = 0; i < size; i++)
	{
		addContact(contacts[i]);
	}
}

void PhoneBook::addContact(Contact contact)
{
	std::string	str;
	int		i;
	int		err;
	
	i = 0;
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
		}
		i++;
	}
	if (err)
	{
		println(color("Contacts not added. Please fix fields and try again.", FDEFAULT, 0));
		exit(EXIT_FAILURE);
	}
	else
		_checkAdd(contact);
}
#endif
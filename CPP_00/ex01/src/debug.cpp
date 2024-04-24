/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:29:22 by lilizarr          #+#    #+#             */
/*   Updated: 2024/04/24 16:33:24 by lilizarr         ###   ########.fr       */
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
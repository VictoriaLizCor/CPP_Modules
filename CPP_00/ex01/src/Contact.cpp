/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:05:59 by lilizarr          #+#    #+#             */
/*   Updated: 2024/04/22 14:52:22 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

//*****************************PUBLIC**************************************//
Contact::Contact(void)
{
	return ;
}
Contact::Contact(std::string info[N_FIELDS])
{
	for (int i = 0; i < N_FIELDS; i++)
		_info[i] = info[i];
}

Contact::~Contact(void)
{
	return ;
}

/*
 * <static_cast> It's a type of casting operator in C++. It converts one type
 * into another, but the types must be compatible. It performs a compile-time
 * type check, making it safer than other types of C++ casts. In your code,
 * 
 *  int i = 3;
 *  double d = static_cast<double>(i);  // Converts the integer i into a double
 * 
 * Here's a simplified example of how `static_cast` works: In this example,
 * `static_cast<double>(i)` converts the integer `i` into a double. The
 * `<double>` part is not a template, it's the type that `i` is being cast to.
 * 
 * `static_cast<Contact::InfoField>(i)` is used to convert the integer `i` into
 * the `InfoField` enum type defined in the `Contact` class. This is necessary
 * because the `set_contact_value` and `get_contact_value` methods of the
 * `Contact` class expect an argument of type `Contact::InfoField`.
*/
/*
 * The const keyword after a member function declaration in C++ means that the
 * function does not modify any member variables of the class. It's a promise
 * that calling this function will not change the state of the class instance.
*/
std::string Contact::fieldToString(int field) const
{
	switch(static_cast<Contact::infoField>(field))
	{
		case FIRST_NAME:
			return ("First Name");
		case LAST_NAME: 
			return ("Last Name");
		case NICKNAME:
			return ("Nickname");
		case PHONE_NUMBER:
			return ("Phone Number");
		case DARKEST_SECRET:
			return ("Darkest Secret");
		default:
			return ("Unknown");
	}
}

void Contact::setValue(int field, const std::string& value)
{
	this->_info[field] = value;
	return ;
}
//contact.set_contact_value(Contact::FIRSTNAME, "John");

std::string Contact::getValue(int field) const
{
	return (this->_info[field]);
}
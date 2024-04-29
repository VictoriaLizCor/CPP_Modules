/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:05:59 by lilizarr          #+#    #+#             */
/*   Updated: 2024/04/29 15:39:40 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

//*****************************PUBLIC**************************************//
/**
 * @brief Default constructor for the Contact class.
 * 
 * This constructor initializes the index member variable to -1.
 */
Contact::Contact(void)
{
	index = -1;
	return ;
}

#if (DEBUG != 0)
/**
 * @brief Constructs a Contact object with the given information.
 * 
 * @param info An array of strings containing the contact information.
 */
Contact::Contact(std::string info[N_FIELDS])
{
	for (int i = 0; i < N_FIELDS; i++)
		_info[i] = info[i];
}
# endif

/**
 * @brief Destructor for the Contact class.
 * 
 * This destructor is responsible for cleaning up any resources
 * allocated by the Contact class.
 */
Contact::~Contact(void)
{
	return ;
}

/**
 * @brief Updates the index of the contact.
 *
 * @param contactIndex The new index of the contact.
 */
void	Contact::updateIndex(const int contactIndex)
{
	index = contactIndex;
}
/*
 * <static_cast> It's a type of casting operator in C++. It converts one type
 * into another, but the types must be compatible. It performs a compile-time
 * type check, making it safer than other types of C++ casts. In your code,
 * 
 *  int i = 3;
 *  double d = static_cast<double>(i);  // Converts the integer i into a double
 * zz
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
/**
 * Converts the specified field of the Contact object to a string representation.
 *
 * @param field The field to convert.
 * @return The string representation of the specified field.
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

/**
 * @brief Sets the value of a specific field in the Contact object.
 * 
 * @param field The field to set the value for.
 * @param value The value to set for the field.
 */
void Contact::setValue(int field, const std::string& value)
{
	this->_info[field] = value;
	return ;
}
//contact.set_contact_value(Contact::FIRSTNAME, "John");

/**
 * @brief Get the value of a specific field in the Contact object.
 * 
 * @param field The index of the field to retrieve the value from.
 * @return std::string The value of the specified field.
 */
std::string Contact::getValue(int field) const
{
	return (this->_info[field]);
}
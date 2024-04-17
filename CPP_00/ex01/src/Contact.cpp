/* ************************************************************************** */
/*																		    */
/*												        :::      ::::::::   */
/*   Contact.cpp									    :+:      :+:    :+:   */
/*												    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*												+#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:26:40 by lilizarr          #+#    #+#			 */
/*   Updated: 2024/04/15 14:32:42 by lilizarr         ###   ########.fr       */
/*																		    */
/* ************************************************************************** */

#include <Phonebook.hpp>

//*****************************PUBLIC**************************************//

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
std::string Contact::infoFieldToString(int field) const
{
	switch(static_cast<Contact::infoField>(field))
	{
		case firstName:
			return ("First Name");
		case lastName: 
			return ("Last Name");
		case nickname:
			return ("Nickname");
		case phoneNumber:
			return ("Phone Number");
		case darkestSecret:
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
//contact.set_contact_value(Contact::FirstName, "John");

std::string Contact::getValue(int field) const
{
	return (this->_info[field]);
}
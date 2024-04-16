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

#include "Phonebook.hpp"

//*****************************PUBLIC**************************************//

Contact::Contact() // initialize Info in the constructor's initializer list
{
	this->info_size = this->NFields;
	std::cout << "Contact constructor called" << std::endl;
	return ;
}

Contact::~Contact(void)
{
	std::cout << "Contact destructor called" << std::endl;
	return ;
}

std::string Contact::InfoFieldToString(int field) const
{
	switch(static_cast<_InfoField>(field))
	{
		case FirstName:
			return ("First Name");
		case LastName: 
			return ("Last Name");
		case Nickname:
			return ("Nickname");
		case PhoneNumber:
			return ("Phone Number");
		case DarkestSecret:
			return ("Darkest Secret");
		default:
			return ("Unknown");
	}
}

void Contact::set_value(int field, const std::string& value)
{
	this->_Info[field] = value;
	return ;
}
//contact.set_contact_value(Contact::FirstName, "John");

std::string Contact::get_value(int field) const
{
	return (this->_Info[field]);
}
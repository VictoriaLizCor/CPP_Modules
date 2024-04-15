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
	std::cout << "Contact constructor called" << std::endl;
	return ;
}

Contact::~Contact(void)
{
	std::cout << "Contact destructor called" << std::endl;
	return ;
}

void Contact::set_contact_value(const InfoField field, const std::string& value)
{
	this->Info[field] = value;
	return ;
}
//contact.set_contact_value(Contact::FirstName, "John");

std::string Contact::get_contact_value(const InfoField field) const
{
	return (this->Info[field]);
}
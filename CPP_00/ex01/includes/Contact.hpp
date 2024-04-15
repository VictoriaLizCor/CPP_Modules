/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:54:19 by lilizarr          #+#    #+#             */
/*   Updated: 2024/04/15 15:52:13 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * #pragma once is a non-standard but widely supported method for instructing the
 *  compiler to only include a header file once in a single compilation unit. This
 * is useful for preventing issues that can arise from including the same header
 * file multiple times in a single source file, which can lead to errors due to
 * redefinition of symbols.
 * 		#ifndef CONTACT_HPP
 * 		# define CONTACT_HPP
 * 		#endif
 * By using #pragma once, the compiler will only include the header file the first
 * time it encounters it in a given compilation unit, and will ignore any
 * subsequent includes of the same header file. This can help to improve
 * compile-time performance and avoid potential issues with redefinition.
*/
#pragma once
# include <iostream>
# include <string>
class Contact
{
	public:
		enum InfoField
		{
			FirstName,
			LastName,
			Nickname,
			PhoneNumber,
			DarkestSecret,
			NFields
		};
		// Constructor
		Contact(void);
		//Destructor
		~Contact(void);
		// Getter methods
		std::string get_contact_value(const InfoField field) const;
		// Setter methods
		void set_contact_value(const Contact::InfoField field, const std::string& value);
	private:
		// Private member variables
		std::string Info[NFields];

		// You can define your own data structure to store the contacts
};

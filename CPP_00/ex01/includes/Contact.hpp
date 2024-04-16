/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:54:19 by lilizarr          #+#    #+#             */
/*   Updated: 2024/04/16 13:42:00 by lilizarr         ###   ########.fr       */
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
		// Constructor
		Contact(void);
		//Destructor
		~Contact(void);
		// Getter methods
		std::string	get_value(int field) const;
		// Setter methods
		void		set_value(int field, const std::string& value);
		std::string	InfoFieldToString(int field) const;
		int		info_size;
	private:
		// Private member variables
		enum _InfoField
		{
			FirstName,
			LastName,
			Nickname,
			PhoneNumber,
			DarkestSecret,
			NFields
		};
		std::string _Info[NFields];
		
};

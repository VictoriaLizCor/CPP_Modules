/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:16:42 by lilizarr          #+#    #+#             */
/*   Updated: 2024/04/23 16:34:04 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_HPP
# define CONTACT_HPP
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
# pragma once
#  include <iostream>
#  include <string>
class Contact
{
	public:
		/*************** Public Variables ***************/
		enum infoField
		{
			FIRST_NAME,
			LAST_NAME,
			NICKNAME,
			PHONE_NUMBER,
			DARKEST_SECRET,
			N_FIELDS
		};
		/*************** Public Methods ***************/
		int	index;
		Contact(void);
# if (DEBUG == 1)
		Contact(std::string info[N_FIELDS]);
# endif
		//Destructor
		~Contact(void);
		// Getter methods
		void		updateIndex(const int contactIndex);
		std::string	getValue(int field) const;
		// Setter methods
		void		setValue(int field, const std::string& value);
		std::string	fieldToString(int field) const;
	private:
		// Private member variables
		std::string _info[N_FIELDS];
};
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:05:40 by lilizarr          #+#    #+#             */
/*   Updated: 2024/04/24 12:48:08 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include "stringUtils.h"
# include "phonebookUtils.h"
# include <iomanip>
# include <iostream>
# include <string>
# include <cstring>
# include <cctype>
# include <sstream>

#ifndef DEBUG
# define DEBUG 0
#endif

# if (DEBUG != 0)
#  include <cstdlib>
#endif

# if (DEBUG == 2)
#  define ADD "ADD"
#  define SEARCH "SEARCH"
#  define EXIT "EXIT"
# else
#  define ADD "1"
#  define SEARCH "2"
#  define EXIT "3"
# endif
/**
 * Member attribues
 * 	A member attribute (also known as a member variable, data member, or
 * 	field) is a variable that is associated with a specific object of a
 * 	class. Each instance of a class has its own copy of the member
 * 	attributes, and can have different values for them.
 * 	Member functions
 * 	A member function is a function that is a member of a class. It has
 * 	access to the private and protected members of the class, and can be

*/
class PhoneBook
{
	private:
		// Private member variables
		static const int _MAX_CONTACTS = 8;
		int		_contactIndex;
		Contact	_contacts[_MAX_CONTACTS];
		void	_checkAdd(Contact& contact);
	public:
		static const int MAX_CONTACTS = _MAX_CONTACTS;
		PhoneBook(void);
		// Destructor
		~PhoneBook(void);
		void	addContact();
		void	displayPhonebook(int size);
		void	searchContact();
		void	showPhonebookMenu();
# if (DEBUG != 0)
		PhoneBook(Contact contacts[], int size);
		void addContact(Contact contact);
# endif
};

#endif

/*
 * NOTES: 
 * The underscore _ before contacts is a naming convention used by some
 * programmers to indicate that this is a private member variable. It's not
 * required by the C++ language, but can make your code easier to understand.
 *
 * This declaration is necessary because it reserves the necessary memory for
 * the Contact objects and allows you to access and manipulate these objects
 * through the _contacts array.
 * 
 */

// PhoneBook.hpp
// class PhoneBook
// {
// public:
//	PhoneBook() : _search(_manager) {};
//	void showPhonebookMenu();
// private:
//	ContactManager _manager;
//	ContactSearch _search;
// };
// ContactManager.hpp
// class ContactManager
// {
// public:
//	ContactManager() : _contactIndex(0) {};
//	void addContact();
// private:
//	int _contactIndex;
//	Contact _contacts[8];
// };

// // ContactSearch.hpp
// class ContactSearch
// {
// public:
//	ContactSearch(ContactManager& manager) : _manager(manager) {};
//	void displayContacts();
//	void searchContact();
// private:
//	ContactManager& _manager;
// };
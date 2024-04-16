#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <iostream>
# include <string>
# include <cctype>


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

	public:
		// Constructor
		PhoneBook();
		// Destructor
		~PhoneBook();

		// Add a contact to the phone book
		void addContact(const std::string& name, const std::string& phoneNumber);
		// Search for a contact by name
		void searchContact(const std::string& name);

	private:
		Contact	_contacts[8]; // Array of contacts in the phonebook
		int		_contactCount;
		// Private member variables
		// You can define your own data structure to store the contacts
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
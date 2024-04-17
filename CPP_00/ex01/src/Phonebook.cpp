/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   phonebook.cpp									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lilizarr <lilizarr@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/04/16 14:35:04 by lilizarr		  #+#	#+#			 */
/*   Updated: 2024/04/17 10:35:53 by lilizarr		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <Phonebook.hpp>

// void PhoneBook::_add(Contact* contact)
// {
// 	if (PhoneBook::_contactCount < 8) {
// 		this->_contacts[PhoneBook::_contactCount++] = *contact;
// 	} else {
// 		printOut("Phonebook is full, first contact will be replaced");
// 		this->_contacts[0] = *contact;
// 	}
// }

//*****************************PUBLIC**************************************//
PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook destructor called" << std::endl;
	return ;
}

static void AddContactExt(int& i, Contact& contact, std::string& str)
{
	if (i == Contact::phoneNumber)
	{
		if (checkInput(str, isdigit))
			contact.setValue(i++, str);
		else
			println("PhoneNumber must be composed of digits.");
	}
	else
	{
		if (checkInput(str, isalpha))
			contact.setValue(i++, str);
		else
			println( "This field must be composed of alphabetic characters.");
	}
}

void PhoneBook::addContact()
{
	Contact contact;
	std::string str;
	int i = 0;

	while(1)
	{
		std::cout << "Enter " << contact.infoFieldToString(i) << ": " << std::endl;
		std::cin >> str;
		if (str.empty())
			println("Field cannot be empty.");
		else
		{
			AddContactExt(i, contact, str);
			if (i == Contact::nFields)
				break;
		}
	}

}

static void	showContactInfo(Contact contact)
{
	int	i;

	i = 0;
	while(i < Contact::nFields)
	{
		println(contact.infoFieldToString(i) + ": " + contact.getValue(i));
		i++;
	}
}

void PhoneBook::searchContact()
{
	int i;
	int index;
    std::string buffer;

	index = 0;
	i = 0;
	buffer = "";
    // if (PhoneBook::_contactCount == 0) {
    //     printOut("No contacts to search");
    //     return ;
    // }

    // printTableHeader();
    // while (i < PhoneBook::_contactCount) {
    //     _printTableContent(i, this->_contacts[i]);
    //     i++;
    // }

    // while (1) {
    //     printOut("Enter index to display: ");
    //     std::getline(std::cin, buffer);
    //     if (buffer.empty()) {
    //         printOut("Index cannot be empty");
    //         continue ;
    //     }
    //     index = atoi(buffer.c_str());
    //     if (index < 0 || index >= PhoneBook::_contactCount) {
    //         printOut("Invalid index");
    //         continue ;
    //     }
    //     break ;
    // }
    showContactInfo(this->_contacts[index]);
}

void	PhoneBook::showMenu()
{
	int choice;

	while (true)
	{
		std::cout << "1. Add Contact\n";
		std::cout << "2. Search Contact\n";
		std::cout << "3. Exit\n";
		std::cout << "Enter your choice: ";
		std::cin >> choice;
		if (choice == 1)
			addContact();
		else if (choice == 2)
			searchContact();
		else if (choice == 3)
			break;
		else
		{
			std::cout << "Invalid choice. Please try again.\n";
			continue ;
		}
	}
}

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
	// std::cout << "PhoneBook destructor called" << std::endl;
	return ;
}

static void AddContactExt(int& i, Contact& contact, std::string& str)
{
	if (i == Contact::PHONE_NUMBER)
	{
		if (checkInput(str, isdigit))
			contact.setValue(i++, str);
		else
		{
			str = color("Phone number must be composed of digits.", FRED, 1);
			println(str);
		}
	}
	else
	{
		if (checkInput(str, isalpha))
			contact.setValue(i++, str);
		else
		{
			str = contact.fieldToString(i);
			str = str + " must be composed of alphabetic characters.";
			println(color(str , FRED, 1));
		}
	}
}

void PhoneBook::addContact()
{
	Contact contact;
	std::string str;
	int i = 0;

	while(1)
	{
		std::cout << "Enter " << contact.fieldToString(i) << ": " << std::endl;
		std::getline(std::cin, str);
		if (str.empty())
			println(color("Field cannot be empty.", FRED, 1));
		else
		{
			AddContactExt(i, contact, str);
			if (i == Contact::N_FIELDS)
				break;
		}
	}
	_contacts[_contactIndex++] = contact;
}

static void	showContactInfo(Contact contact)
{
	int	i;

	i = 0;
	while(i < Contact::N_FIELDS)
	{
		println(contact.fieldToString(i) + ": " + contact.getValue(i));
		i++;
	}
}

static void formatedText(int strColor, std::string idx, const Contact& c, std::string (Contact::*str)(int) const)
{
	int			i;
	std::string	ColoredText;

	i = 0;
	println(std::to_string(color(idx, strColor, 0).length()));
	println(std::to_string(idx.length()));
	std::cout << std::setw(15) << color(idx, strColor, 0);
	while(i <= c.NICKNAME)
	{
		ColoredText = color((c.*str)(i++), strColor,0);
		std::cout << " | " << std::setw(15) << ColoredText;
	}
	println("");
}

void	PhoneBook::displayPhonebook()
{
	int	i;
	std::string str;
	
	i = 0;
	formatedText( FDEFAULT, "Index", _contacts[0], &Contact::fieldToString);
	while(i < _contactIndex)
	{
		formatedText( DEFAULT, std::to_string(i), _contacts[i], &Contact::getValue);
		i++;
	}
}

void	PhoneBook::searchContact()
{
	int			i;
	int			index;
	std::string	str;

	index = 0;
	i = 0;
	if (_contactIndex == 0)
	{
		str = color("\nPhonebook empty. Please add a contact first.", FDEFAULT, 0);
		println(str);
		return ;
	}
	displayPhonebook();
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

static void	menuOptions(void)
{
	println(color("\n***************** MENU ******************", FGREEN, 0));
	println(color("*\t [ 1 ] - Add Contactt\t\t*", FGREEN, 0));
	println(color("*\t [ 2 ] - Search Contact\t\t*", FGREEN, 0));
	println(color("*\t [ 3 ] - Exit\t\t\t*", FGREEN, 0));
	println(color("*****************************************", FGREEN, 0));
}

void	PhoneBook::showPhonebookMenu()
{
	std::string	choice;

	while (choice != "3")
	{
		menuOptions();
		std::cout << "\nEnter your choice: ";
		std::getline(std::cin, choice);
		println("");
		if (choice == "1")
			addContact();
		else if (choice == "2")
			searchContact();
		else if (choice == "3")
			break;
		else
			println(color("Invalid choice. Please try again.", FRED, 1));
	}
	println(color("GOOD BYE!", FBLUE, 0));
	println(color("PS: No data was stored\n", FBLUE, 0));
}

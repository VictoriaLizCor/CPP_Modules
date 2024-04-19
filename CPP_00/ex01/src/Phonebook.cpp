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
	std::string	str;
	std::string	coloredText;
	Contact		contact;
	int i;

	i = 0;
	while(1)
	{
		coloredText = color("Enter " + contact.fieldToString(i) + ": ", FBLUE, 0);
		println(coloredText);
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

static std::string*	fieldToStringArray(int size, const Contact& contact, std::string (Contact::*str)(int) const)
{
	std::string*	array;
	int				i;

	i = 0;
	array = new std::string[size + 1];
	while(i <= size)
	{
		array[i] = (contact.*str)(i);
		i++;
	}
	return (array);
}


static void	showContactInfo(Contact contact, int size)
{
	std::stringstream		field;
	std::stringstream		value;
	std::string*			dataArray;
	size_t					len;
	int						i;

	i = 0;
	dataArray = fieldToStringArray(size, contact, &Contact::getValue);
	len = maxStringLength(size, dataArray);
	while(i < size)
	{
		field.str("");
		field << std::setw(contact.fieldToString(size - 1).length()) << contact.fieldToString(i);
		value.str("");
		value << std::setw(len) << dataArray[i];
		println("  " + color(field.str(), FDEFAULT, 0) + ":\t" + value.str());
		i++;
	}
	delete[] dataArray;
}

static void formatedText(int colorType, std::string idx, int size, std::string* dataArray)
{
	std::stringstream	ss;
	std::string			coloredText;
	std::string			trunc;
	int					i;

	i = 0;
	ss << std::setw(10) << idx;
	std::cout << color(ss.str(), colorType, 0);
	while(i <= size)
	{
		ss.str("");
		trunc = dataArray[i];
		if (trunc.length() > 10)
			trunc = trunc.substr(0, 9) + ".";
		ss << std::setw(10) << trunc;
		coloredText = color(ss.str(), colorType, 0);
		std::cout << "|" << coloredText;
		i ++;
	}
	println("\n");
}

void	PhoneBook::displayPhonebook()
{
	std::string		str;
	std::string*	dataArray;
	int				i;
	int				size;

	i = 0;
	size = Contact::NICKNAME;
	dataArray = fieldToStringArray(size, _contacts[0], &Contact::fieldToString);
	formatedText( FDEFAULT, "Index", size, dataArray);
	delete[] dataArray;
	dataArray = fieldToStringArray(size, _contacts[i], &Contact::getValue);
	while(i < _contactIndex)
	{
		formatedText( DEFAULT, toString(i), size, dataArray);
		i++;
	}
	delete[] dataArray;
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
    showContactInfo(this->_contacts[index], Contact::N_FIELDS);
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

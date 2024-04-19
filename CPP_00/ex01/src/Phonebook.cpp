/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:05:49 by lilizarr          #+#    #+#             */
/*   Updated: 2024/04/19 16:24:14 by lilizarr         ###   ########.fr       */
/*                                                                            */
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
	return ;
}

/**
 * @brief Adds a contact to the phonebook.
 *
 * This function is responsible for adding a contact to the phonebook. It takes
 * an index, a Contact object, and a string as parameters. If the index is equal
 * to Contact::PHONE_NUMBER, it checks if the input string contains only digits.
 * If it does, it sets the value of the contact at the current index and
 * increments the index. If the index is not equal to Contact::PHONE_NUMBER, it
 * checks if the input string contains only alphabetic characters. If it does,
 * it sets the value of the contact at the current index and increments the
 * index. If the input string does not meet the requirements, an error message
 * is printed.
 *
 * @param i The index of the contact field.
 * @param contact The Contact object to add the values to.
 * @param str The input string to validate and set as the contact value.
 */
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
	while(i < Contact::N_FIELDS)
	{
		coloredText = color("Enter " + contact.fieldToString(i) + ": ", FBLUE, 0);
		println(coloredText);
		std::getline(std::cin, str);
		if (str.empty())
			println(color("Field cannot be empty.", FRED, 1));
		else
			AddContactExt(i, contact, str);
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


static void	showContactInfo(Contact contact, int size, std::string& index)
{
	std::stringstream		field;
	std::stringstream		value;
	std::string*			dataArray;
	size_t					len;
	int						i;

	i = 0;
	dataArray = fieldToStringArray(size, contact, &Contact::getValue);
	len = maxStringLength(size, dataArray);
	println("");
	println("************** Contact[ " + index + " ] **************");
	while(i < size)
	{
		field.str("");
		field << std::setw(contact.fieldToString(size - 1).length()) << contact.fieldToString(i);
		value.str("");
		value << std::setw(len) << dataArray[i];
		println("  " + color(field.str(), FDEFAULT, 0) + ":\t" + value.str());
		i++;
	}
	println("******************************************");
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
	println("");
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

static void searchContactExt(std::string& index, int& idx, int& err, int sizeContatcs)
{
	if (checkInput(index, isdigit) && !index.empty())
	{
		idx = std::stoi(index);
		println(index + "[" + toString(idx) + "] size = " + toString(sizeContatcs));
		if (idx < 0 && idx > sizeContatcs)
			err = 1;
	}
	else
		err = 1;
}

void	PhoneBook::searchContact()
{
	std::string	index;
	int			err;
	int			idx;

	err = 0;
	idx = 0;
	if (_contactIndex == 0)
	{
		index = color("\nPhonebook empty. Please add a contact first.", FDEFAULT, 0);
		println(index);
		return ;
	}
	displayPhonebook();
	while (1)
	{
		std::cout << "\nEnter contact index to display: ";
		std::getline(std::cin, index);
		println("");
		searchContactExt(index, idx, err, _contactIndex);
		println(toString(err) + " " + toString(idx) + " " + index);
		if (err)
			println(color("Invalid choice. Please try again.", FRED, 1));
		else
		{
			showContactInfo(this->_contacts[idx], Contact::N_FIELDS, index);
			break;
		}
	}
}

static void	menuOptions(void)
{
	println("");
	println(color("****************** MENU *******************", FGREEN, 0));
	println(color("*                                         *", FGREEN, 0));
	println(color("*\t [ 1 ] - Add Contactt\t\t  *", FGREEN, 0));
	println(color("*\t [ 2 ] - Search Contact\t\t  *", FGREEN, 0));
	println(color("*\t [ 3 ] - Exit\t\t\t  *", FGREEN, 0));
	println(color("*                                         *", FGREEN, 0));
	println(color("*******************************************", FGREEN, 0));
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

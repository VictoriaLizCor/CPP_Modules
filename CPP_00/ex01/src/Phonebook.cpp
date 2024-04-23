/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:05:49 by lilizarr          #+#    #+#             */
/*   Updated: 2024/04/23 17:51:21 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

//*****************************PRIVATE**************************************//
void	PhoneBook::_checkAdd(Contact& contact)
{
	if (_contactIndex < _MAX_CONTACTS)
		_contacts[_contactIndex++] = contact;
	else
	{
		println(color("Phonebook is full, last added contact will be replaced", FRED, 1));
		_contacts[_MAX_CONTACTS - 1] = contact;
	}
}

//*****************************PUBLIC**************************************//

PhoneBook::PhoneBook(void)
{
	_contactIndex = 0;
}

#if (DEBUG == 1)
PhoneBook::PhoneBook(Contact contacts[], int size)
{
	int		i;

	_contactIndex = 0;
	for (i = 0; i < size; i++)
	{
		addContact(contacts[i]);
	}
}
#endif

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
static void AddContactExt(int& i, Contact& contact, std::string& str, int& err)
{
	if (i == Contact::PHONE_NUMBER)
	{
		err = !checkInput(str, isdigit);
		if (err == 0)
			contact.setValue(i, str);
		else
		{
			str = color("Phone Number must be composed of digits and space characters.", FRED, 1);
			println(str);
		}
	}
	else
	{
		err = !checkInput(str, isalpha);
		if (err == 0)
			contact.setValue(i, str);
		else
		{
			str = "Contact [" + toString(contact.index) + "]: ";
			str += contact.fieldToString(i);
			str +=" must be composed of alphabetic and space characters.";
			println(color(str , FRED, 1));
		}
	}
}

#if (DEBUG == 1)
void PhoneBook::addContact(Contact contact)
{
	std::string	str;
	int		i;
	int		err;
	
	i = 0;
	err = 0;
	contact.updateIndex(_contactIndex);
	while(i < Contact::N_FIELDS)
	{
		str = contact.getValue(i);
		if (str.empty())
		{
			err = true;
			str = contact.fieldToString(i) + " field cannot be empty.";
		}
		else
			AddContactExt(i, contact, str, err);
		if (err)
		{
			str = "Contact [" + toString(contact.index) + "]: " + str;
			println(color(str , FRED, 1));
			println(color("Contacts not added. Please fix fields and try again.", FRED, 1));
			exit(EXIT_FAILURE);
		}
		i++;
	}
	_checkAdd(contact);
}
#endif

void PhoneBook::addContact()
{
	std::string	str;
	Contact		contact;
	int			i;
	int			err;

	i = 0;
	contact.updateIndex(_contactIndex);
	while(i < Contact::N_FIELDS)
	{
		println(color("Enter " + contact.fieldToString(i) + ": ", FBLUE, 0));
		std::getline(std::cin, str);
		if (str.empty())
		{
			err = 1;
			println(color("Field cannot be empty.", FRED, 1));
		}
		else
			AddContactExt(i, contact, str, err);
		if (!err)
			i++;
	}
	_checkAdd(contact);
}

static std::string*	fieldToStringArray(int size, const Contact& contact, std::string (Contact::*str)(int) const)
{
	std::string*	array;
	int				i;

	i = 0;
	array = new std::string[size];
	while(i < size)
	{
		array[i] = (contact.*str)(i);
		i++;
	}
	return (array);
}


static void	showContactInfo(Contact contact, int nFields, std::string tmp)
{
	std::stringstream		field;
	std::stringstream		value;
	std::string*			dataArray;
	size_t					len;
	int						i;

	i = 0;
	dataArray = fieldToStringArray(nFields, contact, &Contact::getValue);
	len = maxStringLength(nFields, dataArray);
	println("\n************** Contact[ " + tmp + " ] **************");
	tmp = contact.fieldToString(Contact::DARKEST_SECRET);
	while(i < nFields)
	{
		field.str("");
		field << std::setw(tmp.length()) << contact.fieldToString(i);
		value.str("");
		value << std::setw(len) << dataArray[i];
		println("  " + color(field.str(), FDEFAULT, 0) + ":\t" + value.str());
		i++;
	}
	println("******************************************");
	delete[] dataArray;
}

static void formatedText(int colorType, std::string idx, int fNickname, std::string* dataArray)
{
	std::stringstream	ss;
	std::string			coloredText;
	std::string			trunc;
	int					i;

	i = 0;
	ss << std::setw(10) << idx;
	std::cout << color(ss.str(), colorType, 0);
	while(i < fNickname)
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
	std::string*	contactFieldsArray;
	std::string*	contactValuesArray;
	int				i;
	int				fNickname;

	i = 0;
	fNickname = Contact::NICKNAME + 1;
	contactFieldsArray = fieldToStringArray(fNickname, _contacts[0], &Contact::fieldToString);
	println("");
	formatedText( FDEFAULT, "Index", fNickname, contactFieldsArray);
	delete[] contactFieldsArray;
	while(i < _contactIndex)
	{
		contactValuesArray = fieldToStringArray(fNickname, _contacts[i], &Contact::getValue);
		formatedText( DEFAULT, toString(i + 1), fNickname, contactValuesArray);
		delete[] contactValuesArray;
		i++;
	}
}

static void searchContactExt(std::string& index, int& idx, int& err, int sizeContatcs)
{
	bool				flag_idx;
	std::istringstream	tmp;

	if (checkInput(index, isdigit) && !index.empty())
	{
		err = 0;
		tmp.clear();
		tmp.str(index);
		tmp >> idx;
		idx--;
		flag_idx = idx < 0 || idx >= sizeContatcs;
		if (flag_idx)
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
	while (1)
	{
		displayPhonebook();
		std::cout << "\nEnter contact index to display: ";
		std::getline(std::cin, index);
		println("");
		searchContactExt(index, idx, err, _contactIndex);
		if (err)
			println(color("Invalid choice. Please try again.", FRED, 1));
		else
		{
			showContactInfo(_contacts[idx], Contact::N_FIELDS, index);
			break;
		}
	}
}

static void	menuOptions(void)
{
	std::string	str;
	
	println("");
	println(color("****************** MENU *******************", FGREEN, 0));
	println(color("*                                         *", FGREEN, 0));
	str = ADD;
	str = "*\t [ " + str + " ] \t- Add Contact\t  *";
	println(color(str, FGREEN, 0));
	str = SEARCH;
	str = "*\t [ " + str + " ] \t- Search Contact  *";
	println(color(str, FGREEN, 0));
	str = EXIT;
	str = "*\t [ " + str + " ] \t- Exit\t\t  *";
	println(color(str, FGREEN, 0));
	println(color("*                                         *", FGREEN, 0));
	println(color("*******************************************", FGREEN, 0));
}


void	PhoneBook::showPhonebookMenu()
{
	std::string	choice;

	while (1)
	{
		menuOptions();
		std::cout << "\nEnter your choice: ";
		std::getline(std::cin, choice);
		println("");
		if (choice == ADD)
			addContact();
		else if (choice == SEARCH)
			searchContact();
		else if (choice == EXIT)
			break;
		else
			println(color("Invalid choice. Please try again.", FRED, 1));
	}
	println(color("GOOD BYE!", FBLUE, 0));
	println(color("PS: No data was stored\n", FBLUE, 0));
}

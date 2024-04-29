/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebookUtils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:44:57 by lilizarr          #+#    #+#             */
/*   Updated: 2024/04/29 15:51:55 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

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
void AddContactExt(int& i, Contact& contact, std::string& str, int& err)
{
	if (i == Contact::PHONE_NUMBER)
	{
		if (checkInput(str, isdigit))
			contact.setValue(i, str);
		else
		{
			str = "Phone Number must be composed of digits and space characters.";
			err = true;
		}
	}
	else
	{
		if (checkInput(str, isalpha))
			contact.setValue(i, str);
		else
		{
			str = contact.fieldToString(i)+ " must be composed of alphabetic and space characters.";
			err = true;
		}
	}
}

/**
 * @brief Converts the fields of a Contact to a string array.
 *
 * This function takes a string array, its size, a Contact object, and a
 * member function pointer as input. It calls the member function for each
 * field of the Contact and stores the result in the string array. The
 * member function should take an integer index and return a string.
 *
 * @param array The string array to store the field values.
 * @param size The size of the string array.
 * @param contact The Contact object to convert.
 * @param str The member function to call for each field.
 * @return The string array with the field values.
 */
std::string*	fieldToStringArray(std::string *array, int size, const Contact& contact, std::string (Contact::*str)(int) const)
{
	int	i;

	i = 0;
	while(i < size)
	{
		array[i] = (contact.*str)(i);
		i++;
	}
	return (array);
}

/**
 * @brief Displays the details of a contact.
 *
 * This function takes a Contact object, the number of fields in the contact,
 * and a string as input. It converts the fields of the Contact to a string
 * array and prints them in a formatted manner. The string input is used to
 * color the contact's index in the output.
 *
 * @param contact The Contact object to display.
 * @param nFields The number of fields in the contact.
 * @param tmp The string to color the contact's index.
 */

void	showContactInfo(Contact contact, int nFields, std::string tmp)
{
	std::stringstream	field;
	std::stringstream	value;
	std::string			dataArray[nFields];
	size_t				len;
	int					i;

	i = 0;
	fieldToStringArray(dataArray, nFields, contact, &Contact::getValue);
	len = maxStringLength(nFields, dataArray);
	tmp = color("Contact [ " + tmp + " ]", FDEFAULT, 0);
	println("************* " + tmp + " ***************");
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
	println("*******************************************");
}

/**
 * @brief Prints formatted text with color.
 *
 * This function takes a color type, an index string, a field count, and a
 * data array as input. It prints the index and the fields of the data array
 * in a formatted manner with the specified color. Each field is truncated to
 * 10 characters, and if a field is longer than 10 characters, it is
 * abbreviated with a trailing dot.
 *
 * @param colorType The color type to use for the text.
 * @param idx The index string to print.
 * @param fNickname The number of fields in the data array.
 * @param dataArray The data array containing the fields to print.
 */
void formatedText(int colorType, std::string idx, int fNickname, std::string* dataArray)
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
		std::cout << color("|", FDEFAULT, 0) << coloredText;
		i ++;
	}
	println("");
}

/**
 * @brief Searches for a contact by index.
 *
 * This function takes a string index, an integer index, an error flag, and
 * the size of the contacts array as input. It checks if the string index is
 * a valid integer and within the range of the contacts array. If it is, it
 * converts the string index to an integer and stores it in the integer
 * index. If it is not, it sets the error flag to 1.
 *
 * @param index The string index to search for.
 * @param idx The integer index to store the converted string index.
 * @param err The error flag to set if the string index is not valid.
 * @param sizeContatcs The size of the contacts array.
 */
void searchContactExt(std::string& index, int& idx, int& err, int sizeContatcs)
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

/**
 * @brief Displays the main menu options.
 *
 * This function prints the main menu options for the phone book application.
 * The options include "Add Contact", "Search Contact", and "Exit". Each
 * option is displayed with a command number that the user can enter to
 * select the option. The menu is printed with a green color for better
 * visibility.
 */
void	menuOptions(void)
{
	std::string	str;
	std::string	tmp;

	println("");
	println(color("****************** MENU *******************", FLGREEN, 0));
	println(color("*                                         *", FLGREEN, 0));
	str = "*\t [ " + center(ADD, 6) + " ] - Add Contact\t  *";
	// str = str + center
	println(color(str, FLGREEN, 0));
	str = "*\t [ " +  center(SEARCH, 6) + " ] - Search Contact\t  *";
	println(color(str, FLGREEN, 0));
	str = "*\t [ " + center(EXIT, 6) + " ] - Exit\t\t  *";
	println(color(str, FLGREEN, 0));
	println(color("*                                         *", FLGREEN, 0));
	println(color("*******************************************", FLGREEN, 0));
}


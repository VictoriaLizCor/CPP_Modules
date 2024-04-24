/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebookutils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:44:57 by lilizarr          #+#    #+#             */
/*   Updated: 2024/04/24 12:46:29 by lilizarr         ###   ########.fr       */
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
}

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
		std::cout << "|" << coloredText;
		i ++;
	}
	println("");
}

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

void	menuOptions(void)
{
	std::string	str;
	std::string	tmp;

	println("");
	println(color("****************** MENU *******************", FGREEN, 0));
	println(color("*                                         *", FGREEN, 0));
	str = "*\t [ " + center(ADD, 6) + " ] - Add Contact\t  *";
	// str = str + center
	println(color(str, FGREEN, 0));
	str = "*\t [ " +  center(SEARCH, 6) + " ] - Search Contact\t  *";
	println(color(str, FGREEN, 0));
	str = "*\t [ " + center(EXIT, 6) + " ] - Exit\t\t  *";
	println(color(str, FGREEN, 0));
	println(color("*                                         *", FGREEN, 0));
	println(color("*******************************************", FGREEN, 0));
}
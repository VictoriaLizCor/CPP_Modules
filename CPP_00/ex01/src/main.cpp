/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:24:06 by lilizarr          #+#    #+#             */
/*   Updated: 2024/04/24 15:38:44 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"


int	main()
{
#if (DEBUG == 0)
	PhoneBook phonebook;
#else
	int size;
	const int N_CONTACTS = PhoneBook::MAX_CONTACTS + 1;
	std::string info[N_CONTACTS][Contact::N_FIELDS] =
	{
		{"Linda Victoria", "Lizarraga Cortes", "Vicki", "788", "adfasdfasdfasdf"}, //1
		{"Diana Paulina", "Calvo Cortes", "Diana", "09871233454", "zxfsdfasdfasdfewr"}, //2
		{"Jane", "Doe", "Jane", "4565714", " asdefds"}, //3
		{"John", "Doe", "Jo", "9895521", "ytyty"}, //4
		{"Ricardo", "Montana", "Richy", "58483", "puotooe"}, //5
		{"VAca", "Loca", "Raefa", "63456345", "ofofofofof"}, //6
		{"Leon", "Cielo", "itoeritoepor", "656", "leoeleoe"}, //7
		{"bsdfg", "hertye", "tykrmdfgs", "056934056", "vmvnv"}, //8
		{"ABCDE", "FGHIJ", "KLMNO", "80034056", "PQRST"},//9
	};
	Contact contacts[PhoneBook::MAX_CONTACTS + 1];
	size = sizeof(info) / sizeof(info[0]);
	for (int i = 0; i < size; ++i)
		contacts[i] = Contact(info[i]);
	PhoneBook phonebook(contacts, N_CONTACTS);
#endif
	phonebook.showPhonebookMenu();
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:26:55 by lilizarr          #+#    #+#             */
/*   Updated: 2024/04/24 12:43:31 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main()
{
#if (DEBUG == 0)
	PhoneBook	phonebook;
#else

	std::string info1[Contact::N_FIELDS] = {"Linda Victoria",
											"Lizarraga Cortes",
											"Vicki",
											"1234567890",
											"adfasdfasdfasdf"};
	std::string info2[Contact::N_FIELDS] = {"Diana Paulina",
											"Calvo Cortes",
											"Diana",
											"09871233454",
											"zxfsdfasdfasdfewr"};
	std::string info3[Contact::N_FIELDS] = {"Jane",
											"Doe",
											"Jane",
											"asd ",
											" asdefds"};
	std::string info4[Contact::N_FIELDS] = {"John",
											"Doe",
											"Jo",
											"9895521",
											"ytyty"};
	std::string info5[Contact::N_FIELDS] = {"Ricardo",
											"Montana",
											"Richy",
											"58483",
											"puotooe"};
	std::string info6[Contact::N_FIELDS] = {"VAca",
											"Loca",
											"Raefa",
											"63456345",
											"ofofofofof"};
	std::string info7[Contact::N_FIELDS] = {"Leon",
											"Cielo",
											"itoeritoepor",
											"656",
											"leoeleoe"};
	std::string info8[Contact::N_FIELDS] = {"bsdfg",
											"hertye",
											"tykrmdfgs",
											"056934056",
											"vmvnv"};
	int size;
	// Contact contacts[2] = {Contact(info1), Contact(info2)};
	// Contact contacts[3] = {Contact(info1), Contact(info2), Contact(info3)};
	Contact contacts[8] =	{Contact(info1),
							Contact(info2),
							Contact(info3),
							Contact(info4),
							Contact(info5),
							Contact(info6),
							Contact(info7),
							Contact(info8),};
	size = sizeof(contacts) / sizeof(contacts[0]);
	PhoneBook phonebook(contacts, size);
#endif
	phonebook.showPhonebookMenu();
	return (0);
}

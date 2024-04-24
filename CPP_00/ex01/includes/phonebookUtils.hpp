/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebookUtils.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:44:57 by lilizarr          #+#    #+#             */
/*   Updated: 2024/04/24 15:17:42 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOKUTILS_H
# define PHONEBOOKUTILS_H

# include "Contact.hpp"

void			AddContactExt(int& i, Contact& contact, std::string& str, int& err);
std::string*	fieldToStringArray(std::string *array, int size, const Contact& contact, std::string (Contact::*str)(int) const);
void			showContactInfo(Contact contact, int nFields, std::string tmp);
void 			formatedText(int colorType, std::string idx, int fNickname, std::string* dataArray);
void 			searchContactExt(std::string& index, int& idx, int& err, int sizeContatcs);
void			menuOptions(void);
#endif
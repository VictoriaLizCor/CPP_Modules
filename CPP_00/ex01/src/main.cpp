/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:46:15 by lilizarr          #+#    #+#             */
/*   Updated: 2024/04/16 13:44:42 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <Phonebook.hpp>

/*
 * <static_cast> It's a type of casting operator in C++. It converts one type
 * into another, but the types must be compatible. It performs a compile-time
 * type check, making it safer than other types of C++ casts. In your code,
 * 
 *  int i = 3;
 *  double d = static_cast<double>(i);  // Converts the integer i into a double
 * 
 * Here's a simplified example of how `static_cast` works: In this example,
 * `static_cast<double>(i)` converts the integer `i` into a double. The
 * `<double>` part is not a template, it's the type that `i` is being cast to.
 * 
 * `static_cast<Contact::InfoField>(i)` is used to convert the integer `i` into
 * the `InfoField` enum type defined in the `Contact` class. This is necessary
 * because the `set_contact_value` and `get_contact_value` methods of the
 * `Contact` class expect an argument of type `Contact::InfoField`.
*/
int main() {
	Contact c;
	std::string str;
	int i = 0;

	while(i < c.info_size)
	{
		std::cout << "Enter " << c.InfoFieldToString(i) << ": " << std::endl;
		std::getline(std::cin, str);
		if (str.empty())
			std::cout <<"Field cannot be empty." << std::endl;
		else
			c.set_value(i++, str);
	}
	i = 0;
	while(i < c.info_size)
	{
		std::cout << c.InfoFieldToString(i) << ": " \
		<< c.get_value(i) << std::endl;
		i++;
	}

	return 0;
}


/*
void set_contact(int i, const std::string& value) {
        if (i >= 0 && i < NFields) {
            set_value(static_cast<InfoField>(i), value);
        }
        else {
            // handle error, e.g., throw an exception or return an error code
        }
    }

	while(i < Contact::NFields)
    {
        std::cout << "Enter " << c.InfoFieldToString(i) << ": " << std::endl;
        std::getline(std::cin, str);
        if (str.empty())
            std::cout <<"Field cannot be empty." << std::endl;
        else
            c.set_contact(i++, str);
    }

	
*/
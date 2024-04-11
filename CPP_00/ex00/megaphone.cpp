/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:55:53 by lilizarr          #+#    #+#             */
/*   Updated: 2024/04/11 13:16:28 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include <cstring>

/**
 * @brief Converts a C-style string to uppercase and prints it.
 * This function creates a copy of the input string, converts each character to uppercase using std::toupper, and then prints the resulting string.
 * The memory allocated for the copy is then deallocated using delete[].
 * @param argv The C-style string to be converted to uppercase and printed. This string is not modified.
 * @details
 * 1. `std::string str(argv);` - This is direct initialization. 
 * The `std::string` constructor that takes a `const char*` is called directly to initialize `str`.
 * 2. `std::string str = argv;` - This is copy initialization. Conceptually, this does the same 
 * thing as direct initialization, but it involves an extra step. First, a temporary `std::string`
 * object is created from `argv`, and then this temporary object is used to initialize `str`.
 * In practice, most modern compilers will optimize away the extra step, so there's no 
 * performance difference between direct and copy initialization.
 * In general, both forms of initialization are fine to use, and the choice between 
 * them is largely a matter of personal preference. However, in some cases, direct 
 * initialization can be more efficient or allow for more control over the initialization process.
 **/
void	str_upper(char *argv)
{
	char* cpy;
	std::string str(argv);
	
	cpy = new char[str.length() + 1];
	std::strcpy(cpy, str.c_str());
	for (int i = 0; cpy[i]; i++)
		cpy[i] = std::toupper(cpy[i]);
	std::cout << cpy;
	delete[] cpy;
}

/**
 * @brief The main function of the megaphone program.
 * This function takes command line arguments, converts them to uppercase using
 * the str_upper function, and prints them.
 * @param argc The number of command line arguments.
 * @param argv The command line arguments.
 * @return Returns 0 on success.
 */
int	main(int argc, char *argv[])
{
	std::cout << "\033[0;32m";
	if (argc != 1)
	{
		for (int i = 1; argv[i]; i++)
			str_upper(argv[i]);
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << "\033[0m" <<std::endl;
	return (0);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:55:53 by lilizarr          #+#    #+#             */
/*   Updated: 2024/04/11 12:28:32 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include <cstring>
# include <cctype>

char *str_upper(char *str)
{
	for (int i = 0; str[i]; i++)
		str[i] = std::toupper(str[i]);
	return (str);
}
/**
** Coding Style and Doxygen Documentation
** @brief Print a string with a newline character.
** This function takes a char* as input and prints it to the console with a newline character.
** It converts the char* to a std::string and then inserts a newline character at the end of the string.
** Finally, it prints the string to the console using std::cout.
** @param s The char* to print.
 */

void	ft_str(char *s)
{
	std::string str(s);
	std::cout << str_upper((char *)str.c_str());
}

/**
** @brief Main function
** This function is the main entry point of the program.
** It checks if the user provided any arguments and, if so, it prints each argument with a newline character.
** If the user did not provide any arguments, it prints a loud and unbearable feedback noise.
** @param argc The number of command-line arguments.
** @param argv An array of pointers to the command-line arguments.
** @return 0 to indicate success.
 */
int	main(int argc, char *argv[])
{
	std::cout << "\033[0;32m";
	if (argc != 1)
	{
		std::cout << str_upper(argv[1]);
		argv+=2;
		while (*argv)
		{
			ft_str(*argv);
			argv++;
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << "\033[0m" <<std::endl;
	return (0);
}


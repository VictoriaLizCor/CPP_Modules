#include <iostream>
#include <string>
#include <cstring>

#ifndef DEBUG
# define DEBUG 0
#endif

/*
In C++98, you can't directly print a preprocessor macro that expands to an
integer using `cout` or `printf` because the preprocessor runs before the
compiler and doesn't understand C++ syntax. However, you can use a trick to
convert the macro to a string, and then print that string. Here's an example: In
this example, `STRINGIFY(x)` and `STRINGIFY2(x)` are macros that convert `x` to
a string. `STRINGIFY(DEBUG)` expands to `STRINGIFY2(1)`, which then expands to
`"1"`. This string can be printed with `cout`. Please note that this will print
the value of `DEBUG` at compile time, not at runtime. If you change the value of
`DEBUG` in your code after compilation, it won't affect the printed value.
*/
#if (DEBUG > 0)
# define STRINGIFY(x) STRINGIFY2(x)
# define STRINGIFY2(x) #x
#endif
/**
 * @brief Converts a C-style string to uppercase and prints it. This function
 * creates a copy of the input string, converts each character to uppercase
 * using std::toupper, and then prints the resulting string. The memory
 * allocated for the copy is then deallocated using delete[].
 * @param argv The C-style string to be converted to uppercase and printed. This
 * string is not modified.
 * @details
 * 1. `std::string str(argv);` - This is direct initialization. The
 *    `std::string` constructor that takes a `const char*` is called directly to
 *    initialize `str`.
 * 2. `std::string str = argv;` - This is copy initialization. Conceptually,
 *    this does the same thing as direct initialization, but it involves an
 *    extra step. First, a temporary `std::string` object is created from
 *    `argv`, and then this temporary object is used to initialize `str`. In
 *    practice, most modern compilers will optimize away the extra step, so
 *    there's no p+erformance difference between direct and copy initialization.
 *    In general, both forms of initialization are fine to use, and the choice
 *    between them is largely a matter of personal preference. However, in some
 *    cases, direct initialization can be more efficient or allow for more
 *    control over the initialization process.
 **/
void strUpper(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
	{
		std::string prev = argv[i - 1];
		std::string curr = argv[i];

		for (size_t j = 0; j < curr.size(); ++j)
			curr[j] = std::toupper(curr[j]);
		if (prev[prev.length() - 1] != ' ' && curr[0] != ' ')
			std::cout << ' ';
		std::cout << curr;
	}
}
//std::toupper(cpy[i]));
/**
 * @brief The main function of the megaphone program. This function takes
 * command line arguments, converts them to uppercase using the str_upper
 * function, and prints them.
 * @param argc The number of command line arguments.
 * @param argv The command line arguments.
 * @return Returns 0 on success.
 */
int main(int argc, char *argv[])
{
#if (DEBUG > 0)
	std::cout << "\033[0;31mDEBUG:" << STRINGIFY(DEBUG) << std::endl;
#endif
	std::cout << "\033[0;32m";
	if (argc != 1)
	{
		strUpper(argc, argv);
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << "\033[0m" << std::endl;
	return (0);
}


/**
 * NOTES: 
 * (::) The Scope Resolution Operator : a token that allows access to a
 * constant, static property, or static method of a class or one of its parents.
 *  Moreover, static properties or methods can be overriden via late static binding.
*/
#include <ClapTrap.hpp>

#if (DEBUG == 0)

static int getRandomObj(ClapTrap const& obj) 
{
	return (rand() % obj.getEP() + 1);
}

static bool getRandomNum() 
{
	return (rand() % 2);
}

std::string objName()
{
	static unsigned int num;
	std::ostringstream os;
	os << "Obj_" << (++num);
	return (os.str());
}

static void action(ClapTrap& o1, ClapTrap& o2, int amount)
{
	if (getRandomNum() == 1)
		o1.action(o1, o2, amount);
	else
		o1.beRepaired(amount);
}

int main(void)
{
	srand(static_cast<unsigned int>(time(0)));
	int i = 10;
	ClapTrap o1(objName());
	ClapTrap o2(objName(), getRandomObj(o1) / 2);
	o1.setAD(getRandomObj(o1) / 2);
	coutnl(std::cout << "\n========== CLAPTRAP BEGINS ==========\n");
	while (i)
	{
		if (getRandomNum() == 1)
			action(o1, o2, getRandomObj(o1));
		else
			action(o2, o1, getRandomObj(o2));
		i--;
	}
	coutnl(std::cout << "\n========== CLAPTRAP STOPS ==========\n");
	return (0);
}
#endif


/**
* NOTES: DIFFERENCE BETWEEN OSTREAM AND SSTRINGSTREAM
* `std::ostream` and `std::stringstream` are both output stream classes
* in C++, but they are used for different purposes:
 *
 * 1. `std::ostream` is a base class for output streams that provides functions
 * to write characters and formatted data to output sequences. The most
 * common derived class of `std::ostream` is `std::ofstream` for writing to
 * files, and `std::cout` is an object of type `std::ostream` that represents
 * the standard output stream.
  *
 * 2. `std::stringstream` is a stream class to operate on strings. It basically
 * implements input/output operations on memory (string) based streams.
 * `std::stringstream` can be helpful in different type of parsing. The data
 * written to a `std::stringstream` can be retrieved as a `std::string` by
 * calling the `str` member function. `std::ostream` and `std::ostringstream`
 * are both part of the C++ Standard Library's stream classes, but they serve
 * different purposes:
 * 3. `std::ostringstream` is a type of output stream that operates on strings.
 * It's a part of the stringstream class, which are input/output classes to
 * operate on strings. The data written to a `std::ostringstream` object can
 * be retrieved as a `std::string` using the `str()` member function. It's
 * often used for constructing and formatting strings before output.
  *
 * In summary, you would use `std::ostream` when you want to write data to an
 * output sequence such as the console or a file, and you would use
 * `std::stringstream` when you want to perform input/output operations on a
 * string in memory.
 *
 * NOTES: INLINE FUNCTIONS
 * Inline functions are a type of function in C++ that are expanded in place where
 * they are called. That is, the function call is replaced by the function code by
 * the compiler. They are defined using the `inline` keyword:
 * 
 * ```cpp
 * inline void myInlineFunction() {
 *     std::cout << "Hello, world!" << std::endl;
 * }
 * ```
 * 
 * The main difference between inline functions and non-inline functions is how
 * they are handled by the compiler. When a non-inline function is called, the
 * program jumps to the memory location of that function, executes the code, and
 * then jumps back to the point where the function was called. For inline
 * functions, the compiler replaces the function call with the actual code of the
 * function, which can result in faster execution at the cost of increased binary
 * size.
 * 
 * Inline functions are useful for small, frequently called functions. However, the
 * `inline` keyword is just a suggestion to the compiler. The compiler may choose
 * not to inline a function for various reasons, such as if the function is too
 * complex or if it would result in a significant increase in binary size.
*/
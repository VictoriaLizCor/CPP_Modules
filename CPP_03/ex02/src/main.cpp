#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#if (DEBUG == 0)


/**
 * @brief Executes an action based on the health and status of two ClapTrap objects.
 * 
 * This function decides whether to repair `o1` or attack `o2` based on their health.
 * If `o1`'s health is below a threshold or less than `o2`'s, it repairs; otherwise, it attacks.
 * 
 * @param o1 Reference to the first ClapTrap object.
 * @param o2 Reference to the second ClapTrap object.
 * @param amount The amount of damage to deal or health to recover.
 * @return true if a special condition is met, false otherwise.
 */
static bool checkObjs(ClapTrap& o1 , ClapTrap& o2)
{
	if (!o1.getHitPoints() || !o2.getHitPoints())
		return (1);
	else if (!o1.getEnergyPoints() && !o2.getEnergyPoints())
		return (o1.check_KO_Status() && o2.check_KO_Status());
	return (0);
}


/**
 * @brief Executes an action based on the health and status of two ClapTrap
 * objects.
 *
 * This function decides whether to repair `o1` or attack `o2` based on their
 * health. If `o1`'s health is below a threshold or less than `o2`'s, it
 * repairs; otherwise, it attacks.
 *
 * @param o1 Reference to the first ClapTrap object.
 * @param o2 Reference to the second ClapTrap object.
 * @param amount The amount of damage to deal or health to recover.
 * @return true if a special condition is met, false otherwise.
 */
/**
 * NOTES:
 *  std::cout << "bool healthPriority = " << o1.getHitPoints()
	<< " <= " << o1.getMaxPoints() - o1.getRecoveryPoints() << " ()"
	<< o1.getMaxPoints() << " - " 
	<< o1.getRecoveryPoints() << "); // " 
	<< std::boolalpha << healthPriority << "; "
	<< (healthPriority != o1.getHitPoints() < o2.getHitPoints()) << std::endl;
 */
static bool action(ClapTrap& o1, ClapTrap& o2, int amount)
{
	bool healthPriority = o1.getHitPoints() <= o1.getMaxPoints() - o1.getRecoveryPoints();
	
	std::cout << "\n";
	if (checkObjs(o1, o2))
		return (1);
	if (healthPriority)
		o1.beRepaired(o1.getRecoveryPoints());
	else
		o1.executaAttack(o2, amount);
	return (0);
}


int main(void)
{
	std:: string obj = "Obj";
	bool KO = 0;
	ScavTrap o1(obj);
	ScavTrap o2(obj);
	int i = 0;
	std::cout << "\n" << i << " ========== CLAPTRAP BEGINS ==========\n\n";
	o1.printStatus();
	o2.printStatus();
	std::cout << "\n==============\n";
	while (1)
	{
		if (++i % 2 == 1)
			KO = action(o1, o2, o1.getAttackDamage());
		else
			KO = action(o2, o1, o2.getAttackDamage());
		if (KO)
			break ;
		o1.printStatus();
		o2.printStatus();
	}
	std::cout << "\n" << i << " ========== CLAPTRAP STOPS ==========\n\n";
	{
		ClapTrap c1;
		FragTrap f1=c1;
		f1.printStatus();
	}
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
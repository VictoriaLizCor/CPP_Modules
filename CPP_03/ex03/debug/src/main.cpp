
#include "DiamondTrap.hpp"

#if (DEBUG != 0)

static unsigned int getRandomNum(int num)
{
	return (static_cast<unsigned int>(rand() % num));
}

std::string objName()
{
	static unsigned int num;

	std::ostringstream os;
	os << "Obj" << (++num);
	return (os.str());
}

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
	if (o1.getHitPoints() == 0 || o2.getHitPoints() == 0)
		return (1);
	else if (!o1.getEnergyPoints() && !o2.getEnergyPoints())
		return (o1.check_KO_Status() && o2.check_KO_Status());
	return (0);
}

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
static bool action(ClapTrap& o1, ClapTrap& o2, unsigned int amount)
{
	bool random = getRandomNum(2);
	bool healthPriority = o1.getHitPoints() <= o1.getMaxPoints() - o1.getRecoveryPoints();

	if (checkObjs(o1, o2))
		return (1);
	if (random == 0 && healthPriority)
		o1.beRepaired(o1.getRecoveryPoints());
	else
		o1.executaAttack(o2, amount);
	return (0);
}

static void startClapTrap(ClapTrap& o1 , ClapTrap& o2)
{
	if (&o1 == &o2)
	{
		std::cout << setColor("Difference objects are needed to continue", FRED, 1);
		return ;
	}
	bool KO;
	std::cout << "\n========== CLAPTRAP BEGINS ==========\n\n";
	o1.printStatus();
	o2.printStatus();
	std::cout << "\n==============\n";
	KO = checkObjs(o1, o2);
	if (checkObjs(o1, o2))
	{
		std::cout << "\n";
		(void)o1.check_KO_Status();
		(void)o2.check_KO_Status();
	}
	unsigned int start = getRandomNum(2);
	while (!KO)
	{
		std::cout << "\n";
		if (++start % 2 == 1)
			KO = action(o1, o2, o1.getAttackDamage());
		else
			KO = action(o2, o1, o2.getAttackDamage());
		if (KO)
			break ;
		o1.printStatus();
		o2.printStatus();
	}
	std::cout << "\n========== CLAPTRAP STOPS ==========\n\n";
}

int main(void)
{
	srand(static_cast<unsigned int>(time(0)));
	{
			std::cout << "\n*****\n";
			DiamondTrap d1(objName());
			std::cout << "--\n";
	}
	{
		// std::cout << "\n*****\n";
		// FragTrap f1(objName());
		// DiamondTrap d1(objName(), getRandomNum(static_cast<int>(d1.getMaxPoints()) - 1) + 1);
		// startClapTrap(f1, d1);
		// {
		// 	std::cout << "\n*****\n";
		// 	ClapTrap c1(objName());
		// 	std::cout << "--\n";
		// 	DiamondTrap d1(c1);
		// 	std::cout << "--\n";
		// }
		{
			std::cout << "\n*****\n";
			FragTrap f1(objName());
			std::cout << "--\n";
			DiamondTrap d1=f1;
			std::cout << "--\n";
		}
	}
	std::cout << "--\n";
	return (0);
}
#endif
 
/**
 * NOTES: `-Wshadow` and `-Wno-shadow` flags 
 * In GCC can help manage and
 * control warnings about variable shadowing. Shadowing occurs when a variable in
 * a derived class has the same name as a variable in one of its base classes or
 * in the global scope, potentially leading to confusion or bugs.
 * `-Wshadow` and `-Wno-shadow` are compiler flags that can help you
 * manage and control shadowing warnings in C++ code involving inheritance. Use
 * them according to your project's needs and coding standards.
 * ### Using `-Wshadow`
 *
 * This flag enables warnings about variable shadowing. When compiling code that
 * involves complex inheritance hierarchies, `-Wshadow` can help identify places
 * where a derived class member might unintentionally shadow a member of a base
 * class. This is particularly useful in ensuring that your code is clear and
 * that you're not accidentally hiding base class members.
 *
 * For example, if  [`ScavTrap`]and  [`FragTrap`]) both have a member variable or
 * method that [`DiamondTrap`]also defines, `-Wshadow` will warn you  about
 * this.
 *
 * ### Using `-Wno-shadow`
 *
 * Conversely, `-Wno-shadow` disables these warnings. In some cases, shadowing
 * might be intentional, or you might decide that the warning is not relevant to
 * your current coding task. Using `-Wno-shadow` can clean up your compiler
 * output by removing these warnings.
 * 
 * ### Considerations
 *
 * - **Code Clarity**: Even if you disable shadow warnings, it's generally good
 *   practice to avoid shadowing where possible for the sake of code clarity and
 *   maintainability.
 * - **Intentional Shadowing**: If shadowing is intentional, document it clearly
 *   in your code to avoid confusion for others or for yourself when you return
 *   to the code later.
 * - **Project Guidelines**: Follow any coding standards or guidelines your
 *   project or team has set regarding shadowing.
 * * 
 * NOTES: `virtual keyword`
 * 
 * Removing the `virtual` keyword from the base class [`ClapTrap`] for the
 * derived class [`DiamondTrap`]  can have several implications, especially in a
 * hierarchy involving multiple inheritance and polymorphism. Here's a breakdown
 * of potential impacts:
 *
 * 1. **Object Slicing**: Without `virtual` inheritance, if
 *    [`DiamondTrap`] objects are assigned to [`ClapTrap`]or used in a context
 *    expecting a [`ClapTrap`], you might encounter object slicing. Object
 *    slicing happens when a derived class object is assigned to a base class
 *    object, leading to the loss of the derived class's data and behavior.
 *
 * 2. **Constructor Ambiguity**: [`DiamondTrap`]inherits from both
 *    [`ScavTrap`]and [`FragTrap`], which in turn, inherit from [`ClapTrap`]. If
 *    [`ClapTrap`] is not a virtual base class, [`DiamondTrap`]would inherit two
 *    separate copies of [`ClapTrap`] one via [`ScavTrap`] and one via
 *    [`FragTrap`], leading to ambiguity. This could complicate the constructor
 *    calls for , as it would need to initialize two separate [`ClapTrap`]
 *    subobjects.
 *
 * 3. **Destructor Calls**: Without virtual destructors, if a
 *    [`DiamondTrap`]object is deleted through a pointer to [`ClapTrap`], only
 *    the [`ClapTrap`]destructor would be called, not the [`DiamondTrap`]
 *    destructor. This could lead to resource leaks if [`DiamondTrap`] manages
 *    resources that need to be released in its destructor.
 *
 * 4. **Polymorphic Behavior**: The absence of `virtual` inheritance can affect
 *    polymorphic behavior. For instance, if [`ClapTrap`] has virtual functions
 *    overridden by [`DiamondTrap`], and you use a [`ClapTrap`] pointer to refer
 *    to a [`DiamondTrap`]object, the expected polymorphic behavior (calling
 *    [`DiamondTrap`]s overrides) might not work as intended without virtual
 *    inheritance and virtual destructors.
 *
 * In summary, removing `virtual` from the inheritance of [`ClapTrap`]or
 * [`DiamondTrap`]could lead to object slicing, constructor ambiguity, improper
 * destructor calls, and broken polymorphic behavior. It's crucial in complex
 * inheritance hierarchies, especially with multiple inheritance, to carefully
 * manage inheritance types and ensure virtual destructors are used where
 * appropriate to maintain correct object behavior and resource management.
 *  **/

/*
ScavTrap(), FragTrap()
hp<-FragTrap(100)
ep<-ScavTrap(50)
ad<-FragTrap(30)
attact<-Scavtrap()
*/
#include <ScavTrap.hpp>

#if (DEBUG != 0)

static int getRandomNum(int num){return (rand() % num);}

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
		return (1);
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
static bool action(ClapTrap& o1, ClapTrap& o2, int amount)
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
	int start = getRandomNum(2);
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

	std:: string obj = "Obj";

	ClapTrap o1(obj, getRandomNum(o1.getMaxPoints() - 1) + 1);
	ScavTrap o2(obj, getRandomNum(o1.getMaxPoints() - 1) + 1);
	startClapTrap(o1, o2);
	{
		ScavTrap o3(o1);
	}
	std::cout << "------\n";
	{
		ClapTrap c1;
		c1.printStatus();
		ScavTrap o3=c1;
		o3.printStatus();
	}
	std::cout << "------\n";
	return (0);
}
#endif
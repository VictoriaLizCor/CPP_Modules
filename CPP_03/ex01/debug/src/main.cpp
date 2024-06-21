#include <ScavTrap.hpp>

#if (DEBUG != 0)

static int getRandomNum(int num){return (rand() % num);}

static bool checkObjs(ClapTrap& o1 , ClapTrap& o2)
{
	if (o1.getHitPoints() == 0 || o2.getHitPoints() == 0)
		return (1);
	else if (!o1.getEnergyPoints() && !o2.getEnergyPoints())
		return (1);
	return (0);
}

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

	ScavTrap o1(obj, getRandomNum(o1.getMaxPoints() - 1) + 1);
	ScavTrap o2(obj, getRandomNum(o1.getMaxPoints() - 1) + 1);
	startClapTrap(o1, o2);

	return (0);
}
#endif
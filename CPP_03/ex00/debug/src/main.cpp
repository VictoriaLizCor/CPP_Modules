#include <ClapTrap.hpp>

#if (DEBUG != 0)

static int getRandomNum(int num)
{
	return (rand() % num);
}

std::string objName()
{
	static unsigned int num;

	std::ostringstream os;
	os << "Obj_" << (++num);
	return (os.str());
}

static bool checkObj(ClapTrap& o1 , ClapTrap& o2)
{
	if (!o1.getHitPoints() || !o2.getHitPoints())
		return (1);
	else if (!o1.getEnergyPoints() && !o2.getEnergyPoints())
		return (o1.check_KO_Status() && o2.check_KO_Status());
	return (0);
}

static bool action(ClapTrap& o1, ClapTrap& o2, int amount)
{
	bool healthPriority = o1.getHitPoints() <= o1.getMaxPoints() - o1.getRecoveryPoints();

	std::cout << "\n";
	if (checkObj(o1, o2))
		return (1);
	if (getRandomNum(2) == 0 && healthPriority)
		o1.beRepaired(o1.getRecoveryPoints());
	else
		o1.executaAttack(o2, amount);
	return (0);
}


int main(void)
{
	srand(static_cast<unsigned int>(time(0)));

	bool KO = 0;
	ClapTrap o1(objName(), getRandomNum(ClapTrap::getMaxPoints() - 1) + 1);
	ClapTrap o2(objName());
	o2.setAttackDamage(static_cast<unsigned int>(getRandomNum(ClapTrap::getMaxPoints() - 1) + 1));
	std::cout << "\n========== CLAPTRAP BEGINS ==========\n\n";
	o1.printStatus();
	o2.printStatus();
	std::cout << "\n==============\n";
	while (1)
	{
		if (getRandomNum(2)== 1)
			KO = action(o1, o2, o1.getAttackDamage());
		else
			KO = action(o2, o1, o2.getAttackDamage());
		if (KO)
			break ;
		o1.printStatus();
		o2.printStatus();
	}
	std::cout << "\n========== CLAPTRAP STOPS ==========\n\n";
	return (0);
}
#endif
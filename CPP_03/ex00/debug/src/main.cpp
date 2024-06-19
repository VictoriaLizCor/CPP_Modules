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

static void action(ClapTrap& o1, ClapTrap& o2, int amount)
{
	if (getRandomNum(2) == 0 && (o1.getHP() <= o1.getMP() - o1.getRP()))
		o1.beRepaired(o1.getRP());
	else
		o1.executaAttack(o1, o2, amount);
}

int main(void)
{
	srand(static_cast<unsigned int>(time(0)));

	ClapTrap o1(objName(), getRandomNum(ClapTrap::getMP() - 1) + 1);
	ClapTrap o2(objName());
	o2.setAD(static_cast<unsigned int>(getRandomNum(ClapTrap::getMP() - 1) + 1));
	coutnl(std::cout << "\n========== CLAPTRAP BEGINS ==========\n");
	o1.status();
	o2.status();
	coutnl(std::cout << "\n\n==============\n");
	int i = getRandomNum(2);
	while (o1.getEP() || o2.getEP())
	{
		if (++i % 2 == 0)
			action(o1, o2, o1.getAD());
		else
			action(o2, o1, o2.getAD());
		o1.status();
		o2.status();
		std::cout << "\n\n";
		if ((!o1.getHP() && !o2.getHP()) && i > ClapTrap::getMP() * 2 + 5)
			break ;
	}
	coutnl(std::cout << i << "========== CLAPTRAP STOPS ==========\n");
	return (0);
}
#endif
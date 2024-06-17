#include <ClapTrap.hpp>

#if (DEBUG != 0)
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
	if (bool r1 = getRandomNum() == 0 && o1.getHP() < o1.getMP())
	{
		std::cout << r1;
		o1.beRepaired(amount);
	}
	else
		o1.action(o1, o2, amount);
}

int main(void)
{
	srand(static_cast<unsigned int>(time(0)));
	int i = 10;
	ClapTrap o1(objName());
	ClapTrap o2(objName(), getRandomObj(o1) / 2);
	o1.setAD(getRandomObj(o1) / 2);
	coutnl(std::cout << "\n========== CLAPTRAP BEGINS ==========\n");
	{
		std::cout << o1  << " " + setColor("HP: ", FGREEN, 0) << std::endl;
	}
	// o1.status();
	// o2.status();
	// coutnl(std::cout << "==============");
	// while (i)
	// {
	// 	if (getRandomNum() == 1)
	// 		action(o1, o2, getRandomObj(o1));
	// 	else
	// 		action(o2, o1, getRandomObj(o2));
	// 	i--;
	// }
	coutnl(std::cout << "\n========== CLAPTRAP STOPS ==========\n");
	return (0);
}
#endif
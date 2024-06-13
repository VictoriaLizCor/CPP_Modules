#include <ClapTrap.hpp>

#if (DEBUG == 0)
int main(void)
{
	ClapTrap o1("Victoria");
	ClapTrap o2("Linda");
	std::cout << "HELLO WORLD" << std::endl;
	return (0);
}
#endif
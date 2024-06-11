#if (DEBUG != 0)
#include <ClapTrap.hpp>
#include <stringUtils.hpp>
int main(void)
{
	std::cout << sColor("HELLO WORLD", FGREEN ,0) << std::endl;
	return (0);
}
#endif
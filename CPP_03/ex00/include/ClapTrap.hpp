
#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <stringUtils.hpp>

# ifndef DEBUG
 #  define DEBUG 0
# endif

# if (DEBUG != 0)
# endif
class ClapTrap
{
private:
	t_Name			_name;
	static int		_color;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;
public:
	ClapTrap(std::string const& name);
	~ClapTrap();
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif

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
typedef s_coloredName t_Name;
class ClapTrap
{
	private:
		t_Name			_name;
		static int		_color;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
		static int const _MAX_POINTS = 10;
	public:
		ClapTrap(std::string const& name);
		ClapTrap(std::string const& name, int attackDamage);
		~ClapTrap();
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		setAD(unsigned int amount);
		void		action(ClapTrap& o1, ClapTrap& o2, int amount);
		int			getEP(void) const;
		int			getHP(void) const;
		int			getMP(void) const;
		int			getAD(void) const;
		void		status(void);
		std::string	getName(void);
};

std::ostream& operator << (std::ostream & os, ClapTrap& rhs);
#endif
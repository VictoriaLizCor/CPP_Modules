
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
		//
		unsigned int	_recoveryPoints;
		static int const _MAX_POINTS = 10;
	public:
		ClapTrap(std::string const& name);
		ClapTrap(std::string const& name, unsigned int attackDamage);
		~ClapTrap();
		void		attack(std::string const& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		setAD(unsigned int amount);
		void		setRP(void);
		void		executaAttack(ClapTrap& o1, ClapTrap& o2, int amount);
		int			getEP(void) const;
		int			getHP(void) const;
		int			getAD(void) const;
		int			getRP(void) const;
		static int	getMP(void);

		void		status(void);
		std::string	getName(void);
};

std::ostream& operator << (std::ostream & os, ClapTrap& rhs);
#endif
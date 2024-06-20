
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
		static int const _MAX_POINTS = 5;
		void		initialize(std::string const& name);
	public:
		ClapTrap(std::string const& name);
		ClapTrap(std::string const& name, unsigned int attackDamage);
		ClapTrap& operator=(ClapTrap const& rhs);
		ClapTrap(ClapTrap const& rhs);
		~ClapTrap();
		void		attack(std::string const& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		setAttackDamage(unsigned int amount);
		void		setRecoveryPoints(void);
		void		executaAttack(ClapTrap& o2, int amount);
		int			getEnergyPoints(void) const;
		int			getHitPoints(void) const;
		int			getAttackDamage(void) const;
		int			getRecoveryPoints(void) const;
		static int	getMaxPoints(void);
		static int	getObjects(void);
		void		printStatus(void);
		bool		check_KO_Status(void);
		std::string	getName(void);
};

std::ostream& operator << (std::ostream & os, ClapTrap& rhs);
#endif

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <stringUtils.hpp>

# ifndef DEBUG
 #  define DEBUG 0
# endif

# if (DEBUG != 0)
# endif
typedef s_coloredName t_Name;
class ClapTrap
{
	protected:
		t_Name					_name;
		unsigned int			_hitPoints;
		unsigned int			_energyPoints;
		unsigned int			_attackDamage;
		unsigned int			_recoveryPoints;
		static int				_objectColor;
		static unsigned int		_MAX_HIT_POINTS;

		void				initialize(std::string const& name);
		virtual void		setRecoveryPoints(void);
		static int			getObjects(void);
		void				takeDamage(unsigned int amount);
	private:

	public:
		ClapTrap(void);
		ClapTrap(std::string const& name);
		ClapTrap(std::string const& name, unsigned int attackDamage);
		ClapTrap(std::string const& name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage);
		ClapTrap& operator=(ClapTrap const& rhs);
		ClapTrap(ClapTrap const& rhs);
		virtual					~ClapTrap();
		void					setName(std::string const& name);
		void					setAttackDamage(unsigned int amount);
		unsigned int			getEnergyPoints(void) const;
		unsigned int			getHitPoints(void) const;
		unsigned int			getAttackDamage(void) const;
		unsigned int			getRecoveryPoints(void) const;
		virtual unsigned int	getMaxPoints(void);
		unsigned int			getObjectColor(void);
		void					executaAttack(ClapTrap& o2, int amount);
		virtual void			attack(std::string const& target);
		void					beRepaired(unsigned int amount);
		void					printStatus(void);
		bool					check_KO_Status(void);
		std::string				getName(void);
};

std::ostream& operator << (std::ostream & os, ClapTrap& rhs);
#endif
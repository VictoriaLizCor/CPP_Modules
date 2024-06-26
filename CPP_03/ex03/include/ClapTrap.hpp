
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
	private:
		static unsigned int		_MAX_HIT_POINTS;
		static unsigned int		_CLASS_COLOR;
		unsigned int			_recoveryPoints;

	protected:
		t_Name					_name;
		unsigned int			_hitPoints;
		unsigned int			_energyPoints;
		unsigned int			_attackDamage;
		static unsigned int		_objectColor;

		// to be used only inside class members and derived
		static int				getObjects(void);
		void					takeDamage(unsigned int amount);
		virtual void			setRecoveryPoints(void);
		virtual unsigned int	getClassColor(void);
		virtual void			initialize();

	public:
		ClapTrap(void);
		ClapTrap(std::string const& name);
		ClapTrap(std::string const& name, unsigned int attackDamage);
		ClapTrap(std::string const& name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage);
		ClapTrap& operator=(ClapTrap const& rhs);
		ClapTrap(ClapTrap const& rhs); 
		virtual					~ClapTrap();
		//
		void					setName(std::string const& name);
		std::string 			setColorName(unsigned int const& color);
		void					setAttackDamage(unsigned int amount);
		unsigned int			getEnergyPoints(void) const;
		unsigned int			getHitPoints(void) const;
		unsigned int			getAttackDamage(void) const;
		unsigned int			getObjectColor(void);
		// 
		virtual void			attack(std::string const& target);
		virtual unsigned int	getRecoveryPoints(void);
		virtual unsigned int	getMaxPoints(void);
		void					executaAttack(ClapTrap& o2, unsigned int amount);
		void					beRepaired(unsigned int amount);
		void					printStatus(void);
		bool					check_KO_Status(void);
		virtual std::string		getName(void);

};

std::ostream& operator << (std::ostream & os, ClapTrap& rhs);
#endif
#ifndef DIAMOND_TRAP_HPP
 #define DIAMOND_TRAP_HPP
 #include "FragTrap.hpp"
 #include "ScavTrap.hpp"
 # include <typeinfo>

class DiamondTrap : public ScavTrap, public FragTrap
{
	protected:
		
	private:
		static unsigned int		_MAX_HIT_POINTS;
		static unsigned int		_CLASS_COLOR;
		t_Name					_name;
		unsigned int			_recoveryPoints;
		void					initialize();
		void					setRecoveryPoints(void);
		unsigned int			getClassColor(void);

	public:

		DiamondTrap(void);
		DiamondTrap(std::string const& name);
		DiamondTrap(std::string const& name, unsigned int attackDamage);
		DiamondTrap(std::string const& name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage);
		DiamondTrap& operator=(ClapTrap const& rhs);
		DiamondTrap(ClapTrap const& rhs);
		~DiamondTrap();

		unsigned int			getMaxPoints(void);
		unsigned int			getRecoveryPoints(void);
		std::string				getName(void);
		void					setName(std::string const& name);
		void					attack( std::string const& target);
		void					whoAmI( void );

};
#endif

/*
ScavTrap(), FragTrap()
hp<-FragTrap(100)
ep<-ScavTrap(50)
ad<-FragTrap(30)
attact<-Scavtrap()
*/
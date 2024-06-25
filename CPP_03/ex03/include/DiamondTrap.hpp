#ifndef DIAMOND_TRAP_HPP
 #define DIAMOND_TRAP_HPP
 #include "FragTrap.hpp"
 #include "ScavTrap.hpp"
 # include <typeinfo>

class DiamondTrap : public ScavTrap, FragTrap
{
	protected:
		
	private:
		static unsigned int		_MAX_HIT_POINTS;
		t_Name					_name;

		void					initialize();
	public:

		DiamondTrap(void);
		DiamondTrap(std::string const& name);
		DiamondTrap(std::string const& name, unsigned int attackDamage);
		DiamondTrap(std::string const& name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage);
		DiamondTrap& operator=(ClapTrap const& rhs);
		DiamondTrap(ClapTrap const& rhs);
		virtual ~DiamondTrap();

		unsigned int	getMaxPoints(void);
		void			whoAmI( void );
};
#endif
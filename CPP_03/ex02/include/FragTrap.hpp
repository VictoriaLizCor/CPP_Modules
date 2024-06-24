#ifndef FRAG_TRAP_HPP
 #define FRAG_TRAP_HPP
 #include "ClapTrap.hpp"
 # include <typeinfo>

class ScavTrap : public ClapTrap
{
	protected:
		
	private:
		static unsigned int		_MAX_HIT_POINTS;
	public:

		ScavTrap(void);
		ScavTrap(std::string const& name);
		ScavTrap(std::string const& name, unsigned int attackDamage);
		ScavTrap(std::string const& name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage);
		ScavTrap& operator=(ScavTrap const& rhs);
		ScavTrap(ScavTrap const& rhs);
		virtual ~ScavTrap();

		unsigned int	getMaxPoints(void);
		void			attack( std::string const& target );
		void			guardGate( void );
};
#endif
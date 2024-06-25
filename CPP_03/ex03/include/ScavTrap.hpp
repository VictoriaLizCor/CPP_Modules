#ifndef SCAV_TRAP_HPP
 #define SCAV_TRAP_HPP
 #include "ClapTrap.hpp"
 # include <typeinfo>
class ScavTrap : public virtual ClapTrap
{
	protected:
		unsigned int		_recoveryPoints;
		void				setRecoveryPoints(void);
	// 	void				setRecoveryPoints(void);
	private:
		static unsigned int	_MAX_HIT_POINTS;
		// unsigned int		_recoveryPoints;
		void				initialize(void);
	public:

		ScavTrap(void);
		ScavTrap(std::string const& name);
		ScavTrap(std::string const& name, unsigned int attackDamage);
		ScavTrap(std::string const& name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage);
		ScavTrap& operator=(ClapTrap const& rhs);
		ScavTrap(ClapTrap const& rhs);
		~ScavTrap();

		unsigned int		getMaxPoints(void);
		void				attack( std::string const& target );
		void				guardGate( void );
		void				setRecoveryPoints(void);
};
#endif
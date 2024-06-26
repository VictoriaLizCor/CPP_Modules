#ifndef SCAV_TRAP_HPP
 #define SCAV_TRAP_HPP
 #include "ClapTrap.hpp"
 # include <typeinfo>
class ScavTrap : public virtual ClapTrap
{
	protected:
		void				setRecoveryPoints(void);

	private:	
		static unsigned int	_MAX_HIT_POINTS;
		static unsigned int	_CLASS_COLOR;
		unsigned int		_recoveryPoints;
		void				initialize(void);
		unsigned int		getClassColor(void);

	public:

		ScavTrap(void);
		ScavTrap(std::string const& name);
		ScavTrap(std::string const& name, unsigned int attackDamage);
		ScavTrap(std::string const& name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage);
		ScavTrap& operator=(ClapTrap const& rhs);
		ScavTrap(ClapTrap const& rhs);
		~ScavTrap();

		unsigned int		getMaxPoints(void);
		unsigned int		getRecoveryPoints(void);
		virtual void		attack( std::string const& target );
		void				guardGate( void );
};
#endif

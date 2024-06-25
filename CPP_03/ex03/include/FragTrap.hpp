#ifndef FRAG_TRAP_HPP
 #define FRAG_TRAP_HPP
 #include "ClapTrap.hpp"
 # include <typeinfo>

class FragTrap : public virtual ClapTrap
{
	protected:
	// 	void				setRecoveryPoints(void);
	private:
		static unsigned int	_MAX_HIT_POINTS;
		// unsigned int		_recoveryPoints;
		void				initialize(void);
		// void				setRecoveryPoints(void);
	public:

		FragTrap(void);
		FragTrap(std::string const& name);
		FragTrap(std::string const& name, unsigned int attackDamage);
		FragTrap(std::string const& name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage);
		FragTrap& operator=(ClapTrap const& rhs);
		FragTrap(ClapTrap const& rhs);
		~FragTrap();

		unsigned int		getMaxPoints(void);
		void				highFivesGuys( void );
};
#endif
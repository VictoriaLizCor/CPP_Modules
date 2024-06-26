#ifndef FRAG_TRAP_HPP
 #define FRAG_TRAP_HPP
 #include "ClapTrap.hpp"
 # include <typeinfo>

class FragTrap : public ClapTrap
{
	protected:
		
	private:
		static unsigned int		_MAX_HIT_POINTS;
	public:

		FragTrap(void);
		FragTrap(std::string const& name);
		FragTrap(std::string const& name, unsigned int attackDamage);
		FragTrap(std::string const& name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage);
		FragTrap& operator=(ClapTrap const& rhs);
		FragTrap(ClapTrap const& rhs);
		virtual ~FragTrap();

		unsigned int	getMaxPoints(void);
		void			attack( std::string const& target );
		void			highFivesGuys( void );
};
#endif
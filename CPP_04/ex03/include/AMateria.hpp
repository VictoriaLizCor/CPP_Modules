#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <stringUtils.hpp>
# ifndef DEBUG
#  define DEBUG 0
# endif

class ICharacter;

class AMateria
{
	private:
		struct t_list
		{
			AMateria* instance = 0;
			t_list* next = 0;
		};
		static t_list* _head;

	protected:
		static int			_instanceCount;
		int					_instanceAMateria;
		std::string 		_colorIdStr;
		std::string			_type;

		void initColor(void);
	public:
		AMateria(std::string const & type);
		AMateria& operator=(AMateria const& rhs);
		AMateria(AMateria const& rhs);
		virtual ~AMateria();

		std::string const&	getType(void) const;
		virtual AMateria*	clone(void) const = 0;
		virtual void		use(ICharacter& target);

		virtual std::string	getInfo(void) const; // Do not declare as pure virtual. Read notes */
};

std::ostream& operator << (std::ostream& os, AMateria& rhs);

#endif // AMATERIA_HPP

/**
 * @note: AVOID CALLING PURE VIRTUAL FUNCTIONS IN CONSTRUCTORS
 *
 * getInfo can not be pure virtual function as it get calls with the
 * operator << in the constructor.
 *
 * The error "pure virtual method called" followed by "terminate
 * called without an active exception" and the program aborting with a
 * core dump occurs when a pure virtual function is called on an
 * object that is not fully constructed or is being destructed. This
 * situation typically arises when attempting to call a pure virtual
 * function from a constructor or destructor.
 *
 * In C++, the construction and destruction process of an object
 * involves setting up or tearing down the object's vtable (virtual
 * table), which is used for dynamic dispatch of virtual function
 * calls. During construction, the vtable is built up from the base
 * class to the derived class, and during destruction, it is torn down
 * in the reverse order.
* *
 * - **During Construction:** When a constructor is running, the
 *   object's dynamic type is that of the current constructor's class,
 *   not yet the final derived class if the constructor is for a base
 *   class. This means the vtable entries for the derived class are
 *   not yet set up. If a pure virtual function is called at this
 *   stage, there's no implementation to call (since pure virtual
 *   functions don't have implementations in the base class where they
 *   are declared), leading to undefined behavior.

 * - **During Destruction:** Similarly, when a destructor is running,
 *   the object's dynamic type is set to the destructor's class, and
 *   the vtable is being torn down. If a pure virtual function is
 *   called after or during the derived class's destructor, the vtable
 *   may no longer point to the derived class's implementation,
 *   leading again to undefined behavior.

 *  * Doing so would risk invoking it when the object's vtable is not
 *	fully formed, causing the runtime error you encountered. This is
 *	a fundamental rule in C++ to ensure type safety and object
 *	integrity during construction and destruction phases.
 *
 *
 */

/**
 * @note: COPY CONSTRUCTOR CALL INSTEAD OF COPY ASSIGMENT OPERATOR
 *
 * ```
 * Cure c1;
 * Cure c2 = c1;
 * ```
 * The copy constructor is called for `c2` because this syntax (`Cure
 * c2 = c1;`) is an initialization, not an assignment. In C++, when
 * you initialize an object with another object of the same type, the
 * copy constructor is invoked to create the new object (`c2` in this
 * case) as a copy of the existing object (`c1`). This is a standard
 * behavior defined by the C++ language specification.
 *
 * The relevant code excerpt from your workspace that defines the copy
 * constructor for the `Cure` class is:
 *
 */
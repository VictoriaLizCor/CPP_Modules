#ifndef {{UPPER_H}}
# define {{UPPER_H}}

# include <iostream>

# ifndef DEBUG
 #  define DEBUG 0
# endif

class {{CLASS_NAME}}
{
	private:
	protected:
	public:
		{{CLASS_NAME}}();
		~{{CLASS_NAME}}();
};
std::ostream& operator << (std::ostream & os, {{CLASS_NAME}}& rhs);

#endif // {{UPPER_H}}
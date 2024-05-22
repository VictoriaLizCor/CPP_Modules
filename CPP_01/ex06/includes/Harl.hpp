#pragma once
# ifndef HARL_HPP
#  define HARL_HPP
# include <iostream>
# include <sstream>

typedef enum color
{
	FDEFAULT	= 39,
	FRED		= 91,
	FGREEN		= 92,
	FYELLOW		= 93,
	FBLUE		= 94,
	FWHITE		= 97,
}t_color;

class Harl
{
	public:
		enum type
		{
			DEBUG,
			INFO,
			WARNING,
			ERROR,
			N_TYPE
		};
		Harl();
		~Harl();
		void	complain( std::string level );
		std::string	checkType(int type);
	private:
		typedef void (Harl::*funcPtr)(void);
		funcPtr		_ptr[N_TYPE];
		std::string	types[N_TYPE];
		int			color[N_TYPE];
		void		_debug( void );
		void		_info( void );
		void		_warning( void );
		void		_error( void );

};
# endif
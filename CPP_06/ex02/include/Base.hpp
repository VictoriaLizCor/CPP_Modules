/**
 * @file Base.hpp
 * @author lilizarr (lilizarr@student.42wolfsburg.de)
 * @brief 
 * @version 0.1
 * @date 2024-09-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <Utils.hpp>

# ifndef DEBUG
#  define DEBUG 0
# endif

class Base
{
	public:
		virtual ~Base();
};


#endif // BASE_HPP
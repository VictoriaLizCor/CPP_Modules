/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:14:42 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/23 17:45:35 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#  define FIXED_HPP
# include <iostream>
# include <sstream>
# include <string>
# include <cmath>
# include "stringUtils.hpp"

# ifndef DEBUG
#  define DEBUG 0
# endif

/**
 * @class Fixed
 * @brief This class represents a fixed point number.
 */
class Fixed
{
	private:
		int					_number;
		static const int	_fractionalBits;
	public:
		// Constructors && destructors
		Fixed(void);
		Fixed(int const& number);
		Fixed(float const& number);
		Fixed&	operator=(Fixed const & rhs);
		Fixed(Fixed const& source);
		~Fixed(void);
		// Member functions
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		// giving access to ostream to private class members
		friend std::ostream& operator << (std::ostream & os, Fixed const& source);
};

#endif
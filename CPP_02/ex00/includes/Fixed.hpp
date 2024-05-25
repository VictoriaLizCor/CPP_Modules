/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:14:42 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/25 11:20:27 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#  define FIXED_HPP
# include <iostream>
# include <sstream>
# include <string>
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
		int					_intValue;
		static const int	_bits;
	public:
		Fixed(void);
		~Fixed(void);
		Fixed& operator=(Fixed const & rhs);
		Fixed(Fixed const& source);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
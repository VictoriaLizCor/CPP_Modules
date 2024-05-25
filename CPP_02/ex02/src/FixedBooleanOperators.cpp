#include "Fixed.hpp"

/**
 * @brief Overloads the '>' operator for the Fixed class.
 * @param rhs The Fixed object to compare with.
 * @return True if the current object is greater than rhs, false otherwise.
 */
bool Fixed::operator>(Fixed const& rhs) const
{
	return (_intValue > rhs._intValue);
}

/**
 * @brief Overloads the '<' operator for the Fixed class.
 * @param rhs The Fixed object to compare with.
 * @return True if the current object is less than rhs, false otherwise.
 */
bool Fixed::operator<(Fixed const& rhs) const
{
	return (_intValue < rhs._intValue);
}

/**
 * @brief Overloads the '>=' operator for the Fixed class.
 * @param rhs The Fixed object to compare with.
 * @return True if the current object is greater than or equal to rhs, false otherwise.
 */
bool Fixed::operator>=(Fixed const& rhs) const
{
	return (_intValue >= rhs._intValue);
}

/**
 * @brief Overloads the '<=' operator for the Fixed class.
 * @param rhs The Fixed object to compare with.
 * @return True if the current object is less than or equal to rhs, false otherwise.
 */
bool Fixed::operator<=(Fixed const& rhs) const
{
	return (_intValue <= rhs._intValue);
}

/**
 * @brief Overloads the '==' operator for the Fixed class.
 * @param rhs The Fixed object to compare with.
 * @return True if the current object is equal to rhs, false otherwise.
 */
bool Fixed::operator==(Fixed const& rhs) const
{
	return (_intValue == rhs._intValue);
}

/**
 * @brief Overloads the '!=' operator for the Fixed class.
 * @param rhs The Fixed object to compare with.
 * @return True if the current object is not equal to rhs, false otherwise.
 */
bool Fixed::operator!=(Fixed const& rhs) const
{
	return (_intValue != rhs._intValue);
}

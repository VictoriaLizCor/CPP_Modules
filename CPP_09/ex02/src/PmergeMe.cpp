#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe& PmergeMe::operator=(PmergeMe const& rhs)
{
	(void)rhs;
	return *this;
}

PmergeMe::PmergeMe(PmergeMe const& rhs)
{
	(void)rhs;
}

PmergeMe::~PmergeMe(void)
{
}

std::ostream& operator << (std::ostream& os, PmergeMe& rhs)
{
	(void)rhs;
	return (os);
}

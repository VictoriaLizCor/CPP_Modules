#include <iostream>
#include "PmergeMe.hpp"
#include "Utils.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <sys/time.h>


static float strToFloat(std::string const& strValue)
{
	size_t pos = strValue.find_first_not_of("0123456789", 0);
	if (pos != std::string::npos)
	{
		throw std::invalid_argument(error("Invalid Value input: " + strValue, 0));
		exit(EXIT_FAILURE);
	}
	char* end;
	float value = std::strtof(strValue.c_str(), &end);

	if (*end != '\0' && ((*end != 'f' && *end != 'F') || *(end + 1) != '\0'))
		throw std::invalid_argument(error("Invalid Value input: " + strValue, 0));
	if (value < 0)
		throw std::invalid_argument(error("Invalid Value input: " + strValue, 0));
	return (value);
}

// Function to parse command line arguments into a vector of integers
std::vector<int> parseArguments(int argc, char* argv[])
{
	std::vector<int> numbers;
	for (int i = 1; i < argc; ++i)
	{
		int num;
		num = static_cast<int>(strToFloat(argv[i]));

		numbers.push_back(num);
	}
	std::cout << "Size: " << numbers.size() << std::endl;
	return numbers;
}

// Merge function for merging two sorted sequences (vector)
std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right)
{
	std::vector<int> result;
	std::vector<int>::const_iterator itLeft = left.begin();
	std::vector<int>::const_iterator itRight = right.begin();

	while (itLeft != left.end() && itRight != right.end())
	{
		if (*itLeft < *itRight)
		{
			result.push_back(*itLeft);
			++itLeft;
		} else {
			result.push_back(*itRight);
			++itRight;
		}
	}

	while (itLeft != left.end())
	{
		result.push_back(*itLeft);
		++itLeft;
	}

	while (itRight != right.end())
	{
		result.push_back(*itRight);
		++itRight;
	}

	return result;
}

// Merge function for merging two sorted sequences (deque)
std::deque<int> merge(const std::deque<int>& left, const std::deque<int>& right)
{
	std::deque<int> result;
	std::deque<int>::const_iterator itLeft = left.begin();
	std::deque<int>::const_iterator itRight = right.begin();

	while (itLeft != left.end() && itRight != right.end())
	{
		if (*itLeft < *itRight)
		{
			result.push_back(*itLeft);
			++itLeft;
		} else {
			result.push_back(*itRight);
			++itRight;
		}
	}

	while (itLeft != left.end())
	{
		result.push_back(*itLeft);
		++itLeft;
	}

	while (itRight != right.end())
	{
		result.push_back(*itRight);
		++itRight;
	}

	return result;
}

// Merge-Insertion Sort (Ford-Johnson Algorithm) for std::vector
void mergeInsertionSortVector(std::vector<int>& vec)
{
	if (vec.size() <= 1) return;

	std::vector<std::vector<int> > pairs;
	for (size_t i = 0; i < vec.size(); i += 2)
	{
		if (i + 1 < vec.size())
		{
			if (vec[i] < vec[i + 1])
			{
				std::vector<int> pair;
				pair.push_back(vec[i]);
				pair.push_back(vec[i + 1]);
				pairs.push_back(pair);
			} else {
				std::vector<int> pair;
				pair.push_back(vec[i + 1]);
				pair.push_back(vec[i]);
				pairs.push_back(pair);
			}
		} else {
			std::vector<int> pair;
			pair.push_back(vec[i]);
			pairs.push_back(pair);
		}
	}

	while (pairs.size() > 1)
	{
		std::vector<std::vector<int> > newPairs;
		for (size_t i = 0; i < pairs.size(); i += 2)
		{
			if (i + 1 < pairs.size())
			{
				newPairs.push_back(merge(pairs[i], pairs[i + 1]));
			} else {
				newPairs.push_back(pairs[i]);
			}
		}
		pairs = newPairs;
	}

	vec = pairs[0];
}

// Merge-Insertion Sort (Ford-Johnson Algorithm) for std::deque
void mergeInsertionSortDeque(std::deque<int>& deq)
{
	if (deq.size() <= 1) return;

	std::deque<std::deque<int> > pairs;
	for (size_t i = 0; i < deq.size(); i += 2)
	{
		if (i + 1 < deq.size())
		{
			if (deq[i] < deq[i + 1])
			{
				std::deque<int> pair;
				pair.push_back(deq[i]);
				pair.push_back(deq[i + 1]);
				pairs.push_back(pair);
			} else {
				std::deque<int> pair;
				pair.push_back(deq[i + 1]);
				pair.push_back(deq[i]);
				pairs.push_back(pair);
			}
		} else {
			std::deque<int> pair;
			pair.push_back(deq[i]);
			pairs.push_back(pair);
		}
	}

	while (pairs.size() > 1)
	{
		std::deque<std::deque<int> > newPairs;
		for (size_t i = 0; i < pairs.size(); i += 2)
		{
			if (i + 1 < pairs.size())
			{
				newPairs.push_back(merge(pairs[i], pairs[i + 1]));
			} else {
				newPairs.push_back(pairs[i]);
			}
		}
		pairs = newPairs;
	}

	deq = pairs[0];
}

double calculateExecutionTime( struct timeval start, struct timeval finish )
{
	double startTime = static_cast<double>(start.tv_sec) * 1e+6 + start.tv_usec;
	double finishTime = static_cast<double>(finish.tv_sec) * 1e+6 + finish.tv_usec;
	return (finishTime - startTime);
}


int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cerr << "Error *" << std::endl;
		return EXIT_FAILURE;
	}

	// Parse arguments
	std::vector<int> numbers = parseArguments(argc, argv);

	// Display unsorted sequence
	std::cout << "Before: ";
	for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	nl(1);
	{
		struct timeval		start, finish;
		std::vector<int>	vec(numbers);
		std::deque<int>		deq(numbers.begin(), numbers.end());
		double				vecExecutionTime;
		double				deqExecutionTime;

		gettimeofday( &start, NULL );
		mergeInsertionSortVector(vec);
		gettimeofday( &finish, NULL );
		vecExecutionTime = calculateExecutionTime( start, finish );

		gettimeofday( &start, NULL );
		mergeInsertionSortDeque(deq);
		gettimeofday( &finish, NULL );
		deqExecutionTime = calculateExecutionTime( start, finish );
		// Display sorted sequence
		std::cout << "After: ";
		std::for_each(vec.begin(), vec.end(), PrintFunctor< std::vector<int> >(std::cout, vec, vec.size()));
		std::cout << std::endl;
		/* std::cout << "      \t"; */
		/* printNumbers( deq ); */
		std::cout << "Time to process a range of " << argc - 1
				<< " elements with std::vector : "   << vecExecutionTime << " μs\n";
		std::cout << "Time to process a range of " << argc - 1
				<< " elements with std::deque  : "  << deqExecutionTime << " μs\n";

	}
	nl(1);
	{
		struct timeval start, finish;
		std::vector<int> vec(numbers);
		std::deque<int> deq(numbers.begin(), numbers.end());
		double         vecExecutionTime;
		double         deqExecutionTime;

		gettimeofday( &start, NULL );
		mergeInsertionSortVector(vec);
		gettimeofday( &finish, NULL );
		vecExecutionTime = calculateExecutionTime( start, finish );

		gettimeofday( &start, NULL );
		mergeInsertionSortDeque(deq);
		gettimeofday( &finish, NULL );
		deqExecutionTime = calculateExecutionTime( start, finish );

		/* std::cout << "      \t"; */
		/* printNumbers( deq ); */
		std::cout << "Time to process a range of " << argc - 1
				<< " elements with std::vector : " << vecExecutionTime << " μs\n";
		std::cout << "Time to process a range of " << argc - 1
				<< " elements with std::deque  : " << deqExecutionTime << " μs\n";

	}
	{
		// Copy numbers to different containers
		std::vector<int> vec(numbers);
		std::deque<int> deq(numbers.begin(), numbers.end());

		// Measure time for std::vector
		std::clock_t startVec = std::clock();
		mergeInsertionSortVector(vec);
		std::clock_t endVec = std::clock();
		double durationVec = 1000000.0 * (endVec - startVec) / CLOCKS_PER_SEC;

		// Measure time for std::deque
		std::clock_t startDeque = std::clock();
		mergeInsertionSortDeque(deq);
		std::clock_t endDeque = std::clock();
		double durationDeque = 1000000.0 * (endDeque - startDeque) / CLOCKS_PER_SEC;



		std::cout << "*Time to process a range of " << argc - 1
				<< " elements with std::vector : "<< durationVec << " μs\n";
		std::cout << "Time to process a range of " << argc - 1
				<< " elements with std::deque  : "<< durationDeque << " μs\n";
	}
	{
		// Copy numbers to different containers
		std::vector<int> vec(numbers);
		std::deque<int> deq(numbers.begin(), numbers.end());

		// Measure time for std::vector
		std::clock_t startVec = std::clock();
		mergeInsertionSortVector(vec);
		std::clock_t endVec = std::clock();
		double durationVec = 1000000.0 * (endVec - startVec) / CLOCKS_PER_SEC;

		// Measure time for std::deque
		std::clock_t startDeque = std::clock();
		mergeInsertionSortDeque(deq);
		std::clock_t endDeque = std::clock();
		double durationDeque = 1000000.0 * (endDeque - startDeque) / CLOCKS_PER_SEC;

		std::cout << std::endl;

		std::cout << "Time to process a range of " << argc - 1
				<< " elements with std::vector : "<< durationVec << " μs\n";
		std::cout << "Time to process a range of " << argc - 1
				<< " elements with std::deque  : "<< durationDeque << " μs\n";
	}
	return 0;
}

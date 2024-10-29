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

double calculateExecutionTime( struct timeval start, struct timeval finish )
{
	double startTime = static_cast<double>(start.tv_sec) * 1e+6 + static_cast<double>(start.tv_usec);
	double finishTime = static_cast<double>(finish.tv_sec) * 1e+6 + static_cast<double>(finish.tv_usec);
	return (finishTime - startTime);
}


int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cerr << error("wrong input", 0) << std::endl;
		return (1);
	}

	// Parse arguments
	std::vector<int> numbers = parseArguments(argc, argv);
	std::vector<int> sorted(numbers);
	std::sort(sorted.begin(), sorted.end());
	// Display unsorted sequence
	std::cout << "Before: ";
	std::for_each(numbers.begin(), numbers.end(), PrintFunctor< std::vector<int> >(std::cout, numbers, numbers.size()));
	std::cout << std::endl;
	nl(1);
	{
		struct timeval		start, finish;
		double				vecExecutionTime;
		double				deqExecutionTime;
		#if (DEBUG == 0)
		PmergeMeVector	vec(numbers);
		PmergeMeDeque		deq(numbers.begin(), numbers.end());
		#else
		PmergeMe< std::vector<int> > vec(numbers);
		PmergeMe< std::deque<int> > deq(numbers);
		#endif
		gettimeofday( &start, NULL );
		vec.sort();
		gettimeofday( &finish, NULL );
		vecExecutionTime = calculateExecutionTime( start, finish );

		gettimeofday( &start, NULL );
		deq.sort();
		gettimeofday( &finish, NULL );
		deqExecutionTime = calculateExecutionTime( start, finish );
		// Display sorted sequence
		std::cout << "After: ";
		std::for_each(vec.sorted.begin(), vec.sorted.end(), PrintFunctor< std::vector<int> >(std::cout, vec.sorted, vec.sorted.size()));
		std::cout << std::endl;
		std::cout << "Time to process a range of " << argc - 1
				<< " elements with std::vector : "   << vecExecutionTime << " μs\n";
		std::cout << "Time to process a range of " << argc - 1
				<< " elements with std::deque  : "  << deqExecutionTime << " μs\n";
	}
// 	nl(1);
// 	{
// 		struct timeval start, finish;
// 		std::vector<int> vec(numbers);
// 		std::deque<int> deq(numbers.begin(), numbers.end());
// 		double         vecExecutionTime;
// 		double         deqExecutionTime;

// 		gettimeofday( &start, NULL );
// 		mergeInsertionSortVector(vec);
// 		gettimeofday( &finish, NULL );
// 		vecExecutionTime = calculateExecutionTime( start, finish );

// 		gettimeofday( &start, NULL );
// 		mergeInsertionSortDeque(deq);
// 		gettimeofday( &finish, NULL );
// 		deqExecutionTime = calculateExecutionTime( start, finish );

// 		/* std::cout << "      \t"; */
// 		/* printNumbers( deq ); */
// 		std::cout << "Time to process a range of " << argc - 1
// 				<< " elements with std::vector : " << vecExecutionTime << " μs\n";
// 		std::cout << "Time to process a range of " << argc - 1
// 				<< " elements with std::deque  : " << deqExecutionTime << " μs\n";

// 	}
// 	{
// 		// Copy numbers to different containers
// 		std::vector<int> vec(numbers);
// 		std::deque<int> deq(numbers.begin(), numbers.end());

// 		// Measure time for std::vector
// 		std::clock_t startVec = std::clock();
// 		mergeInsertionSortVector(vec);
// 		std::clock_t endVec = std::clock();
// 		double durationVec = 1000000.0 * (endVec - startVec) / CLOCKS_PER_SEC;

// 		// Measure time for std::deque
// 		std::clock_t startDeque = std::clock();
// 		mergeInsertionSortDeque(deq);
// 		std::clock_t endDeque = std::clock();
// 		double durationDeque = 1000000.0 * (endDeque - startDeque) / CLOCKS_PER_SEC;



// 		std::cout << "*Time to process a range of " << argc - 1
// 				<< " elements with std::vector : "<< durationVec << " μs\n";
// 		std::cout << "Time to process a range of " << argc - 1
// 				<< " elements with std::deque  : "<< durationDeque << " μs\n";
// 	}
// 	{
// 		// Copy numbers to different containers
// 		std::vector<int> vec(numbers);
// 		std::deque<int> deq(numbers.begin(), numbers.end());

// 		// Measure time for std::vector
// 		std::clock_t startVec = std::clock();
// 		mergeInsertionSortVector(vec);
// 		std::clock_t endVec = std::clock();
// 		double durationVec = 1000000.0 * (endVec - startVec) / CLOCKS_PER_SEC;

// 		// Measure time for std::deque
// 		std::clock_t startDeque = std::clock();
// 		mergeInsertionSortDeque(deq);
// 		std::clock_t endDeque = std::clock();
// 		double durationDeque = 1000000.0 * (endDeque - startDeque) / CLOCKS_PER_SEC;

// 		std::cout << std::endl;

// 		std::cout << "Time to process a range of " << argc - 1
// 				<< " elements with std::vector : "<< durationVec << " μs\n";
// 		std::cout << "Time to process a range of " << argc - 1
// 				<< " elements with std::deque  : "<< durationDeque << " μs\n";
// 	}

	return 0;
}

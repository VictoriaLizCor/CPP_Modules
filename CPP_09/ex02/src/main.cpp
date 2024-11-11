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
	size_t start = 0;
		
	if (strValue[0] == '+')
		start = 1;
	size_t pos = strValue.find_first_not_of("0123456789", start);
	if (std::count(strValue.begin(), strValue.end(), '.') > 1 || \
		pos != std::string::npos)
		throw std::invalid_argument(error("Invalid Value input: " + strValue, 0));
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
	if (DEBUG)
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
	// Parse arguments
	try
	{
		if (argc < 2)
		{
			throw std::invalid_argument(error("Wrong input", 0));
		}

		std::vector<int> numbers = parseArguments(argc, argv);
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
			PmergeMeDeque	deq(numbers.begin(), numbers.end());
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
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}

/**
 * @NOTES:
 * The performance difference between `std::vector` and `std::deque`
   in your example can be attributed to several factors, including
   memory allocation patterns, cache locality, and the specific
   implementation details of the sorting algorithm. Here are some
   possible reasons why `std::deque` might be faster than
   `std::vector` in this particular case:

1. **Memory Allocation**:
   - `std::vector` allocates a single contiguous block of memory,
     which can sometimes lead to higher allocation and deallocation
     costs, especially if the vector needs to resize.
   - `std::deque` allocates memory in chunks, which can sometimes be
     more efficient for certain operations, as it avoids the need to
     allocate a large contiguous block.

2. **Cache Locality**:
   - `std::vector` generally has better cache locality because its
     elements are stored contiguously in memory. However, this can
     also mean that any cache misses can be more costly.
   - `std::deque` stores elements in separate chunks, which can
     sometimes lead to better performance if the chunks fit well into
     the cache, reducing the impact of cache misses.

3. **Implementation Details**:
   - The specific implementation of the sorting algorithm and how it
     interacts with the underlying data structure can also affect
     performance. For example, if the sorting algorithm involves a lot
     of insertions and deletions, `std::deque` might perform better
     due to its chunked memory allocation.

4. **Small Data Size**:
   - For small data sizes (like the 14 elements in your example), the
     overhead of managing the contiguous memory in `std::vector` might
     outweigh its benefits. The chunked allocation of `std::deque`
     might be more efficient in this case.

5. **Compiler Optimizations**:
   - The compiler might optimize the code differently for
     `std::vector` and `std::deque`, leading to performance
     differences.

To further investigate the performance difference, you can try the
following:

- **Profile the Code**: Use a profiler to analyze where the time is
  being spent in both cases. This can help identify if there are
  specific operations that are slower for `std::vector`.
- **Increase Data Size**: Test with larger data sizes to see if the
  performance difference persists. Sometimes, the performance
  characteristics change with the size of the data.
- **Check Compiler Flags**: Ensure that the compiler optimization
  flags are the same for both cases. Different optimization levels can
  affect performance.

Here is an example of how you might profile the code using `gprof`:

1. Compile the code with profiling enabled:
   ```sh
   g++ -pg -o PmergeMe main.cpp
   ```

2. Run the program:
   ```sh
   ./PmergeMe 2069 1021 4984 4009 3736 3538 1421 4888 2985 753 144 882 2720 1119
   ```

3. Generate the profiling report:
   ```sh
   gprof PmergeMe gmon.out > profile.txt
   ```

4. Analyze the `profile.txt` file to see where the time is being
   spent.

By profiling the code, you can gain insights into the performance
characteristics and identify any bottlenecks that might explain the
observed behavior.
 * 
 */
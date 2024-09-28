#include "Utils.hpp"
#include "easyfind.hpp"


std::string getType(std::type_info const& type)
{
	std::string typeName = type.name();

	if (typeName.find("vector") != std::string::npos)
		return (getColorStr(FGREEN, "Vector"));
	if (typeName.find("deque") != std::string::npos)
		return (getColorStr(FBLUE, "Deque"));
	if (typeName.find("list") != std::string::npos)
		return (getColorStr(FYELLOW, "List"));
	return (typeName);
}

int main(void)
{
	{
		try
		{
			std::vector<int> vectorCon;
			
			for (int i = 0; i < 5; ++i)
				vectorCon.push_back(i);

			processContainer<int>(vectorCon, 3, 0);
			vectorCon[1] = 3;
			processContainer<int>(vectorCon, 3, 0);
			processContainer<int>(vectorCon, -1, 0);
		}
		catch (const std::exception& e)
		{
			std::cerr << std::endl << e.what() << std::endl;
		}
	}
	nl(1);
	printTitle("runTest()", 70, '*');
	runTest<int>();
	runTest<float>();
	return (0);
}

/**
 * @NOTES:
 * Standard containers in C++ (like `std::vector`, `std::list`, and
   `std::deque`) have different behaviors and use cases. Here's a
   brief overview of each:

1. **std::vector**:
   - **Dynamic array**: Provides dynamic array functionality.
   - **Contiguous memory**: Elements are stored in contiguous memory
     locations.
   - **Fast access**: Provides fast random access to elements.
   - **Insertion/Deletion**: Insertion and deletion at the end are
     fast (amortized constant time), but can be slow (linear time) at
     other positions.

2. **std::list**:
   - **Doubly linked list**: Provides a doubly linked list.
   - **Non-contiguous memory**: Elements are not stored in contiguous
     memory locations.
   - **Fast insertion/deletion**: Provides fast insertion and deletion
     at any position (constant time).
   - **Slow access**: Random access is slow (linear time).

3. **std::deque**:
   - **Double-ended queue**: Provides a double-ended queue.
   - **Non-contiguous memory**: Elements are stored in chunks of
     contiguous memory.
   - **Fast access**: Provides fast random access to elements.
   - **Fast insertion/deletion**: Provides fast insertion and deletion
     at both ends (constant time).
 * 
 */
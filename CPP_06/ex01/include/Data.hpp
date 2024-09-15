#ifndef DATA_HPP
#define DATA_HPP
#include "Utils.hpp"

struct Data
{
	char c;
	int i;
	float f;
	double d;

	void setData(char newC, int newI, float newF, double newD);
	void print(std::string type) const;
};


#endif // DATA_HPP

/**
 * @NOTES:
 * In C++, it is generally considered good practice to encapsulate related functionality within a class or struct. This includes defining member functions inside the class or struct. This approach follows the principles of object-oriented programming, such as encapsulation and data hiding.

### Benefits of Defining Functions Inside a Struct or Class

1. **Encapsulation**: Encapsulating data and functions that operate on that data within a single unit (class or struct) helps to keep the code organized and maintainable.
2. **Data Hiding**: Member functions can access private or protected data members, allowing you to control how the data is accessed and modified.
3. **Code Reusability**: Functions defined within a class or struct can be reused across different parts of the program.
4. **Readability**: Grouping related data and functions together makes the code easier to understand.


### Explanation

1. **Member Functions**: The [`Data`] struct now includes two member functions: `print` and `setData`.
   - `print`: Prints the values of the data members.
   - `setData`: Sets the values of the data members.
2. **Encapsulation**: The member functions operate on the data members of the struct, encapsulating the functionality within the struct.
3. **Usage**: In the `main` function, an instance of [`Data`] is created, and the member functions are used to set and print the data.

### Conclusion

Defining functions inside a struct or class is a good practice in C++ as it promotes encapsulation, data hiding, and code organization. It helps to keep related data and functionality together, making the code more maintainable and readable. 
 * 
 */
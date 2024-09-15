#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <stdint.h>
# include <Utils.hpp>
# include "Data.hpp"

# ifndef DEBUG
#  define DEBUG 0
# endif

class Serializer
{
	private:
		Serializer();
		Serializer& operator=(Serializer const& rhs);
		Serializer(Serializer const& rhs);
		virtual ~Serializer();
		union DataUnion
		{
			Data* ptr;
			uintptr_t raw;
		};

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

// std::ostream& operator << (std::ostream& os, Serializer& rhs);

#endif // SERIALIZER_HPP

/**
	NOTES: 
 * Recasting, specifically using `reinterpret_cast` in C++, is a type
 * of casting that allows you to convert any pointer type to any other
 * pointer type, even if the types are unrelated. It can also be used
 * to convert between pointer types and integral types.
 *
 * ### Key Points:
 * 1. **Pointer to Pointer Conversion**: You can convert a pointer of
 *    one type to a pointer of another type.
 * 2. **Pointer to Integer Conversion**: You can convert a pointer to
 *    an integer type (e.g., `uintptr_t`) and vice versa.
 * 3. **No Type Safety**: `reinterpret_cast` does not perform any type
 *    checking, so it can lead to undefined behavior if used
 *    incorrectly.
 * 4. **Low-Level Operations**: It is often used for low-level
 *    operations, such as interfacing with hardware or performing
 *    certain optimizations.
 *
 * ### Usage:
 * - **Serialization/Deserialization**: As shown in the example,
 *   converting pointers to integers and back.
 * - **Interfacing with C APIs**: When working with C libraries that
 *   use `void*` for generic data pointers.
 * - **Bitwise Operations**: When you need to manipulate the bits of a
 *   pointer or an integer directly.
 *
 * ### Caution:
 * - **Undefined Behavior**: Misuse of `reinterpret_cast` can lead to
 *   undefined behavior, crashes, or security vulnerabilities.
 * - **Portability Issues**: Code using `reinterpret_cast` may not be
 *   portable across different platforms or compilers.
 *
 * ### Summary:
 * `reinterpret_cast` is a powerful but dangerous tool in C++ that
 * should be used with caution. It allows for low-level type
 * conversions that bypass the type system, providing flexibility at
 * the cost of safety.
 * 
 * -------------------------------------------------
### Summary UNIOn

A union is a low-level feature in C++ that allows you to store different types of data in the same memory location. It is particularly useful for tasks like type-punning and efficient memory usage, making it a valuable feature for low-level programming and optimization tasks. It is not a container or a booster but a fundamental part of the C++ language.
A `union` in C++ is neither a container like `std::vector` nor a booster like the Boost libraries. Instead, it is a special data structure that allows you to store different data types in the same memory location. Here are some key points to understand about unions:

### Key Characteristics of Unions

1. **Memory Sharing**: All members of a union share the same memory location. This means that the size of the union is determined by the size of its largest member.

2. **Type-Punning**: Unions are often used for type-punning, which is a way to interpret the same memory location as different data types. This can be useful for low-level programming tasks, such as interpreting raw data or performing certain optimizations.

3. **Efficient Memory Usage**: Since all members share the same memory, unions can be more memory-efficient than structures (`structs`) when you need to store different types of data but never simultaneously.


### Explanation
- **Without Union**: You need to use `reinterpret_cast` to convert between `Data*` and `uintptr_t`.
- **With Union**: The union handles the conversion internally, so you don't need to use `reinterpret_cast`.

Using a union simplifies the code and makes it more readable by eliminating the need for explicit type casting. It also ensures that the conversion is safe and well-defined.
*/
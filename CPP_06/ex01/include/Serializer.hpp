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
 * ### Example:
 * In the context of the `Serializer` class:
 *
 * ```cpp
 * class Serializer {
 * public:
 *     static uintptr_t serialize(Data* ptr) {
 *         return reinterpret_cast<uintptr_t>(ptr);
 *     }
 *
 *     static Data* deserialize(uintptr_t raw) {
 *         return reinterpret_cast<Data*>(raw);
 *     }
 * };
 * ```
 *
 * - **Serialization**: `reinterpret_cast<uintptr_t>(ptr)` converts a
 *   `Data*` pointer to an `uintptr_t` integer.
 * - **Deserialization**: `reinterpret_cast<Data*>(raw)` converts an
 *   `uintptr_t` integer back to a `Data*` pointer.
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
*/
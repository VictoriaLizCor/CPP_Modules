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
		// Serializer& operator=(Serializer const& rhs);
		Serializer(Serializer const& rhs);
		virtual ~Serializer();

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

// std::ostream& operator << (std::ostream& os, Serializer& rhs);

#endif // SERIALIZER_HPP
#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::~Serializer(void)
{
}

/**
 * @brief Convert a Data pointer into unsigned int
 */
uintptr_t Serializer::serialize(Data* data)
{
	if (DEBUG)
	{
		DataUnion du;

		std::cout << getColorStr(FLCYAN, "Union serialize\n");
		du.ptr = data;
		std::cout << "serialize:" << du.raw << std::endl;
		return (du.raw);
	}
	std::cout << "serialize:" << reinterpret_cast<uintptr_t>(data) << std::endl;
	return (reinterpret_cast<uintptr_t>(data));
}

/**
 * @brief Convert unsigned int into Data pointer
 */
Data* Serializer::deserialize(uintptr_t raw)
{
	if (DEBUG)
	{
		DataUnion du;

		std::cout << getColorStr(FLCYAN, "Union deserialize\n");
		du.raw = raw;
		std::cout << "serialize:" << du.raw << std::endl;
		return (du.ptr);
	}
	std::cout << "serialize:" << raw << std::endl;
	return (reinterpret_cast<Data*>(raw));
}

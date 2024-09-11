#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::~Serializer(void)
{
}

/**
 * @brief       Convert a Data pointer into unsigned int
 */
uintptr_t Serializer::serialize( Data* ptr )
{
  return reinterpret_cast<uintptr_t>( ptr );
}

/**
 * @brief       Convert unsigned int into Data pointer
 */
Data* Serializer::deserialize( uintptr_t raw )
{
  return reinterpret_cast<Data*>( raw );
}

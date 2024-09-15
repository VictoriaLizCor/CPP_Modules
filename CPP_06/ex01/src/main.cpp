#include "Data.hpp"
#include "Serializer.hpp"
#include "Utils.hpp"
#include <iostream>

static void checkSerialization(Data* originalPtr, Data* deserializedPtr)
{
	if (originalPtr == deserializedPtr)
	{
		std::cout << getColorStr(FGREEN,"Serialization and deserialization successful!") << std::endl;
		originalPtr->print("Original");
		deserializedPtr->print("Deserialized");
	} else {
		std::cout << error("serialization failed", 0) << std::endl;
		deserializedPtr->print("Deserialized");
	}
	printTitle("", 60, '-');
}

static void testFailure(Data* originalPtr)
{
	uintptr_t serialized = Serializer::serialize(originalPtr);

	uintptr_t corruptedSerialized = serialized + 1;

	Data* corruptedSerializedPtr = Serializer::deserialize(corruptedSerialized);

	checkSerialization(originalPtr, corruptedSerializedPtr);
}

int main()
{
	Data originalData = {'a', 42, 3.14f, 2.718};
	Data* originalPtr = &originalData;

	uintptr_t serialized = Serializer::serialize(originalPtr);

	Data* deserializedPtr = Serializer::deserialize(serialized);

	checkSerialization(&originalData, deserializedPtr);
	deserializedPtr->setData('b', 217473847, 3.1416f, 1.4142);
	deserializedPtr->print("New deserilazed Data");
	std::cout << std::endl;
	testFailure(&originalData);
	return (0);
}
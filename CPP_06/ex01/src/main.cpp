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
	}
	printTitle("", 20, '-');
}

static void testFailure()
{
	Data originalData = {'a', 42, 3.14f, 2.718};
	Data* originalPtr = &originalData;

	uintptr_t serialized = Serializer::serialize(originalPtr);

	uintptr_t corruptedSerialized = serialized + 1;

	Data* deserializedPtr = Serializer::deserialize(corruptedSerialized);

	checkSerialization(&originalData, deserializedPtr);
	deserializedPtr->setData('b', 217473847, 3.1416f, 1.4142);
	deserializedPtr->print("New deserilazed Data");
}

int main()
{
	Data originalData = {'a', 42, 3.14f, 2.718};
	Data* originalPtr = &originalData;

	uintptr_t serialized = Serializer::serialize(originalPtr);

	Data* deserializedPtr = Serializer::deserialize(serialized);

	checkSerialization(&originalData, deserializedPtr);

	testFailure();
	return (0);
}
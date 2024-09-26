#include "Utils.hpp"
#include "easyfind.hpp"


std::string getType(std::type_info const& type)
{
	if (type == typeid(int))
		return (getColorStr(FGREEN, "int"));
	if (type == typeid(float))
		return (getColorStr(FBLUE, "float"));
	if (type == typeid(double))
		return (getColorStr(FCYAN, "double"));
	if (type == typeid(char))
		return (getColorStr(FMAGENTA, "char"));
	if (type == typeid(std::string))
		return (getColorStr(FYELLOW, "string"));
	return (type.name());
}

int main(void)
{
	runTest<int>();
	return (0);
}
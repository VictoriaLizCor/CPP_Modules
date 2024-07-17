#include "MateriaSource.hpp"
#include "AMateria.hpp"

int MateriaSource::_instanceCount = 0;

MateriaSource::MateriaSource():
_instanceId(++_instanceCount),
_colorIdStr(std::string(C_FMT256B) + "50" + "m")
{
	for (size_t i = 0; i < getInvetorySize(); ++i)
		_inventory[i] = NULL;
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " was Created\n");
}

MateriaSource&::MateriaSource::operator=(MateriaSource const& rhs)
{
	if (this != &rhs)
	{
		for (size_t i = 0; i < getInvetorySize(); ++i)
		{
			if (_inventory[i] != NULL)
				delete _inventory[i];
			if (rhs._inventory[i])
				_inventory[i] = rhs._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	if (DEBUG)
		std::cout << *this << getColorStr(FGRAY, " Copy was Created\n");
	return (*this);
}

MateriaSource::MateriaSource(MateriaSource const&rhs):
_instanceId(++_instanceCount),
_colorIdStr(std::string(C_FMT256B) + "50" + "m")
{
	for (size_t i = 0; i < getInvetorySize(); ++i)
		_inventory[i] = NULL;
	*this = rhs;
}


MateriaSource::~MateriaSource(void)
{
	size_t i = getInvetorySize();
	while (--i < getInvetorySize())
	{
		if (_inventory[i])
			delete _inventory[i];
	}
	if (DEBUG)
	{
		std::cout << *this << getColorStr(FGRAY, " was Destroyed\n");
	}
	_instanceCount--;
}

void MateriaSource::learnMateria(AMateria* aMateria)
{
	for (size_t i = 0; i < getInvetorySize(); ++i)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = aMateria;
			if (DEBUG)
			{
				std::cout << *this << " learns in slot ["
				<< i + 1 << "] " << *_inventory[i] << "\n";
				getInventory(_inventorySize);
			}
			return ;
		}
	}
	std::cout << *this << "\t" << getColorFmt(FYELLOW)
	<< "Inventory full. Materia "<< *aMateria
	<< getColorFmt(FYELLOW) <<" can't be learn.\n"
	<< getColorFmt(FRED) << "Deleting " << *aMateria;
	if (DEBUG)
		std::cout << " (" << aMateria << ")";
	std::cout<< "\n";
	delete aMateria;
}

AMateria* MateriaSource::createMateria(const std::string &type)
{
	for (size_t i = 0; i < getInvetorySize(); ++i)
	{
		if (_inventory[i] != NULL && _inventory[i]->getType() == type)
			return (_inventory[i]->clone());

	}
	if (DEBUG)
	{
		std::cout << *this
		<< getColorStr(FYELLOW, " can not create materia '")
		<< getColorStr(FLWHITE, type )
		<< getColorStr(FYELLOW, "', not found in inventory") << "\n";
	}
	return (NULL);
}


size_t MateriaSource::getInvetorySize(void){return (_inventorySize);}

void MateriaSource::getInventory(size_t idx) const
{
	std::cout << *this << " |";
	if (idx == getInvetorySize())
	{ 
		for (size_t i = 0; i < getInvetorySize(); ++i)
		{
			std::cout << "[" << (i + 1) << "] ";
			if (_inventory[i] != NULL)
				std::cout << _inventory[i]->getInfo();
			else
				std::cout << " NULL";
			std::cout << " |";
		}
		std::cout << "\n";
		if (DEBUG == 2)
		{
			std::cout << *this << " |";
			for (size_t i = 0; i < getInvetorySize(); ++i)
			{
				std::cout << "[" << (i + 1) << "] "
				<< _inventory[i];
				std::cout << " |";
			}
		}	
	}
	else if (idx < getInvetorySize())
	{
		if (_inventory[idx] != NULL)
			std::cout << _inventory[idx]->getInfo();
		else
			std::cout << "NULL";
	}

	std::cout << std::endl;
}

std::string MateriaSource::getInfo(void) const
{
	std::ostringstream os;

	os << _colorIdStr;
	if (DEBUG == 1)
		os <<  className(typeid(*this).name()) << _instanceId;
	else 
		os <<  className(typeid(*this).name());
	os << C_END;

	return (os.str());
}

std::ostream& operator << (std::ostream& os, MateriaSource const& rhs)
{
	os << rhs.getInfo();
	return (os);
}

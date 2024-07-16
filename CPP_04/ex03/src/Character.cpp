#include "Character.hpp"
#include "AMateria.hpp"

int Character::_instanceCount = 0;

Character::Character(std::string const &name) : _instanceId(++_instanceCount), _colorIdStr(getRandomColorFmt(1))
{
	if (name.empty())
		_name = "Anon";
	else
	{
		if (DEBUG == 0)
			_name = name;
		else
			_name = getColorStr(_colorIdStr, name);
	}
	for (size_t i = 0; i < getInvetorySize(); ++i)
		_inventory[i] = NULL;
	if (DEBUG)
	{
		std::cout << _colorIdStr << *this
		<< getColorStr(FGRAY, " was Created\n");
	}
}

Character & ::Character::operator=(Character const &rhs)
{
	if (this != &rhs)
	{
		if (_name.empty())
		{
			for (size_t i = 0; i < getInvetorySize(); ++i)
				_inventory[i] = NULL;
		}
		if (DEBUG)
			_name = rhs.getName() + "_copy";
		else
			_name = rhs._name;
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

Character::Character(Character const &rhs) : _instanceId(++_instanceCount), _colorIdStr(getRandomColorFmt(1))
{
	*this = rhs;
}

Character::~Character(void)
{
	size_t i = getInvetorySize();
	while (--i < getInvetorySize())
	{
		if (_inventory[i])
			delete _inventory[i];
	}
	if (DEBUG)
	{
		std::cout << _colorIdStr << *this
				  << getColorStr(FGRAY, " was Destroyed\n");
	}
	_instanceCount--;
}

std::string const &Character::getName(void) const { return (_name); }

void Character::equip(AMateria *m)
{
	if (DEBUG)
		std::cout << *this;
	for (size_t i = 0; i < getInvetorySize(); ++i)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			if (DEBUG)
			{
				std::cout << " equips inventory slot ["
						  << i + 1 << "] " << *_inventory[i] << "\n";
				getInventory(_inventorySize);
			}
			return;
		}
	}
	if (DEBUG)
	{
		std::cout << getColorFmt(FYELLOW)
				  << "\tInventory full. Materia " << *m
				  << getColorFmt(FYELLOW) << " can't be equiped.\n"
				  << "\tUse 'unequip' to have space.\n"
				  << getColorFmt(FRED) << "Deleting " << *m;
		std::cout << " (" << m << ")\n";
	}
	std::cout << "\n";
	delete m;
}

void Character::unequip(int idx)
{
	if (static_cast<size_t>(idx) < _inventorySize)
	{
		if (DEBUG)
			std::cout << *this << " unequips inventory slot [ "
					  << idx << "] " << _inventory[idx];
	}
	if (DEBUG)
		getInventory(_inventorySize);
}

void Character::use(int idx, ICharacter &target)
{
	if (DEBUG)
		std::cout << *this << " ";
	if (static_cast<size_t>(idx) < _inventorySize && _inventory[idx])
		_inventory[idx]->use(target);
	else
	{
		std::cout << getColorFmt(FYELLOW)
				  << "can't use Materia. Slot empty or out fo range" << C_END;
		if (DEBUG)
			std::cout << " " << idx << "/" << _inventorySize << std::flush;
		std::cout << std::endl;
	}
}

size_t Character::getInvetorySize(void) { return (_inventorySize); }

void Character::getInventory(size_t idx) const
{
	if (DEBUG == 0)
		return;
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

	std::cout << std::endl << std::flush;
}

std::string Character::getInfo(void) const
{
	std::ostringstream os;

	os << _colorIdStr;
	if (DEBUG == 2)
		os << className(typeid(*this).name())
		   << _instanceId << "::" << getName();
	else if (DEBUG == 1)
	{
		os << "Char" << _instanceId << "::" << getName();
	}
	else
		os << getName();
	os << C_END << std::flush;

	return (os.str());
}

std::ostream &operator<<(std::ostream &os, Character const &rhs)
{
	os << rhs.getInfo();
	return (os);
}

// #include "Character.hpp"
// #include "Ice.hpp"
// #include "Cure.hpp"
// #include "MateriaSource.hpp"
#include <iomanip>
#include <iostream>

static void printTitle(std::string title)
{
	const int size = 60;
	std::string toPrint = " " + title + " "; 
	
	int len = toPrint.size();
	int padding = (size - len) / 2;

	if (len % 2 != 0 && size % 2 == 0)
		padding++;

	std::cout << std::setfill('=') << std::setw(padding) << "";
	std::cout << toPrint;
	std::cout << std::setfill('=') << std::setw(size - len - padding)
	<< "" << std::endl;
}

// static void testSubject(void)
// {
// 	printTitle("SUBJECT");
// 	IMateriaSource* src = new MateriaSource();

// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());

// 	ICharacter*	me = new Character("me");
// 	AMateria*	tmp;

// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	tmp = src->createMateria("unknown");
// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);

// 	delete bob;
// 	delete me;
// 	delete src;
// }

// static void	testCharacter(void)
// {
// 	printTitle("CHARACTER");
// 	ICharacter	*c1 = new Character("Char1");
// 	ICharacter	*c2 = new Character("Char2");
// 	AMateria	*ice = new Ice();

// 	c1->equip(new Ice());
// 	c1->equip(ice);
// 	c1->equip(new Cure());
// 	c1->equip(new Ice());
// 	c1->equip(new Ice());
// 	c2->equip(new Cure());
// 	c2->equip(new Cure());
// 	c2->equip(new Cure());

// 	c1->printInventory();
// 	c2->printInventory();

// 	c1->use(0, *c2);
// 	c1->use(1, *c2);
// 	c1->use(3, *c2);
// 	c2->use(2, *c1);

// 	c1->unequip(1);
// 	c1->printInventory();
// 	c1->use(1, *c2);

// 	c1->equip(new Cure());
// 	c1->printInventory();
// 	c1->use(1, *c2);

// 	delete c1;
// 	delete c2;
// 	delete ice;
// }

// static void	testMateriaSource()
// {
// 	printTitle("MATERIA SOURCE");
// 	IMateriaSource	*matSource = new MateriaSource();
// 	ICharacter		*c1 = new Character("Char1");
// 	ICharacter		*c2 = new Character("Char2");
	
// 	matSource->learnMateria(new Ice());
// 	matSource->learnMateria(new Cure());
// 	matSource->learnMateria(new Cure());
// 	matSource->learnMateria(new Cure());
// 	matSource->learnMateria(new Cure());

// 	c1->printInventory();
// 	c1->equip(matSource->createMateria("ice"));
// 	c1->equip(matSource->createMateria("cure"));
// 	c1->equip(matSource->createMateria("cure"));
// 	c1->equip(matSource->createMateria("ice"));
// 	c1->printInventory();
// 	c1->equip(matSource->createMateria("cure"));
// 	c1->printInventory();

// 	c1->use(0, *c2);
// 	c1->use(2, *c2);

// 	delete matSource;
// 	delete c1;
// 	delete c2;
// }

int	main(void)
{
	printTitle("MATERIA SOURCE");
	printTitle("CHARACTER");
	// testSubject();
	// testCharacter();
	// testMateriaSource();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:22:17 by lilizarr          #+#    #+#             */
/*   Updated: 2024/05/06 16:02:50 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void compareAddresses(void* addr1, void* addr2, const std::string& name)
{
	if (reinterpret_cast<long>(addr1) < reinterpret_cast<long>(addr2))
		std::cout << "***Zombie " << name << " instance created in Heap memory\n";
	else
		std::cout << "***Zombie " << name << " instance created in Stack memory\n";
}
int	main(void)
{
#if (DEBUG == 1)
	std::srand(time(0));
#endif
	// Zombie z1;
	// Zombie z3("Robb");
	// Zombie z2("Ned");
	// Zombie* z4 = newZombie("Rick");
	// randomChump("Cate");
	// z1.announce();
	// {
	// 	Zombie* z5 = newZombie("HEAP");
	// 	delete z5;
	// }
	// // delete z5;
	// {
	// 	Zombie z6("STACK");
	// 	z6.announce();
	// 	Zombie*	z7 = newZombie("HEAP2");
	// 	z7->announce();
	// 	delete z7;
	// }
	// delete z4;
	// z6.announce();
//////////////////////
	int *i_heap = new int;
	int i_stack = 0;

	Zombie stack1("Stack1");
	Zombie  *Heap1 = newZombie("Heap1");
	Heap1->announce();
	std::cout << "Address of int i_stack: \t" << reinterpret_cast<long>(&i_stack) << std::endl;
	std::cout << "Address start of HEAP: \t" << reinterpret_cast<long>(i_heap) << std::endl;
	std::cout << "Address of HEAP Heap1: \t" << reinterpret_cast<long>(Heap1) << std::endl;
	compareAddresses(&stack1, &i_stack, Zombie::getName(stack1));
	compareAddresses(Heap1, &i_stack, Zombie::getName(*Heap1));
	randomChump("Stack");
	delete Heap1;
	delete i_heap;
	{
		Zombie stack2("Stk2");
		std::cout << "Address of int stack1: " << reinterpret_cast<long>(&stack1) << std::endl;
		std::cout << "Address of int stack2: " << reinterpret_cast<long>(&stack2) << std::endl;
		compareAddresses(&stack2, &i_stack, stack2.getName(stack2));
		{
			Zombie *Heap2 = 0;
			std::cout << "Address of HEAP Heap2: " << reinterpret_cast<long>(Heap2) << std::endl;
			Heap2 = newZombie("Heap2");
			std::cout << "Address of HEAP Heap2: " << reinterpret_cast<long>(Heap2) << std::endl;
			Heap2->announce();
			compareAddresses(Heap1, &i_stack, Heap2->getName(*Heap2));
			delete Heap2;
		}
	}
	// delete Heap2;
///////////////////////
	return (0);
}



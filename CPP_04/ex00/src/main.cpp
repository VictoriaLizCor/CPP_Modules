#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#if (DEBUG == 0)

#include <iostream>

int main(void)
{
	{
		const Animal* animal = new Animal();
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();
		std::cout << "---\n";
		std::cout << animal->getType() << " " << std::endl;
		std::cout << dog->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		std::cout << "---\n";
		animal->makeSound();
		dog->makeSound(); //will output the cat sound!
		cat->makeSound();
		std::cout << "---\n";
		delete animal;
		delete dog;
		delete cat;
		std::cout << "\n";
		std::cout << "---------------------\n";
		const WrongAnimal* wrongAnimal = new WrongAnimal();
		const WrongAnimal* wrongCat = new WrongCat();
		WrongCat wc;
		std::cout << "---\n";
		std::cout << std::endl;
		std::cout << wrongAnimal->getType() << " " << std::endl;
		std::cout << wrongCat->getType() << " " << std::endl;
		std::cout << wc.getType() << " " << std::endl;
		std::cout << std::endl;
		wrongAnimal->makeSound(); // will output wrongAnimal sound!
		wrongCat->makeSound();    // will output wrongAnimal sound!
		wc.makeSound();           // will output wrongCat sound!
		std::cout << std::endl;
		delete wrongAnimal;
		delete wrongCat;
	}
	return (0);
}

#endif

/**
 * NOTES: In C++, when you're creating an object on the stack, the syntax
 * `Animal a;` is used to invoke the default constructor of the `Animal` class,
 * creating an instance of `Animal` named `a`. This syntax is straightforward
 * and is the most common way to create objects when they don't need to be
 * dynamically allocated.
 *
 * The syntax `Animal a();`, on the other hand, is a bit tricky and can lead to
 *a common pitfall known as the "most vexing parse." In this context, `Animal
 *a();` doesn't create an object named `a` of type `Animal`. Instead, it
 *declares a function named `a` that takes no arguments and returns an `Animal`.
 *This is a syntactic ambiguity in C++ that often leads to confusion.
 *
 * For dynamically allocated objects, you use `new` because you want the object
 *to be allocated on the heap rather than the stack. This is useful for objects
 *that should outlive the scope in which they were created or when the size of
 *the object is too large to fit comfortably on the stack. The syntax for
 *dynamic allocation does not suffer from the same ambiguity because `new
 *Animal()` clearly indicates a call to the constructor of `Animal` to create an
 *object on the heap.
 *
 * In summary:
 * - `Animal a;` creates an object `a` on the stack.
 * - `Animal a();` is interpreted as a function declaration.
 * - `new Animal();` dynamically allocates an object of type `Animal` on the
 *   heap.
 *
 * To avoid the most vexing parse and clearly declare an object on the stack
 *without using any constructor arguments, you should use the `Animal a;`
 *syntax.
*/
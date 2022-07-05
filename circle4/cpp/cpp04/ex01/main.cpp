#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	{
		std::cout << "\nCase 1-----------------------------------\n";

		Animal *animals[10];
		for (int i = 0; i < 5; i++)
			animals[i] = new Dog();
		for (int i = 5; i < 10; i++)
			animals[i] = new Cat();

		std::stringstream tempStream;

		for (int i = 0; i < 10; i++)
		{
			std::cout << "index" << i << ": " << animals[i]->getType() << " ";
			animals[i]->makeSound();
		}

		for (int i = 0; i < 10; i++)
		{
			std::cout << i << " delete ~ \n";
			delete animals[i];
		}
	}

	{
		std::cout << "\nCase 2-----------------------------------\n";

		const Cat cat = Cat();
		const Cat copiedCat = cat;

		cat.setIdea(0, "original cat ");
		copiedCat.setIdea(0, "copied cat ");

		std::cout << "Deep copy test\n";
		cat.printIdea(0);
		copiedCat.printIdea(0);
	}
	return 0;
}
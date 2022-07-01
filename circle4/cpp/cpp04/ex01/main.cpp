#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();

	Animal *animals[10];
	for (int i = 0; i < 5; i++)
		animals[i] = new Dog();
	for (int i = 5; i < 10; i++)
		animals[i] = new Cat();

	delete dog; // should not create a leak
	delete cat;

	for (int i = 0; i < 10; i++)
	{
		std::cout << i << " delete ~ \n";
		delete animals[i];
	}

	return 0;
}
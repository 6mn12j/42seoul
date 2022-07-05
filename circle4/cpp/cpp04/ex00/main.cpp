#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		std::cout << "\nCase 1 -----------------------\n";
		const Animal *meta = new Animal();
		const Animal *dog = new Dog();
		const Animal *cat = new Cat();
		std::cout << dog->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;

		cat->makeSound(); // will output the cat sound!
		dog->makeSound();
		meta->makeSound();

		delete meta;
		delete dog;
		delete cat;
	}

	{
		std::cout << "\nCase 2 -----------------------\n";
		const WrongAnimal *meta = new WrongAnimal();
		const WrongAnimal *wrongCat = new WrongCat();
		std::cout << wrongCat->getType() << " " << std::endl;

		wrongCat->makeSound(); // will output the cat sound!
		meta->makeSound();

		delete meta;
		delete wrongCat;
	}
}
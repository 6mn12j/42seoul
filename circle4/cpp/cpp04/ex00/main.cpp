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
		const Animal *j = new Dog();
		const Animal *i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;

		i->makeSound(); // will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}

	{
		std::cout << "\nCase 2 -----------------------\n";
		const WrongAnimal *meta = new WrongAnimal();
		const WrongAnimal *i = new WrongCat();
		std::cout << i->getType() << " " << std::endl;

		i->makeSound(); // will output the cat sound!
		meta->makeSound();

		delete meta;
		delete i;
	}

	{
		std::cout << "\nCase 3 -----------------------\n";
		const Cat *cat = new Cat();
		const Dog *dog = new Dog();
		std::cout << cat->getType() << " " << std::endl;
		std::cout << dog->getType() << " " << std::endl;

		cat->makeSound(); // will output the cat sound!
		dog->makeSound();

		delete cat;
		delete dog;
	}
}
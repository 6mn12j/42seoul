#include <string>
#include <cstdint>
#include <iostream>

struct Data
{
	std::string name;
};

uintptr_t serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int main(void)
{
	Data a;
	Data *b;
	uintptr_t ptr;

	a.name = "aData";
	std::cout << "a: " << a.name << std::endl;

	ptr = serialize(&a);
	std::cout << ptr << ptr << std::endl;

	b = deserialize(ptr);
	std::cout << "b: " << b->name << std::endl;

	return (0);
}
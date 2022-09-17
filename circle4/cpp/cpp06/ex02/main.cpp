#include <cstdlib> //rand(), srand()
#include <ctime>   //time()
#include <iostream>
class Base
{
public:
	virtual ~Base() { std::cout << "Base Destructor" << std::endl; };
};

class A : public Base
{
public:
	~A() { std::cout << "A Destructor" << std::endl; };
};

class B : public Base
{
public:
	~B() { std::cout << "B Destructor" << std::endl; };
};

class C : public Base
{
public:
	~C() { std::cout << "C Destructor" << std::endl; };
};

Base *generate(void)
{
	srand(time(NULL));
	int flag = rand() % 3;

	Base *resultBase;
	if (flag == 0)
		resultBase = new A;
	else if (flag == 1)
		resultBase = new B;
	else
		resultBase = new C;
	return resultBase;
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "pointer is A\n";
	if (dynamic_cast<B *>(p))
		std::cout << "pointer is B\n";
	if (dynamic_cast<C *>(p))
		std::cout << "pointer is C\n";
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "reference is A\n";
		(void)a;
	}
	catch (std::exception &)
	{
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		std::cout << "reference is B\n";
		(void)b;
	}
	catch (std::exception &)
	{
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		std::cout << "reference is C\n";
		(void)c;
	}
	catch (std::exception &)
	{
	}
}

int main(void)
{
	Base *random;

	random = generate();
	identify(random);
	identify(*random);

	delete random;
	return (0);
}
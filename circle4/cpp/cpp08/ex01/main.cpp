#include "Span.hpp"

int main() {
	{
			std::cout << "---------- Base case ----------\n";
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	{
		try{
			std::cout << "---------- Error case ----------\n";
			Span sp = Span(5);
			for(int i = 0 ;i < 5 ;i++)
				sp.addNumber(i+1);
			sp.addNumber(1);	//ERROR
		}catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
	try{
		std::cout << "---------- Error case ----------\n";
		Span sp = Span(5);
		for(int i = 0 ;i < 5 ;i++)
			sp.addNumber(i+1);
		sp.addNumber(1);	//ERROR
	}catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
	return 0;
 }
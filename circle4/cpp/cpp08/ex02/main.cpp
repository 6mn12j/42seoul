#include "MutantStack.hpp"

int main()
{
	{
		std::cout << "--------------- Base case ---------------n";
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
		++it; }
		std::stack<int> s(mstack);
	}


	{

		std::cout << "--------------- Case 2 ---------------\n";

		MutantStack<int> mstack;

		for (int i = 0; i < 5; i++)
			mstack.push(i + 1);
		{
			MutantStack<int>::iterator begin = mstack.begin();
			std::cout <<"begin: " <<  *begin << std::endl;
			MutantStack<int>::iterator end = mstack.end();
			std::cout << "end: " << *(--end) << std::endl;
			MutantStack<int>::reverse_iterator rbegin = mstack.rbegin();
			std::cout <<"rbegin: " <<  *rbegin << std::endl;
			MutantStack<int>::reverse_iterator rend = mstack.rend();
			std::cout << "rend: " << *(--rend) << std::endl;
		}

	}
	return 0;
}
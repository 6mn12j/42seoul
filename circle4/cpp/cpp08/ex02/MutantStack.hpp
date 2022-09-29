#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>

#include <stack>
#include <vector>
template <typename T>
class MutantStack :public std::stack<T>
{
	private:

	public:
	MutantStack();
	MutantStack(const MutantStack &);
	MutantStack &operator=(const MutantStack &);
	~MutantStack();

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;

	reverse_iterator rbegin();
	const_iterator rbegin() const;
	reverse_iterator rend();
	const_iterator rend() const;

};

template <typename T>
MutantStack<T>::MutantStack()
{
	// std::cout << "Default Constructor\n";
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &ref)
{
	*this=ref;
}

template <typename T>
MutantStack<T>::~MutantStack()
{

}
template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &ref)
{
	if(this == &ref)
		return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
  return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const{
  return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
  return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const{
  return this->c.end();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() {
  return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::rbegin() const{
  return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() {
  return this->c.rend();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::rend() const{
  return this->c.rend();
}


#endif

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
private:
	T *array;
	unsigned int len;

public:
	Array(void);
	Array(unsigned int n);
	Array(const Array &);
	Array &operator=(const Array &);
	~Array();
	unsigned int size(void) const;
	T &operator[](unsigned int i);
	const T &operator[](unsigned int i) const;

	class OutBoundsException : public std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};
};

template <typename T>
Array<T>::Array(void)
{
	this->array = NULL;
	this->len = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->array = new T[n];
	this->len = n;
}

template <typename T>
Array<T>::Array(const Array &ref)
{
	this->array = NULL;
	this->len = 0;
	*this = ref;
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->array;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &ref)
{
	if (&ref == this)
		return *this;
	delete[] this->array;
	this->array = new T[ref.len];
	for (unsigned int i = 0; i < ref.len; i++)
		array[i] = ref[i];
	this->len = ref.len;
	return *this;
}

template <typename T>
unsigned int Array<T>::size() const
{
	return this->len;
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= this->len)
		throw Array<T>::OutBoundsException();
	return this->array[i];
}

template <typename T>
const T &Array<T>::operator[](unsigned int i) const
{
	if (i >= this->len)
		throw Array<T>::OutBoundsException();
	return this->array[i];
}

template <typename T>
const char *Array<T>::OutBoundsException::what(void) const throw()
{
	return "Index is out of bounds.";
}

#endif

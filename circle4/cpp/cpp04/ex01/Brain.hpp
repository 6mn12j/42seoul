#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
class Brain
{
private:
	std::string ideas[100];

public:
	Brain();
	~Brain();
	Brain(const Brain &);
	Brain &operator=(const Brain &);

	void setIdea(std::string);
};

#endif
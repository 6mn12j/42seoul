#ifndef PRESIDNETIALPARDONFORM_HPP
# define PRESIDNETIALPARDONFORM_HPP

#include "Form.hpp"

class Form;

class PresidentialPardonForm :  public Form {
	public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(const std::string name);
	PresidentialPardonForm(const PresidentialPardonForm& ref);
	~PresidentialPardonForm();
	PresidentialPardonForm& operator=(const PresidentialPardonForm& ref);

	void execute(const Bureaucrat& bureaucrat)  const;

};

std::ostream &operator<<(std::ostream &outstream, const PresidentialPardonForm &ref);

#endif
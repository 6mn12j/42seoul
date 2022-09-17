#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include "fstream"

class Form;

class ShrubberyCreationForm : public Form {
	public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const std::string name);
	ShrubberyCreationForm(const ShrubberyCreationForm& ref);
	~ShrubberyCreationForm();
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& ref);

	void execute(const Bureaucrat& bureaucrat) const;

};

std::ostream &operator<<(std::ostream &outstream, const ShrubberyCreationForm &ref);

#endif
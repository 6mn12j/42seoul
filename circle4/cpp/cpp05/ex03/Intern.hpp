
#ifndef INTERN_H
#define INTERN_H

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>

class Intern
{
private:
	const std::string name;
	int grade;

public:
	Intern(void);
	Intern(std::string name, int grade);
	~Intern(void);
	Intern(const Intern &);
	Intern &operator=(const Intern &);

	Form *makeForm(std::string formName, std::string target);

	class InvalidFormNameException : public std::exception
	{
	public:
		const char *what(void) const throw();
	};
};

#endif
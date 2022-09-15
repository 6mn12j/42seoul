#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern &ref)
{
	*this = ref;
}

Intern::~Intern(void) {}

Intern &Intern::operator=(const Intern &ref)
{
	return *this;
}

const char *Intern::InvalidFormNameException::what(void) const throw()
{
	return "Invalid form name\n";
}

Form *Intern::makeForm(std::string formName, std::string target)
{
	std::string flag[3] = {"robotomy request", "presidential pardon",
						   "shrubbery creation"};

	Form *resultForm = NULL;
	int idx = -1;
	for (int i = 0; i < flag->length(); i++)
	{
		if (flag[i] == formName)
			idx = i;
	}

	switch (idx)
	{
	case 0:
		resultForm = new RobotomyRequestForm(target);
		break;
	case 1:
		resultForm = new PresidentialPardonForm(target);
		break;
	case 2:
		resultForm = new ShrubberyCreationForm(target);
		break;
	default:
		resultForm = NULL;
	}

	if (resultForm == NULL)
		throw InvalidFormNameException();
	else
		std::cout << "Intern creates " << resultForm->getName() << std::endl;
	return resultForm;
}
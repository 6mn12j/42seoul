#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"

int main(void)
{

	{
		Intern someRandomIntern;
		Form *rrf;
		Form *invalid;
		try
		{
			rrf = someRandomIntern.makeForm("robotomy request", "Bender");
			invalid = someRandomIntern.makeForm("no match name", "Bender1");
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		Intern someRandomIntern;
		Form *rrf;
		Form *invalid;
		try
		{
			invalid = someRandomIntern.makeForm("no match name", "Bender1");
			rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}
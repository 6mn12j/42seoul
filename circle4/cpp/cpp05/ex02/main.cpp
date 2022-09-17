#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{

	{
		Bureaucrat polabear("polabear", 100);

		PresidentialPardonForm presidentailForm;
		ShrubberyCreationForm shrubberyForm;
		RobotomyRequestForm robotomForm;

		polabear.signForm(presidentailForm);
		polabear.executeForm(presidentailForm);

		polabear.signForm(shrubberyForm);
		polabear.executeForm(shrubberyForm);

		polabear.signForm(robotomForm);
		polabear.executeForm(robotomForm);
	}
		std::cout << std::endl;

	{
		Bureaucrat minjupar("minjupar", 100);

		PresidentialPardonForm presidentailForm;
		ShrubberyCreationForm shrubberyForm2("shrubberyForm2");
		RobotomyRequestForm robotomForm;

		minjupar.signForm(presidentailForm);
		minjupar.executeForm(presidentailForm);

		minjupar.signForm(shrubberyForm2);
		minjupar.executeForm(shrubberyForm2);

		minjupar.signForm(robotomForm);
		minjupar.executeForm(robotomForm);
	}

}
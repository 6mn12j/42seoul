#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {

	std::cout << std::endl;

	try{
		Bureaucrat polabear("polabear",100);

		PresidentialPardonForm presidentailForm;
		ShrubberyCreationForm shrubberyForm;
		RobotomyRequestForm robotomForm;

		polabear.executeForm(presidentailForm);
		polabear.executeForm(shrubberyForm);
		polabear.executeForm(robotomForm);

		polabear.signForm(presidentailForm);
		polabear.signForm(shrubberyForm);
		polabear.signForm(robotomForm);

		polabear.executeForm(presidentailForm);
		polabear.executeForm(shrubberyForm);
		polabear.executeForm(robotomForm);

		std::cout << "case 5 종료" << std::endl;

	} catch (std::exception &e)
	{
		std::cout << "예외발생" << e.what();
		std::cout << "case 5 예외 종료" << std::endl;
	}



}
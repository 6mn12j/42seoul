#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {

	{
		try {
			Bureaucrat bureaucrat1;

			std::cout << bureaucrat1;
			bureaucrat1.gradeDecrement();
			bureaucrat1.gradeDecrement();
			std::cout << "case 1 종료" << std::endl;
		} catch (std::exception &e) {
			std::cout << "예외발생" << e.what();
			std::cout << "case 1 예외 종료" << std::endl;
		}
	}

    std::cout << std::endl;
	{
		try {
			Bureaucrat minjupar("minjupar", 2);

			std::cout << minjupar;
			minjupar.gradeIncrement();
			std::cout << minjupar;
			minjupar.gradeIncrement();
			std::cout << minjupar;
			std::cout << "case 2 종료" << std::endl;
		} catch (std::exception &e) {
			std::cout << "예외발생" << e.what();
			std::cout << "case 2 예외 종료" << std::endl;
		}
	}

    std::cout << std::endl;
	{
		try{
			Bureaucrat minjupar("minjupar",10);
			Form form20("Form","form20",20,20);
			Form form10("Form","form10",10,10);
			Form form1("Form","form1",1,1);

			form20.beSigned(minjupar);
			form10.beSigned(minjupar);
			form1.beSigned(minjupar);
			std::cout << "case 3 종료" << std::endl;
		} catch (std::exception &e) {
			std::cout << "예외발생" << e.what();
			std::cout << "case 3 예외 종료" << std::endl;
		}
	}

	std::cout << std::endl;
	{
		try{
			Bureaucrat polabear("polabear",1);
			Bureaucrat minjupar("minjupar",1);
			Form form10("Form","form10",10,10);

			form10.beSigned(polabear);
			form10.beSigned(minjupar);
			std::cout << "case 4 종료" << std::endl;
		} catch (std::exception &e) {
			std::cout << "예외발생" << e.what();
			std::cout << "case 4 예외 종료" << std::endl;
		}
	}

	std::cout << std::endl;
	{
		try{
			Bureaucrat polabear("polabear",1);
			PresidentialPardonForm presidentailForm;
			ShrubberyCreationForm shrubberyForm;
			RobotomyRequestForm robotomForm;


			polabear.signForm(presidentailForm);
			polabear.signForm(shrubberyForm);
			polabear.signForm(robotomForm);

			std::cout << "case 5 종료" << std::endl;

		} catch (std::exception &e)
		{
			std::cout << "예외발생" << e.what();
			std::cout << "case 5 예외 종료" << std::endl;
		}
	}

	std::cout << std::endl;
	{
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

			std::cout << "case 6 종료" << std::endl;

		} catch (std::exception &e)
		{
			std::cout << "예외발생" << e.what();
			std::cout << "case 6 예외 종료" << std::endl;
		}

	}

}
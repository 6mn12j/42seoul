#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {

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

    std::cout << std::endl;
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

    std::cout << std::endl;
    try {
        Bureaucrat minjupar("minjupar", -1);

        std::cout << minjupar;
        minjupar.gradeIncrement();
        std::cout << minjupar;
        minjupar.gradeIncrement();
        std::cout << minjupar;
        std::cout << "case 3 종료" << std::endl;
    } catch (std::exception &e) {
        std::cout << "예외발생" << e.what();
        std::cout << "case 3 예외 종료" << std::endl;
    }
    std::cout << std::endl;

    try {
        Bureaucrat minjupar("minjupar", 20);

        std::cout << minjupar;
        minjupar.gradeIncrement();
        std::cout << minjupar;
        minjupar.gradeDecrement();
        std::cout << minjupar;
        std::cout << "case 4 종료" << std::endl;
    } catch (std::exception &e) {
        std::cout << "예외발생" << e.what();
        std::cout << "case 4 예외 종료" << std::endl;
    }
    std::cout << std::endl;

    {
        try {
            Bureaucrat minjupar("minjupar", 10);
            Form form10("Form", "form10", 10, 10);

            form10.beSigned(minjupar);
            std::cout << "case 6 종료" << std::endl;
        } catch (std::exception &e) {
            std::cout << "예외발생" << e.what();
            std::cout << "case 6 예외 종료" << std::endl;
        }
    }

    {
        try {
            Bureaucrat minjupar("minjupar", 20);
            Form form10("Form", "form10", 10, 10);

            form10.beSigned(minjupar);
            std::cout << "case 7 종료" << std::endl;
        } catch (std::exception &e) {
            std::cout << "예외발생" << e.what();
            std::cout << "case 7 예외 종료" << std::endl;
        }
    }
    std::cout << std::endl;

    {
        try {
            Bureaucrat polabear("polabear", 1);
            Bureaucrat minjupar("minjupar", 1);
            Form form10("Form", "form10", 10, 10);

            form10.beSigned(polabear);
            form10.beSigned(minjupar);
            std::cout << "case 8 종료" << std::endl;
        } catch (std::exception &e) {
            std::cout << "예외발생" << e.what();
            std::cout << "case 8 예외 종료" << std::endl;
        }
    }
    std::cout << std::endl;

    {
        try {
            Bureaucrat polabear("polabear", 1);
            Bureaucrat minjupar("minjupar", 15);
            Form form10("Form", "form10", 10, 10);

            polabear.signForm(form10);
            minjupar.signForm(form10);
            std::cout << "case 9 종료" << std::endl;
        } catch (std::exception &e) {
            std::cout << "예외발생" << e.what();
            std::cout << "case 9 예외 종료" << std::endl;
        }
    }
    std::cout << std::endl;
    {
        try {
            ShrubberyCreationForm shrubberyForm("shrubberyForm");
            Bureaucrat minjupar("minjupar", 100);

            std::cout << shrubberyForm;

            shrubberyForm.beSigned(minjupar);
            shrubberyForm.execute(minjupar);
            std::cout << "case 10 종료" << std::endl;

        } catch (std::exception &e) {
            std::cout << "예외발생" << e.what();
            std::cout << "case 10 예외 종료" << std::endl;
        }
    }

    std::cout << std::endl;

    {
        try {
            ShrubberyCreationForm shrubberyForm("shrubberyForm2");
            Bureaucrat minjupar("minjupar", 149);

            std::cout << shrubberyForm;

            shrubberyForm.beSigned(minjupar);
            shrubberyForm.execute(minjupar);
            std::cout << "case 11 종료" << std::endl;

        } catch (std::exception &e) {
            std::cout << "예외발생" << e.what();
            std::cout << "case 11 예외 종료" << std::endl;
        }
    }
    std::cout << std::endl;
    {
        try {
            RobotomyRequestForm robotoForm("robotoForm2");
            Bureaucrat minjupar("minjupar", 30);

            std::cout << robotoForm;

            robotoForm.beSigned(minjupar);
            robotoForm.execute(minjupar);
            std::cout << "case 12 종료" << std::endl;

        } catch (std::exception &e) {
            std::cout << "예외발생" << e.what();
            std::cout << "case 12 예외 종료" << std::endl;
        }
    }
    std::cout << std::endl;

    {
        try {
            PresidentialPardonForm presiDentialForm("presidentialForm");
            Bureaucrat minjupar("minjupar", 30);

            std::cout << presiDentialForm;
            minjupar.executeForm(presiDentialForm);
            presiDentialForm.beSigned(minjupar);
            minjupar.executeForm(presiDentialForm);
            std::cout << "case 13 종료" << std::endl;

        } catch (std::exception &e) {
            std::cout << "예외발생" << e.what();
            std::cout << "case 13 예외 종료" << std::endl;
        }
    }
    std::cout << std::endl;
    {
        try {
            PresidentialPardonForm presiDentialForm("presidentialForm");
            Bureaucrat minjupar("minjupar", 30);

            std::cout << presiDentialForm;
            presiDentialForm.beSigned(minjupar);
            minjupar.executeForm(presiDentialForm);
            std::cout << "case 14 종료" << std::endl;

        } catch (std::exception &e) {
            std::cout << "예외발생" << e.what();
            std::cout << "case 14 예외 종료" << std::endl;
        }
    }
    std::cout << std::endl;
}
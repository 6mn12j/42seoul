#include "Bureaucrat.hpp"
#include "Form.hpp"

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
	try{
		Bureaucrat minjupar("minjupar",10);
		Form form20("form20",20,20);
		Form form10("form10",10,10);
		Form form1("form1",1,1);

		minjupar.signForm(form20);
		minjupar.signForm(form10);
		minjupar.signForm(form1);
		std::cout << "case 3 종료" << std::endl;
	} catch (std::exception &e) {
		std::cout << "예외발생" << e.what();
		std::cout << "case 3 예외 종료" << std::endl;
	}

	std::cout << std::endl;
	try{
		Bureaucrat polabear("polabear",1);
		Bureaucrat minjupar("minjupar",1);
		Form form10("form10",10,10);


		polabear.signForm(form10);
		minjupar.signForm(form10);
		std::cout << "case 4 종료" << std::endl;
	} catch (std::exception &e) {
		std::cout << "예외발생" << e.what();
		std::cout << "case 4 예외 종료" << std::endl;
	}

}
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {

    {
        Form a("a");
        std::cout << a;
        Form b("b");
        std::cout << b;
        a = b;
        std::cout << a;
    }

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
}
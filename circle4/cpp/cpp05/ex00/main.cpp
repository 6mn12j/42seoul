#include "Bureaucrat.hpp"

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

}
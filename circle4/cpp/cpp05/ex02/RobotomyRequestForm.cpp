#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
    : Form("RobotomyRequestForm", "undefined", 45, 72) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
    : Form("RobotomyRequestForm", target, 45, 72) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref)
    : Form(ref) {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &ref) {
    Form::operator=(ref);
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm(void) {}

std::ostream &operator<<(std::ostream &outstream,
                         const RobotomyRequestForm &ref) {
    outstream << " name: ";
    outstream << ref.getName();
    outstream << ", ";
    outstream << " excute grade: ";
    outstream << ref.getRequiredExecuteGrade();
    outstream << ", ";
    outstream << " sign grade: ";
    outstream << ref.getRequiredSignedGrade();
    outstream << ", ";
    outstream << " form type: ";
    outstream << ref.getType();
    outstream << ", ";
    outstream << " form isSigned: ";
    outstream << ref.getIsSigned() << std::endl;
    return outstream;
}

void RobotomyRequestForm::execute(const Bureaucrat &ref) const {
    if (!this->getIsSigned())
        throw Form::NoSignExecption();
    else if (this->getRequiredExecuteGrade() < ref.getGrade())
        throw Form::GradeTooHighException();
    else {
        std::cout << ref.getName() << " executed " << this->getName() << " "
                  << this->getType();
        std::cout << "Makeeeiiinnnggg..." << std::endl;
        srand(time(NULL));
        if (rand() % 2 == 1)
            std::cout << this->getName() << " SUCCESS " << std::endl;
        else
            std::cout << this->getName() << " FAIL " << std::endl;
    }
}
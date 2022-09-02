#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
    : Form("PresidentialPardonForm", "undefined", 5, 25) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
    : Form("PresidentialPardonForm", target, 5, 25) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &ref)
    : Form(ref) {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &ref) {
    Form::operator=(ref);
    return *this;
}
PresidentialPardonForm::~PresidentialPardonForm(void) {}

std::ostream &operator<<(std::ostream &outstream,
                         const PresidentialPardonForm &ref) {
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

void PresidentialPardonForm::execute(const Bureaucrat &ref) const {
    if (!this->getIsSigned())
        throw Form::NoSignExecption();
    else if (this->getRequiredExecuteGrade() < ref.getGrade())
        throw Form::GradeTooHighException();
    else
        std::cout << this->getName()
                  << " has been pardoned by Zaphod Beeblebrox. " << std::endl;
}
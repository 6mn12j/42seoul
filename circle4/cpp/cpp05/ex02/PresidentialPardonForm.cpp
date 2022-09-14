#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): Form("PresidentialPardonForm", "presidentialPardonForm", 5, 25){}

PresidentialPardonForm::PresidentialPardonForm(const std::string name): Form("PresidentialPardonForm", name, 5, 25){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm&ref):Form(ref){}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &ref) {
    Form::operator=(ref);
	return *this;
}
PresidentialPardonForm::~PresidentialPardonForm(void){}

std::ostream &operator<<(std::ostream &outstream, const PresidentialPardonForm &ref){
	outstream << ref.getName();
   	outstream << ", ";
    outstream << "form require excute grade ";
    outstream << ref.getRequiredExecuteGrade();
    outstream << " form require sign grade ";
    outstream << ref.getRequiredSignedGrade();
	outstream << " form type = ";
	outstream << ref.getType();
    outstream << " form isSigned = ";
    outstream << ref.getIsSigned() << std::endl;
    return outstream;
}

void PresidentialPardonForm::execute(const Bureaucrat& ref) const throw(Form::NoSignExecption,Form::GradeTooHighException)
{
	if (!this->getIsSigned())
		throw Form::NoSignExecption();
	else if (this->getRequiredExecuteGrade() < ref.getGrade())
		throw Form::GradeTooHighException();
	else
		std::cout << this->getName() <<" has been pardoned by Zaphod Beeblebrox. " << std::endl;
}
#include "Form.hpp"

Form::Form(void)
    : name("undefined"), requiredExecuteGrade(150), requiredSignedGrade(150),
      isSigned(false) {}

Form::Form(std::string name)
    : name(name), requiredExecuteGrade(150), requiredSignedGrade(150),
      isSigned(false) {}

Form::Form(std::string name, int requiredExecuteGrade, int requiredSignedGrade) : name(name), requiredExecuteGrade(requiredExecuteGrade), requiredSignedGrade(requiredSignedGrade)
{
    if (requiredExecuteGrade > 150 || requiredSignedGrade > 150)
        throw GradeTooLowException();
    if (requiredExecuteGrade < 0 || requiredSignedGrade < 0)
        throw GradeTooHighException();
}

Form::~Form(void) {}

Form::Form(const Form &ref)
    : name(ref.name), requiredExecuteGrade(ref.requiredExecuteGrade),
      requiredSignedGrade(ref.requiredSignedGrade), isSigned(ref.isSigned)
{
    *this = ref;
}

Form &Form::operator=(const Form &ref)
{
    if (&ref == this)
        return *this;
    this->isSigned = ref.isSigned;
    return *this;
}

std::string Form::getName() const { return this->name; }
int Form::getRequiredExecuteGrade() const { return this->requiredExecuteGrade; }
int Form::getRequiredSignedGrade() const { return this->requiredSignedGrade; }
bool Form::getIsSigned() const { return this->isSigned; }

std::ostream &operator<<(std::ostream &outstream, const Form &ref)
{
	outstream << "name: ";
    outstream << ref.getName();
    outstream << ", ";
    outstream << "form require Execute grade ";
    outstream << ref.getRequiredExecuteGrade();
    outstream << " form require sign grade ";
    outstream << ref.getRequiredSignedGrade();
    outstream <<  " form isSigned: ";
    outstream << std::boolalpha<< ref.getIsSigned() << std::endl;
    return outstream;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
  	if (this->getIsSigned())
        throw IsSingedException();
    if (bureaucrat.getGrade() > this->getRequiredSignedGrade())
        throw Bureaucrat::GradeTooLowException();

    this->isSigned = true;
    std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
}

const char *Form::GradeTooHighException::what(void) const throw()
{
    return "Form Grade Too High\n";
}

const char *Form::GradeTooLowException::what(void) const throw()
{
    return "Form Grade Too Low\n";
}

const char *Form::NoSignExecption::what(void) const throw()
{
    return "Form Is No Signed\n";
}

const char *Form::IsSingedException::what(void) const throw()
{
    return "Form Is Signed\n";
}
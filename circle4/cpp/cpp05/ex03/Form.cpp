#include "Form.hpp"

Form::Form(void)
    : type("Form"), name("undefined"), requiredExecuteGrade(150), requiredSignedGrade(150),
      isSigned(false) {}

Form::Form(std::string name)
    : type("Form"), name(name), requiredExecuteGrade(150), requiredSignedGrade(150),
      isSigned(false)
{
}

Form::Form(std::string type, std::string name, int requiredExecuteGrade, int requiredSignedGrade) : type(type), name(name), requiredExecuteGrade(requiredExecuteGrade), requiredSignedGrade(requiredSignedGrade)
{
    if (requiredExecuteGrade > 150 || requiredSignedGrade > 150)
        throw GradeTooLowException();
    if (requiredExecuteGrade < 0 || requiredSignedGrade < 0)
        throw GradeTooHighException();
}

Form::~Form(void) {}

Form::Form(const Form &ref)
    : type(ref.type), name(ref.name), requiredExecuteGrade(ref.requiredExecuteGrade),
      requiredSignedGrade(ref.requiredSignedGrade), isSigned(ref.isSigned)
{
    *this = ref;
}

Form &Form::operator=(const Form &ref)
{
    if (&ref == this)
        return *this;
    this->isSigned = ref.isSigned;
    this->type = ref.type;
    return *this;
}

std::string Form::getName() const { return this->name; }
int Form::getRequiredExecuteGrade() const { return this->requiredExecuteGrade; }
int Form::getRequiredSignedGrade() const { return this->requiredSignedGrade; }
bool Form::getIsSigned() const { return this->isSigned; }
std::string Form::getType() const { return this->type; }

std::ostream &operator<<(std::ostream &outstream, const Form &ref)
{
    outstream << " name: ";
    outstream << ref.getName();
    outstream << ", ";
    outstream << " Execute grade: ";
    outstream << ref.getRequiredExecuteGrade();
    outstream << ", ";
    outstream << " sign grade: ";
    outstream << ref.getRequiredSignedGrade();
    outstream << " form type: ";
    outstream << ", ";
    outstream << ref.getType();
    outstream << " form isSigned: ";
    outstream << ref.getIsSigned() << std::endl;
    return outstream;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->getRequiredSignedGrade())
        throw Bureaucrat::GradeTooLowException();
    if (this->getIsSigned())
        throw IsSingedException();

    this->isSigned = true;
    std::cout << bureaucrat.getName() << " signed " << this->name << std::endl;
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
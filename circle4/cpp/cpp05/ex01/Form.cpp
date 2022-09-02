#include "Form.hpp"

Form::Form(void)
    : name("undefined"), requiredExecuteGrade(150), requiredSignedGrade(150),
      isSigned(false) {
    std::cout << "Form Default Constructor" << std::endl;
}

Form::Form(std::string name)
    : name(name), requiredExecuteGrade(150), requiredSignedGrade(150),
      isSigned(false) {
    std::cout << "Form Default Constructor" << std::endl;
}

Form::~Form(void) { std::cout << "Form destructor\n"; }

Form::Form(const Form &ref)
    : name(ref.name), requiredExecuteGrade(ref.requiredExecuteGrade),
      requiredSignedGrade(ref.requiredSignedGrade), isSigned(ref.isSigned) {
    *this = ref;
    std::cout << "Form copy constructor" << std::endl;
}

// const 값들은 변경 가능하지 않는데 맞는지?
Form &Form::operator=(const Form &ref) {
    if (&ref == this)
        return *this;
    this->isSigned = ref.isSigned;
    const_cast<std::string &>(this->name) = ref.name;
    return *this;
}

std::string Form::getName() const { return this->name; }
int Form::getRequiredExecuteGrade() const { return this->requiredExecuteGrade; }
int Form::getRequiredSignedGrade() const { return this->requiredSignedGrade; }
bool Form::getIsSigned() const { return this->isSigned; }

std::ostream &operator<<(std::ostream &outstream, const Form &ref) {
    outstream << ref.getName();
    outstream << ", ";
    outstream << "form require excute grade ";
    outstream << ref.getRequiredExecuteGrade();
    outstream << "form require sign grade ";
    outstream << ref.getRequiredSignedGrade();
    outstream << "form isSigned = ";
    outstream << ref.getIsSigned() << std::endl;
    return outstream;
}

void Form::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->requiredSignedGrade) {
        throw GradeTooLowException();
        return;
    }
    this->isSigned = true;
    std::cout << bureaucrat.getName() << "signed" << this->name;
}

const char *Form::GradeTooHighException::what(void) const throw() {
    return "GradeTooHighExcepton\n";
}

const char *Form::GradeTooLowException::what(void) const throw() {
    return "GradeTooLowExcepton\n";
}
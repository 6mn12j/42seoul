#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("undefined"), grade(150) {
    std::cout << "Bureaucrat Default Constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &ref) : name(ref.name) {
    *this = ref;
    std::cout << "Bureaucrat copy constructor \n";
}

Bureaucrat::~Bureaucrat(void) { std::cout << "Bureaucrat destructor\n"; }

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &ref) {
    if (&ref == this)
        return *this;
    this->grade = ref.grade;
    return *this;
}

std::string Bureaucrat::getName() const { return this->name; }

int Bureaucrat::getGrade() const { return this->grade; }

void Bureaucrat::gradeDecrement() {

    if (this->getGrade() >= 150)
        throw GradeTooLowException();
    else
        this->grade++;
}

void Bureaucrat::gradeIncrement() {

    if (this->getGrade() <= 150)
        throw GradeTooHighException();
    else
        this->grade--;
}

void Bureaucrat::gradeIncrement() {}

const char *Bureaucrat::GradeTooHighException::what(void) {
    return "GradeTooHighException\n";
}

const char *Bureaucrat::GradeTooLowException::what(void) {
    return "GradeTooLowException\n";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &ref) {
    out << ref.getName();
    out << ", ";
    out << "bureaucrat grade ";
    out << ref.getGrade() << ".\n";
    return out;
}
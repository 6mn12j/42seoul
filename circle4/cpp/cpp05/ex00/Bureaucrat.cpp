#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("undefined"), grade(150) {
    std::cout << "Bureaucrat Default Constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &ref) : name(ref.name) {
    *this = ref;
    std::cout << "Bureaucrat copy constructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {

    if (grade > 150)
        this->grade = 150;
    else if (grade < 1)
        this->grade = 1;
    else
        this->grade = grade;

    std::cout << "Bureaucrat Name Grade Constructor" << std::endl;
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

    if (this->getGrade() <= 1)
        throw GradeTooHighException();
    else
        this->grade--;
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw() {
    return "GradeTooHighException\n";
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw() {
    return "GradeTooLowException\n";
}

std::ostream &operator<<(std::ostream &outstreame, const Bureaucrat &ref) {
    outstreame << ref.getName();
    outstreame << ", ";
    outstreame << "bureaucrat grade ";
    outstreame << ref.getGrade() << std::endl;
    return outstreame;
}
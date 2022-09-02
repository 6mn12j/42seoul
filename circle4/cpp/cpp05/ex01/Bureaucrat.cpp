#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("undefined"), grade(150) {
    std::cout << "Bureaucrat Default Constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &ref) : name(ref.name) {
    *this = ref;
    std::cout << "Bureaucrat copy constructor \n";
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

void Bureaucrat::signForm(Form &form) {

    // form 보다 bureaucrat 의 권한이 더 낮을때
    if (this->grade > form.getRequiredSignedGrade()) {
        std::cout << this->name << " couldn't sign " << form.getName()
                  << "because too Low" << std::endl;
        return;
    }
    //이미 사인 되어 있을때
    if (form.getIsSigned()) {
        std::cout << this->name << " couldn't sign " << form.getName()
                  << "because signed" << std::endl;
        return;
    }

    form.beSigned(*this);
}
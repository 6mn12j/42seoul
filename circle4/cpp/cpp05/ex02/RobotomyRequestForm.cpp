#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form("RobotomyRequestForm", "robotomyRequestForm", 45, 72) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string name) : Form("RobotomyRequestForm", name, 45, 72) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref) : Form(ref) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &ref)
{
	Form::operator=(ref);
	return *this;
}
RobotomyRequestForm::~RobotomyRequestForm(void) {}

std::ostream &operator<<(std::ostream &outstream, const RobotomyRequestForm &ref)
{
	outstream << "name: ";
	outstream << ref.getName();
	outstream << ", ";
	outstream << "form require Execute grade ";
	outstream << ref.getRequiredExecuteGrade();
	outstream << " form require sign grade ";
	outstream << ref.getRequiredSignedGrade();
	outstream << " form type: ";
	outstream << ref.getType();
	outstream << " form isSigned: ";
	outstream << ref.getIsSigned() << std::endl;
	return outstream;
}

void RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) const throw(Form::NoSignExecption, Form::GradeTooHighException)
{
	if (!this->getIsSigned())
		throw Form::NoSignExecption();
	else if (this->getRequiredExecuteGrade() < bureaucrat.getGrade())
		throw Form::GradeTooHighException();
	else
	{
		std::cout << bureaucrat.getName() << " executed " << this->getName() << " " << this->getType();
		std::cout << "Makeeeiiinnnggg..." << std::endl;
		srand(time(NULL));
		if (rand() % 2 == 1)
			std::cout << this->getName() << " SUCCESS " << std::endl;
		else
			std::cout << this->getName() << " FAIL " << std::endl;
	}
}
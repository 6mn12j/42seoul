#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("ShrubberyForm", "shrubberyForm", 137, 145) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name) : Form("ShrubberyForm", name, 137, 145) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ref) : Form(ref) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ref)
{
	Form::operator=(ref);
	return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

std::ostream &operator<<(std::ostream &outstream, const ShrubberyCreationForm &ref)
{
	outstream << ref.getName();
	outstream << ", ";
	outstream << "form require Execute grade ";
	outstream << ref.getRequiredExecuteGrade();
	outstream << " form require sign grade ";
	outstream << ref.getRequiredSignedGrade();
	outstream << " form type = ";
	outstream << ref.getType();
	outstream << " form isSigned = ";
	outstream << ref.getIsSigned() << std::endl;
	return outstream;
}

void ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const throw(Form::NoSignExecption, Form::GradeTooHighException)
{
	if (!this->getIsSigned())
		throw Form::NoSignExecption();
	else if (this->getRequiredExecuteGrade() < bureaucrat.getGrade())
		throw Form::GradeTooHighException();
	else
	{
		std::ofstream of;

		of.open(this->getName() + "_shrubbery");
		of << "    oxoxoo    ooxoo\n";
		of << "  ooxoxo oo  oxoxooo\n";
		of << " oooo xxoxoo ooo ooox\n";
		of << " oxo o oxoxo  xoxxoxo\n";
		of << "  oxo xooxoooo o ooo\n";
		of << "    ooo\\oo\\  /o/o\n";
		of << "        \\  \\/ /\n";
		of << "         |   /\n";
		of << "         |  |\n";
		of << "         | D|\n";
		of << "         |  |\n";
		of << "         |  |\n";
		of << "  ______/____\\____" << std::endl;
		of.close();
		std::cout << bureaucrat.getName() << " executed " << this->getName() << " " << this->getType();
	}
}

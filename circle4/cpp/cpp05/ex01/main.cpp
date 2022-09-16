#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{

	{
		Bureaucrat minjupar("minjupar", 10);
		Form form20("form20", 20, 20);
		Form form10("form10", 10, 10);
		Form form1("form1", 1, 1);

		minjupar.signForm(form20);
		minjupar.signForm(form10);
		minjupar.signForm(form1);
		std::cout << "case 1 종료" << std::endl;
	}

	{
		Bureaucrat polabear("polabear", 1);
		Bureaucrat minjupar("minjupar", 1);
		Form form10("form10", 10, 10);

		std::cout << form10 << std::endl;

		polabear.signForm(form10);
		minjupar.signForm(form10);
		std::cout << "case 2 종료" << std::endl;
	}
}
#ifndef ROBOTOMYREQUEST_HPP
# define ROBOTOMYREQUEST_HPP

#include "Form.hpp"
#include <cstdlib> //rand(), srand()
#include <ctime> //time()

class Form;

class RobotomyRequestForm : public Form {
	public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(const std::string name);
	RobotomyRequestForm(const RobotomyRequestForm& ref);
	~RobotomyRequestForm();
	RobotomyRequestForm& operator=(const RobotomyRequestForm& ref);

	void execute(const Bureaucrat& bureaucrat) const;

};

std::ostream &operator<<(std::ostream &outstream, const RobotomyRequestForm &ref);

#endif
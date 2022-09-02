#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class Form {
  private:
    const std::string name;
    const int requiredExecuteGrade;
    const int requiredSignedGrade;
    bool isSigned;

  public:
    Form(void);
    Form(const std::string name);
    ~Form(void);
    Form(const Form &);
    Form &operator=(const Form &);

    void beSigned(Bureaucrat &bureaucrat);

    std::string getName() const;
    int getRequiredExecuteGrade() const;
    int getRequiredSignedGrade() const;
    bool getIsSigned() const;

    class GradeTooLowException : public std::exception {
      public:
        const char *what(void) const throw();
    };
    class GradeTooHighException : public std::exception {
      public:
        const char *what(void) const throw();
    };
};

std::ostream &operator<<(std::ostream &outstream, const Form &ref);

#endif
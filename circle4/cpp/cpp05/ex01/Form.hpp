#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
private:
  const std::string name;
  const int requiredExecuteGrade;
  const int requiredSignedGrade;
  bool isSigned;

public:
  Form(void);
  Form(const std::string name);
  Form(const std::string name, const int requiredExecuteGrade,
       const int requiredSignedGrade);
  ~Form(void);
  Form(const Form &);
  Form &operator=(const Form &);

  std::string getName() const;
  int getRequiredExecuteGrade() const;
  int getRequiredSignedGrade() const;
  bool getIsSigned() const;

  void beSigned(Bureaucrat &bureaucrat);

  class GradeTooLowException : public std::exception
  {
  public:
    const char *what(void) const throw();
  };
  class GradeTooHighException : public std::exception
  {
  public:
    const char *what(void) const throw();
  };
  class NoSignExecption : public std::exception
  {
  public:
    const char *what(void) const throw();
  };
  class IsSingedException : public std::exception
  {
  public:
    const char *what(void) const throw();
  };
};

std::ostream &operator<<(std::ostream &outstream, const Form &ref);

#endif
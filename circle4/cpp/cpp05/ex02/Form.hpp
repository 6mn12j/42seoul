#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
private:
  bool isSigned;
  std::string type;
  const std::string name;
  const int requiredExecuteGrade;
  const int requiredSignedGrade;

public:
  Form(void);
  Form(const std::string name);
  Form(std::string type, const std::string name, const int requiredExecuteGrade, const int requiredSignedGrade);
  virtual ~Form(void);
  Form(const Form &);
  Form &operator=(const Form &);

  std::string getName() const;
  int getRequiredExecuteGrade() const;
  int getRequiredSignedGrade() const;
  bool getIsSigned() const;
  std::string getType() const;

  void beSigned(Bureaucrat &bureaucrat);
  virtual void execute(Bureaucrat const &executor) const = 0;

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
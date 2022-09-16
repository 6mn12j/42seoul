#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat
{
private:
  const std::string name;
  int grade;

public:
  Bureaucrat(void);
  Bureaucrat(std::string name, int grade);
  ~Bureaucrat(void);
  Bureaucrat(const Bureaucrat &);
  Bureaucrat &operator=(const Bureaucrat &);

  std::string getName() const;
  int getGrade() const;

  void gradeIncrement(void);
  void gradeDecrement(void);

  class GradeTooHighException : public std::exception
  {
  public:
    const char *what(void) const throw();
  };

  class GradeTooLowException : public std::exception
  {
  public:
    const char *what(void) const throw();
  };
};

std::ostream &operator<<(std::ostream &outstream, const Bureaucrat &ref);

#endif
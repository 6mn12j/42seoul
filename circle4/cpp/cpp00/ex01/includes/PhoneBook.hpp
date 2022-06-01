#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "Contact.hpp"
#include <string>
#include <iomanip>
#include <limits>
#define MAX_PHONEBOOK 8

class PhoneBook
{
private:
  Contact contacts[MAX_PHONEBOOK];
  int currentCnt;
  int prevIndex;

public:
  int getCnt();
  bool isEmpty();
  bool checkValidIndex(int index);
  void printPhoneBook();
  void saveContact(std::string firstName, std::string lastName,
                   std::string nickName, std::string phoneNumber,
                   std::string darkSecret);
  void searchContact(int targetIndex);
  PhoneBook();
  ~PhoneBook();
};

#endif

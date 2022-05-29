#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "Contact.hpp"
#include <string>

#define MAX_PHONEBOOK 3

class PhoneBook
{
private:
  Contact contacts[MAX_PHONEBOOK];
  int currentCnt;
  int prevIndex;

public:
  int getCnt();
  void printPhoneBook();
  void saveContact(std::string firstName, std::string lastName,
                   std::string nickName, std::string phoneNumber,
                   std::string darkSecret);
  void SEARCH(int index, std::string first_name, std::string last_name,
              std::string nick_name);
  PhoneBook();
  ~PhoneBook();
};

#endif

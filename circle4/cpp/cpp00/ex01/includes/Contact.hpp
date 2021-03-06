#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
private:
  std::string firstName;
  std::string lastName;
  std::string nickName;
  std::string darkSecret;
  std::string phoneNumber;
  bool isUsed;

public:
  std::string getFirstName();
  void setFirstName(std::string firstName);

  std::string getLastName();
  void setLastName(std::string lastName);

  std::string getNickName();
  void setNickName(std::string nickName);

  std::string getDarkSecret();
  void setDarkSecret(std::string dark_name);

  std::string getPhoneNumber();
  void setPhoneNumber(std::string phoneNumber);

  bool getIsUsed();
  void setIsUsed(bool value);

  Contact();
  ~Contact();
};

#endif
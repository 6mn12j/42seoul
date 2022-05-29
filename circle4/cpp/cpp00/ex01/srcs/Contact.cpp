/*
        index, first name, lastname, nickname
        각 컬름은 10자, 오른쪽 정렬

        유저가 9번 인덱스를 넣으려고 하면 제일 오래인덱스의 데이터를 대신한다.

*/

#include "Contact.hpp"

Contact::Contact()
{
    std::cout << "contact 생성\n";
}

Contact::~Contact()
{
    std::cout << "contact 소멸\n";
}

std::string Contact::getFirstName() { return this->firstName; }
std::string Contact::getLastName() { return this->lastName; }
std::string Contact::getNickName() { return this->nickName; }

void Contact::setFirstName(std::string firstName)
{
    this->firstName = firstName;
}

void Contact::setLastName(std::string lastName)
{
    this->lastName = lastName;
}

void Contact::setNickName(std::string nickName)
{
    this->nickName = nickName;
}

void Contact::setDarkSecret(std::string darkSecret)
{
    this->darkSecret = darkSecret;
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

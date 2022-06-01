/*
        index, first name, lastname, nickname
        각 컬름은 10자, 오른쪽 정렬

        유저가 9번 인덱스를 넣으려고 하면 제일 오래인덱스의 데이터를 대신한다.

*/

#include "Contact.hpp"

Contact::Contact() { this->isUsed = false; }

Contact::~Contact() {}

std::string Contact::getFirstName() { return this->firstName; }
std::string Contact::getLastName() { return this->lastName; }
std::string Contact::getNickName() { return this->nickName; }
std::string Contact::getDarkSecret() { return this->darkSecret; }

std::string Contact::getPhoneNumber() { return this->phoneNumber; }
bool Contact::getIsUsed() { return this->isUsed; }

void Contact::setFirstName(std::string firstName) {
    this->firstName = firstName;
}

void Contact::setLastName(std::string lastName) { this->lastName = lastName; }

void Contact::setNickName(std::string nickName) { this->nickName = nickName; }

void Contact::setDarkSecret(std::string darkSecret) {
    this->darkSecret = darkSecret;
}

void Contact::setPhoneNumber(std::string phoneNumber) {
    this->phoneNumber = phoneNumber;
}

void Contact::setIsUsed(bool value) { this->isUsed = value; }

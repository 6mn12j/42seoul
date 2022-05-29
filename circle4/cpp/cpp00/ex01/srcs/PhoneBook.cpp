
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->prevIndex = -1;
    this->currentCnt = 0;
    std::cout << "phonebook 생성\n";
}

PhoneBook::~PhoneBook()
{
    std::cout << "phonebook 소멸\n";
}

int PhoneBook::getCnt()
{
    int cnt = 0;
    while (this->contacts[cnt].getFirstName().length() > 0)
        cnt++;
    return cnt;
}

void PhoneBook::saveContact(std::string firstName, std::string lastName,
                            std::string nickName, std::string phoneNumber,
                            std::string darkSecret)
{
    int currentIndex;
    if (this->prevIndex == MAX_PHONEBOOK - 1)
        currentIndex = 0;
    else
        currentIndex = prevIndex + 1;

    this->contacts[currentIndex].setPhoneNumber(phoneNumber);
    this->contacts[currentIndex].setLastName(lastName);
    this->contacts[currentIndex].setFirstName(firstName);
    this->contacts[currentIndex].setNickName(nickName);
    this->contacts[currentIndex].setDarkSecret(darkSecret);
    this->prevIndex = currentIndex;
    this->currentCnt = getCnt();
}

void print_col_10(std::string str)
{
    int flag = 1;
    int len = str.length();
    if (len > 10)
        str = str.substr(0, 9);
    else
    {
        flag = 0;
        while (len++ < 10)
            str += ' ';
    }
    std::cout
        << str;
    if (flag)
        std::cout << ".";
    std::cout << "|";
}

void PhoneBook::printPhoneBook()
{
    int index = 0;

    std::cout << "INDEX     "
              << "|";
    std::cout << "FIRST NAME"
              << "|";
    std::cout << "LAST NAME "
              << "|";
    std::cout << "NICK NAME "
              << "|" << std::endl;
    while (index < this->currentCnt)
    {

        std::cout << index << "         |";
        print_col_10(this->contacts[index].getFirstName());
        print_col_10(this->contacts[index].getLastName());
        print_col_10(this->contacts[index].getNickName());
        std::cout << std::endl;

        index++;
    }
}
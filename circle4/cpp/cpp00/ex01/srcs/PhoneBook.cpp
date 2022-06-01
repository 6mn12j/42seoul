
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    this->prevIndex = -1;
    this->currentCnt = 0;
}

PhoneBook::~PhoneBook() {}

int PhoneBook::getCnt() {
    int cnt = 0;
    while (this->contacts[cnt].getIsUsed() == true)
        cnt++;
    return cnt;
}

void PhoneBook::saveContact(std::string firstName, std::string lastName,
                            std::string nickName, std::string phoneNumber,
                            std::string darkSecret) {
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
    this->contacts[currentIndex].setIsUsed(true);
    this->prevIndex = currentIndex;
    this->currentCnt = getCnt();
}

void printColumn(std::string str) {
    int len = str.length();
    if (len > 10) {
        str = str.substr(0, 9);
        str += ".";
    }
    std::cout << std::setw(10) << str;
    std::cout << "|";
}

bool PhoneBook::isEmpty() {
    if (this->currentCnt == 0) {
        std::cout << "Empty PhoneBook\n";
        return true;
    } else
        return false;
}
bool PhoneBook::checkValidIndex(int index) {
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    if (index < 0 || index >= this->currentCnt)
        return false;
    return true;
}

void PhoneBook::printPhoneBook() {
    int index = 0;
    std::cout << std::setw(10) << "Index"
              << "|";
    std::cout << std::setw(10) << "First Name"
              << "|";
    std::cout << std::setw(10) << "Last Name"
              << "|";
    std::cout << std::setw(10) << "Nickname"
              << "|";
    std::cout << std::endl;

    while (index < this->currentCnt) {

        std::cout << std::setw(10) << index << "|";
        printColumn(this->contacts[index].getFirstName());
        printColumn(this->contacts[index].getLastName());
        printColumn(this->contacts[index].getNickName());
        std::cout << std::endl;

        index++;
    }
}
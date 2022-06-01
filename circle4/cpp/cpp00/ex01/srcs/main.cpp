#include "PhoneBook.hpp"

bool isValidValue(std::string value) {
    if (value.length() <= 0) {
        std::cout << "필드가 비어 있습니다.\n";
        return false;
    } else
        return true;
}

bool getColmun(std::string str, std::string &value) {
    std::cout << str << "을 입력하세요.\n";
    getline(std::cin, value);
    return isValidValue(value);
}

void handleAdd(PhoneBook &phonebook) {
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkSecret;

    if (!getColmun("firstName", firstName) ||
        !getColmun("lastName", lastName) || !getColmun("nickName", nickName) ||
        !getColmun("phoneNumber", phoneNumber) ||
        !getColmun("darkSecret ", darkSecret))
        return;

    phonebook.saveContact(firstName, lastName, nickName, phoneNumber,
                          darkSecret);
    std::cout << "추가 되었습니다.\n";
}

void PhoneBook::searchContact(int targetIndex) {
    std::cout << "----- contact[" << targetIndex << "] INFOMATION -----"
              << std::endl;

    std::cout << "FIRST_NAME: " << this->contacts[targetIndex].getFirstName()
              << std::endl;
    std::cout << "LAST_NAME: " << this->contacts[targetIndex].getLastName()
              << std::endl;
    std::cout << "NICK_NAME: " << this->contacts[targetIndex].getNickName()
              << std::endl;
    std::cout << "DARK_SECRET: " << this->contacts[targetIndex].getDarkSecret()
              << std::endl;
    std::cout << "PHONE_NUMBER: "
              << this->contacts[targetIndex].getPhoneNumber() << std::endl;
    std::cout << "-------- END INFOMATION --------" << std::endl;
}

void handleSearch(PhoneBook &phoneBook) {
    int targetIndex = -1;
    if (phoneBook.isEmpty())
        return;
    phoneBook.printPhoneBook();
    std::cout << "찾을 연락처의 인덱스를 입력하세요.\n";
    std::cin >> targetIndex;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (!phoneBook.checkValidIndex(targetIndex)) {
        std::cout << "잘못된 index값 입니다.\n";
        return;
    }
    phoneBook.searchContact(targetIndex);
}

int main(void) {
    std::string cmd;
    PhoneBook phoneBook;

    std::cout << "Start PhoneBook\n";

    while (std::cin.eof() == false) {
        std::cout << "\n-----------------------------------------\n";
        std::cout << "ADD SEARCH EXIT 명령어 중 하나를 입력하세요.\n";
        std::cout << ">> ";
        getline(std::cin, cmd);
        if (cmd == "ADD")
            handleAdd(phoneBook);
        else if (cmd == "SEARCH")
            handleSearch(phoneBook);
        else if (cmd == "EXIT")
            return (1);
        else
            std::cout << "ADD,SEARCH,EXIT 명령어만 사용할 수 있습니다.\n";
    }
    std::cout << "fin\n";
}
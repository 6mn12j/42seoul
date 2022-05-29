#include "PhoneBook.hpp"

void handleAdd(PhoneBook &phonebook)
{
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkSecret;

    std::cout << "firstName을 입력하세요.\n";
    getline(std::cin, firstName);
    std::cout << "lastName 입력하세요.\n";
    getline(std::cin, lastName);
    std::cout << "nickName 입력하세요.\n";
    getline(std::cin, nickName);
    std::cout << "phoneNumber 입력하세요.\n";
    getline(std::cin, phoneNumber);
    std::cout << "darkSecret 입력하세요.\n";
    getline(std::cin, darkSecret);

    phonebook.saveContact(firstName, lastName, nickName, phoneNumber,
                          darkSecret);
}

void handleSearch(PhoneBook phoneBook)
{
    (void)phoneBook;
    phoneBook.printPhoneBook();
}

int main(void)
{
    std::string cmd;
    PhoneBook phoneBook;

    while (getline(std::cin, cmd))
    {
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
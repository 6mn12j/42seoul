#include <iostream>
#include <string>

int main(int argc, char **argv) {
    std::string message;
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return (1);
    }
    for (int i = 1; argv[i]; i++)
        message += argv[i];

    for (int i = 0; message[i]; i++)
        message[i] = toupper(message[i]);
    std::cout << message;
}


#include <fstream>
#include <iostream>
#include <string>

std::string changeString(std::string str, std::string s1, std::string s2) {
    int length = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == s1[0]) {
            int j = i;
            length = 0;
            while (str[j] == s1[length] && str[j]) {
                length++;
                j++;
            }
            if (length == s1.length()) {
                std::string temp1 = str.substr(0, i);
                std::string temp2 = str.substr(i + s1.length());
                return temp1 + s2 + temp2;
            }
        }
    }
    return str;
}

void sed(std::ifstream &readFile, std::ofstream &writeFile, std::string s1,
         std::string s2) {

    std::string result = "";
    while (!readFile.eof()) {
        int i = 0;
        std::string str;
        getline(readFile, str);
        result += changeString(str, s1, s2);
        result += "\n";
    }
    writeFile << result;
    return;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cout << "Input is not enough" << std::endl;
        return 0;
    }

    std::string fileName = argv[1];
    std::ifstream readFile(fileName);

    if (readFile.fail()) {
        std::cerr << "Error read file" << std::endl;
        return 0;
    }

    std::ofstream writeFile(fileName + ".replace");

    if (writeFile.fail()) {
        std::cerr << "Error write file" << std::endl;
        readFile.close();
        return 0;
    }

    sed(readFile, writeFile, argv[2], argv[3]);
    readFile.close();
    writeFile.close();
    return 1;
}
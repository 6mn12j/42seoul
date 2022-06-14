
#include <fstream>
#include <iostream>
#include <string>

void handleSED(std::ifstream &readFile, std::ofstream &writeFile,
               std::string s1, std::string s2) {

    std::string line;
    std::string::size_type next = 0;
    while (getline(readFile, line)) {

        next = line.find(s1);
        if (next == std::string::npos)
            writeFile << line;
        else {
            writeFile << line.substr(0, next) << s2;
            std::string nextStr = line.substr(next + s1.length());
            next = nextStr.find(s1);
            while (next != std::string::npos) {
                writeFile << nextStr.substr(0, next) << s2;
                nextStr = nextStr.substr(next + s1.length());
                next = nextStr.find(s1);
            }
            writeFile << nextStr;
        }
        writeFile << std::endl;
    }

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

    handleSED(readFile, writeFile, argv[2], argv[3]);
    readFile.close();
    writeFile.close();
    return 1;
}
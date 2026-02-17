#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "./Scanner.h"

int main() {
    std::string fileName;
    std::cout << "Enter filename: ";
    std::cin >> fileName;

    std::ifstream InputFile(fileName);

    if (!InputFile) {
        std::cout << "Can not open file\n";
        return 1;
    }

    std::stringstream buffer;
    buffer << InputFile.rdbuf();
    std::string fileContent = buffer.str();
    //std::cout << fileContent;

    std::vector<Token> tokenList;
    Scanner scanner(fileContent);

    Token token = scanner.getNextToken();

    while (token.type != TokenType::END_OF_FILE) {
        tokenList.push_back(token);
        token = scanner.getNextToken();
    }

    for (auto x: tokenList) {
        std::cout << tokenTypeToString(x.type) << x.value << "\n";
    }
}       


#ifndef SCANNER_H
#define SCANNER_H

#include <string>
#include "Token.h"

class Scanner {
private:
    std::string input;
    size_t position;

    char currentChar();

    void getNextChar();
    void skipWhitespace();
    void skipComment();

    Token scanIdentifire();
    Token scanNumber();
    Token scanString();
    Token scanOperator();
    Token scanPunction();

    bool isLetter(char c);
    bool isDigit(char c);
    bool isOperator(char c);
    bool isComment();
    bool isSpace(char c);
    bool isPunction(char c);

public:
    Scanner(const std::string& soruce);
    Token getNextToken();
};

#endif

#include <unordered_set>
#include <string>
#include <iostream>
#include "./Scanner.h"

static const std::unordered_set<std::string> keywords = {
    "let",
    "where",
    "in",
    "within",
    "rec",
    "fn",
    "aug",
    "or",
    "and",
    "not",
    "gr",
    "ge",
    "ls",
    "le",
    "eq",
    "ne",
    "true",
    "false",
    "nil",
    "dummy"
};

Scanner::Scanner(const std::string& src)
    : input(src), position(0) {}

Token Scanner::getNextToken() {
    while (position < input.length()) {
        char c = currentChar();

        if (isspace(c)) {
            skipWhitespace();
            continue;
        }

        if (isComment()) {
            skipComment();
            continue;
        }

        if (isLetter(c)) {
            return scanIdentifire();
        }

        if (isDigit(c)) {
            return scanNumber();
        }

        if (c == '"') {
            return scanString();
        }

        if (isOperator(c)) {
            return scanOperator();
        }

        return Token(TokenType::ERROR, std::string(1, c));
    }
    return Token(TokenType::END_OF_FILE, "");
}

char Scanner::currentChar() {
    return input[position];
}

void Scanner::getNextChar() {
    position++;
}

bool Scanner::isLetter(char c) {
    return std::isalpha(c);
}

bool Scanner::isDigit(char c) {
    return std::isdigit(c);
}

bool Scanner::isOperator(char c) {
    std::string ops = "+-*/=<>&|.@:/~^$!#%[]{}()";
    return ops.find(c) != std::string::npos;
}

bool Scanner::isComment() {
    if (position + 1 >= input.length()) {
        return false;
    }
    std::cout << "Incomplete current\n";
    return input[position] == '/' && input[position + 1] == '/';
}

Token Scanner::scanIdentifire() {
    std::string tokenValue;

    while (position < input.length() && (isLetter(currentChar())) || (isDigit(currentChar())) || (currentChar() == '_')) {
        tokenValue += currentChar();
        getNextChar();
    }

    if (keywords.count(tokenValue)) {
        return Token(TokenType::KEYWORD, tokenValue);
    }

    return Token(TokenType::IDENTIFIER, tokenValue);
}

Token Scanner::scanNumber() {
    std::string tokenValue;

    while (position < input.length() && isDigit(currentChar())) {
        tokenValue += currentChar();
        getNextChar();
    }

    return Token(TokenType::INTEGER, tokenValue);
}

Token Scanner::scanString() {
    std::string tokenValue;
    getNextChar(); // skip '"'

    while (position <input.length() && currentChar() != '"') {
        tokenValue += currentChar();
        getNextChar();
    }

    if (position >= input.length()) {
        return Token(TokenType::ERROR, "Unterminated string");
    }

    getNextChar(); // skip '"' closing quote
    return Token(TokenType::STRING, tokenValue);
}

Token Scanner::scanOperator() {
    std::string tokenValue;

    while (position < input.length() && isOperator(currentChar())) {
        tokenValue += currentChar();
        getNextChar();
    }
    return Token(TokenType::OPERATOR, tokenValue);
}

void Scanner::skipComment() {
    while (position <input.length() && (currentChar() != '\n')) {
        getNextChar();
    }
}

void Scanner::skipWhitespace() {
    while (position <input.length() && isspace(currentChar())) {
        getNextChar();
    }
}

#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum class TokenType {
    IDENTIFIER,
    INTEGER,
    STRING,
    OPERATOR,
    KEYWORD,
    PUNCTUATION,
    ERROR,
    END_OF_FILE
};

struct Token {
    TokenType type;
    std::string value;

    Token(TokenType t, const std::string& v)
        : type(t), value(v) {}
};

std::string tokenTypeToString(TokenType type);

#endif

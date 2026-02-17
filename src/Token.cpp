#include "Token.h"

std::string tokenTypeToString(TokenType type) {
    switch (type) {
        case TokenType::IDENTIFIER: return "IDENTIFIER";
        case TokenType::INTEGER: return "INTEGER";
        case TokenType::STRING: return "STRING";
        case TokenType::KEYWORD: return "KEYWORD";
        case TokenType::OPERATOR: return "OPERATOR";
        case TokenType::PUNCTUATION: return "PUNCTUATION";
        case TokenType::END_OF_FILE: return "EOF";
        case TokenType::ERROR: return "ERROR";
        default: return "UNKNOWN";
    }
}

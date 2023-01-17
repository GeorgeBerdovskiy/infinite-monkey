#include <string>
#include "token.h"

using std::string;

Token::Token(TokenType type, string lexeme, string literal, int line) {
    Token::type = type;
    Token::lexeme = lexeme;
    Token::literal = literal;
    Token::line = line;
}

string Token::typeString() {
    switch (type) {
        case LEFT_PAREN:
            return "LEFT_PAREN";
        case RIGHT_PAREN:
            return "RIGHT_PAREN";
        default:
            return "SOME_TYPE";
    }
}

string Token::toString() {
    // TODO - Use the actual TokenType here
    return typeString() + " " + lexeme + " " + literal;
}
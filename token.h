#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include "token_type.h"

using std::string;

class Token {
    public:
        // NOTE - The 'literal' parameter is a Java Object in the series
        Token(TokenType type, string lexeme, string literal, int line) {
            Token::type = type;
            Token::lexeme = lexeme;
            Token::literal = literal;
            Token::line = line;
        }

        string toString() {
            // TODO - Use the actual TokenType here
            return "TYPE" + " " + lexeme + " " + literal;
        }
    private:
        TokenType type;
        string lexeme, literal;
        int line;
};

#endif
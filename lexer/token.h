#ifndef TOKEN_H
#define TOKEN_H

#include <string>
using std::string;

// Represents the different possible token types
enum TokenType {
    // Single-character tokens
    LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
    COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

    // One or two character tokens
    BANG, BANG_EQUAL,
    EQUAL, EQUAL_EQUAL,
    GREATER, GREATER_EQUAL,
    LESS, LESS_EQUAL,

    // Literals
    IDENTIFIER, STRING, NUMBER,

    // Keywords
    AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
    PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,

    END_OF_FILE
};

// Represents tokens, defined in 'token.cpp'
class Token {
    public:
        // NOTE - The 'literal' parameter is a Java Object in 'Crafting Interpreters'
        Token(TokenType type, string lexeme, string literal, int line);

        string toString();
    private:
		// Private class members
        TokenType type;
        string lexeme, literal;
        int line;

		// Converts token (enum) to string
		string typeString();
};

#endif
#include <string>
#include "token.h"

using std::string;

class Token {
    public:
        // NOTE - The 'literal' parameter is a Java Object in 'Crafting Interpreters'
        Token(TokenType type, string lexeme, string literal, int line) {
            Token::type = type;
            Token::lexeme = lexeme;
            Token::literal = literal;
            Token::line = line;
        }

        string toString() {
            // TODO - Use the actual TokenType here
            return typeString() + " " + lexeme + " " + literal;
        }
    private:
		// Private class members
        TokenType type;
        string lexeme, literal;
        int line;

		// Converts token (enum) to string
		string typeString() {
			switch (type) {
				case LEFT_PAREN:
					return "LEFT_PAREN";
				case RIGHT_PAREN:
					return "RIGHT_PAREN";
				default:
					return "SOME_TYPE";
			}
		}
};

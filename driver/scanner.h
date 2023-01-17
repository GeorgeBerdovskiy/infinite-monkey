#ifndef SCANNER_H
#define SCANNER_H

#include <string>
#include <vector>
#include "token.h"

using std::string;
using std::vector;

class Scanner {
	public:
		Scanner(string source);
	private:
		string source;
		vector<Token> tokens;
};

#endif
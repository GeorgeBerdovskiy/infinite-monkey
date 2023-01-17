#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

#include "../lexer/token.h"

using std::cout;
using std::cin;
using std::endl;

using std::string;
using std::ifstream;

// NOTE - This is a static class member in 'Crafting Interpreters'
bool hasError = false;

// TODO - Put somewhere else
std::string read_string_from_file(const std::string &file_path) {
    const std::ifstream input_stream(file_path, std::ios_base::binary);

    if (input_stream.fail()) {
        throw std::runtime_error("Failed to open file.");
    }

    std::stringstream buffer;
    buffer << input_stream.rdbuf();

    return buffer.str();
}

// Run source code provided as string
void run(string source) {
	cout << "Running source..." << endl;

	for (int i = 0; i < source.size(); i++) {
		cout << source[i] << endl;
	}
}

// Run file located at 'path'
void run_file(string path) {
	string source;
	source = read_string_from_file(path);
	run(source);

	if (hasError) {
		// TODO - Replace with nonzero exit code
		exit(0);
	}
}

// Listen for user prompts and run them one at a time
void run_prompt() {
	string line;

	do {
		cout << "> ";
		cin >> line;
		cout << "Your line has been read." << endl;

		// TODO - Run the line
		hasError = false;
	} while (line != "Exit.");

	cout << "Exiting..." << endl;
}

int main(int argc, char *argv[]) {
	if (argc > 2) {
		cout << "USAGE - 'lox [script]'." << endl;
	} else if (argc == 2) {
		run_file(argv[1]);
	} else {
		run_prompt();
	}

	return 0;
}
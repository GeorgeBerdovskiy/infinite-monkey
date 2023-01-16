#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

#include "token.h"

using std::cout;
using std::cin;
using std::endl;

using std::string;
using std::ifstream;

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

// TODO - Put somewhere else
std::vector<std::string> tokenize(string const &str, const char delimiter) {
	std::vector<string> output;

	std::stringstream ss(str);

	string s;
	while (getline(ss, s, delimiter)) {
		output.push_back(s);
	}

	return output;
}

// TODO - Put these somewhere else too
void report(int line, string where, string message) {
	cout << "[Line " << line << "] Error " << where << " - ";
	cout << message << endl;
}

void error(int line, string message) {
	report(line, "", "message");
}

// Run source code provided as string
void run(string source) {
	cout << "Running source..." << endl;

	std::vector<string> tokenized_source = tokenize(source, ' ');

	for (int i = 0; i < tokenized_source.size(); i++) {
		cout << tokenized_source[i] << endl;
	}
}

// Run file located at 'path'
void run_file(string path) {
	string source;
	source = read_string_from_file(path);
	run(source);
}

// Listen for user prompts and run them one at a time
void run_prompt() {
	string line;

	do {
		cout << "> ";
		cin >> line;
		cout << "Your line has been read." << endl;
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
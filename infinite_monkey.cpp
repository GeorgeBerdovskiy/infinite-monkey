#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;

using std::string;
using std::ifstream;

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
	string single_line;
	string source = "";

	ifstream file(path);

	if (file.is_open()) {
		while (getline(file, single_line)) {
			source = source + single_line;
		}
	} else {
		cout << "ERROR - File not found." << endl;
	}

	// TODO - Find a better replacement for this logic
	if (source != "") {
		// TODO - Remove when finished debugging
		cout << source << endl;
		run(source);
	}

	file.close();
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
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;

void run_file(string path) {
	cout << "- DEBUG - Running file with path '" << path << "'." << endl;

	string line;
	ifstream file(path);

	if (file.is_open()) {
		cout << "- DEBUG - File found." << endl;

		while (getline(file, line)) {
			cout << line << '\n';
		}
	} else {
		cout << "- DEBUG - File not found." << endl;
	}

	file.close();
}

void run_prompt() {
	cout << "- DEBUG - Listening for prompt." << endl;
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
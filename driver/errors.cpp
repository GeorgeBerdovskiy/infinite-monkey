#include <iostream>

using std::cout;
using std::endl;
using std::string;

class ErrorManager {
	public:
		ErrorManager() {
			// Do nothing for now
		}

		void report(int line, string where, string message) {
			cout << "[Line " << line << "] Error " << where << " - ";
			cout << message << endl;
		}

		void error(int line, string message) {
			report(line, "", "message");
		}
};
//rewrite clean to c++, review stuff

#include <iostream>
#include <string>
#include "mathey.h"

using namespace std;

int main()
{
	string mode; //For storing the string the user enters as desired mode of operation.
	cout << "Enter desired mode of operation:" << endl;
	while (true) {
		cout << "math> ";
		cin >> mode;
		if (mode.compare("calc") == 0) {
            clean();
			calc();
		}
		else if (mode.compare("matrix") == 0) {
			clean();
			cout << "math>matrix>" << endl;
			matrix();
		}
		else if (mode.compare("help") == 0 || mode.compare("?") == 0)
			help();
		else if (mode.compare("quit") == 0 || mode.compare("q") == 0 || mode.compare("exit") == 0)
			break;
		else
			cout << "I do not understand that command. Please type help to see"
			        "a list of commands, or quit to quit." << endl;
	}
	return 0;
}

void help()
{
	cout << "Enter a command to perform a desired function. Acceptable"
		 << " commands include:" << endl
		 << "calc	help	matrix	quit" << endl;
}

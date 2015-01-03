//rewrite clean to c++, review stuff

#include <iostream>
#include <string>
#include "mathey.hpp"

using namespace std;

void help(string);

int main()
{
	string mode; //For storing the string the user enters as desired mode of operation.
	cout << "Enter desired mode of operation:" << endl;
	while (true) { //Loop forever
		cout << "math> ";
		getline(cin,mode,'\n');
		if (mode == "calc") { //If the strings compare as equivalent
            clean(); // Call the cleanup crew
			calc();  // Call the function in calcey.c
		}
		else if (mode == "matrix") {
			clean();
			cout << "math>matrix>" << endl;
			matrix(); //Call the function in matrixey.c
		}
		else if (mode.substr(0,4) == "help") {
			help(mode.substr(4,string::npos));
		}
		else if (mode.substr(0,1) == "?")
			help(mode.substr(1,string::npos));
		else if (mode == "quit"|| mode == "q" || mode == "exit")
			break;
		else
			cout << "I do not understand that command. Please type help to see "
			        "a list of commands, or quit to quit." << endl;
	}
	return 0;
}

void help(string func)
{
	if (func == "")
		cout << "Enter a command to perform a desired function. Acceptable"
		     << " commands include:" << endl
		     << "calc	help	matrix	quit" << endl
		     << "You may also type help [command] for more advanced help"
		     << endl;
	else {
		if (func.substr(1,string::npos) == "calc") 
		// I have to use the substring because of the leading space.
			cout << "A program to perform basic calculator functions. NON" 
			     << " OPERATIONAL" << endl;
		else if (func.substr(1,string::npos) == "matrix")
			cout << "Program to row reduce a matrix" << endl;
		else if (func.substr(1,string::npos) == "quit")
			cout << "Quits the program. a simple 'q' is also acceptable"
			     << endl;
		else if (func.substr(1,string::npos) == "help")
			cout << "Provides general help text or specific help depending on"
			     << " whether or not [program] is included. '?' is an"
			     << " acceptable alternative." << endl;
		else
			cout << "That is not a valid help topic" << endl;
	}
}

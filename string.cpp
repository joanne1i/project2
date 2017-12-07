
//string.cpp
#include "string.h"
#include "list.h"
#include "node.h"
#include "expression.h"
#include <cctype>
#include <string>
#include <iostream>
int main() {
    int result1 = 0;
    char result2 = 0;
    string evalInfix = "";
    int input = 0;
    string infix1 = "";
   string infix2 = "";
    cout << "Please enter 1 for Expression Evaluation, 2 for Expression Comparison, or 3 to exit the program" << endl;
    cin >> input;
    cin.ignore();
    if(input != 1 && input != 2 && input != 3) { 
	    cout << "Invalid input." << endl;  
    }
    while(input == 1 || input == 2) {
      switch(input)
      {
      case 1:
	cout << "Enter infix: \n";
	getline(cin, evalInfix);
	try {
		result1 = Expression().eval(evalInfix);
		cout << "Result: " << result1 << endl;
	}
	catch(string error) {
		cerr << "bad expression: " << error << endl;
	}
	break;
      case 2:
	cout << "Enter infix 1: \n";
	getline(cin, infix1);
	cout << "Enter infix 2: \n";
	getline(cin, infix2);
	try {
		result2 = Expression().compare(infix1, infix2);
		cout << infix1  << " " << result2 << " " << infix2 << endl;
	}
	catch(string error) {
		cerr << "bad expression: " << error << endl;
	}
	break;
      }
	cout << "Please enter 1 for Expression Evaluation, 2 for Expression Comparison, or 3 to exit the program" << endl;
        cin >> input;
	cin.ignore();
	    if(input != 1 && input != 2 && input != 3) { 
	    cout << "Invalid input." << endl;  
	    }

    }	
    cout << "Goodbye!" << endl;
	return 0;
      
}  


//string.cpp
#include "string.h"
#include "node.h"
#include "expression.h"
#include <cctype>
#include <iostream>
int main() {
  /*
    string infix_str;
    Expression* my_exp = new Expression();

    cout << "Please enter full parenthesized infix expression: \n";
    getline(cin, infix_str);
    my_exp->store_exp(infix_str);

    cout << endl << "infix: " << my_exp->infixString() << endl
        << "prefix: " << my_exp->prefixString() << endl
        << "postfix: " << my_exp->postfixString() << endl;
  */
    string infix;
    int input;
    string infix1, infix2;
    cout << "Please enter 1 for Expression Evaluation, 2 for Expression Comparison, or 3 to exit the program" << endl;
    cin >> input;
    switch(input)
      {
      case 1:
	cout << "Enter infix: \n";
	getline(cin, infix);
	cout << "Result: " << Expression().eval(infix) << endl;
	break;
      case 2:
	cout << "Enter infix 1: \n";
	getline(cin, infix1);
	cout << "Enter infix 2: \n";
	getline(cin, infix2);
	if (Expression().isEqual(infix1, infix2))
	  {
	    cout << infix1 << " is equal to " << infix2;
	  }
	else
	  {
	    cout << infix1 << " is not equal to " << infix2;
	  }
	break;
      case 3:
	cout << "Goodbye!" << endl;
	return 0;
      }

 
}

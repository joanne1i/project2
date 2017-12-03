#include "node.h"
#include "list.h"
#include "expression.h"
#include "string.h"
#include <iostream>
#include <cctype>

using namespace std;
int main() {
  /*  string infix_str;
    Expression* my_exp = new Expression();

    cout << "Please enter full parenthesized infix expression: \n";
    getline(cin, infix_str);
    my_exp->store_exp(infix_str);

    cout << endl << "infix: " << my_exp->infixString() << endl
        << "prefix: " << my_exp->prefixString() << endl
        << "postfix: " << my_exp->postfixString() << endl;
*/
 string infix;
// Expression* my_exp = new Expression();
 cout << "Enter infix: \n";
 getline(cin, infix);
 cout << "result: " << Expression().eval(infix) << endl;
    return 0;
}

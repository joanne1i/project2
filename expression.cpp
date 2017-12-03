#include "list.h"
#include "node.h"
#include "expression.h"
#include <string>
#include <cctype>
#include <stack>
#include <cstdlib>
using namespace std;

Expression::Expression() {
    this->head = NULL;
}

void Expression::store_exp(string infix_str) {
    this->head = build_list(infix_str);
}

string Expression::infixString() const {
    return head->print_infix();
}

string Expression::prefixString() const {
    return head->print_prefix();
}

string Expression::postfixString() const {
    return head->print_postfix();
}

bool balanced(string exp) {
	string temp = exp;
	for(int j = 0; j < temp.length(); j++) {
		if(temp[j] == ' ')
		       temp.erase(j,1);
	}
	stack<char> s;
	for(int k = 0; k < temp.length(); k++) {
		if(temp[k] == '(') 
			s.push(temp[k]);
		if(temp[k] == ')') {
			if(temp[k] == 0)
				return false;
			else
				s.pop();
		}
	}
	//cout << "og length " << exp.length() << endl;
	//cout << "new length " << temp.length() << endl;
	return s.empty();
}
				
int Expression::eval(string exp) {
	if(!balanced(exp)) 
		throw string("missing parentheses");
	if(exp[exp.length()-1] != ')')
		throw string("missing parentheses");
	if(exp[0] != '(')
		throw string("missing parentheses");
	int left = 0;
	int right = 0;
	int result = 0;
	char oper = '\0';
	stack<int> nums;
	stack<char> op;
	for(int i = 0; i < exp.length(); i++) {
		if(isdigit(exp[i]))
			nums.push((exp[i]-'0'));
		else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') 
			op.push(exp[i]);
		else if(exp[i] == '(') {
		}
		else if(exp[i] == ')') {
			if(nums.empty())
				throw string("missing Rnumber");

			right = nums.top();
			nums.pop();
			if(op.empty()) 
				throw string("missing operator");
			oper = op.top();
			op.pop();
			if(nums.empty()) 
				throw string("missing Lnumber");
			left = nums.top();
			nums.pop();

			switch(oper) {
				case '+':
					nums.push(left + right);
					break;
				case '-':
					nums.push(left - right);
					break;
				case '*': 
					nums.push(left  * right);
					break;
				case '/':
					nums.push(left / right);
					break;
			}
		}
	}
		result = nums.top();
		return result;
}

char Expression::compare(string infix1, string infix2)
{	
	// checks if infix1 is balanced
  	if(!balanced(infix1))
                throw string("missing parentheses");
        if(infix1[infix1.length()-1] != ')')
                throw string("missing parentheses");
        if(infix1[0] != '(')
                throw string("missing parentheses");
	// checks if infix2 is balanced
	if(!balanced(infix2))
                throw string("missing parentheses");
        if(infix2[infix2.length()-1] != ')')
                throw string("missing parentheses");
        if(infix2[0] != '(')
                throw string("missing parentheses");
	// if balanced, it compares
	if(eval(infix1) > eval(infix2)) 
	  return '>';
 	else if(eval(infix1) < eval(infix2))
	  return '<';
 	else
	  return '=';
}

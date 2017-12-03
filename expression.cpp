#include "list.h"
#include "node.h"
#include "expression.h"
#include <string>
#include <cctype>
#include <stack>
#include <stdexcept>
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

bool Expression::balanced(string exp) {
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
	if(!balanced(exp)) {
            cout << "parentheses not balanced" << endl;
            return 0;
	    }
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
			if(nums.empty()) {
				cout << "error - need rnum" << endl;
				return 0;
			}

			right = nums.top();
			nums.pop();
			if(op.empty()) {
				cout << "error - need operator" << endl;
				return 0;
			}
			oper = op.top();
			op.pop();
			if(nums.empty()) {
				cout << "error - need lnum" << endl;
				return 0;
			}
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

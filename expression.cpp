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


int Expression::eval(string exp) {
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
				return 0;//	throw invalid_argument("error - need rnum");

			right = nums.top();
			nums.pop();
			if(op.empty())
				return 0;//throw invalid_argument("error - need operator");
			oper = op.top();
			op.pop();
			if(nums.empty())
				return 0; //throw invalid_argument("error - need lnum");
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

#include "list.h"
#include "node.h"
#include "expression.h"
#include <string>
#include <cctype>
#include <stack>
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

int Expression::eval(string infix)  {
	int left = 0;
	int right = 0;
	int result = 0;
	stack<int> nums;
//	stack<char> ops;
	for(int i = 0; i < infix.length(); i++) {
		if(isdigit(infix[i])) 
			nums.push((infix[i]- '0'));
		else {
			switch(infix[i]) 
			{
				case '+':
					right = nums.top();
					nums.pop();
					left = nums.top();
					nums.pop();
					nums.push(left + right);
					break;
				case '-':
					right = nums.top();
					nums.pop();
					left = nums.top();
					nums.pop();
					nums.push(left - right);
					break;
				case '*':
					right = nums.top();
					nums.pop();
					left = nums.top();
					nums.pop();
					nums.push(left * right);
					break;
				case '/':
					right = nums.top();
					nums.pop();
					left = nums.top();
					nums.pop();
					nums.push(left / right);
					break;
			}
		}
	}
	return nums.top();
}

	

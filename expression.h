#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <string>
#include "node.h"


using namespace std;

class Expression {
    public:
        Expression();

        void store_exp(string infix_str);

        string infixString() const;
        string prefixString() const;
        string postfixString() const;
	int eval(string exp);
	char compare(string infix1, string infix2);
    private:
        Node* head;
};

#endif

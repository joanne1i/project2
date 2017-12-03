//expression.h
#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <string>
#include "node.h"
//must use standard library stack class
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iostream>


using namespace std;

class Expression {
    public:
        Expression();

        void store_exp(string infix_str);
	
        string infixString() const;
        string prefixString() const;
        string postfixString() const;
	//write these two
	int eval(string exp);
	bool balanced(string exp);
	bool isEqual(string infix1, string infix2);
    private:
        Node* head;
};

#endif 

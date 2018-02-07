/*
 * File: subexpression.cpp
 * Author: David Robbins
 * Date: 2017.12.14
 * Purpose: 
 */

#include <iostream>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "plus.h"
#include "minus.h"
#include "times.h"
#include "divide.h"
#include "lessthan.h"
#include "greaterthan.h"
#include "equalto.h"
#include "or.h"
#include "and.h"

SubExpression::SubExpression(Expression* left, Expression* right)
{
    this->left = left;
    this->right = right;
}

Expression* SubExpression::parse()
{
    Expression* left;
    Expression* right;
    char operation, paren;
    
    left = Operand::parse();
    cin >> operation;
    right = Operand::parse();
    cin >> paren;
    switch (operation)
    {
        case '+':
            return new Plus(left, right);
        case '-':
            return new Minus(left, right);
        case '*':
            return new Times(left, right);
        case '/':
            return new Divide(left, right);
        case '<':
            return new LessThan(left, right);
        case '>':
            return new GreaterThan(left, right);
        case '=':
            return new EqualTo(left, right);
        case '|':
            return new Or(left, right);
        case '&':
            return new And(left, right);    
    }
    return 0;
}

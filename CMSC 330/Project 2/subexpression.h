/*
 * File: subexpression.h
 * Author: David Robbins
 * Date: 2017.12.14
 * Purpose: 
 */

#ifndef SUBEXPRESSION_H
#define SUBEXPRESSION_H

class SubExpression: public Expression
{
public:
    SubExpression(Expression* left, Expression* right);
    static Expression* parse();
protected: 
    Expression* left;
    Expression* right;
};

#endif /* SUBEXPRESSION_H */


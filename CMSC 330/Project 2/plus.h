/*
 * File: plus.h
 * Author: David Robbins
 * Date: 2017.12.14
 * Purpose: 
 */

#ifndef PLUS_H
#define PLUS_H

class Plus: public SubExpression
{
public:
    Plus(Expression* left, Expression* right):
        SubExpression(left, right)
    {
    }
    int evaluate()
    {
       return left->evaluate() + right->evaluate();
    }
};

#endif /* PLUS_H */


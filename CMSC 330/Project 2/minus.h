/*
 * File: minus.h
 * Author: David Robbins
 * Date: 2017.12.14
 * Purpose: 
 */

#ifndef MINUS_H
#define MINUS_H

class Minus: public SubExpression
{
public:
    Minus(Expression* left, Expression* right):
        SubExpression(left, right)
    {
    }
    int evaluate()
    {
       return left->evaluate() - right->evaluate();
    }
};

#endif /* MINUS_H */


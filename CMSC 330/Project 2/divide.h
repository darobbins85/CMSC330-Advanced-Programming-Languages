/*
 * File: divide.h
 * Author: David Robbins
 * Date: 2017.12.14
 * Purpose: 
 */

#ifndef DIVIDE_H
#define DIVIDE_H

class Divide: public SubExpression
{
public:
    Divide(Expression* left, Expression* right):
        SubExpression(left, right)
    {
    }
    int evaluate()
    {
       return left->evaluate() / right->evaluate();
    }
};

#endif /* DIVIDE_H */


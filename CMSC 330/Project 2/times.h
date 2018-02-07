/*
 * File: times.h
 * Author: David Robbins
 * Date: 2017.12.14
 * Purpose: 
 */

#ifndef TIMES_H
#define TIMES_H

class Times: public SubExpression
{
public:
    Times(Expression* left, Expression* right):
        SubExpression(left, right)
    {
    }
    int evaluate()
    {
       return left->evaluate() * right->evaluate();
    }
};

#endif /* TIMES_H */


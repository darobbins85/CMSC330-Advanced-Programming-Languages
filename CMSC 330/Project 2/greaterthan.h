/*
 * File: greaterthan.h 
 * Author: David Robbins
 * Date: 2017.12.14
 * Purpose: 
 */

#ifndef GREATERTHAN_H
#define GREATERTHAN_H

class GreaterThan : public SubExpression
{
public:
   GreaterThan(Expression* left, Expression* right) :
       SubExpression(left, right)
   {
   }
   int evaluate()
   {
       if (left->evaluate() > right->evaluate())
           return 1;
       else
           return 0;
   }
};

#endif /* GREATERTHAN_H */


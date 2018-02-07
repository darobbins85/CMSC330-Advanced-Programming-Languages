/*
 * File: lessthan.h
 * Author: David Robbins
 * Date: 2017.12.14
 * Purpose: 
 */

#ifndef LESSTHAN_H
#define LESSTHAN_H

class LessThan : public SubExpression
{
public:
   LessThan(Expression* left, Expression* right) :
       SubExpression(left, right)
   {
   }
   int evaluate()
   {
       if (left->evaluate() < right->evaluate())
           return 1;
       else
           return 0;
   }
};

#endif /* LESSTHAN_H */


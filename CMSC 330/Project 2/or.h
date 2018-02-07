/*
 * File: or.h
 * Author: David Robbins
 * Date: 2017.12.14
 * Purpose: 
 */

#ifndef OR_H
#define OR_H

class Or : public SubExpression
{
public:
   Or(Expression* left, Expression* right) :
       SubExpression(left, right)
   {
   }
   int evaluate()
   {
       if (left->evaluate() == 1 || right->evaluate() == 1)
           return 1;
       else
           return 0;
   }
};

#endif /* OR_H */


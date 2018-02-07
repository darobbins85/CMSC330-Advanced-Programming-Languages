/*
 * File: and.h
 * Author: David Robbins
 * Date: 2017.12.14
 * Purpose: 
 */

#ifndef AND_H
#define AND_H

class And : public SubExpression
{
public:
   And(Expression* left, Expression* right) :
       SubExpression(left, right)
   {
   }
   int evaluate()
   {
       if (left->evaluate() == 1 && right->evaluate() == 1)
           return 1;
       else
           return 0;
   }
};

#endif /* AND_H */


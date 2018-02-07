/*
 * File: equalto.h
 * Author: David Robbins
 * Date: 2017.12.14
 * Purpose: 
 */

#ifndef EQUALTO_H
#define EQUALTO_H

class EqualTo : public SubExpression
{
public:
   EqualTo(Expression* left, Expression* right) :
       SubExpression(left, right)
   {
   }
   int evaluate()
   {
       if (left == right)
           return 1;
       else
           return 0;
   }
};

#endif /* EQUALTO_H */


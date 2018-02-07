/*
 * File: operand.h
 * Author: David Robbins
 * Date: 2017.12.14
 * Purpose: 
 */

#ifndef OPERAND_H
#define OPERAND_H

class Operand: public Expression
{
public:
    static Expression* parse();
};

#endif /* OPERAND_H */


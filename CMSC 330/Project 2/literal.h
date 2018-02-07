/*
 * File: literal.h
 * Author: David Robbins
 * Date: 2017.12.14
 * Purpose: 
 */

#ifndef LITERAL_H
#define LITERAL_H

class Literal: public Operand
{
public:
    Literal(int value)
    {
        this->value = value;
    }
    int evaluate()
    {
        return value;
    }
private:
    int value;
};

#endif /* LITERAL_H */


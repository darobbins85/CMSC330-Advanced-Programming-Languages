/*
 * File: variable.h
 * Author: David Robbins
 * Date: 2017.12.14
 * Purpose: 
 */

#include <string>
using namespace std;

#ifndef VARIABLE_H
#define VARIABLE_H

class Variable: public Operand
{

public:
    Variable(string name)
    {
        this->name = name;
    }
    int evaluate() override;
private:
    string name;
};

#endif /* VARIABLE_H */


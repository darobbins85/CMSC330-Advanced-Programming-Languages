/*
 * File: symboltable.h
 * Author: David Robbins
 * Date: 2017.12.14
 * Purpose: 
 */

#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

class SymbolTable
{
public:
    SymbolTable() {}
    void insert(string variable, double value);
    double lookUp(string variable) const;
private:
    struct Symbol
    {
        Symbol(string variable, double value)
        {
            this->variable = variable;
            this->value = value;
        }
        string variable;
        double value;
    };
    vector <Symbol> elements;
};

#endif /* SYMBOLTABLE_H */


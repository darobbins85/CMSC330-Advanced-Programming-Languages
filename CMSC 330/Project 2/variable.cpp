/*
 * File: variable.cpp
 * Author: David Robbins
 * Date: 2017.12.14
 * Purpose: 
 */

#include <vector>
using namespace std;

#include "expression.h"
#include "operand.h"
#include "variable.h"
#include "symboltable.h"

extern SymbolTable symbolTable;

int Variable::evaluate()
{
    return symbolTable.lookUp(name);
}
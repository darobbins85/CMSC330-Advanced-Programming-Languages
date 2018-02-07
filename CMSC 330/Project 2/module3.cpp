/*
 * File: module3.cpp
 * Author: David Robbins
 * Date: 2017.12.14
 * Purpose: 
 */

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ios>

using namespace std;


#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"
#include "makeName.h"

SymbolTable symbolTable;

void parseAssignments();



int main()
{   
    int count = 0;
    while(makeName(count) != ""){
        string line = makeName(count);
        cout << "" << line << endl;
        count++;
        
        Expression* expression;
        char paren, comma;
        cout << "Enter expression: ";
        cin >> paren;
        expression = SubExpression::parse();
        cin >> comma;
        parseAssignments();
        cout << "Value = " << expression->evaluate() << "\n" << endl;
    } 
    
    
}
void parseAssignments()
{
   char assignop, delimiter;
   string variable;
   double value;
   do
   {
       variable = parseName();
       cin >> ws >> assignop >> value >> delimiter;
       symbolTable.insert(variable, value);
   } while (delimiter == ',');
}



/*
 * File: parse.cpp
 * Author: David Robbins
 * Date: 2017.12.14
 * Purpose: 
 */

#include <cctype>
#include <iostream>
#include <string>
using namespace std;

#include "parse.h"

string parseName()
{
   char alnum;
   string name = "";

   cin >> ws;
   while (isalnum(cin.peek()))
   {
       cin >> alnum;
       name += alnum;
   }
   return name;
}
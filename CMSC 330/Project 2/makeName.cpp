/*
 * File: makeName.cpp
 * Author: David Robbins
 * Date: 2017.12.16
 * Purpose: 
 */

#include <cctype> 
#include <iostream> 
#include <string> 
#include <fstream>
using namespace std;

#include "makeName.h"

string arr[100];

string makeName(int k)
{
    ifstream inFile;
    inFile.open("test.txt");
    
    if(inFile.fail()){
        cerr << "Error opening" << endl;
        exit(1);
    }
    
    string line;
    
    int i = 0;
    
    
    while(inFile.good()){
        
        while(getline(inFile, line)){
            arr[i] = line;
            i++;
        }
        
        /*for(int j = 0; i > j; j++){
            cout << "" << arr[j] << "\n" << endl;
        }*/
        inFile.close();
    }
    
    return arr[k];
}


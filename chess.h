#include<string>
#include"counter.h"
using namespace std;
#pragma once

#ifndef  CHESS_H
#define  CHESS_H

class Chess {
public:
    Chess();
    ~Chess();
    void set_location(string, int*);
    
    int** get();
    int** score();
    void display();
    void fresh(string);
    void ClearchessArray();
   
private:
    int** thischess;
    int** thisscore;
};

#endif
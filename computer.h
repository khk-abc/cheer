#include"player.h"
#include"chess.h"
#include"counter.h"
#include"checker.h"

#include<string>
using namespace std;

#pragma once
#ifndef  COMOUTER_H
#define  COMOUTER_H

class Computer :public Player {
public:
    Computer();
    ~Computer();
    int* get_location(Chess);
    void set_name(string);
    string get_name();
    void drop(Chess, int*);
    void set_score(Chess,Counter,Checker);


private:
    string name;
    int location[2];

};

#endif
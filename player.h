#include<string>
#include"chess.h"
#include"checker.h"
#include"counter.h"

using namespace std;
#pragma once
#ifndef  PLAYER_H
#define  PLAYER_H

class Player {
public:
    Player();
    ~Player();
    
    virtual int* get_location(Chess);
    virtual  void set_name(string);
    virtual string get_name();
    virtual void drop(Chess, int*);
    virtual void set_score(Chess, Counter, Checker);

private:
    string name;
    int location[2];

};

#endif
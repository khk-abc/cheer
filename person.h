#include"player.h"
#include"chess.h"
#include<string>
using namespace std;

#pragma once
#ifndef  PERSON_H
#define  PERSON_H

class Person :public Player {
public:
    Person();
    ~Person();
    int* get_location(Chess);
    void set_name(string);
    string get_name();
    void drop(Chess, int*);

private:
    string name;
    int location[2];
};

#endif
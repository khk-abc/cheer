#include"counter.h"
#include<string>
using namespace std;
#pragma once
#ifndef  CHECKER_H
#define  CHECKER_H

class Checker {//game类，进行棋盘打印以及赢家检测或黑子禁手检测
public:
    Checker();
    ~Checker();
    int check(int**, Counter, int, int,string,string);
    int all_check(int**,  Counter, string);
};

#endif
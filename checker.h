#include"counter.h"
#include<string>
using namespace std;
#pragma once
#ifndef  CHECKER_H
#define  CHECKER_H

class Checker {//game�࣬�������̴�ӡ�Լ�Ӯ�Ҽ�����ӽ��ּ��
public:
    Checker();
    ~Checker();
    int check(int**, Counter, int, int,string,string);
    int all_check(int**,  Counter, string);
};

#endif
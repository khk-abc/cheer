#include<string>
using namespace std;
#pragma once
#ifndef  COUNTER_H
#define  COUNTER_H


class Counter {
public:
    Counter();
    ~Counter();
    int* left(int**, int, int, string);
    int* right(int**, int, int, string);
    int* up(int**, int, int, string);
    int* down(int**, int, int, string);
    int* left_up(int**, int, int, string);
    int* right_up(int**, int, int, string);
    int* right_down(int**, int, int, string);
    int* left_down(int**, int, int, string);
};

#endif
#include"counter.h"
#include"player.h"
#include"Chess.h"
#include"Checker.h"
#include"Counter.h"
#include<string>
using namespace std;

#pragma once
#ifndef  GAME_H
#define  GAME_H

class Game {//game类，进行棋盘打印以及赢家检测或黑子禁手检测
public:
    Game();
    ~Game();
    int mode(Player&,Player&);
   // int check(int **,Checker,Counter,string);
   /* int mode1();
    int mode2();
    int mode3();*/
    //void turn(Player, Player);

};

#endif
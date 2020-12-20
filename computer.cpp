#include"computer.h"
#include"checker.h"
#include <string>
#include <iostream>

using namespace std;

Computer::Computer() {
    location[0] = 0;
    location[1] = 0;
}
int* Computer::get_location(Chess chess)
{
    /*
    char place0;
    int place1;
    cout << "Computer input:";
    cin >> place0 >> place1;
    location[0] = int(place0 - 97);
    location[1] = 15 - place1; //int(place[1]-48);
    while (location[0] < 0 || location[0] >= 15 || location[1] < 0 || location[1] >= 15 || 
        chess.get()[location[1]][location[0]] <= 0 || chess.get()[location[1]][location[0]] >= 10)
    {
        cout << "输入不合法，请重新输入：";
        cin >> place0 >> place1;
        location[0] = int(place0 - 97);
        location[1] = 15 - place1; //int(place[1]-48);
    }
    */

    /*
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (chess.get()[i][j] <= 0 || chess.get()[i][j] >= 10) {
                continue;
            }
            else{
                    location[0] = j;
                    location[1] = i;
                    break;
     
            }
        }
    }
    */
    location[0] = rand() % 15;
    location[1] = rand() % 15;
    while (chess.get()[location[1]][location[0]] <= 0 || chess.get()[location[1]][location[0]] >= 10) {
        location[0] = rand() % 15;
        location[1] = rand() % 15;
    }
    
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (chess.get()[i][j] <= 0 || chess.get()[i][j] >= 10) {
                continue;
            }
            else if(chess.score()[location[1]][location[0]]< chess.score()[i][j]){
                location[1] = i;
                location[0] = j;
            }
        }
    }
    return location;
}

void Computer::set_name(string myname) {
    name = myname;

}

void Computer::set_score(Chess chess,Counter counter,Checker checker) {
    /*
    int lefter[2] = {0};
    int righter[2] = {0 };
    int uper[2] = { 0};
    int downer[2] = { *counter.down(chess, i, j, name=="yes"?"no":"yes") , *(counter.down(chess, i, j, name=="yes"?"no":"yes") + 1) };
    int left_uper[2] = { *counter.left_up(chess, i, j, name=="yes"?"no":"yes") , *(counter.left_up(chess, i, j, name=="yes"?"no":"yes") + 1) };
    int left_downer[2] = { *counter.left_down(chess, i, j, name=="yes"?"no":"yes") , *(counter.left_down(chess, i, j, name=="yes"?"no":"yes") + 1) };
    int right_uper[2] = { *counter.right_up(chess, i, j, name=="yes"?"no":"yes") , *(counter.right_up(chess, i, j, name=="yes"?"no":"yes") + 1) };
    int right_downer[2] = { *counter.right_down(chess, i, j, name=="yes"?"no":"yes") , *(counter.right_down(chess, i, j, name=="yes"?"no":"yes") + 1) };
    */
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (chess.get()[i][j] >= 1 && chess.get()[i][j] <= 9) {
                int lefter[2] = { *counter.left(chess.get(), i, j, name=="yes"?"no":"yes") , *(counter.left(chess.get(), i, j, name=="yes"?"no":"yes") + 1) };
                int righter[2] = { *counter.right(chess.get(), i, j, name=="yes"?"no":"yes") , *(counter.right(chess.get(), i, j, name=="yes"?"no":"yes") + 1) };
                int uper[2] = { *counter.up(chess.get(), i, j, name=="yes"?"no":"yes") , *(counter.up(chess.get(), i, j, name=="yes"?"no":"yes") + 1) };
                int downer[2] = { *counter.down(chess.get(), i, j, name=="yes"?"no":"yes") , *(counter.down(chess.get(), i, j, name=="yes"?"no":"yes") + 1) };
                int left_uper[2] = { *counter.left_up(chess.get(), i, j, name=="yes"?"no":"yes") , *(counter.left_up(chess.get(), i, j, name=="yes"?"no":"yes") + 1) };
                int left_downer[2] = { *counter.left_down(chess.get(), i, j, name=="yes"?"no":"yes") , *(counter.left_down(chess.get(), i, j, name=="yes"?"no":"yes") + 1) };
                int right_uper[2] = { *counter.right_up(chess.get(), i, j, name=="yes"?"no":"yes") , *(counter.right_up(chess.get(), i, j, name=="yes"?"no":"yes") + 1) };
                int right_downer[2] = { *counter.right_down(chess.get(), i, j, name=="yes"?"no":"yes") , *(counter.right_down(chess.get(), i, j, name=="yes"?"no":"yes") + 1) };
            


            if (checker.check(chess.get(), counter, i, j, name, "pulish")== 2) {//如果禁手需要惩罚
                chess.score()[i][j] = -10000;
            }

            if (checker.check(chess.get(), counter, i, j, name, "pulish") == 10 ) {//返回10是指白子活三，因为无禁手限制，所以进行奖赏
                chess.score()[i][j] = 100;
            }

            if (checker.check(chess.get(), counter, i, j, name, "pulish") == 11) {//返回11是指白子活四，因为无禁手限制，所以进行奖赏
                chess.score()[i][j] = 150;
            }

            if (checker.check(chess.get(), counter, i, j, name, "pulish") == 1) {//返回1有玩家赢，奖赏应该大一些
                chess.score()[i][j] = 50000;
            }

            int directions[8][2] = {
                {lefter[0],lefter[1]},
                {righter[0],righter[1]},
                {uper[0],uper[1]},
                {downer[0],downer[1]},
                {left_downer[0],left_downer[1]},
                {right_uper[0],right_uper[1]},
                {left_uper[0],left_uper[1]},
                {right_downer[0],right_downer[1]}
            };
            int lines[4] = { lefter[0] +righter[0], uper[0] + downer[0], left_downer[0] + right_uper[0], left_uper[0] + right_downer[0] };
            int count4 = 0;



            //计算8个方向
            for (int k = 0; k < 8; k++) {
                switch (directions[k][0]) {
                case 0:
                    break;
                case 1:
                    if(directions[k][1]==0){
                        chess.score()[i][j] += 1;
                        break;
                    }
                    else {
                        chess.score()[i][j] += 10;
                        break;
                    }
                case 2:
                    if (directions[k][1] == 0) {
                        chess.score()[i][j] += 30;
                        break;
                    }
                    else {
                        chess.score()[i][j] += 60;
                        break;
                    }
                case 3:
                    if (directions[k][1] == 0) {
                        chess.score()[i][j] += 100;
                        break;
                    }
                    else {
                        chess.score()[i][j] += 200;
                        break;
                    }
                case 4:
                    if (directions[k][1] == 0) {
                        chess.score()[i][j] += 500;
                        break;
                    }
                    else {
                        chess.score()[i][j] += 1000;
                        break;
                    }
                default:
                    chess.score()[i][j] += 400;
                }
            }
            
           
            for (int q = 0; q < 4; q++) {
                switch (lines[q]) {
                case 0:
                    break;
                case 1:
                    chess.score()[i][j] += 5;
                    break;
                case 2:
                    chess.score()[i][j] += 30;
                    break;
                case 3:
                    chess.score()[i][j] += 70;
                    break;
                case 4:
                    chess.score()[i][j] += 400;
                    break;
                default:
                    chess.score()[i][j] += 400;
                }
            }
            }
        }
    }
    return;
}




void Computer::drop(Chess chess, int* location)
{
    chess.set_location(this->name, location);
}

string Computer::get_name() {
    return name;

}

Computer::~Computer() {

}
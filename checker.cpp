#include <string>
#include<iostream>
#include"checker.h"

using namespace std;
Checker::Checker() {

}



int Checker::check(int** chess, Counter counter, int row, int col,string name,string mode="check") {
	int lefter[2] = { *counter.left(chess, row, col, name) , *(counter.left(chess, row, col, name)+1) };
	int righter[2] = { *counter.right(chess, row, col, name) , *(counter.right(chess, row, col, name) + 1) };
	int uper[2] = { *counter.up(chess, row, col, name) , *(counter.up(chess, row, col, name) + 1) };
	int downer[2] = { *counter.down(chess, row, col, name) , *(counter.down(chess, row, col, name) + 1) };
	int left_uper[2] = { *counter.left_up(chess, row, col, name) , *(counter.left_up(chess, row, col, name) + 1) };
	int left_downer[2] = { *counter.left_down(chess, row, col, name) , *(counter.left_down(chess, row, col, name) + 1) };
	int right_uper[2] = { *counter.right_up(chess, row, col, name) , *(counter.right_up(chess, row, col, name) + 1) };
	int right_downer[2] = { *counter.right_down(chess, row, col, name) , *(counter.right_down(chess, row, col, name) + 1) };
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
	int lines[4] = {
		lefter[0] + righter[0],
		uper[0]  + downer[0],
		left_uper[0] + right_downer[0],
		right_uper[0] + left_downer[0]
	};
	
	int longconnect = 0;


	
	//判断活三
	int life_three = 0;
	for (int i = 0; i < 8; i++) {
		if (directions[i][0]+1 == 3 && directions[i][1] == 1) {
			life_three += 1;
		}
	}
	for (int i = 0; i + 1 < 8; i=i+2) {
		if ((directions[i][0] + directions[i + 1][0] +1== 3 && directions[i][0]!=0 && directions[i+1][0]!=0) && (directions[i][1] + directions[i + 1][1] != 0)) {
			life_three += 1;
		}
	}

	if (life_three >= 2 ) {
		if (name == "yes") {
			if (mode == "check") {
				cout << "活三禁手!" << endl;
			}
			return 2;//活三禁手
		}
		if (name == "no") {
			return 10;
		}
	}



	//判断活四
	int life_four = 0;
	for (int i = 0; i < 8; i++) {
		if (directions[i][0] +1== 4 && directions[i][1] == 1) {
			life_four += 1;
		}
	}
	for (int i = 0; i + 1 < 8; i+=i+2) {
		if ((directions[i][0] + directions[i + 1][0] + 1 == 4 && directions[i][0] != 0 && directions[i + 1][0] != 0) && (directions[i][1] + directions[i + 1][1] != 0)) {
			life_four += 1;
		}
	}

	if (life_four >= 2 ) {
		if (name == "yes") {
			if (mode == "check") {
				cout << "活四禁手!" << endl;
			}
			return 2;//活四禁手
		}
		if (name == "no") {
			return 11;
		}
	}
	


	//判断是否长连
	for (int i = 0; i < 4; i++) {
		if (name == "yes") {
			if (lines[i] + 1 >= 6) {
				longconnect += 1;
				if (longconnect >= 1) {
					if (mode == "check") {
						cout << "执黑者长连禁手，执白者赢!" << endl;
					}
					return 2;//长连禁手
				}
			}
		}
	}


	//判断是否有赢家
	for (int i = 0; i < 4; i++) {
		if (lines[i] + 1 == 5 || (longconnect<=1 && lines[i]+1>5) || (name=="no" && lines[i]+1>=5)) {
			if (name == "yes") {
				cout << "执黑者获胜!" << endl;
			}
			else {
				cout << "执白者获胜!" << endl;
			}
			return 1;//有玩家获胜
		}
	}
	return 0;
}

int  Checker::all_check(int** thischess, Counter counter, string name) {
	//int** thischess = chess.get();
	int flag = 0;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			if (name == "yes") {
				if (thischess[i][j] == 21 || thischess[i][j] == 20) {
					flag = check(thischess, counter, i, j, name);
					if (flag != 0) {
						return flag;
					}
				}
			}
			else {
				if (thischess[i][j] == 11 || thischess[i][j] == 10) {
					flag = check(thischess, counter, i, j, name);
					if (flag != 0) {
						return flag;
					}
				}
			}
		}
	}
	return flag;
}

Checker::~Checker() {

}

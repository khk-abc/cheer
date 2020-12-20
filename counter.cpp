#include"counter.h"

#include <string>
#include <iostream>
using namespace std;
Counter::Counter() {

}
//使用了lefter[1]作为判断是否是活子的标志，仅改动了left，后续更新
int* Counter::left(int** chess, int row, int col, string name) {
	int lefter[2] = { 0 };
	//int lefter = 0;

	for (int i = 1; col - i >= 0;i++) {
		if (name == "yes") {//黑子
			if (chess[row][col - i] == 20 || chess[row][col - i] == 21) {
				lefter[0]+= 1;
			}
			else if(chess[row][col - i] <=9 && chess[row][col - i] >=1){
				lefter[1] = 1;
				return lefter;
			}
			else {
				return lefter;
			}
		}
		else if (name == "no") {//白子
			if (chess[row][col - i] == 10 || chess[row][col - i] == 11) {
				lefter[0]+= 1;
			}
			else if (chess[row][col - i] <= 9 && chess[row][col - i] >= 1) {
				lefter[1] = 1;
				return lefter;
			}
			else {
				return lefter;
			}
		}
		else {
			cout << "出现违法棋子!" << endl;
		}
	}
	return lefter;
}
int* Counter::right(int** chess, int row, int col, string name) {
	//int righter = 0;
	int righter[2] = { 0 };

	for (int i = 1; col + i <= 14; i++) {
		if (name == "yes") {//黑子
			if (chess[row][col + i ] == 20 || chess[row][col + i] == 21) {
				righter[0] += 1;
			}
			else if (chess[row][col + i] <= 9 && chess[row][col + i] >= 1) {
				righter[1] = 1;
				return righter;
			}
			else {
				return righter;
			}
		}
		else if (name == "no") {//白子
			if (chess[row][col + i] == 10 || chess[row][col + i] == 11) {
				righter[0] += 1;
			}
			else if (chess[row][col + i] <= 9 && chess[row][col + i] >= 1) {
				righter[1] = 1;
				return righter;
			}
			else {
				return righter;
			}
		}
		else {
			cout << "出现违法棋子!" << endl;
		}
	}
	return righter;
}
int* Counter::up(int** chess, int row, int col, string name) {
	//int uper = 0;
	int uper[2] = { 0 };
	
	for (int i = 1; row-i >=0; i++) {
		if (name == "yes") {//黑子
			if (chess[row-i][col ] == 20 || chess[row-i][col] == 21) {
				uper[0] += 1;
			}
			else if (chess[row - i][col] <= 9 && chess[row - i][col] >= 1) {
				uper[1] = 1;
				return uper;
			}
			else {
				return uper;
			}
		}
		else if (name == "no") {//白子
			if (chess[row-i][col] == 10 || chess[row-i][col] == 11) {
				uper[0] += 1;
			}
			else if (chess[row - i][col] <= 9 && chess[row - i][col] >= 1) {
				uper[1] = 1;
				return uper;
			}
			else {
				return uper;
			}
		}
		else {
			cout << "出现违法棋子!" << endl;
		}
	}
		return uper;
}
int* Counter::down(int** chess, int row, int col, string name) {
	//int downer = 0;
	int downer[2] = { 0 };

	for (int i = 1; row+i <= 14; i++) {
		if (name == "yes") {//黑子
			if (chess[row + i][col] == 20 || chess[row + i][col] == 21) {
				downer[0] += 1;
			}
			else if (chess[row + i][col] <= 9 && chess[row + i][col] >= 1) {
				downer[1] = 1;
				return downer;
			}
			else {
				return downer;
			}
		}
		else if (name == "no") {//白子
			if (chess[row + i][col] == 10 || chess[row + i][col] == 11) {
				downer[0] += 1;
			}
			else if (chess[row + i][col] <= 9 && chess[row + i][col] >= 1) {
				downer[1] = 1;
				return downer;
			}
			else {
				return downer;
			}
		}
		else {
			cout << "出现违法棋子!" << endl;
		}
	}
	return downer;
}
int* Counter::left_up(int** chess, int row, int col, string name) {
	//int left_uper = 0;
	int left_uper[2] = { 0 };
	
	for (int i = 1; row - i>=0 && col - i >= 0; i++) {
		if (name == "yes") {//黑子
			if (chess[row -i][col-i] == 20 || chess[row - i][col-i] == 21) {
				left_uper[0] += 1;
			}
			else if (chess[row - i][col - i] <= 9 && chess[row - i][col - i] >= 1) {
				left_uper[1] = 1;
				return left_uper;
			}
			else {
				return left_uper;
			}
		}
		else if (name == "no") {//白子
			if (chess[row - i][col - i] == 10 || chess[row - i][col - i] == 11) {
				left_uper[0] += 1;
			}
			else if (chess[row - i][col - i] <= 9 && chess[row - i][col - i] >= 1) {
				left_uper[1] = 1;
				return left_uper;
			}
			else {
				return left_uper;
			}
		}
		else {
			cout << "出现违法棋子!" << endl;
		}
	}
		return left_uper;
}

int* Counter::right_up(int** chess, int row, int col, string name) {
	//int right_uper = 0;
	int right_uper[2] = { 0 };

	for (int i = 1; row-i>=0 && col + i <= 14; i++) {
		if (name == "yes") {//黑子
			if (chess[row - i][col+i] == 20 || chess[row - i][col+i] == 21) {
				right_uper[0] += 1;
			}
			else if (chess[row - i][col + i] <= 9 && chess[row - i][col + i] >= 1) {
				right_uper[1] = 1;
				return right_uper;
			}
			else {
				return right_uper;
			}
		}
		else if (name == "no") {//白子
			if (chess[row - i][col + i] == 10 || chess[row - i][col + i] == 11) {
				right_uper[0] += 1;
			}
			else if (chess[row - i][col + i] <= 9 && chess[row - i][col + i] >= 1) {
				right_uper[1] = 1;
				return right_uper;
			}
			else {
				return right_uper;
			}
		}
		else {
			cout << "出现违法棋子!" << endl;
		}
	}
		return right_uper;
}
int* Counter::right_down(int** chess, int row, int col, string name) {
	//int right_downer = 0;
	int right_downer[2] = { 0 };

	
	for (int i = 1; row+i<=14 && col + i <= 14; i++) {
		if (name == "yes") {//黑子
			if (chess[row + i][col+i] == 20 || chess[row + i][col+i] == 21) {
				right_downer[0] += 1;
			}
			else if (chess[row + i][col + i] <= 9 && chess[row + i][col + i] >= 1) {
				right_downer[1] = 1;
				return right_downer;
			}
			else {
				return right_downer;
			}
		}
		else if (name == "no") {//白子
			if (chess[row + i][col+i] == 10 || chess[row + i][col+i] == 11) {
				right_downer[0] += 1;
			}
			else if (chess[row + i][col + i] <= 9 && chess[row + i][col + i] >= 1) {
				right_downer[1] = 1;
				return right_downer;
			}
			else {
				return right_downer;
			}
		}
		else {
			cout << "出现违法棋子!" << endl;
		}
	}
	return right_downer;
}
int* Counter::left_down(int** chess, int row, int col, string name) {
	//int left_downer = 0;
	int left_downer[2] = { 0 };

	for (int i = 1; row + i <= 14 && col-i>=0; i++) {
		if (name == "yes") {//黑子
			if (chess[row + i][col-i] == 20 || chess[row + i][col-i] == 21) {
				left_downer[0] += 1;
			}
			else if (chess[row + i][col - i] <= 9 && chess[row + i][col - i] >= 1) {
				left_downer[1] = 1;
				return left_downer;
			}
			else {
				return left_downer;
			}
		}
		else if (name == "no") {//白子
			if (chess[row + i][col-i] == 10 || chess[row + i][col-i] == 11) {
				left_downer[0] += 1;
			}
			else if (chess[row + i][col - i] <= 9 && chess[row + i][col - i] >= 1) {
				left_downer[1] = 1;
				return left_downer;
			}
			else {
				return left_downer;
			}
		}
		else {
			cout << "出现违法棋子!" << endl;
		}
	}
	return left_downer;
}

Counter::~Counter() {

}
#include <string>
#include <iostream>
#include"chess.h"


using namespace std;

Chess::Chess() {
	thischess = (int**)malloc(sizeof(int*) * 15);
	for (int i = 0; i < 15; i++) {
		*(thischess + i) = (int*)malloc(sizeof(int) * 15);
	}
	thisscore = (int**)malloc(sizeof(int*) * 15);
	for (int i = 0; i < 15; i++) {
		*(thisscore + i) = (int*)malloc(sizeof(int) * 15);
		for (int j = 0; j < 15; j++) {
			*(*(thisscore + i) + j) = 0;
		}
	}
}

void Chess::set_location(string name, int* location) {
	if (name == "yes") {
		thischess[*(location + 1)][*location ] = 21;
	}
	else {
		thischess[*(location + 1)][*location] = 11;
	}
	return;
}

int** Chess::score() {
	return thisscore;
}

void Chess::fresh(string name) {
	int i, j;
	for (i = 0; i < 15; i++)
		for (j = 0; j < 15; j++)
		{
			if (name == "yes")
			{
				if (thischess[i][j] == 21)
				{
					thischess[i][j] = 20;
				}
			}
			if (name == "no")
			{
				if (thischess[i][j] == 11)
				{
					thischess[i][j] = 10;
				}
			}
		}
	return;
}

int** Chess::get() {
	return thischess;
}


void Chess::display() {//打印棋盘
	int i, j;
	int alpha[15] = { 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	char beta[15] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O' };
	system("cls");//清屏

	for (i = 0; i <= 14; i++)
	{
		if (alpha[i] < 10)
			cout << " " << alpha[i];
		else
			cout << alpha[i];
		for (j = 0; j <= 14; j++)
		{
			switch (thischess[i][j] % 100)//%100为了适应将来有分值的情形
			{
			case 1:
				cout << "┏";
				break;

			case 2:
				cout << "┓";
				break;

			case 3:
				cout << "┛";
				break;

			case 4:
				cout << "┗";
				break;

			case 5:
				cout << "┠";
				break;

			case 6:
				cout << "┯";
				break;

			case 7:
				cout << "┨";
				break;

			case 8:
				cout << "┷";
				break;

			case 9:
				cout << "┼";
				break;

			case 10:
				cout << "●";
				break;

			case 11:
				cout << "▲";
				break;

			case 20:
				cout << "◎";
				break;

			case 21:
				cout << "△";
				break;
			}
			if (j == 14)
			{
				cout << endl;
			}
		}
	}
	cout << " ";
	for (i = 0; i < 15; i++) {
		cout << " " << beta[i];
	}
	cout << endl;
}

void Chess::ClearchessArray()
{
	int i, j; //i＝行，j＝列

	thischess[0][0] = 1;
	thischess[0][14] = 2;
	thischess[14][14] = 3;
	thischess[14][0] = 4;

	for (i = 1; i <= 13; i++)
	{
		thischess[i][0] = 5;
	}

	for (i = 1; i <= 13; i++)
	{
		thischess[i][14] = 7;
	}

	for (j = 1; j <= 13; j++)
	{
		thischess[0][j] = 6;
	}
	for (j = 1; j <= 13; j++)
	{
		thischess[14][j] = 8;
	}

	for (i = 1; i <= 13; i++)
	{
		for (j = 1; j <= 13; j++)
		{
			thischess[i][j] = 9;
		}
	}
}

Chess::~Chess() {
	//free(thischess);
	//free(thisscore);
}
#include <string>
#include <iostream>
#include<windows.h>
#include"classes.h"
#include<windows.h>




using namespace std;
/*
int check(int** thischess, Checker checker, Counter counter, string name) {
	//int** thischess = chess.get();
	int flag = 0;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			if (name == "yes") {
				if (thischess[i][j] == 21 || thischess[i][j] == 20) {
					flag = checker.check(thischess, counter, i, j, name);
					if (flag != 0) {
						return flag;
					}
				}
			}
			else {
				if (thischess[i][j] == 11 || thischess[i][j] == 10) {
					flag = checker.check(thischess, counter, i, j, name);
					if (flag != 0) {
						return flag;
					}
				}
			}
		}
	}
	return flag;
}*/

Game::Game() {

}

/*
int Game::mode1() {


	Person player1;
	Person player2;


	//�ж��Ƿ�Ϸ�����ִ��������ֱ����ȷ
	string first;
	cout << "���Ƿ�ִ��?(yes or no)��";
	cin >> first;
	while (first != "yes" && first != "no")
	{
		cout << "�������벻�Ϸ������������룺";
		cin >> first;
	}
	if (first == "yes") {
		player1.set_name("yes");
		player2.set_name("no");
	}
	else {
		player1.set_name("no");
		player2.set_name("yes");
	}
	Chess chess;
	Checker checker;
	Counter counter;
	int* location1 = (int*)malloc(sizeof(int) * 2);
	int* location2 = (int*)malloc(sizeof(int) * 2);

	chess.ClearchessArray();
	chess.display();
	if (player1.get_name() == "yes") {
		while (1) {
			//���1����
			chess.fresh(player1.get_name());//�Ի�ȡ��ǰ����λ�ã�����ǰ����λ�õ�ֵ���£���ʾ��ǰ��ַ�Ѹ�����
			location1 = player1.get_location(chess);
			player1.drop(chess, location1);
			//chess.set_location(player1.get_name(), location1);
			chess.display();
			//chess.fresh(player1.get_name());//�Ի�ȡ��ǰ����λ�ã�����ǰ����λ�õ�ֵ���£���ʾ��ǰ��ַ�Ѹ�����
			int flag = checker.check(chess.get(), counter, *(location1 + 1), *(location1), player1.get_name());
			if (flag) {
				break;
			}

			//���2����
			chess.fresh(player2.get_name());
			player2.set_score(chess, counter, checker);
			location2 = player2.get_location(chess);
			player2.drop(chess, location2);
			//chess.set_location(player2.get_name(), location2);
			chess.display();

			if (checker.check(chess.get(), counter, *(location2 + 1), *(location2), player2.get_name())) {
				break;
			}
		}
	}
	if (player2.get_name() == "yes") {
		while (1) {
			//���2����
			chess.fresh(player2.get_name());
			player2.set_score(chess, counter, checker);
			location2 = player2.get_location(chess);
			player2.drop(chess, location2);
			//chess.set_location(player2.get_name(), location2);
			chess.display();
			if (checker.check(chess.get(), counter, *(location2 + 1), *(location2), player2.get_name())) {
				break;
			}

			//���1����
			chess.fresh(player1.get_name());
			location1 = player1.get_location(chess);
			player1.drop(chess, location1);
			//chess.set_location(player1.get_name(), location1);
			chess.display();
			if (checker.check(chess.get(), counter, *(location1 + 1), *(location1), player1.get_name())) {
				break;
			}
		}
	}

	return 0;
}
int Game::mode2() {

	
	Person player1;
	Computer player2;
	
	
	//�ж��Ƿ�Ϸ�����ִ��������ֱ����ȷ
	string first;
	cout << "���Ƿ�ִ��?(yes or no)��";
	cin >> first;
	while (first != "yes" && first != "no")
	{
		cout << "�������벻�Ϸ������������룺";
		cin >> first;
	}
	if (first == "yes") {
		player1.set_name("yes");
		player2.set_name("no");
	}
	else {
		player1.set_name("no");
		player2.set_name("yes");
	}
	Chess chess;
	Checker checker;
	Counter counter;
	int* location1 = (int*)malloc(sizeof(int) * 2);
	int* location2 = (int*)malloc(sizeof(int) * 2);

	chess.ClearchessArray();
	chess.display();
	if (player1.get_name() == "yes") {
		while (1) {
			//���1����
			chess.fresh(player1.get_name());//�Ի�ȡ��ǰ����λ�ã�����ǰ����λ�õ�ֵ���£���ʾ��ǰ��ַ�Ѹ�����
			location1 = player1.get_location(chess);
			player1.drop(chess, location1);
			//chess.set_location(player1.get_name(), location1);
			chess.display();
			//chess.fresh(player1.get_name());//�Ի�ȡ��ǰ����λ�ã�����ǰ����λ�õ�ֵ���£���ʾ��ǰ��ַ�Ѹ�����
			int flag = checker.check(chess.get(), counter, *(location1 + 1), *(location1), player1.get_name());
			if (flag) {
				break;
			}

			//���2����
			chess.fresh(player2.get_name());
			player2.set_score(chess, counter, checker);
			location2 = player2.get_location(chess);
			player2.drop(chess, location2);
			//chess.set_location(player2.get_name(), location2);
			chess.display();

			if (checker.check(chess.get(), counter, *(location2 + 1), *(location2), player2.get_name())) {
				break;
			}
		}
	}
	if (player2.get_name() == "yes") {
		while (1) {
			//���2����
			chess.fresh(player2.get_name());
			player2.set_score(chess, counter, checker);
			location2 = player2.get_location(chess);
			player2.drop(chess, location2);
			//chess.set_location(player2.get_name(), location2);
			chess.display();
			if (checker.check(chess.get(), counter, *(location2 + 1), *(location2), player2.get_name())) {
				break;
			}

			//���1����
			chess.fresh(player1.get_name());
			location1 = player1.get_location(chess);
			player1.drop(chess, location1);
			//chess.set_location(player1.get_name(), location1);
			chess.display();
			if (checker.check(chess.get(), counter, *(location1 + 1), *(location1), player1.get_name())) {
				break;
			}
		}
	}

	return 0;
}
int Game::mode3() {


	Computer player1;
	Computer player2;


	//�ж��Ƿ�Ϸ�����ִ��������ֱ����ȷ
	string first;
	cout << "���Ƿ�ִ��?(yes or no)��";
	cin >> first;
	while (first != "yes" && first != "no")
	{
		cout << "�������벻�Ϸ������������룺";
		cin >> first;
	}
	if (first == "yes") {
		player1.set_name("yes");
		player2.set_name("no");
	}
	else {
		player1.set_name("no");
		player2.set_name("yes");
	}
	Chess chess;
	Checker checker;
	Counter counter;
	int* location1 = (int*)malloc(sizeof(int) * 2);
	int* location2 = (int*)malloc(sizeof(int) * 2);

	chess.ClearchessArray();
	chess.display();
	if (player1.get_name() == "yes") {
		while (1) {
			//���1����
			chess.fresh(player1.get_name());//�Ի�ȡ��ǰ����λ�ã�����ǰ����λ�õ�ֵ���£���ʾ��ǰ��ַ�Ѹ�����
			location1 = player1.get_location(chess);
			player1.drop(chess, location1);
			//chess.set_location(player1.get_name(), location1);
			chess.display();
			//chess.fresh(player1.get_name());//�Ի�ȡ��ǰ����λ�ã�����ǰ����λ�õ�ֵ���£���ʾ��ǰ��ַ�Ѹ�����
			int flag = checker.check(chess.get(), counter, *(location1 + 1), *(location1), player1.get_name());
			if (flag) {
				break;
			}

			//���2����
			chess.fresh(player2.get_name());
			player2.set_score(chess, counter, checker);
			location2 = player2.get_location(chess);
			player2.drop(chess, location2);
			//chess.set_location(player2.get_name(), location2);
			chess.display();

			if (checker.check(chess.get(), counter, *(location2 + 1), *(location2), player2.get_name())) {
				break;
			}
		}
	}
	if (player2.get_name() == "yes") {
		while (1) {
			//���2����
			chess.fresh(player2.get_name());
			player2.set_score(chess, counter, checker);
			location2 = player2.get_location(chess);
			player2.drop(chess, location2);
			//chess.set_location(player2.get_name(), location2);
			chess.display();
			if (checker.check(chess.get(), counter, *(location2 + 1), *(location2), player2.get_name())) {
				break;
			}

			//���1����
			chess.fresh(player1.get_name());
			location1 = player1.get_location(chess);
			player1.drop(chess, location1);
			//chess.set_location(player1.get_name(), location1);
			chess.display();
			if (checker.check(chess.get(), counter, *(location1 + 1), *(location1), player1.get_name())) {
				break;
			}
		}
	}

	return 0;
}*/

/*
void turn(Player player1,Player player2) {

	//�ж��Ƿ�Ϸ�����ִ��������ֱ����ȷ
	string first;
	cout << "���Ƿ�ִ��?(yes or no)��";
	cin >> first;
	while (first != "yes" && first != "no")
	{
		cout << "�������벻�Ϸ������������룺";
		cin >> first;
	}
	if (first == "yes") {
		player1.set_name("yes");
		player2.set_name("no");
	}
	else {
		player1.set_name("no");
		player2.set_name("yes");
	}
	Chess chess;
	Checker checker;
	Counter counter;
	int* location1 = (int*)malloc(sizeof(int) * 2);
	int* location2 = (int*)malloc(sizeof(int) * 2);

	chess.ClearchessArray();
	chess.display();
	if (player1.get_name() == "yes") {
		while (1) {
			//���1����
			chess.fresh(player1.get_name());//�Ի�ȡ��ǰ����λ�ã�����ǰ����λ�õ�ֵ���£���ʾ��ǰ��ַ�Ѹ�����
			location1 = player1.get_location(chess);
			player1.drop(chess, location1);
			//chess.set_location(player1.get_name(), location1);
			chess.display();
			//chess.fresh(player1.get_name());//�Ի�ȡ��ǰ����λ�ã�����ǰ����λ�õ�ֵ���£���ʾ��ǰ��ַ�Ѹ�����
			int flag = checker.check(chess.get(), counter, *(location1 + 1), *(location1), player1.get_name());
			if (flag) {
				break;
			}

			//���2����
			chess.fresh(player2.get_name());
			location2 = player2.get_location(chess);
			player2.drop(chess, location2);
			chess.set_location(player2.get_name(), location2);
			chess.display();

			if (checker.check(chess.get(), counter, *(location2 + 1), *(location2), player2.get_name())) {
				break;
			}
		}
	}
	if (player2.get_name() == "yes") {
		while (1) {
			//���2����
			location2 = player2.get_location(chess);
			player2.drop(chess, location2);
			chess.set_location(player2.get_name(), location2);
			chess.display();
			if (checker.check(chess.get(), counter, *(location2 + 1), *(location2), player2.get_name())) {
				break;
			}

			//���1����
			location1 = player1.get_location(chess);
			player1.drop(chess, location1);
			chess.set_location(player1.get_name(), location1);
			chess.display();
			if (checker.check(chess.get(), counter, *(location1 + 1), *(location1), player1.get_name())) {
				break;
			}
		}
	}
}*/

int Game::mode(Player &player1,Player &player2) {



	//�ж��Ƿ�Ϸ�����ִ��������ֱ����ȷ
	string first;
	cout << "���Ƿ�ִ��?(yes or no)��";
	cin >> first;
	while (first != "yes" && first != "no")
	{
		cout << "�������벻�Ϸ������������룺";
		cin >> first;
	}
	if (first == "yes") {
		player1.set_name("yes");
		player2.set_name("no");
	}
	else {
		player1.set_name("no");
		player2.set_name("yes");
	}
	Chess chess;
	Checker checker;
	Counter counter;
	int* location1 = (int*)malloc(sizeof(int) * 2);
	int* location2 = (int*)malloc(sizeof(int) * 2);

	chess.ClearchessArray();
	chess.display();
	if (player1.get_name() == "yes") {
		while (1) {
			//���1����
			chess.fresh(player1.get_name());//�Ի�ȡ��ǰ����λ�ã�����ǰ����λ�õ�ֵ���£���ʾ��ǰ��ַ�Ѹ�����
			player1.set_score(chess, counter, checker);
			location1 = player1.get_location(chess);
			player1.drop(chess, location1);
			//chess.set_location(player1.get_name(), location1);
			chess.display();
			//Sleep(3000);
			//chess.fresh(player1.get_name());//�Ի�ȡ��ǰ����λ�ã�����ǰ����λ�õ�ֵ���£���ʾ��ǰ��ַ�Ѹ�����
			//int flag = checker.check(chess.get(), counter, *(location1 + 1), *(location1), player1.get_name());
			int flag =checker.all_check(chess.get(),  counter, player1.get_name());
			if (flag == 2 || flag == 1) {
				return 0;
				//break;
			}
			Sleep(800);

			//���2����
			chess.fresh(player2.get_name());
			player2.set_score(chess, counter, checker);
			location2 = player2.get_location(chess);
			player2.drop(chess, location2);
			//chess.set_location(player2.get_name(), location2);
			chess.display();
			//Sleep(3000);
			//flag = checker.check(chess.get(), counter, *(location2 + 1), *(location2), player2.get_name()) ;
			flag = checker.all_check(chess.get(), counter, player2.get_name());
			if (flag == 2 || flag == 1) {
				return 0;
				//break;
			}
			Sleep(800);
		}
	}
	if (player2.get_name() == "yes") {
		while (1) {
			//���2����
			chess.fresh(player2.get_name());
			player2.set_score(chess, counter, checker);
			location2 = player2.get_location(chess);
			player2.drop(chess, location2);
			//chess.set_location(player2.get_name(), location2);
			chess.display();
			//int flag = checker.check(chess.get(), counter, *(location2 + 1), *(location2), player2.get_name());
			int flag = checker.all_check(chess.get(), counter, player2.get_name());
			if (flag==2 || flag==1) {
				return 0;
				//break;
			}
			Sleep(800);
			//���1����
			chess.fresh(player1.get_name());
			player1.set_score(chess, counter, checker);
			location1 = player1.get_location(chess);
			player1.drop(chess, location1);
			//chess.set_location(player1.get_name(), location1);
			chess.display();
			//flag = checker.check(chess.get(), counter, *(location1 + 1), *(location1), player1.get_name());
			flag=checker.all_check(chess.get(), counter, player1.get_name());
			if (flag == 2 || flag == 1) {
				return 0;
				//break;

			}
			Sleep(800);
		}
	}

	//Sleep(10000);
	return 0;
}





Game::~Game() {

}
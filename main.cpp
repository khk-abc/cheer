#include <string>
#include <iostream>
#include"classes.h"
#include<time.h>


using namespace std;

int main() {
	//system("chcp 65001");
	//�ж��Ƿ�Ϸ�������Ϸģʽ��ֱ����ȷ
	srand(time(NULL));
	cout << "��ʼ��Ϸ(yes or no)��";
	string start;
	cin >> start;
	while (start=="yes") {
		Game game;
		int mode;
		cout << "��������Ϸģʽ(1:��vs�ˣ�2����vs����3����vs��):";
		cin >> mode;
		while (mode != 1 && mode != 2 && mode != 3) {
			cout << "�������벻�Ϸ������������룺";
			cin >> mode;
		}
		if (mode == 1) {
			//game.mode1();
			Person player1;
			Person player2;
			game.mode(player1, player2);
		}
		else if (mode == 2) {
			Person player1;
			Computer player2;
			game.mode(player1, player2);
			//game.mode2();
			//turn(player1, player2);
		}
		else if (mode == 3) {
			Computer player1;
			Computer player2;
			game.mode(player1, player2);
			//game.mode3();
			//turn(player1, player2);
		}
		cout << "��ʼ��Ϸ(yes or no)��";
		cin >> start;
	}
	return 0;
}

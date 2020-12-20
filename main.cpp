#include <string>
#include <iostream>
#include"classes.h"
#include<time.h>


using namespace std;

int main() {
	//system("chcp 65001");
	//判断是否合法输入游戏模式，直至正确
	srand(time(NULL));
	cout << "开始游戏(yes or no)：";
	string start;
	cin >> start;
	while (start=="yes") {
		Game game;
		int mode;
		cout << "请输入游戏模式(1:人vs人；2：人vs机；3：机vs机):";
		cin >> mode;
		while (mode != 1 && mode != 2 && mode != 3) {
			cout << "您的输入不合法，请重新输入：";
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
		cout << "开始游戏(yes or no)：";
		cin >> start;
	}
	return 0;
}

#include <string>
#include <iostream>
#include"person.h"


using namespace std;
Person::Person() {

}

int* Person::get_location(Chess chess) {
	char place0;
	int place1;
	if (name == "yes") {
		cout << "执黑者请落子：";
	}
	else {
		cout << "执白者落子：";
	}
	cin >> place0 >> place1;
	location[0] = int(place0 - 97);
	location[1] = 15 - place1; //int(place[1]-48);
	while (location[0] < 0 || location[0] >= 15 || location[1] < 0 || location[1] >= 15 ||
		chess.get()[location[1]][location[0]] <=0 || chess.get()[location[1]][location[0]] >=10 )
	{
		cout << "输入不合法，请重新输入：";
		cin >> place0 >> place1;
		location[0] = int(place0 - 97);
		location[1] = 15 - place1; //int(place[1]-48);
	}
	return location;
}

void Person::set_name(string myname) {
	name = myname;

}

string Person::get_name() {
	return name;

}

void Person::drop(Chess chess, int* location)
{
	chess.set_location(this->name, location);
}

Person::~Person() {

}
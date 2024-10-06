#include <iostream>
using namespace std;

class Container {
	int size;
public:
	Container() { size = 10; }
	void fill() { size = 10; };
	void consume(int num) { if (size > 0) size-=num; };
	int getSize() {	return size; };
};

class CoffeeVendingMachine {
	Container tong[3];
	void fill() {
		for (int i = 0; i < 3; i++) {
			tong[i].fill();
		}
	};
	void selectEspresso() {
		if (tong[0].getSize() > 0 && tong[1].getSize() > 0) {
			tong[0].consume(1);
			tong[1].consume(1);
			cout << "에스프레소 드세요" << endl;
		}else{
			cout << "재료가 부족합니다." << endl;
			}
	};
	void selectAmericano() {
		if (tong[0].getSize() > 0) {
			tong[0].consume(1);
			tong[1].consume(2);
			cout << "아메리카노 드세요" << endl;
		}else{
			cout << "재료가 부족합니다." << endl;
			}
	};
	void selectSugarCoffee() {
		if (tong[0].getSize() && tong[1].getSize() > 0 && tong[2].getSize() > 0) {
			tong[0].consume(1);
			tong[1].consume(2);
			tong[2].consume(1);
			cout << "설탕커피 드세요" << endl;
		}else{
			cout << "재료가 부족합니다." << endl;
			}
	};
	void show() {
		cout << "커피 " << tong[0].getSize() << "물 " << tong[1].getSize() << "설탕 " << tong[2].getSize() << endl;
	};

public:
	void run() {
		int choice;
		fill();
		cout << "***** 커피자판기를 작동합니다. *****" << endl;
		while (true) {
			cout << "메뉴를 눌러주세요(1:에스프레소, 2:아메리카노, 3:설탕커피, 4:잔량보기, 5:채우기)>> ";
			cin >> choice;

			switch (choice)	{
			case 1: selectEspresso(); break;
			case 2: selectAmericano(); break;
			case 3: selectSugarCoffee(); break;
			case 4: show(); break;
			case 5: fill(); show(); break;

			default:
				cout << "잘못 누르셨습니다. 다시 입력해 주세요" << endl;
				continue;
			}
		}
	};

};



int main() { 
	CoffeeVendingMachine machine;
	machine.run();

	return 0;
}
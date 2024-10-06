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
			cout << "���������� �弼��" << endl;
		}else{
			cout << "��ᰡ �����մϴ�." << endl;
			}
	};
	void selectAmericano() {
		if (tong[0].getSize() > 0) {
			tong[0].consume(1);
			tong[1].consume(2);
			cout << "�Ƹ޸�ī�� �弼��" << endl;
		}else{
			cout << "��ᰡ �����մϴ�." << endl;
			}
	};
	void selectSugarCoffee() {
		if (tong[0].getSize() && tong[1].getSize() > 0 && tong[2].getSize() > 0) {
			tong[0].consume(1);
			tong[1].consume(2);
			tong[2].consume(1);
			cout << "����Ŀ�� �弼��" << endl;
		}else{
			cout << "��ᰡ �����մϴ�." << endl;
			}
	};
	void show() {
		cout << "Ŀ�� " << tong[0].getSize() << "�� " << tong[1].getSize() << "���� " << tong[2].getSize() << endl;
	};

public:
	void run() {
		int choice;
		fill();
		cout << "***** Ŀ�����Ǳ⸦ �۵��մϴ�. *****" << endl;
		while (true) {
			cout << "�޴��� �����ּ���(1:����������, 2:�Ƹ޸�ī��, 3:����Ŀ��, 4:�ܷ�����, 5:ä���)>> ";
			cin >> choice;

			switch (choice)	{
			case 1: selectEspresso(); break;
			case 2: selectAmericano(); break;
			case 3: selectSugarCoffee(); break;
			case 4: show(); break;
			case 5: fill(); show(); break;

			default:
				cout << "�߸� �����̽��ϴ�. �ٽ� �Է��� �ּ���" << endl;
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
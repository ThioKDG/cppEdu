#include <iostream>
#include <sstream>
using namespace std;

class Person {
	string name;
	string tel;

public:
	Person() {}
	string getName() { return name; }
	string getTel() { return tel; }
	void set(string name, string tel);
};

void Person::set(string name, string tel){
	this->name = name;
	this->tel = tel;
}


int main() {
	const int MaxPerson = 3;
	Person persons[MaxPerson]; // 3���� Person ��ü�迭 ����
	string input, name, tel;

	//�̸� ��ȭ��ȣ �Է�
	for (int i = 0; i < MaxPerson; i++) {
		cout << "�̸��� ��ȭ ��ȣ�� �Է��� �ּ���" << endl;
		cout << "��� " << i + 1 << ">>";
		getline(cin, input);

		istringstream iss(input);
		iss >> name >> tel;

		persons[i].set(name, tel);
	}


	cout << "������� �̸��� ";
	for (int i = 0; i < MaxPerson; i++) {
		cout << persons[i].getName();
		if (i < MaxPerson - 1) cout << " ";
	}
	cout << endl;

	//�̸��˻�
	cout << "��ȭ��ȣ �˻��մϴ�. �̸��� �Է��ϼ���>> ";
	getline(cin, name);
	bool found = false;
	for (int i = 0; i < MaxPerson; i++) {
		if (persons[i].getName() == name) {
			cout << "��ȭ ��ȣ�� " << persons[i].getTel() << endl;
			found = true;
			break;
		}
	}
	if (!found) {
		cout << "ã�� ����� �����ϴ�." << endl;
	}

	return 0;
}
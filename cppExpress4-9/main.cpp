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
	Person persons[MaxPerson]; // 3명의 Person 객체배열 생성
	string input, name, tel;

	//이름 전화번호 입력
	for (int i = 0; i < MaxPerson; i++) {
		cout << "이름과 전화 번호를 입력해 주세요" << endl;
		cout << "사람 " << i + 1 << ">>";
		getline(cin, input);

		istringstream iss(input);
		iss >> name >> tel;

		persons[i].set(name, tel);
	}


	cout << "모든사람의 이름은 ";
	for (int i = 0; i < MaxPerson; i++) {
		cout << persons[i].getName();
		if (i < MaxPerson - 1) cout << " ";
	}
	cout << endl;

	//이름검색
	cout << "전화번호 검색합니다. 이름을 입력하세요>> ";
	getline(cin, name);
	bool found = false;
	for (int i = 0; i < MaxPerson; i++) {
		if (persons[i].getName() == name) {
			cout << "전화 번호는 " << persons[i].getTel() << endl;
			found = true;
			break;
		}
	}
	if (!found) {
		cout << "찾는 사람이 없습니다." << endl;
	}

	return 0;
}
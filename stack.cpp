#include <iostream>

using namespace std;

class stack {
public:
	stack(int size) {
		arr = new int[size];
		cap = size;
		top = -1;
	}
	~stack() {
		delete[] arr;
	}
	void push(int ele) {
		if (top == cap - 1) {
			cout << "stack overflow\n";
			return;
		}
		arr[++top] = ele;
	}
	int pop() {
		if (top == -1) {
			cout << "stack underflow\n";
			return -1;
		}
		return arr[top--];
	}
	void print() {
		for (int i = top; i >= 0; i--) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	void clear() {
		top = -1;
	}
private:
	int* arr; // 동적 메모리 주소 저장
	int cap;
	int top;
};

int main()
{
	stack stk(5);
	while (1) {
		system("cls");
		cout << "\n\n\t\t***stack with array***\n\n";
		cout << "\n1. push   2.pop   3. print   4. clear   0. terminate\n";
		cout << "------------------------------------------------------\n";
		cout << "choice: [ ]\b\b";
		int choice;
		cin >> choice;

		int value;
		switch (choice) {
		case 1:
			cout << "\n\n정수 입력: ";
			cin >> value;
			stk.push(value);
			break;
		case 2:
			value = stk.pop();
			if (value == -1)
				cout << "stack underflow\n";
			else
				cout << "\n\n\t\t" << value << "pop";
			break;
		case 3:
			stk.print();
			break;
		case 0:
			cout << "\n\n\t\t프로그램 종료\n";
			return 0;
		}
		cout << "\n\n\t\t";
		system("pause");
	}
	return 0;
}

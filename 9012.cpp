#include <iostream>
#include <string>
using namespace std;

struct Stack {
	char arr[50];
	int top;

	Stack() { top = -1; }

	void push(char ch) {

		if (top<9999)
			arr[++top] = ch;
		else
			cout << "Stack is Full" << endl;
	}
	void pop() {
		if (top >= 0)top--;
	}
	bool isEmpty() {
		return top == -1;
	}
};

bool isVPS(string str) {
	Stack s;

	for(char ch : str) {
		if (ch == '(') {
			s.push(ch);
		}
		else if (ch == ')'){
			if (s.isEmpty()) return false;
			s.pop();
		}
	}

	return s.isEmpty();
}

int main() {
	int T;
	cin >> T;
	bool result[50];
	int index = 0;

	while (T--) {
		string str;
		cin >> str;
		
		result[index++] = isVPS(str);
	}

	for (int i = 0; i < index; i++)
		cout << (result[i]? "YES":"NO") << endl;

	return 0;
}
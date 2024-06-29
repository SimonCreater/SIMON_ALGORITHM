#include<iostream>
#include<string>
using namespace std;

//스택자료구조
class Stack {
private:
	int* repository;
	int StackSize;
	int location;
public:
	Stack(int n) {
		StackSize = n;
		repository = new int[n];
		location = 0;
	}
	void push(int data) {
		if (location == StackSize) {
			cout << "FULL" << '\n';
		}
		else {
			repository[location] = data;
			location++;
		}
	}
	int pop() {
		if (location == 0) {
			return -1;
		}
		else {
			location--;
			return repository[location];
		}
	}
	int size() {
		return location;
	}
	int top() {
		return repository[location - 1];
	}
	bool empty() {
		if (location == 0)
			return 1;
		else
			return 0;
	}
	bool full() {
		if (location == StackSize)
			return 1;
		else
			return 0;
	}

};
int main() {
	int size;
	int n;
	cin >> size >> n;
	Stack stk(size);
	while (n--) {
		string str;
		cin >> str;
		if (str == "pop") {
			cout << stk.pop() << '\n';
		}
		else if (str == "empty") {
			cout << stk.empty() << '\n';
		}
		else if (str == "push") {
			int pushnum;
			cin >> pushnum;
			stk.push(pushnum);
		}
		else if (str == "full") {
			cout << stk.full() << '\n';
		}
		else if (str == "top") {
			cout<<stk.top()<<'\n';
		}
		else if (str == "size") {
			cout << stk.size() << '\n';
		}
	}
}

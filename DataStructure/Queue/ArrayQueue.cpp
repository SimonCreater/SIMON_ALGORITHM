#include<iostream>
using namespace std;
class Queue {
public:
	int arr[5001];
	int back, front;
	Queue() {
		back = 0;
		front = 0;
	}
	void push(int data) {
		arr[back++] = data;
	}
	int Front() {
		return arr[front];
	}
	void pop() {
		for (int i = 0; i < back; i++) {
			arr[i] = arr[i + 1];
		}
		back--;
	}
	bool empty() {
		if (back == front)
			return true;
		else
			return false;
	}

};
int main() {
	Queue q;
	int a,b;
	cin >> a>>b;
	for (int i = 1; i <= a; i++) {
		q.push(i);
	}
	int i = 1;
	cout << '<';
	while (!q.empty()) {
		if (i == b) {
			cout << q.Front() << ',' << " ";
			q.pop();
			i = 1;
		}
		else {
			q.push(q.Front());
			q.pop();
			i++;
		}

	}
	

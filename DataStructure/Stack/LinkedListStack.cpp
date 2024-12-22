#include<iostream>
#include<string>
using namespace std;

//스택자료구조
struct Node {
	int data;
	Node* next;
	Node* prev;
};
class LinkedLIstStack {
private:
	int stackSize;
	Node* head;
	Node* tail;
public:
	LinkedLIstStack() {
		stackSize = 0;
		head = NULL;
		tail = NULL;
	}
	void push(int data) {
		Node* newNode = new Node;
		newNode->data = data;
		
		if (head == NULL) {
			head = newNode;
			tail = newNode;
			tail->next = NULL;
			stackSize++;
		}
		else {
			newNode->next = head;
			head = newNode;
			stackSize++;
		}
	}
	void pop() {
		if (head == NULL) {
			cout << -1 << '\n';
		}
		else {
			int data = head->data;
			Node* curNode = head;
			head = head->next;
			delete curNode;
			cout << data << '\n';
			stackSize--;
		}
	}
	void empty() {
		if (head == NULL) {
			cout << 1 << '\n';

		}
		else {
			cout << 0 << '\n';
		}
	}
	void top() {
		if (head == NULL)
			cout << -1 << '\n';
		else {
			cout << head->data << '\n';
		}
	}
	int size() {
		return stackSize;
	}

};
int main() {
	int num;
	cin >> num;
	LinkedLIstStack stk;
	while (num--) {
		string str;
		cin >> str;
		if (str == "pop") {
			stk.pop();
		}
		else if (str == "empty") {
			stk.empty();
		}
		else if (str == "size") {
			cout<<stk.size()<<'\n';
		}
		else if (str == "push") {
			int pushnum;
			cin >> pushnum;
			stk.push(pushnum);
		}
		else if (str == "top") {
			stk.top();
		}
	}
}

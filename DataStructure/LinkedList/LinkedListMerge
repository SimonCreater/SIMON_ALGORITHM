#include<iostream>
#include<string>
using namespace std;
struct Node {
	int data;
	Node* next;
};

class LinkedList {
public:
	int size;
	Node* head;
	Node* tail;
	LinkedList() {
		size = 0;
		head = nullptr;
		tail = nullptr;
	}
	void append(int x) {
		Node* newNode = new Node;
		newNode->data = x;
		newNode->next = nullptr;
		if (size == 0) {
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
		size++;
	}
	void print() {
		Node* curNode = head;
		while (curNode != nullptr) {
			cout << curNode->data << " ";
			curNode = curNode->next;
		}
		cout << '\n';
	}
	int findNode(int e) {
		Node* curNode = head;
		int cnt = 0;
		while (curNode != nullptr) {
			if (curNode->data == e) {
				return cnt;
			}
			curNode = curNode->next;
			cnt++;
		}
		return -1;
	}
	void insert(int idx, int x) {
		Node* curNode = head;
		Node* newNode = new Node;
		newNode->data = x;
		if (idx == 0) {
			newNode->next = head;
			head = newNode;
			size++;
			return;
		}
		for (int i = 0; i < idx-1; i++) {
			curNode=curNode->next;
		}
		newNode->next = curNode->next;
		curNode->next = newNode;
		size++;


	}

};
int main() {
	int m;
	cin >> m;
	while (m--) {
		int n1, n2;
		cin >> n1;
		LinkedList list1;
		LinkedList list2;
		while (n1--) {
			int x;
			cin >> x;
			list1.append(x);
		}
		cin >> n2;
		while (n2--) {
			int x;
			cin >> x;
			list2.append(x);
		}
		list1.tail->next = list2.head;
		list1.tail = list2.tail;
		list1.size += list2.size;
		list1.print();
		int x, y;
		cin >> x >> y;
		list1.insert(list1.findNode(x), y);
		list1.print();
	}
}

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
	void print() {
		if (size == 0) {
			cout << "empty" << '\n';
			return;
		}

		Node* curNode = head;
		while (curNode != nullptr) {
			cout << curNode->data << " ";
			curNode = curNode->next;
		}
		cout << '\n';
	}
	void append(int x) {
		Node* newNode = new Node;
		newNode->data = x;
		newNode->next = nullptr;
		if (size == 0) {
			head = tail = newNode;
		}
		else
			tail = tail->next = newNode;
		size++;

	}
	int findNode(int x) {
		Node* curNode = head;
		int cnt = 0;
		for (int i = 0; i < size; i++) {
			if (curNode->data == x)
				return cnt;
			curNode = curNode->next;
			cnt++;
		}
		return -1;
	}
	void Delete(int k) {
		Node* cur = head;
		if (size == 0 || size <= k) {
			cout << -1 << '\n';
			return;
		}
		if (k == 0) {
			if (size == 1) {
				int data = head->data;
				head = tail = nullptr;
				size--;
				cout << data << '\n';
				return;
			}
			else {
				int data = head->data;
				head = head->next;
				size--;
				cout << data << '\n';
				return;
			}

		}
		else {
			for (int i = 0; i < k - 1; i++) {
				cur = cur->next;
			}
			Node* delNode = cur->next;
			cur->next = delNode->next;
			if (delNode == tail) {
				tail = cur;
			}
			cout << delNode->data << '\n';
			delete delNode;
			size--;
		}

	}
	void afterMax(int i) {
		if (size==0 || i >= size) {
			cout << "error" << '\n';
			return;
		}
		int max = 0;
		Node* curNode = head;
		int k = 0;
		for (int k = 0; k < size; k++) {
			if (k >= i && curNode->data > max)
				max = curNode->data;
			curNode = curNode->next;
		}
		cout << max << '\n';

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
		else {
			for (int i = 0; i < idx - 1; i++) {
				curNode = curNode->next;
			}
			newNode->next = curNode->next;
			curNode->next = newNode;
			size++;
		}
	}
	void Sum() {
		int sum = 0;
		Node* curNode = head;
		for (int i = 0; i < size; i++) {
			sum += curNode->data;
			curNode = curNode->next;
		}
		cout << sum << '\n';
	}
};
int main() {
	int M;
	cin >> M;

	LinkedList sll;
	while (M--) {
		string cmd;
		cin >> cmd;

		if (cmd == "Print")
			sll.print();
		else if (cmd == "Append") {
			int x;
			cin >> x;
			sll.append(x);
			sll.print();
		}
		else if (cmd == "Delete") {
			int i;
			cin >> i;
			sll.Delete(i);
		}
		
		else if (cmd == "Sum")
			sll.Sum();
		else if (cmd == "AfterMax") {
			int i;
			cin >> i;
			sll.afterMax(i);
		}
	}
}

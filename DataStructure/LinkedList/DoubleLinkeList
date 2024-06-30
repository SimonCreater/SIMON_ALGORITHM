#include<iostream>
#include<string>
using namespace std;
struct Node {
	int data;
	Node* next;
	Node* prev;
};
class DoubleLinkedList {
private:
	Node* trailer;
	Node* header;
	int listSize;
public:
	DoubleLinkedList() {
		listSize = 0;
		header = new Node;
		trailer = new Node;
		header->next = trailer;
		trailer->prev = header;
	}
	void insert(int k, int x) {
		if (k > listSize || k < 0) {
			cout << "out_of_range" << '\n';
			return;
		}
		Node* newNode = new Node;
		newNode->data = x;
		Node* cur = header->next;
		for (int i = 0; i < k; i++) {
			cur = cur->next;
		}
		newNode->next = cur;
		newNode->prev = cur->prev;
		cur->prev->next = newNode;
		cur->prev = newNode;
		listSize++;
	}
	void erase(int k) {
		if (k >= listSize || k < 0) {
			cout << "out_of_range" << '\n';
			return;
		}
		Node* cur = header->next;
		for (int i = 0; i < k; i++) {
			cur = cur->next;
		}
		Node* delNode = cur;
		delNode->prev->next = delNode->next;
		delNode->next->prev = delNode->prev;
		delete delNode;
		listSize--;

	}
	int empty() {
		if (listSize == 0)
			return 1;
		else
			return 0;
	}
	void find(int x) {
		int index = 0;
		Node* cur = header->next;
		bool flag = false;
		for (int i = 0; i < listSize; i++) {
			if (cur->data == x) {
				flag = true;
				break;
			}
			cur = cur->next;
			index++;
		}
		if (flag == false) {
			cout << "not_found" << '\n';
		}
		else
			cout << index << '\n';
	}
	void Print(int m) {
		
		if (listSize == 0) {
			cout << "empty" << '\n';
			return;
		}
		if (m == 0) {
			Node* cur = header->next;
			for (int i = 0; i < listSize; i++) {
				cout << cur->data << " ";
				cur = cur->next;
			}
			cout << '\n';
		}
		 else if (m == 1) {
			Node* cur = trailer->prev;;
			for (int i = 0; i < listSize; i++) {
				cout << cur->data << ' ';
				cur = cur->prev;
			}
			cout << '\n';
		}
	}
};
int main() {
	int n;
	cin >> n;
	DoubleLinkedList list;
	while (n--) {
		string str;
		cin >> str;
		if (str == "empty") {
			if (list.empty())
				cout << "true" << '\n';
			else
				cout << "false" << '\n';
		}
		else if (str == "insert") {
			int x, y;
			cin >> x >> y;
			list.insert(x, y);
		}
		else if (str == "find") {
			int x;
			cin >> x;
			list.find(x);
		}
		else if (str == "print") {
			int m;
			cin >> m;
			list.Print(m);
		}
		else if (str == "erase") {
			int x;
			cin >> x;
			list.erase(x);
		}
	}
}

#include<iostream>
#include<string>
using namespace std;
struct Node {
	int data;
	Node* next;
};
class LinkedListQueue {
private:
	int QueueSize;
	Node* head;
	Node* tail;
public:
	LinkedListQueue() {
		QueueSize = 0;
		head = NULL;
		tail = NULL;
	}
	void enqueue(int data) {
		Node* newNode = new Node;
		newNode->data = data;
		if (head == NULL) {
			head = newNode;
			tail = newNode;
			tail->next = NULL;
			QueueSize++;
		}
		else {
			newNode->next = tail->next;
			tail->next = newNode;
			tail = newNode;
			QueueSize++;
		}
	}
	int dequeue() {
		if (head == NULL) {
			return -1;
		}
		else {
			int data = head->data;
			Node* delNode = new Node;
			delNode = head;
			head = head->next;
			delete delNode;
			QueueSize--;
			return data;
		}
	}
	int rear() {
		if (head == NULL) {
			return -1;
		}
		else {
			return tail->data;
		}
	}
	int front() {
		if (head == NULL) {
			return -1;
		}
		else {
			return head->data;
		}
	}
	int isEmpty() {
		if (head == NULL) {
			return true;
		}
		else
			return false;
	}
	int size() {
		return QueueSize;
	}
};
//int main() {
//	int n;
//	cin >> n;
//	LinkedListQueue q;
//	while (n--) {
//		string str;
//		cin >> str;
//		if (str == "isEmpty") {
//			if (q.isEmpty()) {
//				cout << "True" << '\n';
//			}
//			else
//				cout << "False" << '\n';
//		}
//		else if (str == "dequeue") {
//			int result = q.dequeue();
//			if (result == -1) {
//				cout << "Empty" << '\n';
//			}
//			else {
//				cout << result << '\n';
//			}
//		}
//		else if (str == "enqueue") {
//			int data;
//			cin >> data;
//			q.enqueue(data);
//		}
//		else if (str == "size") {
//			cout << q.size() << '\n';
//		}
//		else if (str == "rear") {
//			if (q.isEmpty()) {
//				cout << "Empty" << '\n';
//			}
//			else {
//				cout << q.rear() << '\n';
//			}
//		}
//		else if (str == "front") {
//			if (q.isEmpty()) {
//				cout << "Empty" << '\n';
//			}
//			else {
//				cout << q.front() << '\n';
//			}
//		}
//	}
//}

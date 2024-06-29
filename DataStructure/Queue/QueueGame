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
int main() {
	int n;
	cin >> n;

	while (n--) {
		LinkedListQueue player1;
		LinkedListQueue player2;
		int cardnum;
		cin >> cardnum;
		for (int i = 0; i < cardnum; i++) {
			int p1;
			cin >> p1;
			player1.enqueue(p1);			
		}
		for (int i = 0; i < cardnum; i++) {
			int p2;
			cin >> p2;
			player2.enqueue(p2);
		}
		int difference = 0;
		int score1 = 0;//
		int score2 = 0;//
		int sum1 = 0;//보너스 점수 합한 것
		int sum2 = 0;
		for (int i = 1; i < cardnum + 1; i++) {
			int cardnum1 = player1.dequeue();
			int cardnum2 = player2.dequeue();
			sum1 += cardnum1;
			sum2 += cardnum2;
			if (sum1 > sum2) {
				score1 += 1;
				cout << "Round" << i << " " << sum1 << '>' << sum2 << ' ' << score1 << ':' << score2 << '\n';
				sum1 = sum1 - sum2;
				sum2 = 0;
			}
			else if (sum1 < sum2) {
				score2 += 1;
				cout << "Round" << i << " " << sum1 << '<' << sum2 << ' ' << score1 << ':' << score2 << '\n';
				sum2 = sum2 - sum1;
				sum1 = 0;
			}
			else {
				
				cout << "Round" << i << " " << sum1 << '=' << sum2 << ' ' << score1 << ':' << score2 << '\n';
				sum2 = 0;
				sum1 = 0;
			}
		}
		if (score1 == score2) {
			cout << "Draw" << '\n';
		}
		else if (score1 > score2) {
			cout << "Winner P1"<<'\n';
		}
		else {
			cout << "Winner P2" << '\n';
		}

	}
}

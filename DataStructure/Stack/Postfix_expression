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
	int pop() {
		if (head == NULL) {
			return -1;
		}
		else {
			int data = head->data;
			Node* curNode = head;
			head = head->next;
			stackSize--;
			delete curNode;
			return data;
			
		}
	}
	bool empty() {
		if (head == NULL) {
			return true;

		}
		else {
			return false;
		}
	}
	int top() {
		if (head == NULL)
			return -1;
		else {
			return head->data;
		}
	}
	int size() {
		return stackSize;
	}

};
int GetOpPrec(char op) {
	if (op == '*' || op == '/')
		return 5;
	else if (op == '+' || op == '-') {
		return 3;
	}
	else if (op == '(')
		return 1;
}
void Convert(string exp) {
	LinkedLIstStack stk;
	int size = exp.size();
	string convertresult="";
	char tok;
	int idx = 0;
	int num = 0;
	for (int i = 0; i < size; i++) {
		tok = exp[i];
		if (isdigit(tok)) {
			convertresult+= tok;
		}
		else {
			while (!stk.empty() && GetOpPrec(stk.top()) >= GetOpPrec(tok)) {
				convertresult+= stk.pop();
				if (stk.empty()) {
					num++;
				}
			}
			stk.push(tok);
			
		}
	}
	while (!stk.empty()) {
		convertresult += stk.pop();
	}
	
	cout << convertresult <<" "<<num+1<< '\n';
}
int main() {
	int n;
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		Convert(str);

	}
	
}

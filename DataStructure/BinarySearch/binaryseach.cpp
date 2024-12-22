#include<iostream>
using namespace std;
int c = 0;
struct Node {
	int key;
	Node* left;
	Node* right;
	Node* parent;
	Node(int k) {
		key = k;
		parent = left = right = nullptr;
	}
};
class BST {
public:
	Node* root;
	BST() {
		root = nullptr;
	}
	Node* search(Node* curNode, int key) {
		if (curNode == nullptr)
			return nullptr;
		else if (curNode->key == key)
			return curNode;
		else if (curNode->key > key)
			return search(curNode->left, key);
		else
			return search(curNode->right, key);
	}
	void search2(Node* curNode, int key) {
		if (curNode == nullptr)
		{

			return;
		}
		else if (curNode->key == key)
		{
			c++;
			return;
		}
		else if (curNode->key > key) {
			c++;
			search2(curNode->left, key);
		}
		else {
			c++;
			search2(curNode->right, key);
		}
	}

	void insert(int key) {
		if (search(root, key) != nullptr)
			return;
		Node* newNode = new Node(key);
		if (root == nullptr) {
			root = newNode;
			return;
		}
		Node* curNode = root;
		Node* parentNode = root->parent;
		while (curNode != nullptr) {
			parentNode = curNode;
			if (curNode->key > key)
				curNode = curNode->left;
			else
				curNode = curNode->right;
			c++;
		}
		if (parentNode->key > newNode->key)
			parentNode->left = newNode;
		else
			parentNode->right = newNode;
		newNode->parent = parentNode;

	}




	void parent(int key) {
		Node* childNode = search(root, key);
		if (childNode == nullptr) {
			cout << -1 << '\n';
			return;
		}
		else if (childNode->parent == nullptr) {
			cout << -2 << '\n';
			return;
		}
		else {
			cout << childNode->parent->key << '\n';
			return;
		}
	}
	void child(int key) {
		Node* parentNode = search(root, key);
		if (parentNode == nullptr) {
			cout << -1 << '\n';
			return;
		}
		else if (parentNode->left == nullptr) {
			cout << -2 << '\n';
			return;
		}
		else {
			cout << parentNode->left->key << '\n';
			return;
		}
	}

};
int main() {
	int t1;
	int t;
	cin >> t1;

	while (t1--) {
		cin >> t;
		BST bst;
		while (t--) {
			c = 0;
			string cmd;
			cin >> cmd;
			if (cmd == "insert") {
				int a;
				cin >> a;
				bst.insert(a);
				cout << c << '\n';
			}

			else if (cmd == "child") {
				int a;
				cin >> a;
				bst.child(a);
			}
			else if (cmd == "parent") {
				int a;
				cin >> a;
				bst.parent(a);
			}
			else if (cmd == "search") {
				int key;
				cin >> key;
				bst.search2(bst.root, key);
				if (bst.root == nullptr)
					cout << "empty" << '\n';
				else
					cout << c << '\n';
			}
		}
	}
}
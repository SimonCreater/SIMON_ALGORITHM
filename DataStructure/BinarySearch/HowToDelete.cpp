11-2
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
	void depth(Node* curNode) {
		Node* depNode = curNode;
		int q = 0;
		while (depNode->parent != nullptr) {
			depNode = depNode->parent;
			q++;
		}
		cout << q << '\n';
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
	void remove(int key) {
		Node* delNode = search(root, key);
		if (delNode == nullptr)
			return;
		
		Node* parentNode = delNode->parent;
		Node* childNode;
		if (delNode->left == nullptr && delNode->right == nullptr)
			childNode = nullptr;
		else if (delNode->left != nullptr && delNode->right == nullptr)
			childNode = delNode->left;
		else if (delNode->left == nullptr && delNode->right != nullptr)
			childNode = delNode->right;
		else {
			childNode = delNode->right;
			while (childNode->left != nullptr) {
				childNode = childNode->left;
			}
			delNode->key = childNode->key;
			delNode = childNode;
			parentNode = delNode->parent;
			childNode = delNode->right;
		}
		if (parentNode == nullptr) {
			root = childNode;
			if (root != nullptr) {
				root->parent = nullptr;
			}
		}
		else if (delNode == parentNode->left) {
			parentNode->left = childNode;
			if (childNode != nullptr)
				childNode->parent = parentNode;
		}
		else {
			parentNode->right = childNode;
			if (childNode != nullptr)
				childNode->parent = parentNode;
		}


	}
	void min(Node* curNode, int idx) {
		if (curNode->left != nullptr)
			min(curNode->left, idx);
		c++;
		if (c == idx) {
			cout << curNode->key << endl;
			return;
		}
		if (curNode->right != nullptr)
			min(curNode->right, idx);
	}

	int height(Node* node) {
		if (node == nullptr)
			return 0;

		if (height(node->left) < height(node->right))
			return height(node->right) + 1;
		else
			return height(node->left) + 1;
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
	void max(Node* curNode, int idx) {
		if (curNode->right != nullptr)
			max(curNode->right, idx);
		c++;
		if (c == idx) {
			cout << curNode->key << endl;
			return;
		}
		if (curNode->left != nullptr)
			max(curNode->left, idx);
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
				
			}

			else if (cmd == "max") {
				int a;
				cin >> a;
				bst.max(bst.root,a);
			}
			else if (cmd == "delete") {
				int a;
				cin >> a;
				bst.remove(a);
			}
			
		}
	}
}
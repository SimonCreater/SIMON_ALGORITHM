#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct Node
{
	int data;
	Node* parent;
	vector<Node*>children;
	int depth;
	int mx;
	int repositorySum;
};
class Tree {
private:
	Node* root;
	vector<Node*> treeList;
public:
	Tree() {
		root = new Node;
		root->data = 1;
		root->depth = 0;
		treeList.push_back(root);
		root->mx = 1;
		root->repositorySum = 0;
	}
	Node* findNode(int x) {
		for (auto Node : treeList) {
			if (Node->data == x)
				return Node;
		}
		return nullptr;
	}
	void insert(int x, int y) {
		Node* parentNode = findNode(x);
		if (parentNode == nullptr || findNode(y) != nullptr) {
			cout << -1 << '\n';
			return;
		}
		Node* newNode = new Node;
		newNode->data = y;
		newNode->depth = parentNode->depth + 1;
		newNode->parent = parentNode;
		newNode->mx = y;
		parentNode->children.push_back(newNode);
		newNode->repositorySum = 0;
		treeList.push_back(newNode);
	}
	void erase(int x) {
		Node* findx = findNode(x);
		if (findx == nullptr) {
			cout << -1 << '\n';
			return;
		}
		for (auto Node : findx->children) {
			Node->parent = findx->parent;
			findx->parent->children.push_back(Node);
		}
		for (int i = 0; i < findx->parent->children.size(); i++) {
			if (findx->parent->children[i]->data == x) {
				findx->parent->children.erase(findx->parent->children.begin() + i);
				break;
			}
		}
		for (int i = 0; i < treeList.size(); i++) {
			if (treeList[i] == findx) {
				treeList.erase(treeList.begin() + i);
			}
		}
	}
	void parent(int x) {
		Node* findx = findNode(x);
		if (findx == nullptr) {
			cout << -1 << '\n';
			return;
		}
		cout << findx->parent->data << '\n';
	}
	void child(int x) {
		Node* findx = findNode(x);
		if (findx == nullptr || findx->children.size()==0) {
			cout << -1 << '\n';
			return;
		}
		for (int i = 0; i < findx->children.size(); i++) {
			cout << findx->children[i]->data << " ";
		}
		cout << '\n';
	}
	void min_maxChild(int x) {
		Node* findx = findNode(x);
		if (findx == nullptr || findx->children.size() == 0) {
			cout << -1 << '\n';
			return;
		}
		if (findx->children.size() == 1) {
			cout << findx->children[0]->data << '\n';
			return;
		}
		int min = findx->children[0]->data;
		int mx = findx->children[0]->data;
		for (int i = 0; i < findx->children.size(); i++) {
			if (findx->children[i]->data > mx) {
				mx = findx->children[i]->data;
			}
			if (findx->children[i]->data < min) {
				min = findx->children[i]->data;
			}
		}
		cout << mx + min << '\n';
	}
	void ansdepth(int x, int y) {
		Node* findx = findNode(x);
		Node* findy = findNode(y);
		if (findx == nullptr || findy == nullptr) {
			cout << "error" << '\n';
			return;
		}
		int sum = abs(findx->depth - findy->depth);
		cout << findx->depth << " " << findy->depth<<" " << sum << '\n';

	}
	void preOrder(Node* current) {
		if (current == nullptr)
			return;
		cout << current->mx<<" ";
		for (auto Node : current->children) {
			if (Node->mx< current->mx)
				Node->mx = current->mx;
			preOrder(Node);
		}
	}
	void preOrderFile(Node* current) {
		if (current == nullptr)
			return;
		for (auto Node : current->children) {
			Node->repositorySum = current->data + current->repositorySum;
			preOrderFile(Node);
		}

	}
	void printfolderrepository(int x) {
		preOrderFile(returnRoot());
		Node* findx = findNode(x);
		if (findx->children.size() == 0)
		{
			cout << "D" << " " << findx->repositorySum<<'\n';
		}
		else {
			cout << "F" << " " << findx->repositorySum<<'\n';
		}
	}
	Node* returnRoot() {
		return root;
	}
};
int main() {
	int n, m;
	cin >> n>>m;
	n = n - 1;
	Tree tree;
	while (n--) {
		int x, y;
		cin >> x >> y;
		tree.insert(x, y);
		
	 }
	while (m--) {
		int x;
		cin >> x;
		tree.printfolderrepository(x);
	}	
	
}

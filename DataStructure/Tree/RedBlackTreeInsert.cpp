#include<iostream>
using namespace std;
#define BLACK 1
#define RED 2

struct Node {
	int key;
	Node* parent;
	int color;
	Node* left;
	Node* right;
	
	Node(int k) {
		key = k;
		color = 0;
		parent=left = right = nullptr;
	}
};
class redblack {
public:
	Node* root;
	redblack() {
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
	

	Node* grandparent(int k) {
		Node* curNode = search(root, k);
		if ((curNode != nullptr) && (curNode->parent != nullptr))
			return curNode->parent->parent;
		else
			nullptr;
	}
	Node* uncle(int k) {
		Node* curNode = search(root,k);
		Node* grand = grandparent(k);
		if (grand == nullptr)
			return nullptr;
		if (curNode->parent == grand->left)
			return grand->right;
		else
			return grand->left;
	}
	void insert(int key) {
		if (search(root, key) != nullptr)
			return;//이진 탐색트리는 노드에 저장되어 있는 key값이 모두 달라야해 즉 삽입하려는 숫자가 트리에 있으면 그걸 막으려는거야!
		Node* newNode = new Node(key);//새로 삽입하려는 노드 초기화
		if (root == nullptr) {
			root = newNode;//루트가 비어있으면 즉 트리에 아무런 노드가 없을 때 root에다가 노드를 넣으면 되겠지?
			return;
		}
		Node* curNode = root;//자 이제 삽입할 위치를 찾으려면 현재 위치를 root로 초기화 한 후 찾아야겠지?
		Node* parentNode = root->parent;//트리는 부모의 위치도 중요하기 때문에 curnode의 부모노드도 초기화 필수
		while (curNode != nullptr) {//curNode가 nullptr이 됐을 때 반복문을 멈춰 이 떄 parentNode는 leafnode가 되겠지?
			parentNode = curNode;//한 칸씩 들어가는거야 족보 따라 들어간다 생각하면 돼. 자식으로 내려갈려면 현재 노드를 부모로 초기화 해야겠지?
			if (curNode->key > key)//현재 노드의 key가 삽입하려는 key보다 클 경우 왼쪽으로 가야겠지?
				curNode = curNode->left;//왼쪽으로 가는 과정!
			else
				curNode = curNode->right;//반대 경우
			
		}
		if (parentNode->key > newNode->key)//leafnode의 key가 newnode의 key보다 클 때를 의미하는거겠지?
			parentNode->left = newNode;//newNode의 데이터가 leafnode보다 작으니까 왼쪽 자식으로 들어가지?
		else
			parentNode->right = newNode;//반대 경우 생략
		newNode->parent = parentNode;

	}
	void insert_case1(int key) {//새로운 노드가 드리의 root가 될 떄
		Node* newNode = search(root, key);//이미 insert되어 있다고 가정하고 색깔 정함
		if (newNode->parent == nullptr) {
			newNode->color = BLACK;
		}
		else
			insert_case2(key);
	}
	void insert_case2(int key) {
		Node* newNode = search(root, key);
		if (newNode->parent->color == BLACK)
			return;
		else
			insert_case3(key);
			

	}
	void insert_case3(int key) {
		Node* u = uncle(key);
		Node* n = search(root,key);
		Node* g;
		if (u != nullptr && u->color == RED) {
			n->parent->color = BLACK;
			u->color = BLACK;
			g = grandparent(key);
			g->color = RED;
			insert_case1(g->key);
		}
		else
			insert_case4(key);
	}
	void insert_case4(int key) {
		Node* g = grandparent(key);
		Node* n = search(root,key);

		if (n == n->parent->right && n->parent == g->left) {
			rotate_left(n->parent->key);
			n = n->left;
		}
		else if (n == n->parent->left && n->parent==g->right) {
			rotate_right(n->parent->key);
			n = n->right;
		}
	}
	void rotate_left(int key) {
		Node* n = search(root, key);//P
		Node* p = n->parent;//G
		Node* r = n->right;//N

		if (r->left != nullptr)
			r->left->parent = n;
		n->right = r->left;
		n->parent = r;
		r->left = n;
		r->parent = p;
		if (p != nullptr) {
			if (p->left == n)
				p->left = r;
			else
				p->right = r;
		}
 	}
	void rotate_right(int key) {
		Node* n = search(root, key);
		Node* p = n->parent;
		Node* le = n->left;
		if (le->right != nullptr)
			le->right->parent = n;
		n->left = le->right;
		n->parent = le;
		le->right = n;
		le->parent = p;
		if (p != nullptr) {
			if (p->left == n)
				p->left = le;
			else
				p->right = le;
		}

	}
	void insert_case5(int key) {
		Node* g = grandparent(key);

		Node* n = search(root, key);
		n->parent->color = BLACK;
		g->color = RED;
		if (n == n->parent->left)
			rotate_right(g->key);
		else
			rotate_left(g->key);
	}
};
#include<iostream> 
#include<string>
#include<vector>
using namespace std;
struct Node {
   int data;
   Node* parent;
   vector<Node*>children;
   int depth;
   int repositorySum;
   int upperFileRepositorySum;
   int mx;
};
class Tree {
private:
   Node* root;
   vector<Node*>TreeList;

public:
   bool flag;
   Tree() {
      root = new Node;
      root->data = 1;
      root->depth = 0;
      root->repositorySum = 0;
      root->upperFileRepositorySum = 0;
      TreeList.push_back(root);
      flag = false;
      root->mx = 1;
   }
   Node* findNode(int x) {
      for (auto Node : TreeList) {
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
      TreeList.push_back(newNode);
   }
   void erase(int x) {
      Node* delNode = findNode(x);
      for (auto Node : delNode->children) {
         Node->parent = delNode->parent;
         delNode->parent->children.push_back(Node);
      }
      for (int i = 0; i < delNode->parent->children.size(); i++) {
         if (delNode->parent->children[i]->data == x)
         {
            delNode->parent->children.erase(delNode->parent->children.begin() + i);
            break;
         }
      }
      for (int i = 0; i < TreeList.size(); i++) {
         if (TreeList[i] == delNode) {
            TreeList.erase(TreeList.begin() + i);
         }
      }
   }
   void preOrderFile(Node* current, int limited) {
      if (current == nullptr)
         return;
      if (current->upperFileRepositorySum == limited && current->children.size() == 0) {
         flag = true;
         cout << current->data << " ";
      }
      for (Node* child : current->children) {
         child->upperFileRepositorySum = current->upperFileRepositorySum + 1;
         preOrderFile(child, limited);
      }

   }
   void preOrder(Node* current) {
      if (current == nullptr)
         return;
      cout << current->mx << " ";

      for (auto Node : current->children) {
         if (Node->mx < current->mx) {
            Node->mx = current->mx;
         }
         preOrder(Node);

      }
   }
   void initFolder(int x, int repository) {
      Node* found = findNode(x);
      found->repositorySum = repository;
   }
   void postOrderFoler(Node* current) {
      if (current == nullptr)
         return;
      for (auto Node : current->children) {
         postOrderFoler(Node);
         current->repositorySum += Node->repositorySum;
      }

   }
   void postOrderFolderPrint(int x) {
      Node* find = findNode(x);
      cout << find->repositorySum << '\n';
   }
   void postOrder(Node* current) {
      if (current == nullptr)
         return;
      for (auto Node : current->children) {
         postOrder(Node);
      }
      if (current->children.size() == 0)
         cout << current->depth << " ";
      else {
         cout << current->children.size() << " ";
      }

   }


   Node* returnRoot() {
      return root;
   }

};
int main() {
   /*int n;
   int m;
   cin >> n;

   while (n--) {
   cin >> m;
   m = m - 1;
   Tree tree;
   while (m--) {
   int x, y;
   cin >> x >> y;
   tree.insert(x, y);
   }
   tree.preOrder(tree.returnRoot());
   cout << '\n';
   }*/
   int n, M;
   cin >> n >> M;
   n = n - 1;
   int m = n + 1;
   Tree tree;
   while (n--) {
      int x, y;
      cin >> x >> y;
      tree.insert(x, y);
   }
   while (m--) {
      int x, y;
      cin >> x >> y;
      tree.initFolder(x, y);
   }
   tree.postOrderFoler(tree.returnRoot());

   while (M--) {
      int x;
      cin >> x;
      tree.postOrderFolderPrint(x);
   }
   /*int n;

   cin >> n >> limited;
   n = n - 1;
   Tree tree;
   while (n--) {
   int x, y;
   cin >> x >> y;
   tree.insert(x, y);
   }
   while (limited--) {
   int lim;
   cin >> lim;
   tree.preOrderFile(tree.returnRoot(), lim);

   if (tree.flag == false) {
   cout << -1;
   }
   tree.flag = false;
   cout << '\n';
   }*/
}

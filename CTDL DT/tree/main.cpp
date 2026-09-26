#include <iostream>
#include <stack>

using namespace std;

struct Node {
  int data;
  Node *pLeft;
  Node *pRight;
};

/**
 * Yêu cầu: Khởi tạo 1 Node mới với data = value input
 *  Input:
 *         + int value;
 *  Output:
 *         + Node *pNode;
 */
Node *initNode(int value) {
  Node *pNode = new Node();
  pNode->data = value;
  pNode->pLeft = nullptr;
  pNode->pRight = nullptr;
  return pNode;
}

struct Tree {
  Node *root;
};

/**
 * Yêu cầu: Khởi tạo 1 Tree rỗng
 *  Input:
 *         + Tree &tree;
 *  Output:
 *         + Tree &tree;
 */
void initTree(Tree &tree) { tree.root = nullptr; }

/**
 * Yêu cầu: Thêm 1 Node vào Tree
 *  Input:
 *         + Tree &tree;
 *         + int value;
 *  Output:
 *         + Tree &tree;
 */
void add(Tree &tree, int value) {
  Node *newNode = initNode(value);
  if (tree.root == nullptr) {
    tree.root = newNode;
  } else {
    Node *pRunner = tree.root;
    Node *pLocaltionToAdd = nullptr;
    while (pRunner != nullptr) {
      pLocaltionToAdd = pRunner;
      if (value < pRunner->data) {
        pRunner = pRunner->pLeft;
      } else {
        pRunner = pRunner->pRight;
      }
    }
    if (value < pLocaltionToAdd->data) {
      pLocaltionToAdd->pLeft = newNode;
    } else {
      pLocaltionToAdd->pRight = newNode;
    }
  }
}

/**
 * Yêu cầu: In ra Tree theo thứ tự tăng dần
 *  Input:
 *         + Tree tree;
 *  Output:
 *         + cout
 */
void printTreeUseStack(Tree tree) {
  stack<Node *> s;
  Node *pRunner = tree.root;
  while (pRunner != nullptr || !s.empty()) {
    while (pRunner != nullptr) {
      s.push(pRunner);
      pRunner = pRunner->pLeft;
    }
    pRunner = s.top();
    s.pop();
    cout << pRunner->data << " ";
    pRunner = pRunner->pRight;
  }
}
/**
 * Yêu cầu: Tìm 1 Node trong Tree
 *  Input:
 *         + Tree tree;
 *         + int value;
 *  Output:
 *         + bool
 */
bool find(Tree t, int value) {
  Node *pRunner = t.root;
  while (pRunner != nullptr) {
    if (value == pRunner->data) {
      return true;
    }
    if (value < pRunner->data) {
      pRunner = pRunner->pLeft;
    } else {
      pRunner = pRunner->pRight;
    }
  }
  return false;
}

int main() {
  Tree tree;
  initTree(tree);
  add(tree, 10);
  add(tree, 5);
  add(tree, 15);
  add(tree, 3);
  add(tree, 7);
  add(tree, 12);
  add(tree, 18);
  add(tree, 1);
  add(tree, 8);
  add(tree, 14);
  add(tree, 20);

  printTreeUseStack(tree);
  cout << endl;

  cout << "Tìm 10 trong cây: " << (find(tree, 10) ? "Có" : "Không có") << endl;
  cout << "Tìm 20 trong cây: " << (find(tree, 20) ? "Có" : "Không có") << endl;
  cout << "Tìm 30 trong cây: " << (find(tree, 30) ? "Có" : "Không có") << endl;

  return 0;
}
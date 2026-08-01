#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Node {
  int data;
  Node *next;
};
struct List {
  Node *pHead;
  Node *pTail;
};

/*
* Yêu cầu: Tạo 1 Node với giá trị là value
*  Input:
         + int value;
*  Output:
         + Node* node;
 */
Node *initNode(int value) {
  Node *node = new Node();
  node->data = value;
  node->next = nullptr;

  return node;
}
/*
 * Yêu cầu: Tạo 1 List rỗng
 *  Input:
 *         + Không
 *  Output:
 *         + List* list;
 */
List *initist() {
  List *list = new List();
  list->pHead = nullptr;
  list->pTail = nullptr;
  return list;
}

/*
 * Yêu cầu: Thêm 1 Node vào đầu List
 *  Input:
         + List* l;
         + int value;
 *  Output:
         + List* l;
 */
void addFirst(List *l, int value) {
  Node *newNode = initNode(value);
  if (l->pHead == nullptr) {
    l->pHead = newNode;
    l->pTail = newNode;
  } else {
    newNode->next = l->pHead;
    l->pHead = newNode;
  }
}

/*
 * Yêu cầu: Thêm 1 Node vào cuối List
 *  Input:
         + List* l;
         + int value;
 *  Output:
         + List* l;
 */
void addLast(List *l, int value) {
  Node *newNode = initNode(value);
  if (l->pHead == nullptr) {
    l->pHead = newNode;
    l->pTail = newNode;
  } else {
    l->pTail->next = newNode;
    l->pTail = newNode;
  }
}

/*
* Yêu cầu: nhập giá trị do danh sách từ mảng số nguyên 1 chiều
*  Input:
        + List* l;
        + int* arr;
        + int size;
*  Output:
        + List* l;
*/
void inputList(List *l, int *arr, int size) {
  for (int i = 0; i < size; i++) {
    addLast(l, *(arr + i));
  }
}

/*
* Yêu cầu: In danh sách liên kết đơn
*     Input:
        + List* l;
*  Output:
        + cout;
*/
void printList(List *l) {
  Node *temp = l->pHead;
  while (temp != nullptr) {
    cout << temp->data;
    if (temp->next != nullptr) {
      cout << ", ";
    }
    temp = temp->next;
  }
  cout << endl;
}

/*
* Yêu cầu: In danh sách liên kết đơn cùng với địa chỉ của từng node
* Input:
        + List* l;
* Output:
        + cout;
*/
void printListWithAddress(List *l) {
  Node *temp = l->pHead;
  while (temp != nullptr) {
    cout << temp->data << "->(" << temp << ") ";
    if (temp->next != nullptr) {
      cout << ", ";
    }
    temp = temp->next;
  }
  cout << endl;
}

/*
* Yêu cầu: Kiểm tra danh sách liên kết đơn có rỗng hay không
  * Input:
          + List* l;
  * Output:
        + bool;
*/
bool isEmpty(List *l) { return l->pHead == nullptr; }

/*
* Yêu cầu: trả về Node* thứ n trong List*
*  Input:
        + List* l;
        + int n;
*  Output:
        + Node* node;
*/

Node *getNodeAt(List *l, int n) {
  Node *temp = l->pHead;
  for (int i = 0; i < n; i++) {
    temp = temp->next;
  }
  return temp;
}

/*
* Yêu cầu: tìm kiếm Node có giá trị x trong danh sách
*  Input:
        + List* l;
        + int x;
*  Output:
        + Node* node;
*/

Node *findNode(List *l, int x) {
  Node *temp = l->pHead;
  while (temp != nullptr) {
    if (temp->data == x) {
      return temp;
    }
    temp = temp->next;
  }
  return nullptr;
}

/*
* Yêu cầu: Tìm kiếm các địa chỉ node có giá trị X trong danh sách
*  Input:
        + List* l;
        + int x;
        + Node**& arr;
        + int& size;
*  Output:
        + Node**& arr;
        + int& size;
*/
Node **findNodeAddressWithValueX(List *l, int x, int &size) {
  Node **arr;
  Node *temp = l->pHead;
  while (temp != nullptr) {
    if (temp->data == x) {
      size++;
    }
    temp = temp->next;
  }
  arr = new Node *[size];
  temp = l->pHead;
  int index = 0;
  while (temp != nullptr) {
    if (temp->data == x) {
      arr[index] = temp;
      index++;
    }
    temp = temp->next;
  }
  return arr;
}

/*
* Yêu cầu: Viết hàm đếm số lượng số âm, dương trong danh sách
*  Input:
        + List* l;
        + int& soAm
        + int& soDuong;
*  Output:
        + int& soAm;
        + int& soDuong;
*/
void countNegativePossitive(List *l, int &countOfNegative,
                            int &countOfPossitive) {

  countOfNegative = 0;
  countOfPossitive = 0;
  Node *temp = l->pHead;
  while (temp != nullptr) {
    if (temp->data < 0) {
      countOfNegative++;
    } else if (temp->data > 0) {
      countOfPossitive++;
    }
    temp = temp->next;
  }
}

/*
* Yêu cầu: Tìm node có giá trị âm lớn nhất trong danh sách
*  Input:
        + List* l;
*   Output:
        + Node* node;
*/
Node *findMaxNegativeNode(List *l) {
  Node *temp = l->pHead;
  Node *maxNegativeNode = nullptr;
  while (temp != nullptr) {
    if (temp->data < 0) {
      if (maxNegativeNode == nullptr || temp->data > maxNegativeNode->data) {
        maxNegativeNode = temp;
      }
    }
    temp = temp->next;
  }
  return maxNegativeNode;
}

/*
* Yêu cầu: Tìm node có giá trị lẻ nhỏ nhất
*  Input:
        + List* l;
*   Output:
        +  Node* node;
*/
Node *findMinOddNode(List *l) {
  Node *temp = l->pHead;
  Node *minOddNode = nullptr;
  while (temp != nullptr) {
    if (temp->data % 2 != 0) {
      if (minOddNode == nullptr || temp->data < minOddNode->data) {
        minOddNode = temp;
      }
    }
    temp = temp->next;
  }
  return minOddNode;
}

/*
* Yêu cầu: thay thế giá trị Y cho node có giá trị X
*  Input:
        + List* l;
        + int x;
        + int y;
*  Output:
        + List* l;
*/
void replaceXWithValueY(List *l, int x, int y) {
  Node *temp = l->pHead;
  while (temp != nullptr) {
    if (temp->data == x) {
      temp->data = y;
    }
    temp = temp->next;
  }
}

/*
* Yêu cầu: Viết hàm copy danh sách liên kết đơn từ danh sách L
*  Input:
        + List* l;
*  Output:
        + List* l;
*/
List *copyList(List *l) {
  List *newList = initist();
  Node *temp = l->pHead;
  while (temp != nullptr) {
    addLast(newList, temp->data);
    temp = temp->next;
  }
  return newList;
}

int main() {
  List *l = initist();
  cout << "Test: Thêm phần từ vào đầu danh sách" << endl;
  addFirst(l, 1);
  cout << "Phần tử đầu tiên là: " << l->pHead->data << endl;
  cout << "Phần tử cuối cùng là: " << l->pTail->data << endl;
  cout << "Test: Thêm phần từ vào cuối danh sách" << endl;
  addLast(l, 2);
  cout << "Phần tử đầu tiên là: " << l->pHead->data << endl;
  cout << "Phần tử cuối cùng là: " << l->pTail->data << endl;

  int *arr = new int[4]{6, 7, 8, 9};
  cout << "Test: Nhập danh sách từ mảng số nguyên 1 chiều" << endl;
  inputList(l, arr, 4);
  cout << "Phần tử đầu tiên là: " << l->pHead->data << endl;
  cout << "Phần tử cuối cùng là: " << l->pTail->data << endl;
  cout << "Mảng sau khi nhập nên là 1,2,6,7,8,9" << endl;
  cout << "Mảng thực tế là:";
  printList(l);

  cout << "Test: In danh sách liên kết đơn cùng với địa chỉ của từng node"
       << endl;
  printListWithAddress(l);

  cout << "Test: Kiểm tra danh sách liên kết đơn có rỗng hay không" << endl;
  if (isEmpty(l)) {
    cout << "Danh sách rỗng" << endl;
  } else {
    cout << "Danh sách không rỗng" << endl;
  }

  List *emptyList = initist();
  cout << "Test: Kiểm tra danh sách liên kết đơn có rỗng hay không(danh sách "
          "này chắc chắn rỗng)"
       << endl;
  if (isEmpty(emptyList)) {
    cout << "Danh sách rỗng" << endl;
  } else {
    cout << "Danh sách không rỗng" << endl;
  }

  delete emptyList;

  cout << "Test: lấy Node thứ 4 trong List nên là số: 8, kq là: "
       << getNodeAt(l, 4)->data << endl;

  cout << "Test: lấy Node thứ 2 trong List nên là số: 6, kq là: "
       << getNodeAt(l, 2)->data << endl;

  cout << "Test: Tìm kiếm node có giá trị là 6, nên có địa chỉ khác null: "
       << findNode(l, 6) << endl;

  cout << "Test: Tìm kiếm node có giá trị là 9999, nên là null/0: "
       << findNode(l, 9999) << endl;

  cout << "Thêm lại 1 lượt nữa arr để có các số lặp lại" << endl;
  inputList(l, arr, 4);

  cout << "Test: tìm và in các nodes có giá trị bằng 7" << endl;

  int size = 0;
  Node **nodesWithValueEq7 = findNodeAddressWithValueX(l, 7, size);
  cout << "Các node có giá trị bằng 7 là: " << endl;
  for (int i = 0; i < size; i++) {
    cout << (*(nodesWithValueEq7 + i))->data << " "
         << (*(nodesWithValueEq7 + i)) << endl;
  }
  delete[] nodesWithValueEq7;

  delete[] arr;

  arr = new int[4]{-6, -77, -88, -9};
  inputList(l, arr, 4);

  cout << "Test: đếm số âm dương:" << endl;

  int countOfNegative = 0;
  int countOfPossitive = 0;
  countNegativePossitive(l, countOfNegative, countOfPossitive);
  cout << "Số âm là: " << countOfNegative << endl;
  cout << "Số dương là: " << countOfPossitive << endl;

  cout << "Test: Tìm node có giá trị âm lớn nhất" << endl;

  Node *maxNegativeNode = findMaxNegativeNode(l);
  if (maxNegativeNode != nullptr) {
    cout << "Node có giá trị âm lớn nhất là: " << maxNegativeNode->data << endl;
  } else {
    cout << "Không có node nào có giá trị âm" << endl;
  }

  cout << "Test: Tìm node có giá trị lẻ nhỏ nhất" << endl;

  Node *minOddNode = findMinOddNode(l);
  if (minOddNode != nullptr) {
    cout << "Node có giá trị lẻ nhỏ nhất là: " << minOddNode->data << endl;
  } else {
    cout << "Không có node nào có giá trị lẻ" << endl;
  }

  cout << "Test: thay thế số -77 bằng số 66" << endl;
  replaceXWithValueY(l, -77, 66);
  cout << "Danh sách sau khi thay thế: " << endl;
  printList(l);

  cout << "Test copy list:" << endl;
  List *newList = copyList(l);
  cout << "Danh sách sau khi copy: " << endl;
  printList(newList);

  return 0;
}
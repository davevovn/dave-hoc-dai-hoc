#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node *next;
};
/*
* Yêu cầu: Tạo 1 Node với giá trị là value
*  Input:
         + int value;
*  Output:
         + Node* node;
 */
Node *initNode(int value)
{
	Node *newNode = new Node;
	newNode->data = value;
	newNode->next = NULL;
	return newNode;
}
struct Stack
{
	Node *pTop;
};

/*
* Yêu cầu: Khởi tạo Stack
*  Input:
         + Stack &s;
*  Output:
         + Stack &s;
 */
void initStack(Stack &s)
{
	s.pTop = nullptr;
}


/*
* Yêu cầu: Thêm một Node vào Stack
*  Input:
         + Stack &s;
         + Node *node;
*  Output:
         + Stack &s;
 */
void push(Stack &s, Node *node)
{
	if (s.pTop != nullptr)
	{
		node->next = s.pTop;
	}
	s.pTop = node;
}
/*
* Yêu cầu: Thêm một giá trị vào Stack
*  Input:
         + Stack &s;
         + int value;
*  Output:
         + Stack &s;
 */
void push(Stack &s, int value)
{
	push(s, initNode(value));
}


/*
* Yêu cầu: Xoá top khỏi Stack
*  Input:
         + Stack &s;
*  Output:
         + Stack &s;
 */
void pop(Stack &s)
{
	if (s.pTop == nullptr)
	{
		return;
	}
	Node *top = s.pTop;
	s.pTop = top->next;
	delete top;
}
/*
* Yêu cầu: Lấy top của Stack
*  Input:
         + Stack s;
*  Output:
         + Node* node;
 */
Node *getTop(Stack s)
{
	return s.pTop;
}

/*
* Yêu cầu: In Stack
*  Input:
         + Stack s;
*  Output:
         + cout;
 */
void printStack(Stack s)
{
	Node *node = s.pTop;
	cout<<"Stack:"<<endl;
	while (node != nullptr)
	{
		cout << node->data<<", ";
		node = node->next;
	}
	cout << endl;
}

int main()
{

	Stack stack;
	initStack(stack);

	push(stack,3);
	push(stack,6);
	push(stack,72);
	push(stack,90);
	push(stack,7);
	push(stack,8);
	push(stack,-55);
	push(stack,-3);

	printStack(stack);

	int selection = 0;

	do {
		cout<<"1. Thêm vào stack"<<endl;
		cout<<"2. Xoá top khỏi stack"<<endl;
		cout<<"3. Lấy top của stack"<<endl;
		cout<<"4. In stack"<<endl;
		cout<<"5. Thoát"<<endl;
		cout<<"Chọn: ";
		cin>>selection;
		switch(selection) {
		case 1:
			cout<<"Nhập số cần thêm: ";
			int value;
			cin>>value;
			push(stack,value);
			break;
		case 2:
			pop(stack);
			break;
		case 3:
		{
			Node* top =getTop(stack);
			if (top != nullptr) {
				cout<<"Top value: "<<top->data<<endl;
			}
			else {
				cout<<"Stack rỗng"<<endl;
			}
			break;
		}
		case 4:
			printStack(stack);
			break;
		case 5:
			break;
		default:
			cout<<"Invalid selection"<<endl;
		}
	} while(selection != 5);

	return 0;
}
#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct node
{
	int data;
	node * next;
};
node *head  = nullptr;
//node *tail = nullptr; only use if you want doubly linked stack
node *newp = nullptr;
node *eraser = nullptr;

bool isEmpty()
{
	if (head == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void push(int val)
{
	newp = new node;
	newp->data = val;
	if(isEmpty())
	{
		head = newp;
	}
	else
	{
		newp->next = head;
		head = newp;
	}
}

void pop()
{
	if (isEmpty())
	{
		cout << "Empty list" << endl;
	}
	else
	{
		eraser = head;
		head = head->next;
		delete eraser;
	}
}
void printStack()
{
	newp = head;
	while (newp->next != nullptr)
	{
		cout << newp->data << " ";
		newp =newp->next;
	}
	//recursively printing the stack
		/*int x = head->data;
		
		pop();
		if (head != nullptr)
		{
			cout << x;
			printStack();
		}*/
}
void printing(stack<int> g)
{
	if (!g.empty())
	{
		int x = g.top();
		g.pop();
		printing(g);
		cout << x << " ";
	}
}


int main()
{
	/*stack <int> lazlo; testing this in STL form
	lazlo.push(3);
	lazlo.push(34);
	lazlo.push(36);
	lazlo.push(37);
	printing(lazlo);*/
	cout << "Insert how many you want to put in?: ";
	int c;
	int k = 0;
	cin >> c;
	while (k < c)
	{
		cout << "Insert num you want to register to stack: ";
		int h;
		cin >> h;
		push(h);
		cout << endl;
		k++;
	}
	printStack();


	system("pause");

	return 0;
}
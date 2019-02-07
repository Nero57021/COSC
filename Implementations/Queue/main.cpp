#include <Queue>
#include<iostream>
#include<string>
#include <stack>
using namespace std;

void showq(queue <char> gq)
{
	queue <char> g = gq;
	/*while (!g.empty())
	{
		cout << '\t' << g.front();
		g.pop();
	}
	cout << '\n';*/
	if (!g.empty()) //recursively printing queue forward
	{
		char x = g.front();
		cout << x << " ";  //printing it backwards, just put this behind the recursion!
		g.pop();
		showq(g);
	}
}

//void dequeue(queue <int> q)
//{
//	q.pop();//lol
//	// or normal
//	/*QueueNode *trash;
//	trash = frontNode;
//	frontNode = frontNode->next;
//	delete trash;
//	size--;*/
//}

int main()
{
	queue <int> lazy;
	stack <int> bruh;
	
	lazy.push(2);
	lazy.push(3);
	lazy.push(4);
	lazy.push(5);

	bruh.push(5);
	bruh.push(4);
	bruh.push(3);
	bruh.push(2);
	bool pal = true;
	while (!lazy.empty() || !bruh.empty())
	{
		

		if ( bruh.top() == lazy.front())
		{
			lazy.pop();
			bruh.pop();
		}
		else
		{
			pal = false;
			break;
		}
	}
	if (pal == false)
	{
		cout << "is not palindrome";
	}
	else
	{
		cout << " un palindrome" << endl;
	}

	system("pause");
	return 0;
}
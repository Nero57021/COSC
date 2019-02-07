//node.h
#include <iostream>


template<class C>
class Node
{
private:
	C data;
	Node<C> * next;
public:
	Node();
	Node<C> * getNext(void);
	void setNext(Node<C> * newNext);
	C getData();
	void setData(C d);

};

template<class C>
inline Node<C>* Node<C>::getNext(void)
{
	return NULL;
}

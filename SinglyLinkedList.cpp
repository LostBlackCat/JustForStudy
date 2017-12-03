#include"stdafx.h"
//#include<iostream>
using namespace std;
struct  Node
{
	int data;
	Node * next;
};
Node * head;

void Create(int n)
{
	Node * NewNode,* rear=NULL;	//NewNode为新节点,rear为尾节点
	for (int i = 1; i <= n; i++)
	{
		NewNode = new Node;
		NewNode->data = i;
		NewNode->next = NULL;
		if (head==NULL)
		{
			head = NewNode;
			rear = NewNode;
		}
		else
		{
			rear->next = NewNode;
			rear = NewNode;
		}
	}
}

void Display()
{
	Node *p = head;
	if (p == NULL)
	{
		cout << "Empty,no node for output." << endl;
		return;
	}
	while (p!=NULL)
	{
		cout << p->data << "[" << p << "]" << "=>";
		p = p->next;
		cout << "NULL" << endl;
	}
}

int main()
{

	head = new Node;
	head = NULL;
	Create(5);
	cout << "Bytes occupied by nodes is " << sizeof(Node) << endl;
	Display();
	return 0;
}
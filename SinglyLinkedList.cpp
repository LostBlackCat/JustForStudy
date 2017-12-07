//SinglyLinkedList.cpp
//TP301.6 264
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
	}
	cout << "NULL" << endl;

}

Node * Search(int n)
{
	int flag = 0;
	Node *p = head;
	while (p!=NULL)
	{
		if (p->data == n)
		{
			flag = true;
			break;
		}
		p = p->next;
	}
	if (flag == 0)
		return NULL;
	else
		return p;
}

void Delete(Node *DelNode)
{
	Node *p;
	if (head==NULL)
	{
		cout << "Empty linked list." << endl;
		return;
	}
	if (DelNode==NULL)
	{
		cout << "No such a node in linked list. " << endl;
	}
	if (DelNode==head)
	{
		if (head->next!=NULL)
		{
			head = head->next;
			delete DelNode;
		}
		//TODO
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

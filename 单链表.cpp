// 单链表.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct node
{
	int data;
	struct node * next;
};

void mytest();

int main()
{

    return 0;
}

void mytest()
{
	using std::cout;
	node singleNode[20];
	srand(static_cast<int>(time(0)));
	for (int i = 0; i <= 20; i++)
	{
		singleNode[i].data = rand();
		if (i < 20)
			singleNode[i].next = &singleNode[i + 1];
	}
	for (int i = 0; i <= 20; i++)
	{
		cout << i << "\t";
		cout << singleNode[i].data << "\t";
		cout << singleNode[i].next << "\n";
	}

}
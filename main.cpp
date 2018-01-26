#include "stdafx.h"
//#include"pointer.h"
//Head file included above.
#include"SequenceList.h"

#define OK 0                //成功执行
#define Err_Memory -1       //内存分配错误
#define Err_InvalidParam -2 //输入参数无效
#define Err_Overflow -3     //溢出错误
#define Err_IllegalPos -4   //非法位置
#define Err_No_result -5    //无返回结果/返回结果为空

typedef int ElemType;
typedef struct node //链表
{
	ElemType data;
	struct node * next;
}ListNode, *LinkList;

typedef int status;
status InitList(LinkList L)
{
	if (!L)
		return Err_InvaildParam;
	L->next = NULL;
	return OK;
}
status ClearList(LinkList L)
{
	ListNode *p, *q;
	if (!L)
		return Err_InvaildParam;
	p = L->next;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	L->next = NULL;
	return OK;
}
int EmptyList(LinkList L)
{
	if (!L)
		return Err_InvaildParam;
	return(L->next == NULL);
}
int LengthList(LinkList L)
{
	int count = 0;
	ListNode *p;
	p = L->next;
	while (p)
	{
		count++;
		p = p->next;
	}
	return count;
}

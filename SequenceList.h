//SequenceList.h
//顺序表

#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif // !iostream


//#include"stdafx.h"
/*
ADT List
{
数据对象:D;
数据关系:R;
基本操作:
	InitList(L);	//构造一个空的线性表L
	ClearList(L);	//清空线性表L
	EmptyList(L);	//测试线性表L是否为空，（空=True）
	LengthList(L);	//求线性表L的长度
	TraverseList(L);	//访问线性表L的每个元素一次
	InsertList(L,i,e);	//将元素e插入到线性表L的第i 个位置上，线性表长度加1
	DeleteList(L,i,e);	//删除线性表L第i个位置上的元素并将其存到e中，线性表长度减1
	LocateList(e,L);	//返回元素e再线性表L中第一次出现的位置，如未出现返回0
	GetElem(L,i,e);	//在线性表L中，获取第i个位置上的元素，并将其存到e中
}ADT List;
*/

//执行状态参数表
#define OK 0							//成功执行
#define Err_Memory -1				//内存分配错误
#define Err_InvaildParam -2		//输入参数无效
#define Err_Overflow -3			//溢出错误
#define Err_IllegalPos -4			//非法位置
#define Err_NoResult				//无返回结果或返回结果为空
typedef int Status;						//状态值实例化为整形

#define Max_Length 100		//顺序表的最大长度
#define Increment_Length 0		//顺序表的空间分配增量
typedef int ElemType;

typedef struct
{
	ElemType * data;		//data指向储存元素的一维数组，初始大小为Max_Length
	int Length;		//顺序表的实际长度，其值大小等于ListLength
	int ListLength;		//当前顺序表分配的空间大小，初始值为MaxLength
}SeqList;

//初始化顺序表
Status InitList(SeqList *L)
{
	//L->data = (ElemType *)malloc(Max_Length * sizeof(ElemType));	//分配内存空间(C语言实现方法)
	L->data = new ElemType ;	//分配内存空间
	if (!L->data)		//分配失败返回错误
		return Err_Memory;
	L->Length = 0;		//实际长度置0
	L->ListLength = Max_Length;	//储存表大小置为Max_Length
	return OK;			//成功返回
}

//清空线性表
Status ClearList(SeqList *L)
{
	L->Length = 0;	//线性表实际长度置0
	return OK;	//成功返回
}

//测试线性表是否为空
bool EmptyList(SeqList *L)
{
	return(L->Length == 0);
}

//求线性表的长度
int LengthList(SeqList *L)
{
	return L->Length;
}

//遍历线性表
void TraverseList(SeqList *L)
{
	for (int i = 0; i < L->Length; i++)
		std::cout << L->data[i];
}


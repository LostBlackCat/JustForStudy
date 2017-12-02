//SequenceList.h
//˳���

#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif // !iostream


//#include"stdafx.h"
/*
ADT List
{
���ݶ���:D;
���ݹ�ϵ:R;
��������:
	InitList(L);	//����һ���յ����Ա�L
	ClearList(L);	//������Ա�L
	EmptyList(L);	//�������Ա�L�Ƿ�Ϊ�գ�����=True��
	LengthList(L);	//�����Ա�L�ĳ���
	TraverseList(L);	//�������Ա�L��ÿ��Ԫ��һ��
	InsertList(L,i,e);	//��Ԫ��e���뵽���Ա�L�ĵ�i ��λ���ϣ����Ա��ȼ�1
	DeleteList(L,i,e);	//ɾ�����Ա�L��i��λ���ϵ�Ԫ�ز�����浽e�У����Ա��ȼ�1
	LocateList(e,L);	//����Ԫ��e�����Ա�L�е�һ�γ��ֵ�λ�ã���δ���ַ���0
	GetElem(L,i,e);	//�����Ա�L�У���ȡ��i��λ���ϵ�Ԫ�أ�������浽e��
}ADT List;
*/

//ִ��״̬������
#define OK 0							//�ɹ�ִ��
#define Err_Memory -1				//�ڴ�������
#define Err_InvaildParam -2		//���������Ч
#define Err_Overflow -3			//�������
#define Err_IllegalPos -4			//�Ƿ�λ��
#define Err_NoResult				//�޷��ؽ���򷵻ؽ��Ϊ��
typedef int Status;						//״ֵ̬ʵ����Ϊ����

#define Max_Length 100		//˳������󳤶�
#define Increment_Length 0		//˳���Ŀռ��������
typedef int ElemType;

typedef struct
{
	ElemType * data;		//dataָ�򴢴�Ԫ�ص�һά���飬��ʼ��СΪMax_Length
	int Length;		//˳����ʵ�ʳ��ȣ���ֵ��С����ListLength
	int ListLength;		//��ǰ˳������Ŀռ��С����ʼֵΪMaxLength
}SeqList;

//��ʼ��˳���
Status InitList(SeqList *L)
{
	//L->data = (ElemType *)malloc(Max_Length * sizeof(ElemType));	//�����ڴ�ռ�(C����ʵ�ַ���)
	L->data = new ElemType ;	//�����ڴ�ռ�
	if (!L->data)		//����ʧ�ܷ��ش���
		return Err_Memory;
	L->Length = 0;		//ʵ�ʳ�����0
	L->ListLength = Max_Length;	//������С��ΪMax_Length
	return OK;			//�ɹ�����
}

//������Ա�
Status ClearList(SeqList *L)
{
	L->Length = 0;	//���Ա�ʵ�ʳ�����0
	return OK;	//�ɹ�����
}

//�������Ա��Ƿ�Ϊ��
bool EmptyList(SeqList *L)
{
	return(L->Length == 0);
}

//�����Ա�ĳ���
int LengthList(SeqList *L)
{
	return L->Length;
}

//�������Ա�
void TraverseList(SeqList *L)
{
	for (int i = 0; i < L->Length; i++)
		std::cout << L->data[i];
}


#pragma once
#include<stdio.h>
#include<malloc.h>
typedef int DListDataType;

typedef struct DListNode
{
	struct DListNode* pHead;
	struct DListNode* _pNext;
	struct DListNode* _pPre;
	DListDataType data;
}DListNode;


typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _pNext;
	struct ListNode* _pPre;
}ListNode;
typedef struct List
{
	ListNode* _pHead;
}List;
DListDataType BuyDListNewNode(DListDataType data);
void ListInit(List* plist);
void ListDestory(List* plist);
void ListPushBack(List* plist, LTDataType x);
void ListPushBack(List* plist);
void ListPushFront(List* plist, LTDataType x);
void ListPopFront(List* plist);
ListNode* ListFind(List* plist, LTDataType x);
// ��pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x);
// ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos);
void ListRemove(List* plist, LTDataType x);
void ListPrint(List* plist);
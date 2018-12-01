#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SListNode;


typedef struct SList
{
	SListNode* first;
}SList;
//��ʼ��
void SListInit(SList* list);
//��������
void SListDestory(SList* list);
//����һ���ڵ�
SListNode* BuySListNode(SLTDataType x);
//ͷ��
void SListPushFront(SList* list, SLTDataType x);
//ͷɾ
void SListPopFront(SList* list);
//β��
void SListPushBack(SList* list,SLTDataType data);
void SListPopBack(SList* list);
//����
SListNode* SListFind(SList* list, SLTDataType x);
//��pos����в���
void SListInsertAfter(SListNode* pos, SLTDataType x);
//ɾ��pos��Ľڵ�
void SListEraseAfter(SListNode* pos);
//��ӡ����
void SListPrint(SList* list);
void SListRemove(SList *list, SLTDataType data);

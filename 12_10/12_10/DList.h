#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// ��������
typedef int DLDataType;

// �������
typedef struct DListNode {
	DLDataType val;
	struct DListNode *next;	// ��̽��
	struct DListNode *prev;	// ǰ�����
}	DListNode;

// ˫����������
typedef struct {
	DListNode *head;		// ָ��ͷ���
}	DList;

// �ڲ��ӿ�
DListNode * BuyNode(DLDataType val) {
	DListNode *node = (DListNode *)malloc(sizeof(DListNode));
	assert(node);
	node->val = val;
	node->next = node->prev = NULL;

	return node;
}

// �ӿ�
// ��ʼ��/����
void DListInit(DList * dlist) {
	// ����ͷ���
	DListNode *head = BuyNode(0); // ͷ����е� val û��ʵ������
								  // ͨ���������ĳ���
								  // ������û��
	head->next = head;
	head->prev = head;

	// ��ͷ�����õ�������
	dlist->head = head;
}

// ���
void DListClear(DList *dlist) {
	DListNode *cur, *next;

	// �͵�����������
	for (cur = dlist->head->next; cur != dlist->head; cur = next) {
		next = cur->next;
		free(cur);
	}

	dlist->head->next = dlist->head;
	dlist->head->prev = dlist->head;
}

// ����
// ͷ��㶼û���ˣ��Ǹ���Ч����
void DListDestroy(DList *dlist) {
	DListClear(dlist);
	free(dlist->head);
	dlist->head = NULL;
}


// ��ɾ�Ĳ�
// �� pos ���ǰ��������
void DListInsert(DListNode *pos, DLDataType val) {
	// ������
	DListNode *node = BuyNode(val);

	node->next = pos;
	node->prev = pos->prev;
	pos->prev->next = node;
	pos->prev = node;
}


// ͷ��
void DListPushFront(DList *dlist, DLDataType val) {
	DListInsert(dlist->head->next, val);
#if 0
	// ������
	DListNode *node = BuyNode(val);

	// ���� next / prev
	// �� 4 ��ָ��
	node->prev = dlist->head;
	node->next = dlist->head->next;
	dlist->head->next->prev = node;
	dlist->head->next = node;
#endif
}

// β��
void DListPushBack(DList *dlist, DLDataType val) {
	DListInsert(dlist->head, val);
#if 0
	// ������
	DListNode *node = BuyNode(val);

	node->prev = dlist->head->prev;
	node->next = dlist->head;
	dlist->head->prev->next = node;
	dlist->head->prev = node;
#endif
}

// ��ӡ
void DListPrintByHead(DListNode *head) {
	for (DListNode *cur = head->next; cur != head; cur = cur->next) {
		printf("%d --> ", cur->val);
	}
	printf("\n");
}

void DListPrintByDList(DList *dlist) {
	DListPrintByHead(dlist->head);
}

// ����
// �ҵ���һ�� val �Ľ�㣬���ؽ���ַ
// ���û�ҵ������� NULL
DListNode * DListFind(DList *dlist, DLDataType val) {
	for (DListNode *cur = dlist->head->next; cur != dlist->head; cur = cur->next) {
		if (cur->val == val) {
			return cur;
		}
	}

	return NULL;
}

// ɾ�� pos ��㣬pos ����ͷ���
void DListErase(DListNode *pos) {
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}

void DListPopFront(DList *dlist) {
	assert(dlist->head->next != dlist->head);	// ����Ϊ��
	DListErase(dlist->head->next);
}

void DListPopBack(DList *dlist) {
	assert(dlist->head->next != dlist->head);	// ����Ϊ��
	DListErase(dlist->head->prev);
}
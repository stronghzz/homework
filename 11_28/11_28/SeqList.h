#pragma once
// Sequence List

#include <stddef.h>

typedef int SLDataType;

struct SeqList {
	SLDataType *array;	// ָ�룬ָ�������ݵĿռ䣬�����Ŀռ��ڶ���
	int capacity;		// ˳������������
	int size;			// ˳�����������Ч�ĸ���
						// ��ʼֵΪ 0��ͬʱҲ��ʾ��һ����Чλ�õ��±�
};

typedef struct SeqList	SeqList;

// ��װ�Ľӿ�

// ��ʼ��/����
void SeqListInit(SeqList *sl, size_t capacity);
void SeqListDestroy(SeqList *sl);

// ��ɾ���
// β�壬������˳����β��
void SeqListPushBack(SeqList *sl, SLDataType data);

// ͷ�壬������˳����ͷ�� ([0])
void SeqListPushFront(SeqList *sl, SLDataType data);

// βɾ��ɾ��˳���β��������
void SeqListPopBack(SeqList *sl);

// ͷɾ��ɾ��˳���ͷ��������
void SeqListPopFront(SeqList *sl);

// �� pos ���ڵ��±������ݲ���
void SeqListInsert(SeqList *sl, size_t pos, SLDataType data);

// ɾ�� pos ���ڵ��±�����
void SeqListErase(SeqList *sl, size_t pos);

// ����
// �Ҵ� 0 ��ʼ�ĵ�һ�������֪���ˣ������������ڵ��±�
// ���û�ҵ����� -1
int SeqListFind(SeqList *sl, SLDataType data);

// ɾ����һ�������� data
void SeqListRemove(SeqList *sl, SLDataType data);

// ɾ������������ data
void SeqListRemoveAll(SeqList *sl, SLDataType data);

// �޸ģ�pos ���ڵ��±�
void SeqListModify(SeqList *sl, size_t pos, SLDataType data);


// ��ӡ
void SeqListPrint(SeqList *sl);

// �ڲ��ӿ�
void CheckCapacity(SeqList *sl);

// ð������
void SeqListBubbleSort(SeqList *sl);

// ���ֲ��ң�ǰ������������
// ����ҵ����������������±꣬���û�ҵ������� -1
int SeqListBinarySearch(SeqList *sl, SLDataType data);
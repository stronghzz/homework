#include "SeqList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


void SeqListInit(SeqList *sl, size_t capacity)
{
	assert(sl != NULL);

	// ��������ֵ Ϊ capacity
	// ��size��ֵΪ 0
	// ��array ���ٿռ䣨���ϣ����ռ��СΪ capacity

	sl->capacity = capacity;
	sl->size = 0;
	sl->array = (SLDataType *)malloc(capacity * sizeof(SLDataType));
	// û����������
	assert(sl->array != NULL);
}

void SeqListDestroy(SeqList *sl)
{
	assert(sl != NULL);
	// �Ƽ������ŵ�˳�����

	free(sl->array);
	sl->array = NULL;	// �����Դ���
	sl->capacity = sl->size = 0;
}

// ƽ�� O(1)
void SeqListPushBack(SeqList *sl, SLDataType data)
{
	assert(sl != NULL);

	CheckCapacity(sl);	// ��װ��˼��

	sl->array[sl->size] = data;
	sl->size++;
}

// O(n)
void SeqListPushFront(SeqList *sl, SLDataType data)
{
	SeqListInsert(sl, 0, data);

#if 0
	assert(sl != NULL);

	CheckCapacity(sl);	// ��װ��˼��

						// ��β��ͷ�������ݰ���
						// i �ĺ����ǿռ���±�
	int i;
	for (i = sl->size; i >= 1; i--) {
		sl->array[i] = sl->array[i - 1];
	}

	sl->array[0] = data;
	sl->size++;
#endif
}


// O(1)
void SeqListPopBack(SeqList *sl)
{
	assert(sl);
	assert(sl->size > 0);

	sl->size--;
}


// O(n)
void SeqListPopFront(SeqList *sl)
{
	assert(sl);
	assert(sl->size > 0);

	// i �������ڵ��±�
	for (int i = 1; i < sl->size; i++) {	// 1. ���䷶Χ����
		sl->array[i - 1] = sl->array[i];	// 2. i �ĺ������
	}

	sl->size--;
}

void SeqListPrint(SeqList *sl)
{
	for (int i = 0; i < sl->size; i++) {
		printf("%d ", sl->array[i]);
	}

	printf("\n");
}

void CheckCapacity(SeqList *sl)
{
	// size �� capacity
	// �����費��Ҫ����
	if (sl->size < sl->capacity) {
		return;
	}

	// 1. �����¿ռ�
	int newCapacity = sl->capacity * 2;
	SLDataType *newArray = (SLDataType *)malloc(
		sizeof(SLDataType)* newCapacity);
	assert(newArray);
	// 2. ���
	for (int i = 0; i < sl->size; i++) {
		newArray[i] = sl->array[i];
	}

	// 3. �ͷ��ϵ�
	free(sl->array);		// �ڴ�й©
							// 4. �����µ�
	sl->array = newArray;

	sl->capacity = newCapacity;
}

int SeqListFind(SeqList *sl, SLDataType data) {
	for (int i = 0; i < sl->size; i++) {
		if (sl->array[i] == data) {
			return i;
		}
	}

	// û���ҵ�
	return -1;
}

void SeqListInsert(SeqList *sl, size_t pos, SLDataType data)
{
	assert(sl);
	CheckCapacity(sl);

	// pos ��Ч��Χ [0, size]
	assert(pos >= 0 && (int)pos <= sl->size);

	// i ��ʾ���������±�
	for (int i = sl->size - 1; i >= (int)pos; i--) {
		sl->array[i + 1] = sl->array[i];
	}

	sl->array[pos] = data;
	sl->size++;
}

void SeqListErase(SeqList *sl, size_t pos)
{
	assert(sl);
	assert(sl->size > 0);
	assert(pos >= 0 && (int)pos < sl->size);

	// i ��ʾ���������±�
	for (int i = pos + 1; i < sl->size; i++) {
		sl->array[i - 1] = sl->array[i];
	}
	sl->size--;
}

void SeqListRemove(SeqList *sl, SLDataType data)
{
	assert(sl != NULL);
	int pos = SeqListFind(sl, data);
	if (pos != -1) {
		SeqListErase(sl, pos);
	}
}

void SeqListModify(SeqList *sl, size_t pos, SLDataType data)
{
	assert(sl != NULL);
	assert(pos >= 0 && (int)pos < sl->size);

	sl->array[pos] = data;
}

// 3 ������
static void Swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void SeqListBubbleSort(SeqList *sl)
{
	assert(sl);

	// i ���������� 0 ��ʼ
	for (int i = 0; i < sl->size - 1; i++) {

		int isSort = 1;

		// ��ʾҪ�Ƚϵ��������� [j], [j+1]; j ���±�
		for (int j = 0; j <= sl->size - 2 - i; j++) {
			if (sl->array[j] > sl->array[j + 1]) {
				Swap(sl->array + j, sl->array + j + 1);
				isSort = 0;	// һ����������
			}
		}

		if (isSort == 1) {
			return;
		}
	}
}


int SeqListBinarySearch(SeqList *sl, SLDataType data)
{
	// ���ݺ��±겻��Ū��
	// left, right	�����±�
	// [left, right)
	int left = 0;
	int right = sl->size;

	// ֻ�� 0 ��������Ҫ��
	while (left < right) {
		// mid Ҳ���±�
		int mid = left + (right - left) / 2;

		if (data == sl->array[mid]) {
			return mid;
		}
		else if (data < sl->array[mid]) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}

	return -1;
}

// ɾ������������ data
// 5 5 5 5 1 1 1 1	ɾ�� 1
void SeqListRemoveAll(SeqList *sl, SLDataType data)
{
#if 0	// ʱ�临�Ӷ� O(n^2)
	int pos;
	while ((pos = SeqListFind(sl, data)) != -1) {	// O(n)
		SeqListErase(sl, pos);	// O(n)
	}
#endif

#if 0	// ʱ�临�Ӷ� O(n)���ռ临�Ӷ� O(n)
	SLDataType *tempArray = (SLDataType *)malloc(
		sizeof(SLDataType)* sl->size);
	assert(tempArray);
	int j = 0;

	for (int i = 0; i < sl->size; i++) {
		if (sl->array[i] != data) {
			tempArray[j++] = sl->array[i];
		}
	}

	for (int k = 0; k < j; j++) {
		sl->array[k] = tempArray[k];
	}

	sl->size = j;
#endif

	int j = 0;
	for (int i = 0; i < sl->size; i++) {
		if (sl->array[i] != data) {
			sl->array[j++] = sl->array[i];
		}
	}

	sl->size = j;
}


void BubbleSort(SLDataType array[], int size)
{
	// i ���������� 0 ��ʼ
	for (int i = 0; i < size - 1; i++) {

		int isSort = 1;

		// ��ʾҪ�Ƚϵ��������� [j], [j+1]; j ���±�
		for (int j = 0; j <= size - 2 - i; j++) {
			if (array[j] > array[j + 1]) {
				Swap(array + j, array + j + 1);
				isSort = 0;	// һ����������
			}
		}

		if (isSort == 1) {
			return;
		}
	}
}

void SeqListBubbleSort1(SeqList *sl)
{
	assert(sl != NULL);

	BubbleSort(sl->array, sl->size);
}

void SeqListBubbleSort2(SeqList *sl)
{
	assert(sl != NULL);

	// i ���������� 0 ��ʼ
	for (int i = 0; i < sl->size - 1; i++) {

		int isSort = 1;

		// ��ʾҪ�Ƚϵ��������� [j], [j+1]; j ���±�
		for (int j = 0; j <= sl->size - 2 - i; j++) {
			if (sl->array[j] > sl->array[j + 1]) {
				Swap(sl->array + j, sl->array + j + 1);
				isSort = 0;	// һ����������
			}
		}

		if (isSort == 1) {
			return;
		}
	}
}
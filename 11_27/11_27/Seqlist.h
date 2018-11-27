#pragma once
#define MAX_SIZE 10 
#include <stdio.h>

typedef int DataType;
typedef struct SeqList
{
	DataType _array[MAX_SIZE];
	int _size; // ��ʾ˳�������ЧԪ�صĸ��� 
}SeqList, *PSeqList;



//��ʼ��
void SeqListInit(PSeqList ps)
{
	ps->_size = 0;

}//��ЧֵΪ��

 //β��
void SeqListPushBack(PSeqList ps, DataType data)
{
	if (NULL == ps)
	{
		return;
	}
	if (ps->_size == MAX_SIZE)
	{
		printf("װ���ˣ����ܲ���");
		return;
	}
	ps->_array[ps->_size] = data;
	ps->_size++;
}
//βɾ
void SeqListPopBack(PSeqList ps)
{
	if (NULL == ps)
	{
		return;
	}
	if (0 == ps->_size)
	{
		printf("ɾ���ˣ�����Ҫɾ��");
		return;
	}
	ps->_size--;
}
//ͷ��
void SeqListPushFront(PSeqList ps, DataType data)
{
	if (NULL == ps)
	{
		return;
	}
	if (ps->_size == MAX_SIZE)
	{
		printf("װ����");
		return;
	}
	DataType i = ps->_size;
	for (i; i >0; i--)
	{
		ps->_array[i] = ps->_array[i-1];
	}
	ps->_array[i] = data;
	ps->_size++;
}
//ͷɾ
void SeqListPopFront(PSeqList ps)
{
	if (NULL == ps)
	{
		return;
	}
	if (ps->_size == 0)
	{
		printf("û�����ˣ�����Ҫɾ��");
		return;
	}
	DataType i = 0;

	for (i; i < ps->_size; i++)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_size--;
}
//posλ�ò���Ԫ��
void SeqListInsert(PSeqList ps, int pos, DataType data)
{
	if (ps == NULL || !(pos <= 0 && pos >= ps->_size))
	{
		return;
	}
	if (ps->_size == MAX_SIZE)
	{
		printf("���ˣ�װ������\n");
		return;
	}
	DataType i = ps->_size;


	for (i; i >= pos; i--)
	{
		ps->_array[i] = ps->_array[i - 1];
	}
	ps->_array[pos] = data;
	ps->_size++;

}
//ɾ��posλ��Ԫ��
void SeqListErase(PSeqList ps, int pos)
{
	if (ps == NULL || !(pos >= 0 && pos <= ps->_size))
	{
		return;
	}
	if (0 == ps->_size)
	{
		printf("˳����ѿ�");
		return;
	}
	DataType i = pos;
	for (i; i < ps->_size; i++)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_size--;
}
//�Ƴ�˳����е�һ��ֵΪdata��Ԫ��
void Remove(PSeqList ps, DataType data)
{
	if (ps == NULL)
	{
		return;
	}
	DataType i = 0;
	for (i; i < ps->_size; i++)
	{
		if (ps->_array[i] == data)
		{
			DataType j = i;
			for (j; j < ps->_size; j++)
			{
				ps->_array[j] = ps->_array[j + 1];
			}
			ps->_size--;
			return;
		}
	}
}
// �Ƴ�˳���������ֵΪdata��Ԫ�� 
void RemoveAll(PSeqList ps, DataType data)
{
	if (ps == NULL)
	{
		return;
	}
	DataType i = 0;
	for (i; i < ps->_size; i++)
	{
		if (ps->_array[i] == data)
		{
			DataType j = i;
			for (j; j < ps->_size; j++)
			{
				ps->_array[j] = ps->_array[j + 1];
			}
			ps->_size--;

		}
	}

}
// ��˳����в���ֵΪdata��Ԫ�أ��ҵ����ظ�Ԫ����˳����е�λ�ã����򷵻�-1 
int SeqListFind(PSeqList ps, DataType data)
{
	if (ps == NULL)
	{
		return 0;
	}
	DataType i = 0;
	for (i = 0; i < ps->_size; i++)
	{
		if (ps->_array[i] == data)
		{
			return i;
		}
	}
	return -1;
}
// ��ȡ˳�����Ԫ�صĸ��� 
int SeqListSize(PSeqList ps)
{
	if (ps == NULL)
	{
		return 0;
	}
	DataType i = 0;

}
void TestSeqListInsertorErase()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	printf("size = %d\n", SeqListSize(&s));

}



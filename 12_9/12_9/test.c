#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node pNode;
struct Node
{
	int data;
	pNode *prev, *next;
};
/* ��ʼ������β�巨 */
pNode *InitList(pNode **head, int n)
{
	pNode *p, *s;
	(*head) = (pNode *)malloc(sizeof(pNode));
	if ((*head) == NULL)
		exit(0);
	(*head)->next = NULL;//head��prev��next��ָ��NULL
	(*head)->prev = NULL;
	p = (*head);//pָ��head
	int i;
	for (i = 0; i < n; ++i)
	{
		s = (pNode *)malloc(sizeof(pNode));
		if (s == NULL)
			exit(0);
		printf("Input the value of the %dth node:", i + 1);
		scanf("%d", &s->data);
		s->next = NULL;
		p->next = s;
		s->prev = p;
		p = s;//pָ��β�ڵ�
	}
	return p;
}
/* ������ӡ */
void PrintList(pNode *head)
{
	pNode *p;
	p = head->next;
	if (head->next == NULL)
		printf("the list is empty\n");
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
/* ������� */
void DeleteList(pNode **head)
{
	pNode *p;
	while ((*head)->next != NULL)
	{
		p = (*head);
		p->next->prev = NULL;
		(*head) = p->next;
		free(p);
	}
}
/* ���������ڵ�ĳ��ֵ */
int SearchList(pNode *head)
{
	int number;
	printf("Values are about to be deleted:");
	scanf("%d", &number);
	pNode *p;
	p = head->next;
	while (p != NULL)
	{
		if (p->data == number)
		{
			return number;
		}
		p = p->next;
	}
	return 0;
}
/* ɾ��������ĳ��Ԫ�أ���p��ǰ���ڵ�ͺ����ڵ��໥ָ�򼴿ɣ����p��β�ڵ���ֱ�ӽ�ǰ���ڵ�ָ��NULL*/
void DelNumqList(pNode **head, int n)
{
	int i;
	pNode *p;
	p = (*head)->next;
	for (i = 1; i < n; ++i)
		p = p->next;
	if (p->next == NULL)
	{
		p->prev->next = NULL;
		free(p);
	}
	else
	{
		p->next->prev = p->prev;
		p->prev->next = p->next;
		free(p);
	}
}
int main(int argc, char const *argv[])
{
	int n, element, flag;
	pNode *head, *last;
	/***************************************************************/
	printf("Please input the size of the list:");
	scanf("%d", &n);
	last = InitList(&head, n);//��ʼ��������ֵ,����β�ڵ�last
	printf("%d %d \n", head->next->data, last->data); //��ӡΪ��һ��Ԫ�غ����һ��Ԫ��
	PrintList(head);
	/***************************************************************/
	flag = SearchList(head); //����ĳ��ֵ��ɾ���ڵ�
	if (flag > 0 && flag <= n)
	{
		DelNumqList(&head, flag);
		PrintList(head);
	}
	else
		printf("Element does not exist, cannot be deleted\n");
	/***************************************************************/
	DeleteList(&head);//����б�
	PrintList(head);
	return 0;
}
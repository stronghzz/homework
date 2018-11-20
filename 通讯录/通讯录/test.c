#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1000
typedef struct PersonInfo
{
	char name[1024];
	char phone[1024];

}PersonInfo;

typedef struct AddrBook
{
	PersonInfo person_info[SIZE];//SIZE��ʾ����ͨѶ¼����Ϣ�����ޣ�
								 //��Ҫ��ע����Щ��Ϣ��������ģ���Щ��Ϣ��û�������
								 //ͨѶ¼�����ǳ����������������1000�����ݶ����������
	int size;//[0,size]�����������
}AddrBook;
AddrBook g_addr_book;
void Init()
{
	g_addr_book.size = 0;
	memset(g_addr_book.person_info, 0x0, sizeof(g_addr_book.person_info));
}
int Menu()
{
	//��ӡ�����û��ṩ�Ĳ���
	//������ʾ��������
	//���û�����Ľ�����س���
	printf("============================\n");
	printf("1.���\n");
	printf("2.ɾ��\n");
	printf("3.�޸�\n");
	printf("4.����\n");
	printf("5,��ʾ\n");
	printf("6,���\n");
	printf("0.�˳�\n");
	printf("============================\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
enum
{
	EXIT = 0,
	ADD,
	DEL,
	MODIFY,
	FIND,//����ĳ����¼
	PRINT,//��ӡ��������
	CLEAR,//�����������
};

void AddPersonInfo()
{
	//���һ���û���Ϣ��ͨѶ¼��
	//��ʾ�û�������ص��û���Ϣ��Ȼ��Ѷ�Ӧ�����ݸ��µ�������
	if (g_addr_book.size >= SIZE)
	{
		printf("��ǰͨѶ¼����������ʧ�ܣ�\n");
		return;
	}
	printf("���һ�����û���\n");
	printf("�������û�����");
	//�±�λ size ��λ�þ���������Ҫ���õ���Ԫ�ص�λ��
	scanf("%s", g_addr_book.person_info[g_addr_book.size].name);
	printf("������绰���룺");
	scanf("%s", g_addr_book.person_info[g_addr_book.size].phone);
	++g_addr_book.size;
	printf("����ɹ���");
	return;

}
void DelPersonInfo()//�����û���Ϣ�ı�Ž���ɾ��
{
	printf("ɾ��ָ����¼��\n");
	printf("������Ҫɾ������Ŀ�ı�ţ�");
	int num = 0;
	scanf("%d", &num);
	if (num < 0 || num >= g_addr_book.size)
	{
		printf("����ı�Ų��Ϸ���ɾ��ʧ�ܣ�");
		return;
	}
	//��ʱ��ȡһ�ֱȽϼ򵥵ķ���
	//1.����û�Ҫɾ���������һ��Ԫ�أ���ô��ֱ�� --size
	if (num != g_addr_book.size - 1)
	{
		//2.����û�Ҫɾ������ĳ���м�λ�õ�Ԫ�أ��Ͱ����һ��Ԫ����䵽��λ��
		strcpy(g_addr_book.person_info[num].name, g_addr_book.person_info[g_addr_book.size - 1].name);
		strcpy(g_addr_book.person_info[num].phone, g_addr_book.person_info[g_addr_book.size - 1].phone);
	}
	g_addr_book.size--;
	printf("ɾ���ɹ�\n");
	return;
}
void ModifyPersonInfo()//���ݱ�Ž����޸�
{
	printf("�޸�ĳ����¼��\n");
	printf("������Ҫ�޸ĵ���Ϣ�ı�ţ�");
	int num = 0;
	scanf("%d", &num);
	if (num < 0 || num >= g_addr_book.size)
	{
		printf("����ı�Ų��Ϸ���");
		return;
	}
	printf("�������µ��û�����");
	scanf("%s", g_addr_book.person_info[num].name);
	printf("�������µĵ绰���룺");
	scanf("%s", g_addr_book.person_info[num].phone);
	printf("�޸ĳɹ���");

}
void FindPersonInfo()
{
	printf("���ҵ绰���룺");
	printf("������Ҫ���ҵ�������");
	char name[1024] = { 0 };
	scanf("%s", name);
	int count = 0;
	for (int i = 0; i < g_addr_book.size; ++i)
	{
		if (strcmp(name, g_addr_book.person_info[i].name) == 0)
		{
			printf("�绰����Ϊ��%s\n", g_addr_book.person_info[i].phone);
			count++;
		}
	}
	if (count == 0)
	{
		printf("û���ҵ���\n");
	}
	else
	{
		printf("�ҵ�%d����¼\n", count);
	}
}
void PrintPersonInfo()//��ӡ�����û��������Ϣ
{
	printf("��ӡ�����û���Ϣ��\n");
	for (int i = 0; i < g_addr_book.size; ++i)
	{
		printf("[%d] %s %s\n", i, g_addr_book.person_info->name, g_addr_book.person_info[i].phone);
	}
	printf("��ӡ���!,����ӡ%d����¼��\n", g_addr_book.size);
}
void ClearPersonInfo()//�������
{
	printf("��������û���Ϣ!\n");
	printf("�Ƿ���������û���Ϣ��y  or  n    \n");
	char input[1024] = { 0 };
	scanf("%s", input);
	if (strcmp(input, "y") != 0)
	{
		printf("��ȡ��ɾ������\n");
		return;
	}
	g_addr_book.size = 0;
	printf("����ɹ���\n");
}
int main()
{
	Init();//1.�ȴ���һ��ͨѶ¼�ı���������Ҳ��Ҫ������������г�ʼ��
	while (1)
	{
		//2.����ѭ������ӡһ���û��˵���������ʾ�û����в���
		int choice = Menu();
		//3.�û�������Ӧ�ı��֮�󣬾͵��ö�Ӧ�Ĳ�������
		switch (choice)
		{
		case ADD:
			AddPersonInfo();
			break;
		case DEL:
			DelPersonInfo();
			break;
		case MODIFY:
			ModifyPersonInfo();
			break;
		case FIND:
			FindPersonInfo();
			break;
		case PRINT:
			PrintPersonInfo();
			break;
		case CLEAR:
			ClearPersonInfo();
			break;
		case EXIT:
			printf("Goodbye\n");
			system("pause");
			return 0;
		default:
			break;
		}
	}

	return 0;
}
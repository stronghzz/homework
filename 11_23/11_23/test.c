#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define N 100
#include <stdio.h>
#include <stdlib.h>
void main()
{
	FILE*fp;
	char ch, filename[10];
	printf("�����ļ���: ");
	scanf("%s", filename);
	if ((fp = fopen(filename, "w")) == NULL)
	{
		printf("�޷��򿪴��ļ�!");
		exit(0);
	}
	ch = getchar();
	printf("���뽫Ҫ�洢�ڴ��̵��ַ���#������");
	printf("\n");
	ch = getchar();
	while (ch != '#')
	{
		fputc(ch, fp);
		putchar(ch);
		ch = getchar();
	}
	fclose(fp);
	printf("\n");
}
//void main()
//{
//	FILE*fp1, *fp2;
//	char ch, filename1[N], filename2[N];
//	printf("����Ҫ������ļ���:");
//	scanf("%s", filename1);
//	printf("����Ҫ������ļ���:");
//	scanf("%s", filename2);
//	if ((fp1 = fopen(filename1, "r")) == NULL)
//	{
//		printf("�򲻿����ļ�����");
//		exit(0);
//	}
//	if ((fp2 = fopen(filename2, "w")) == NULL)
//	{
//		printf("�򲻿����ļ�����");
//		exit(0);
//	}
//	while (!feof(fp1))//δ�������ļ���־��
//	{
//		ch = fgetc(fp1);//��ȡ�ַ�
//		fputc(ch, fp2);// д���ļ�
//		putchar(ch);//��ʾ��Ļ
//	}
//	putchar(N);
//	fclose(fp1);
//	fclose(fp2);
//	puts("\n");
//}

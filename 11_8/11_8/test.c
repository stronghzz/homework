#define _CRT_SECURE_NO_WARNINGS    1
#include <stdio.h>
#include <stdlib.h>

void yhtp(int k)
{
	//����һ����ά���飻
	int arr[100][100] = { 0 };
	int i = 0;
	int j = 0;
	//������ĵ�һ��ȫ����Ϊ1���Խ�����Ҳȫ����Ϊ1��
	for (i = 0; i<k; i++)
	{
		arr[i][0] = 1;
		arr[i][i] = 1;
	}
	//�ӵ����еڶ��п�ʼ��ֵ��
	for (i = 2; i<k; i++)
	{
		for (j = 1; j<k; j++)
		{
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}
	//��ӡ��ʽ��
	for (i = 0; i<k; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%3d", arr[i][j]);
		}
		putchar('\n');
	}
}
int main()
{
	int n = 0;
	printf("������n��ֵ:>");
	scanf("%d", &n);
	yhtp(n);

	system("pause");
	return 0;
}

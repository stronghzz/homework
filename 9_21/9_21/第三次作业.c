#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>
int main()
{
	int n = 1;
	int i = 0;
	int count = 0;
	for (n = 1; n < 101; n++)
	{
		i = n % 10;
		if (i % 9 == 0)
		{
			count++;
		}
		//i = n / 10;
		//if (i % 9 == 0)
		//{
		//	count++;
		//}
		
	}
	printf("%d",count);
	//double sum = 0;
	//int i = 0;
	//int n = -1;
	//for (i = 1; i < 101; i++)
	//{
	//	n = -n;
	//	sum  += 1.0 / i * n;
	//}
	//printf("%f", sum);
	////int a[10] = { 0 };
	////int b[10] = { 0 };
	//int i = 0;
	//int j = 0;
	//printf("����A���飺");
	//for (i = 0; i < 10; i++)
	//{
	//	scanf("%d", &a[i]);
	//}
	//printf("����B����:");
	//for (i = 0; i < 10; i++)
	//{
	//	scanf("%d", &b[i]);
	//}
	//for (j = 0; j < 10; j++)
	//{
	//	a[j] ^= b[j];
	//	b[j] ^= a[j];
	//	a[j] ^= b[j];
	//}
	//printf("������");
	//printf("A���飺");
	//for (j = 0; j < 10; j++)
	//{
	//	printf("%d ", a[j]);
	//}
	//printf("\n");
	//printf("B���飺");
	//for (j = 0; j < 10; j++)
	//{
	//	printf("%d ", b[j]);
	//}
	system("pause");

	return 0;
	
}
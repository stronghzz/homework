#include <stdio.h>
#include <windows.h>
void find(int a[3][3], int row, int col, int k, int *px, int *py)
{
	//�����Ͻǿ�ʼ��
	int i = 0;
	int j = col - 1;
	while ((i < row) && (j >= 0))
	{
		if (k == a[i][j])//����ҵ�k��ֵ������k����ʾ��ֵ��λ��
		{
			*px = i;
			*py = j;
			return;
		}
		else if (a[i][j] < k) //�����ǰֵС��k��������
		{
			i++;
		}
		else
		{
			j--;//�����ǰֵ����k��������
		}
	}
	*px = -1;
	*py = -1;
}
int main()
{
	int a[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int px = 0;
	int py = 2;
	find(a, 3, 3, 5, &px, &py);
	printf("%d %d\n", px+1, py+1);
	system("pause");
	return 0;
}
//void reverse(int a[], int n)
//{
//	int left = 0;
//	int right = n - 1;
//	while (left < right)
//	{
//		//����߿�ʼ�ҵ�һ��ż��
//		while ((left < right) && a[left] % 2 != 0)
//		{
//			left++;
//		}
//		//���ұ߿�ʼ�ҵ�һ������
//		while ((left < right) && (a[right] % 2) == 0)
//		{
//		right--;
//		}
//		if (left<right)
//		{
//			int temp = a[left];
//			a[left] = a[right];
//			a[right] = temp;
//		}
//	}
//}
//int main()
//{	
//	int i = 0;
//	int len = 0;
//	int a[] = { 1,2,3,4,5,6,7,8,9};
//	len = sizeof(a) / sizeof(a[0]);
//	reverse(a,len);
//	for (i = 0;i<len ; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	system("pause");
//	return 0;
//}
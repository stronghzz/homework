#include <stdio.h>


void swap(int *x, int *y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

//���η�������ֳ�����
int patition(int *a, int left, int right) {
	int j = left;    //������������
	int i = j - 1;    //����ָ��С�ڻ�׼Ԫ�ص�λ��
	int key = a[right];    //��׼Ԫ��
						   //�����ұ������飬��С�ڵ��ڻ�׼Ԫ�صķŵ���ߣ����ڻ�׼Ԫ�صķŵ��ұ�
	for (; j < right; ++j) {
		if (a[j] <= key)
			swap(&a[j], &a[++i]);
	}
	//�ѻ�׼Ԫ�طŵ��м�
	swap(&a[right], &a[++i]);
	//���������м�λ��
	return i;
}
//��������
void quickSort(int *a, int left, int right) {
	if (left >= right)
		return;
	int mid = patition(a, left, right);
	quickSort(a, left, mid - 1);
	quickSort(a, mid + 1, right);
}
int main() {
	int a[] = { 10,6,5,7,12,8,1,3,11,4,2,9,16,13,15,14 };
	int n = sizeof(a) / sizeof(int);
	quickSort(a, 0, n - 1);
	printf("����õ�����Ϊ��");
	for (int l = 0; l < n; l++) {
		printf("%d ", a[l]);
	}
	printf("\n");
	return 0;
}
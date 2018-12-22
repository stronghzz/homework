#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


long long c[105][105];
const int mod = 1000000007;
void init()   //���������
{
	c[0][0] = 1;
	for (int i = 1; i <= 100; i++)
	{
		c[i][0] = 1;
		for (int j = 1; j <= 100; j++)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
	}
}
int main()
{
	int k;                //�赥�ܳ���
	int a;                //����Ϊa�ĸ� 
	int b;                //����Ϊb�ĸ� 
	int x;                //����Ϊa�ĸ���x��
	int y;                //����Ϊb�ĸ���y��
	long long ans = 0;    //��ɸ赥��������
	init();
	scanf("%d", &k);
	scanf("%d%d%d%d", &a, &x, &b, &y);
	for (int i = 0; i <= x; i++)
	{
		if (i * a <= k && (k - i * a) % b == 0 && (k - i * a) / b <= y) //������Ŀ���ж�����
		{
			ans = (ans + (c[x][i] * c[y][(k - i * a) / b]) % mod) % mod;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
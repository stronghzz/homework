#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main()
{

	(*(void(*)())0)();//���ǰ� 0 �ŵ�ַǿת��һ������ָ�룬�ٽ��к�������
}



//char *MyStrcat(char *str1, char *str2)
//{
//	assert(str1);
//	assert(str2);
//	char *ret = str1;
//	while (*str1)
//	{
//		str1++;
//	}
//	while (*str1++ = *str2++);
//	return ret;
//}
//
//int main()
//{
//	char str1[] = "hello";
//	char str2[] = "world";
//	MyStrcat(str1,str2);
//	printf("%s", str1);
//
//	system("pause");
//	return 0;
//}
#include <stdio.h>






int my_strcmp(const char *s1, const char *s2)//�����ַ������ܱ��ı�
{
	assert(s1&&s2);//ָ�벻��Ϊ��
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return 0;
		s1++;//�����ȼ������Ƚ�
		s2++;
	}
	return *s1 - *s2;//���ز�ֵ
}
int my_strcmp(const char *s1, const char *s2)//�����ַ������ܱ��ı�
{
	assert(s1&&s2);//ָ�벻��Ϊ��
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return 0;
		s1++;//�����ȼ������Ƚ�
		s2++;
	}
	return *s1 - *s2;//���ز�ֵ
}

int main()
{
	char str1[] = "hello";
	char str2[] = "world";

	my_strcmp(str1, str2);
	my_strcmp(str1, str2);
	system("pause");
	return 0;
}
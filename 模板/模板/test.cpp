#include <iostream>
using namespace std;

//ģ�������Ϊ�����βκͷ������β�
//�����βΣ�������ģ������б��У���һ�����ͣ��� int double
//�������βΣ�ģ������б��еĲ�����һ������������������
//����һ��ģ�����͵ľ�̬����
//template<class T,size_t N = 10>
//class Array
//{
//public:
//	T& operator[](size_t index)
//	{
//		return _array[index];
//	}
//	const T& operator[](size_t index)const
//	{
//		return _array[index];
//	}
//	size_t Size()const
//	{
//		return _size;
//	}
//	bool Empty()const
//	{
//		return 0 == _size;
//	}
//private:
//	T _array[N];
//	size_t _size;
//};

//ģ����ػ�
template<class T>
bool IsEqual(T& left, T& right)
{
	return left == right;
}
template<>
bool IsEqual<char*>(char*&left,char*& right)
{
	if (strcmp(left, right) > 0)
		return true;
	return false;
}
void Test()
{
	const char* p1 = "hello";
	const char* p2 = "world";
	if (IsEqual(p1, p2))//�Ƚϵ���ָ��Ĵ�С��Ҳ���ǵ�ַ��˭��ǰ��˭С��
		cout << p1 << endl;
	else
		cout << p2 << endl;
}//��ʱ����Ҫ��ģ������ػ�

int main()
{
	//Array<int,10> arr;
	//cout << arr.Size() << endl;
	Test();
	return 0;
}





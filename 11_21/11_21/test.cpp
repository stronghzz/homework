#include <iostream>
using namespace std;


int Add(int left, int right)
{
	return left + right;
}
double  Add(double left, double right)
{
	return left + right;
}
long Add(long left, long right)
{
	return left + right;
}
int main()
{
	Add(10, 20);
	Add(10.0, 20.0);
	Add(10L, 20L);
	system("pause");
	return 0;
}



//void Test(int a = 0, int b = 0, int c = 0)
//{
//	cout << "a = " << a <<endl;
//	cout << "b = " << b <<endl;
//	cout << "c = " << c <<endl;
//}
//
//
//void Test1(int a , int b = 0, int c = 0)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}



//void Test(int a = 0)
//{
//	cout << a << endl;
//}



//int main()
//{
//	
//	//cout << "change world!!!" << endl;
//	Test();
//	Test1(10);
//
//	system("pause");
//	return 0;
//}





//void Drink_Num(int money)
//{
//	int price = 1;//���ϵļ۸�
//	int bottle = 0; // ��ƿ����
//	int drink_num = 0;//���˶���ƿ
//	bottle = money / price;
//	drink_num = bottle;
//	while (bottle != 1)//����ƿʣ��һ��ʱ��ѭ������
//	{
//
//		drink_num += bottle / 2;//����ˮ����
//		bottle = bottle / 2 + bottle % 2;//����ƿ���������ܱ�2����ʱ�����ǰ��������浽��ƿ�����У�Ϊ���´λ����ϡ�
//
//	}
//	printf("%d", drink_num);
//}
//
//int main()
//{
//	int money = 20;
//	Drink_Num(money);
//	system("pause");
//	return 0;
//}
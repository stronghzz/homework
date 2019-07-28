#include <iostream>
#include <vector>
#include <string>
using namespace std;

//int main()
//{
//	vector<string> arr;
//
//	arr.push_back("hello");
//	arr.push_back("world");
//	cout << arr.at(0)<<endl;
//	vector<string>::iterator it = arr.begin();
//	cout << *it << endl;
//	cout << arr.capacity() << endl;
//	vector<int> arr1;
//	vector<int>::iterator it1 = arr1.begin();
//	it++;
//	cout << *it << endl;
//	return 0;
//}
void PrintV(const vector<int>& v)
{
	//vector<int>::const_iterator vit = v.begin();
	auto vit = v.begin();

	while (vit != v.end())
	{
		cout << *vit << " ";
		++vit;
	}
	cout << endl;
}

//int main()
//{
//	vector<int> v;
//
//	vector<int> v2(10, 8);
//
//	vector<int> v3(v2.begin(), v2.end());
//
//	string s("hello");
//
//	//ֻҪ������������֮�������һ�£��Ϳ���ʹ�õ���������
//	vector<char> v4(s.begin(), s.end());
//
//	//vector<Date> v5(s.begin(), s.end());
//	
//	/*vector<int>::reverse_iterator vit = v7.rbegin();
//	while (vit != v7.rend())
//	{
//		cout << *vit << " ";
//		++vit;
//	}
//	cout << endl;*/
//
//
//	/*for (const auto& e : v2)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	for (int i = 0; i < v2.size(); i++)
//	{
//		cout << v2[i] << " ";
//	}
//	
//	cout << endl;*/
//	vector<int> v7;
//	v7.push_back(1);
//	v7.push_back(2);
//	v7.push_back(3);
//	v7.push_back(4);
//	auto vit = v7.begin();
//	cout << *vit << endl;
//	//insert�����������ʧЧ,���ݵ��µ�ԭ��ָ��Ŀռ��Ѿ����ͷţ�������ָ���λ�÷Ƿ�
//	//v7.insert(v7.begin() + 3, 0);  // 1 2 3 0 4
//	// �������֮�����»�ȡ���������ܼ���ʹ��
//	vit = v7.begin();
//	cout << *vit << endl;
//	//v7.insert(v7.end() - 2, 5);  // 1 2 3 5 0 4
//	// erase���ܵ��µ���������Խ��
//	// ɾ�����֮�󣬻�ȡerase����ֵ�����µ�������ֵ
//	vit = v7.erase(vit);
//	cout << *vit << endl;
//	v7.clear();
//	cout << v7.size() << endl;
//	cout << v7.capacity() << endl;
//	PrintV(v7);
//		return 0;
//	
//}

//int main()
//{
//	vector<int> v;
//	v.reserve(200);
//	size_t capa = v.capacity();
//	cout << "init capacity: ";
//	cout << capa << endl;
//	for (int i = 0; i < 200; i++)
//	{
//		v.push_back(i);
//		if (capa != v.capacity())
//		{
//			capa = v.capacity();
//			cout << capa << endl;
//		}
//	}
//
//	return 0;
//}

class Date
{
public:
	Date(int y, int month, int day)
		:_year(y)
	{
		cout << "Date(int)" << endl;
	}

	Date(const Date& d)
		:_year(d._year)
	{
		cout << "Date(const Date&)" << endl;
	}
private:
	int _year;
};

//int main()
//{
//	vector<Date> v;
//	auto vit = v.begin();
//	v.insert(vit, Date(2019, 4, 3));
//	vit = v.begin();
//	cout << "emplace: " << endl;
//	v.emplace(vit, 2019, 4, 3);
//	vector<Date> v2;
//	int a = 10; int b = 2;
//	swap(a, b);
//	// ��Աswap�ͷǳ�Աswap�����߼���ͬ�� �ǳ�Աswap�ڲ����ó�Աswap��ɽ���
//	swap(v, v2);  // --->  v.swap(v2)
//	v.swap(v2);
//
//	string s("hello");
//	string s2 = "hello";
//	return 0;
//}

//string mapLetter[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
//
//class Solution {
//public:
//	// C++11 ��ͨ��Ա�������������ʼ�����൱��ȱʡֵ, ���鲻�����������ʼ��
//	//string mapLetter[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
//	//��digits�ĳ��ȿ��Ƶݹ�����
//	//ÿ�ΰѵ�ǰ�����ϵ��Ӵ����뵽��һ��ĵݹ飬����һ�����ĸ��ϸ������Ӵ�
//	//ֱ�����һ�㣬�����ɣ��Ѷ�Ӧ����ϴ�ŵ�vector
//	
//	void combination(int depth, string& digits, 
//		const string& comStr, vector<string>& vec)
//	{
//		//�������һ�㣬��ȡ��ĸ���
//		if (depth == digits.size())
//		{
//			vec.push_back(comStr);
//			return;
//		}
//		// digits --> "234"  digits[0] --> '2'   --> mapLetter[2]
//		int mapNum = digits[depth] - '0';
//		string Letters = mapLetter[mapNum];  // "def"
//		//��ǰ���Ӵ���ÿһ����ĸ���
//		for (int i = 0; i < Letters.size(); i++)
//		{
//			combination(depth + 1, digits, comStr + Letters[i], vec);
//		}
//	}
//
//	vector<string> letterCombinations(string digits) {
//		vector<string> vec;
//		if (digits.empty())
//			return vec;
//		string comStr;
//		combination(0, digits, comStr, vec);
//		return vec;
//	}
//};


class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> matrix;
		matrix.resize(numRows);
		for (int i = 0; i < numRows; i++)
		{
			matrix[i].resize(i + 1);
			// vector<vector<int>>.operator[](i)--> vector<int>.operator[](i)--> int
			matrix[i][0] = matrix[i][i] = 1;
		}

		for (int i = 2; i < numRows; i++)
		{
			for (int j = 1; j < i; j++)
			{
				matrix[i][j] = matrix[i - 1][j] + matrix[i - 1][j - 1];
			}
		}

		return matrix;
	}
};

int main()
{
	Solution s;
	s.generate(10);
	return 0;
}
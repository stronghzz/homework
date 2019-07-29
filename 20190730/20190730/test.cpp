#include <vector>
#include <string>
#include <iostream>
using namespace std;
string letterMap[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
class Solution {
public:
	// ����˼�룺�ܼ����Ϊdigits.size()��ĵݹ飬
	// ÿ��ݹ����ַ�����һ���ַ�������ϡ�
	void combineStr(const string& digits, size_t index, const string& str, vector<string>&
		strs)
	{
		if (index == digits.size())
		{
			strs.push_back(str);
			return;
		}
		// ��ȡ���ֶ�Ӧ���ַ�����
		string letters = letterMap[digits[index] - '0'];
		for (size_t i = 0; i < letters.size(); ++i)
		{
			combineStr(digits, index + 1, str + letters[i], strs);
		}
	}
	vector<string> letterCombinations(string digits) {
		vector<string> strs;
		if (digits.empty())
			return strs;
		size_t index = 0;
		string str;
		// �ݹ�����������ַ���
		combineStr(digits, index, str, strs);
		return strs;
	}
};

int main()
{
	Solution s;
	vector<string> v1 = s.letterCombinations("234");



	return 0;
}
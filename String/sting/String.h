#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cassert>
using namespace std;
class String
{
public:
	typedef char* iterator;
	typedef const char* const_iterator;
	String(const char* str = "")
	{
		assert(str != nullptr);
		// _size: ��Ч�ַ�������������'\0'
		_size = strlen(str);
		_str = new char[_size + 1];
		strcpy(_str, str);  // while(*str1++ = *str2++);
		_capacity = _size;
	}

	String(const String& s)
		:_str(nullptr)
		, _size(0)
		, _capacity(0)
	{
		String tmp(s._str);
		Swap(tmp);
	}

	void Swap(String& s)
	{
		swap(_str, s._str);
		swap(_size, s._size);
		swap(_capacity, s._capacity);
	}

	String& operator=(String s)
	{
		Swap(s);
		return *this;
	}
	// s[i] = c
	char& operator[](size_t pos)
	{
		assert(pos < _size);
		return _str[pos];
	}

	const char& operator[](size_t pos) const
	{
		assert(pos < _size);
		return _str[pos];
	}

	iterator begin()
	{
		return _str;
	}

	iterator end()
	{
		return _str + _size;
	}

	const_iterator begin()const
	{
		return _str;
	}

	const_iterator end()const
	{
		return _str + _size;
	}

	size_t Size() const
	{
		return _size;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
	}

	char* c_str()
	{
		return _str;
	}

	void PushBack(char c)
	{
		//���ռ��Ƿ��㹻
		if (_size == _capacity)
		{
			//��ʼ������Ϊ15
			size_t newC = (_capacity == 0 ? 15 : 2 * _capacity);//����Ϊ0���15������2������
			Reserve(newC);
		}
		_str[_size++] = c;
		_str[_size] = '\0';
	}

	void Reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete _str;
			//��ָ��ָ���¿ռ�
			_str = tmp;
			//��������
			_capacity = n;
		}
	}

	void PopBack()
	{
		if (_size > 0)
		{
			_str[--_size] = '\0';
		}
	}

	void Resize(size_t n, char c = '\0')
	{
		if (n > _capacity)
		{
			Reserve(n);
		}
		if (n > _size)
		{
			memset(_str + _size, c, n - _size);
		}
		_size = n;
		_str[_size] = '\0';
	}

	void Erase(size_t pos, size_t len)
	{
		assert(pos < _size);
		if (pos + len >= _size)
		{
			_size = pos;
			_str[_size] = '\0';
		}
		else
		{
			//��pos + lenλ�ÿ�ʼŲ������,ÿ��������ǰŲ��len��λ��
			for (int i = pos + len; i <= _size; i++)
			{
				_str[pos++] = _str[i];
			}
			_size -= len;
		}

	}

	void Append(const char* str)
	{
		size_t sz = strlen(str);
		if (_size + sz > _capacity)
		{
			Reserve(_size + sz);
		}
		//��'\0'λ�ÿ�ʼ�����ַ���str
		strcpy(_str + _size, str);
		_size += sz;
	}

private:
	char* _str;
	size_t _size;
	size_t _capacity;
};
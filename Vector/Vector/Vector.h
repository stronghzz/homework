#pragma once
#include <vector>
#include <iostream>
#include <assert.h>
#include <string>
using namespace std;
template <class T>
class Vector
{
public:

	typedef T* iterator;
	typedef const T* const_iterator;
	//vector��ʼ������
	Vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _endOfStorage(nullptr)
	{}

	void PushBack(const T& val)
	{
		//�ж�����
		/*if (_finish == _endOfStorage)
		{
			size_t newCapacity = _start == nullptr ? 1 : 2 * Capacity();
			Reserve(newCapacity);
		}
		*_finish++ = val;*/
		Insert(end(), val);
	}

	Vector(const Vector<T>& v)
	{
		//�������
		//���ռ�
		//����
		_start = new T[v.Capacity()];
		for (int i = 0; i < v.Size(); i++)
		{
			_start[i] = v[i];
		}
		_finish = _start + v.Size();
		_endOfStorage = _start + v.Capacity();
	}
	// v1 = v2 = v3 = v4
	//Vector<T>& operator=(const Vector<T>& v)
	//{
	//	//����Ƿ��Լ���ֵ
	//	//����ֵ���ͣ� ���ã� Ϊ��������ֵ
	//	//���أ� *this
	//	if (this != &v)
	//	{
	//		T* tmp = new T[v.Capacity()];
	//		for (int i = 0; i < v.Size(); i++)
	//		{
	//			tmp[i] = v[i];
	//		}
	//		if (_start)
	//		{
	//			delete[] _start;
	//		}
	//		_start = tmp;
	//		_finish = _start + v.Size();
	//		_endOfStorage = _start + v.Capacity();
	//	}

	//	return *this;
	//}
	// v1 = v2   v2 --> v  
	Vector<T> operator=(Vector<T> v)
	{
		Swap(v);
		return *this;
	}

	void Swap(Vector<T>& v)
	{
		swap(_start, v._start);
		swap(_finish, v._finish);
		swap(_endOfStorage, v._endOfStorage);
	}

	void PopBack()
	{
		Erase(end() - 1);
		//Erase(_finish - 1);
	}
	//�ɶ���д
	T& operator[](size_t pos)
	{
		assert(pos < Size());
		return _start[pos];
	}

	const T& operator[](size_t pos) const
	{
		assert(pos < Size());
		return _start[pos];
	}

	size_t Capacity() const
	{
		return _endOfStorage - _start;
	}

	bool Empty()
	{
		return _start == _finish;
	}

	size_t Size() const
	{
		return _finish - _start;
	}

	//�ɶ���д
	iterator begin()
	{
		return _start;
	}

	iterator end()
	{
		return _finish;
	}

	//ֻ��
	const_iterator begin() const 
	{
		return _start;
	}

	const_iterator end() const
	{
		return _finish;
	}

	void Reserve(size_t n)
	{
		if (n > Capacity())
		{
			int len = Size();
			//�����µĿռ�
			T* tmp = new T[n];
			//����ԭ�пռ������
			// memcpy : ǳ����
			/*if (_start)
			{
				memcpy(tmp, _start, sizeof(T)* len);
				delete[] _start;
			}*/
			// �����Զ������͵ĸ�ֵ��������أ��������
			if (_start)
			{
				for (int i = 0; i < len; i++)
				{
					tmp[i] = _start[i];
				}
				delete[] _start;
			}
			//����ָ��
			_start = tmp;
			_finish = _start + len;
			_endOfStorage = _start + n;
		}
	}

	// ����ᵼ�µ�����ʧЧ�� ���ݣ� ԭ�пռ䱻�ͷţ�������ָ���λ��ʧЧ
	void Insert(iterator pos, const T& val)
	{
		assert(pos <= _finish && pos >= _start);
		size_t len = pos - _start;
		//���ռ��Ƿ��㹻
		if (_finish == _endOfStorage)
		{
			size_t newC = _start == nullptr ? 1 : 2 * Capacity();
			Reserve(newC);
		}
		//����֮�󣬸��µ�����
		pos = _start + len;
		iterator end = _finish;
		//�Ӻ���ǰŲ��Ԫ�أ��ڳ�pos�Ŀռ䣬����µ�Ԫ��val
		while (end > pos)
		{
			*end = *(end - 1);
			end--;
		}

		*pos = val;
		_finish++;
	}

	iterator Erase(iterator pos)
	{
		assert(pos < _finish && pos >= _start);
		iterator begin = pos + 1;
		//��pos+1������ǰŲ��Ԫ��
		while (begin < _finish)
		{
			// pos + 1 --> pos
			// _finish - 1 --> _finish - 2
			*(begin - 1) = *begin;
			++begin;
		}

		--_finish;

		return pos;
	}

	void Resize(size_t n, const T& val = T())
	{
		if (n <= Size())
		{
			_finish = _start + n;
		}
		else
		{
			if (n > Capacity())
				Reserve(n);
			//����λ�ø�ֵ
			while (_finish != _start + n)
			{
				*_finish = val;
				++_finish;
			}
		}
	}

	~Vector()
	{
		if (_start)
		{
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}
	}
private:
	T* _start;
	T* _finish;
	T* _endOfStorage;
};
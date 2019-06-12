
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
using namespace std;

//class Person
//{
//public:
//	Person(const char*name,const char*gender,int age)
//	{
//		strcpy(_name, name);
//		strcpy(_gender, gender);
//		_age = age;
//	}
//	void Print()
//	{
//		cout << _name <<' ' <<_gender<<' ' << _age<<endl;
//	}
//private:
//	char _name[20];
//	char _gender[3];
//	int _age;
//};
//
//class Teacher :public Person
//{
//public:
//	Teacher(const char*name, const char*gender, int age,const char*major,const char* title,const char* course)
//		:Person(name, gender, age)
//	{
//		strcpy(_major, major);
//		strcpy(_title, title);
//		strcpy(_course, course);
//	}
//	void Print()
//	{
//		Person::Print();
//		cout << _major<<' ' <<' '<< _title<<' ' << _course;
//	}
//private:
//	char _major[20];
//	char _title[20];
//	char _course[20];
//
//};
//
//int main()
//{
//	//Person p("peter", "��", 18);
//	//p.Print();
//	Teacher t("tom", "��", 20, "����", "��ʦ", "ͨ��");
//	t.Print();
//	return 0;
//}


//class Base
//{
//public:
//	virtual void display()
//	{
//		cout << " this is Base" << endl;
//	}
//};
//class FirstB :public Base
//{
//public:
//	virtual void display()
//	{
//		cout << "this is FirstB" << endl;
//	}
//};
//class SecondB :public Base
//{
//public:
//	virtual void display()
//	{
//		cout << "this is SecondB"<< endl;
//	}
//};
//
//int main()
//{
//	Base* ptr;
//	Base b1;
//	FirstB f1;
//	SecondB s1;
//	ptr = &b1;
//	ptr->display();
//	ptr = &f1;
//	ptr->display();
//	ptr = &s1;
//	ptr->display();
//	return 0;
//}

//class Shape
//{
//public:
//	virtual double area()
//	{
//		return 0;
//	}
//};
//class Circle :public Shape
//{
//public:
//	Circle(double centerX,double centerY,double radius)
//		:_radius(radius)
//	{
//	}
//	virtual double area()
//	{
//		return 3.14*_radius*_radius;
//	}
//private:
//	double _radius;
//};
//class Square:public Shape
//{
//public:
//	Square(double centerX,double centerY,double peakX,double peakY)
//	{
//		_width = 2 * abs(peakY - centerY);
//	}
//	virtual double area()
//	{
//		return _width * _width;
//	}
//private:
//	double _width;
//};
//class Rectangle :public Shape
//{
//public:
//	Rectangle(double centerX, double centerY, double peak1X, double peak1Y,double peak2X,double peak2Y)
//	{
//		_width = 2 * abs(peak1Y - centerY);
//		_long = abs(peak2X - peak1X);
//	}
//	virtual double area()
//	{
//		return _width * _long;
//	}
//private:
//	double _width;
//	double _long;
//};
//int main()
//{
//	Shape* ptr;
//	Square s(0,0,5,5);
//	ptr = &s;
//	cout<< ptr->area()<<endl;
//	Circle c(0, 0, 5);
//	ptr = &c;
//	cout << ptr->area()<<endl;
//	Rectangle r(0, 0, 5, 5, -5, 5);
//	ptr = &r;
//	cout << ptr->area();
//	return 0;
//}
//class Student
//{
//public:
//	Student(const char* name,int num,const char* grade,const char* addr,int numcourse,const char* major)
//	{
//		strcpy(_name, name);
//		_num = num;
//		strcpy(_grade, grade);
//		strcpy(_addr, addr);
//		_numcourse = numcourse;
//		strcpy(_major, major);
//	}
//	virtual void print()
//	{
//		cout << _name<<' '<<_num<<' '<<_grade<<' '<<_addr<<' '<<_numcourse<<' '<<_major << endl;
//	}
//private:
//	char _name[20];
//	int _num;
//	char _grade[20];
//	char _addr[20];
//	int _numcourse;
//	char _major[20];
//};
//class IntStudent :public Student
//{
//public:
//	IntStudent(const char* name, int num, const char* grade, const char* addr, int numcourse, const char* major)
//		:Student(name,num,grade,addr,numcourse,major)
//	{}
//	virtual void print()
//	{
//		cout << "ѧ������:��У��" << endl;
//		Student::print();
//	}
//
//};
//class CorStudent :public Student
//{
//public:
//	CorStudent(const char* name, int num, const char* grade, const char* addr, int numcourse, const char* major)
//		:Student(name, num, grade, addr, numcourse, major)
//	{}
//	virtual void print()
//	{
//		cout << "ѧ�����ͣ�������" << endl;
//		Student::print();
//	}
//};
//int main()
//{
//	Student* ptr;
//	IntStudent s1("peter", 15040204, "����", "����", 11,"����");
//	ptr = &s1;
//	ptr->print();
//	CorStudent s2("tom", 16040204, "����", "����", 12, "ͨ��");
//	ptr = &s2;
//	ptr->print();
//	return 0;
//}

class Shape
{
public:
	virtual void Print()
	{
		
	}
};
class Circle :public Shape
{
public:
	Circle(double centerX,double centerY,double radius)
		:_radius(radius)
	{
	}
	virtual void Print()
	{
		double ret = 2 * 3.14*_radius;
		cout << "Բ���ܳ���" << ret << endl;
	}
private:
	double _radius;
};
class Square:public Shape
{
public:
	Square(double centerX,double centerY,double peakX,double peakY)
	{
		_width = 2 * abs(peakY - centerY);
	}
	virtual void Print()
	{
		double ret = 4 * _width;
		cout << "�������ܳ���" << ret << endl;
	}
private:
	double _width;
};

int main()
{
	Shape* p1, *p2;
	p1 = new Circle(3, 3.5, 2);
	p2 = new Square(4.5, 5, 6.2, 5);
	p1->Print();
	p2->Print();

	delete p1, p2;
	return 0;
}
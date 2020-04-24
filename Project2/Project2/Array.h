#ifndef __ARRAY__
#define __ARRAY__

#include <stdio.h>
#include <cstdlib>
#include <iostream>
using namespace std;

template <typename T>//template T ����
class Array {
protected:
	T* data;//array�� data
	int len;//array�� ũ��
public:
	Array(int size) //array����
	{
		if (size < 1)//size�� 1���� ������, error ���
			cout << "Size�� 1���� �۽��ϴ�." << endl;
		else//size�� ������ �ƴҽ� array����
		{
			len = size;
			data = new T[size];
			cout << "Data �����Ϸ�" << endl;
		}
	};

	~Array() //�Ҹ���, array ����
	{
		delete(data);
		cout << "Data �Ҹ�Ϸ�" << endl;
	};

	int length() const //array�� ũ���� len return
	{
		return len;
	};

	virtual T& operator[](int i)//virtual�� ���� ����Ÿ�� ������ ����
	{
		static T tmp;

		if (i >= 0 && i < len)//i�� array�� size�� �����ҽ� data[i] return
			return data[i];
		else//i�� array�� size���� ���Ͻ� error ���
		{
			cout << "���� ���Դϴ�" << endl;
			return tmp;
		}
	};

	T operator[](int i)const
	{
		if (i >= 0 && i < len)//i�� array�� size�� �����ҽ� data[i] return
			return data[i];
		else//i�� array�� size���� ���Ͻ� error ���
		{
			cout << "���� ���Դϴ�" << endl;
			return 0;
		}
	};

	void print() //array�� �����ϴ� ��� ���� ���
	{
		int i; cout << "[";
		for (i = 0; i < len; i++)
			cout << " " << data[i];
		cout << " ]" << endl;

	};
};

#endif

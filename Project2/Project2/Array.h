#ifndef __ARRAY__
#define __ARRAY__

#include <stdio.h>
#include <cstdlib>
#include <iostream>
using namespace std;

template <typename T>//template T 형성
class Array {
protected:
	T* data;//array의 data
	int len;//array의 크기
public:
	Array(int size) //array생성
	{
		if (size < 1)//size가 1보다 작을시, error 출력
			cout << "Size가 1보다 작습니다." << endl;
		else//size가 음수가 아닐시 array생성
		{
			len = size;
			data = new T[size];
			cout << "Data 생성완료" << endl;
		}
	};

	~Array() //소멸자, array 삭제
	{
		delete(data);
		cout << "Data 소멸완료" << endl;
	};

	int length() const //array의 크기인 len return
	{
		return len;
	};

	virtual T& operator[](int i)//virtual을 통해 서브타입 다형성 구축
	{
		static T tmp;

		if (i >= 0 && i < len)//i가 array의 size에 만족할시 data[i] return
			return data[i];
		else//i가 array의 size범위 밖일시 error 출력
		{
			cout << "범위 밖입니다" << endl;
			return tmp;
		}
	};

	T operator[](int i)const
	{
		if (i >= 0 && i < len)//i가 array의 size에 만족할시 data[i] return
			return data[i];
		else//i가 array의 size범위 밖일시 error 출력
		{
			cout << "범위 밖입니다" << endl;
			return 0;
		}
	};

	void print() //array에 존재하는 모든 원소 출력
	{
		int i; cout << "[";
		for (i = 0; i < len; i++)
			cout << " " << data[i];
		cout << " ]" << endl;

	};
};

#endif

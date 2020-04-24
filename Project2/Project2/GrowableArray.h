#include "Array.h"

template <typename T>
class GrowableArray : public Array<T> //Array class를 기반으로 상속
{
public:
	int len;//array의 크기
	GrowableArray(int size);
	T& operator[](int i);
	void print()//array의 모든 원소 출력
	{
		cout << "[";
		for (int i = 0; i < len; i++)
			cout << " " << this->data[i];
		cout << " ]" << endl;
	};
};

template <typename T>
GrowableArray<T>::GrowableArray(int size) :Array<T>(size)
{
	if (size < 1)//만약 size가 1보다 작을시 error 출력
		cout << "Size가 1보다 작습니다." << endl;
	else//아닐시, array 생성
	{
		this->data = new T[size];
		this->len = size;
	}
}

template <typename T>
T& GrowableArray<T>::operator[](int i)
{
	static T tmp;

	if (i > this->len)//만일 i가 현재 array의 크기보다 클시
	{
		int new_size = this->len;//새로운 size생성
		for (;;)//새로운 사이즈가 i보다 커질때까지 2배로 증가
		{
			if (new_size > i)
				break;
			new_size *= 2;
		}
		T *new_data = new T[new_size];//새로운 array생성
		for (int a = 0; a < new_size; a++)//기존 array의 data복사, 추가된 공간은 0으로 초기화
		{
			if (a < this->len)
				new_data[a] = this->data[a];
			else
				new_data[a] = 0;
		}
		T* pt = this->data; //새로운 array지정
		this->len = new_size;
		this->data = new_data;
		delete(pt); //기존 array삭제

		cout << "Data 범위 확장 완료" << endl;
	}

	if (i < 0)//만일 i가 음수일시 error 출력
	{
		cout << "Error! '-index'는 없습니다" << endl;
		return tmp;
	}
	else
		return this->data[i];
}
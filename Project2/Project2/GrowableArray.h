#include "Array.h"

template <typename T>
class GrowableArray : public Array<T> //Array class�� ������� ���
{
public:
	int len;//array�� ũ��
	GrowableArray(int size);
	T& operator[](int i);
	void print()//array�� ��� ���� ���
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
	if (size < 1)//���� size�� 1���� ������ error ���
		cout << "Size�� 1���� �۽��ϴ�." << endl;
	else//�ƴҽ�, array ����
	{
		this->data = new T[size];
		this->len = size;
	}
}

template <typename T>
T& GrowableArray<T>::operator[](int i)
{
	static T tmp;

	if (i > this->len)//���� i�� ���� array�� ũ�⺸�� Ŭ��
	{
		int new_size = this->len;//���ο� size����
		for (;;)//���ο� ����� i���� Ŀ�������� 2��� ����
		{
			if (new_size > i)
				break;
			new_size *= 2;
		}
		T *new_data = new T[new_size];//���ο� array����
		for (int a = 0; a < new_size; a++)//���� array�� data����, �߰��� ������ 0���� �ʱ�ȭ
		{
			if (a < this->len)
				new_data[a] = this->data[a];
			else
				new_data[a] = 0;
		}
		T* pt = this->data; //���ο� array����
		this->len = new_size;
		this->data = new_data;
		delete(pt); //���� array����

		cout << "Data ���� Ȯ�� �Ϸ�" << endl;
	}

	if (i < 0)//���� i�� �����Ͻ� error ���
	{
		cout << "Error! '-index'�� �����ϴ�" << endl;
		return tmp;
	}
	else
		return this->data[i];
}
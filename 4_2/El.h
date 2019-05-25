#pragma once
#include <iostream>
template <typename T>
class El
{
private:
	T data; 
	El<T> *next; // ��������� �� ����. ������� ����
public:
	T getData(); 
	void setData(T newData); // ���������� data
	El<T>* getLink(); //�������� ��������� �� ����. �������
	void setLink(El<T>* link); //���������� ��������� �� ����. �������
	El();
	~El();
};

#include "El.cpp"
#pragma once
#include <iostream>
#include "El.h"
#include <fstream>

using namespace std;

template <typename T>
class deque
{
	El<T>* head; // ��������� �� ������ ������� ����
	El<T>* tail; // ��������� �� ��������� ������� ����
	int size; // ���������� ���������
public:
	deque(); // ����������
	~deque(); // ����������
	deque(deque<T>& op2); //����������� �����������
	El<T>* getHead(); //��������� ��������� �� ������ �������
	void setHead(El<T>* newHead); //���������� ��������� �� ������ �������
	El<T>* getTail();//��������� ��������� �� ��������� �������
	void setTail(El<T>* newTail);//���������� ��������� �� ���������� �������
	void sizeEdit(int num); //�������� ���������� ���������
	deque<T>& operator-(int); // ���������� ��������� - / ���� a = b - 0
	deque<T>& operator+(const deque<T>& op2); // ���������� ��������� +
	deque<T>& operator=(deque<T>& op2);// ���������� ��������� =
	bool operator<(deque<T>& op2); // ���������� ��������� <
	friend ostream& operator << <T>(ostream& stream, deque<T>& op2); // ���������� ������
	friend istream& operator >> <T>(istream& stream, deque<T>& op2);// ���������� �����
};


#include "deque.cpp"
#ifndef FUNC_CPP
#define FUNC_CPP

#include <iostream>
#include "Func.h"
#include "El.cpp"
#include <fstream>

using namespace std;

template <typename T>
void worker(T) // � ����������� �� ���� ��� �� ���������� � ��� �������, T ������ ������ ����� 
{
	system("cls");
	int size = rand() % 30 + 1; // ������ �������� �� 1 �� 30
	int c = 0;

	cout << "�������� ����� : " << endl
		<< "1. ���������� ��� A � B" << endl
		<< "2. �������/������ ������ � ���" << endl
		<< "3. ������� ��������� ������� ����" << endl
		<< "4. ������� �������� ���� �����" << endl
		<< "5. �������� ��� ����" << endl;
	cin >> c; 
	deque<T> first_decue;
	deque<T> second_decue;
	deque<T> third_decue;
	system("cls");
	T buf;
	El<T>* ptr_head = first_decue.getHead(); // �������� ���������
	El<T>* ptr_tail = first_decue.getTail();
	for (int i = 0; i < size; i++) //��������� ���
	{
		if (!first_decue.getHead())
		{
			ptr_head = new El<T>;
			first_decue.setHead(ptr_head);
			buf = rand() % 10 + 1;
			ptr_head->setData(buf);
			first_decue.setTail(ptr_head);
		}
		else
		{
			ptr_tail = first_decue.getTail();
			ptr_tail->setLink(new El<T>);
			ptr_tail = ptr_tail->getLink();
			buf = rand() % 10 + 1;
			ptr_tail->setData(buf);
			first_decue.setTail(ptr_tail);
		}
	}
	first_decue.sizeEdit(size); // ������������� ������ ����
	ptr_head = second_decue.getHead(); // ���� ����� ��� � � ������
	ptr_tail = second_decue.getTail();
	for (int i = 0; i < size; i++)
	{
		if (!second_decue.getHead())
		{
			ptr_head = new El<T>;
			second_decue.setHead(ptr_head);
			buf = rand() % 10 + 1;
			ptr_head->setData(buf);
			second_decue.setTail(ptr_head);
		}
		else
		{
			ptr_tail = second_decue.getTail();
			ptr_tail->setLink(new El<T>);
			ptr_tail = ptr_tail->getLink();
			buf = rand() % 10 + 1;
			ptr_tail->setData(buf);
			second_decue.setTail(ptr_tail);
		}
	}
	second_decue.sizeEdit(size);

	system("cls");
	if (c != 2) // �� ���� ������� ����� ������� ����� ������� � �������� �������� ������ � �����
	{
		cout << "������ �: " << first_decue;
		cout << "������ B: " << second_decue;
		cout << endl;
	}
	switch (c)
	{
	case 1:
		first_decue = second_decue;  // ����������
		break;
	case 2:
		cin >> third_decue; //������ �����
		cout << third_decue; //������� ���
		break;
	case 3:
		first_decue - 0; // ������� ���������
		break;
	case 4:
		first_decue = first_decue + second_decue; //�������� �����
		break;
	case 5:
		first_decue < second_decue; // ���������
		break;
	}
	if (c != 2) // ����� �� ���� ����� ������� ������ ���������� ���� ����� ���������
	{
		cout << endl << "����� ��������� " << endl;
		cout << "������ �: " << first_decue;
		cout << "������ B: " << second_decue;
	}
	system("pause");
}

#endif
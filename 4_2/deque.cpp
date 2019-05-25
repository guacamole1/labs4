#ifndef DEQUE
#define DEQUE

#include "deque.h"
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

template <typename T>
deque<T>::deque()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

template <typename T>
deque<T>::~deque()
{
	if (head) // ���� ��������� �� �������
	{
		El<T>* current = head->getLink(); // �� �������� ��� ��������� �� ���� �������
		El<T>* buf;
		delete head; //������� ������ �������
		while (current) // ���������� ������ ���� �������� �� ����������
		{
			buf = current->getLink(); // �������� ���������
			delete current; // � ������� ��������
			current = buf;
		}
	}
}


template<typename T>
deque<T>::deque(deque<T>& op2)
{
	if (!op2.size) // �������� �� �������
	{
		cout << "������ ����" << endl;
		system("pause");
	}
	size = op2.size; // �������� ��������� ���������
	El<T>* current = op2.getHead(); //������� ��������� �� ������ �������
	El<T>* ptr = new El<T>; // �������� ������ ��� �������
	ptr->setData(current->getData()); //�������� ���� ������ �� ������� �������� ����������� ����
	setHead(ptr); //������������� ���� ������� ��� ������ � ����
	current = current->getLink(); // �������� ���������
	while (current != nullptr) //����� ��� ���� ����� ���� �� ��������� ��� ��������
	{
		ptr->setLink(new El<T>);
		ptr = ptr->getLink();
		ptr->setData(current->getData());
		current = current->getLink();
	}
	setTail(ptr); //��������� �� ��������� ������� ���������� ��� tail
}

template<typename T>
El<T>* deque<T>::getHead()
{
	return head;
}

template<typename T>
void deque<T>::setHead(El<T>* newHead)
{
	head = newHead;
}

template<typename T>
El<T>* deque<T>::getTail()
{
	return tail;
}

template<typename T>
void deque<T>::setTail(El<T>* newTail)
{
	tail = newTail;
}

template<typename T>
void deque<T>::sizeEdit(int num)
{
	size += num;
}

template <typename T>
deque<T>& deque<T>::operator-(int)
{
	El<T>* ptr = nullptr;
	switch (size) //���� ������ 0, �� �� ����
	{
	case 0:
		cout << "��� ������" << endl;
		break;
	case 1: // ���� 1, �� �� ��� � �������
		delete head;
		head = nullptr;
		tail = nullptr;
		cout << "������� ������� ��������" << endl;
		break;
		sizeEdit(-1);
	default: // ���� ����� ������, �� ������� ���������
		ptr = head;
		while (ptr->getLink() != tail) //���������� �� ����, ���� �� ������� �������������
		{
			ptr = ptr->getLink();
		}
		delete tail; //������� ���������
		tail = ptr; // � ���������� ������ ������������� ��� ��������� :)
		tail->setLink(NULL);
		cout << "������� ������� ��������" << endl;
		sizeEdit(-1); // ��������� ���������� ��������� �� 1
		break;
	}
	return *this;
}

template<typename T>
deque<T>& deque<T>::operator+(const deque<T>& op2)
{
	deque<T>* temp = new deque<T>;
	if (!size || !op2.size)
	{
		cout << "������ ����" << endl;
		system("pause");
		return *this;
	}
	temp->size = size + op2.size;
	El<T>* current = head;
	El<T>* ptr = new El<T>;
	ptr->setData(current->getData());
	temp->setHead(ptr);
	current = current->getLink();
	while (current != nullptr)
	{
		ptr->setLink(new El<T>);
		ptr = ptr->getLink();
		ptr->setData(current->getData());
		current = current->getLink();
	}
	current = op2.head;
	while (current != nullptr)
	{
		ptr->setLink(new El<T>);
		ptr = ptr->getLink();
		ptr->setData(current->getData());
		current = current->getLink();
	}
	cout << "���� ������� ����������" << endl;
	system("pause");
	temp->setTail(ptr);
	return *temp;
}

template<typename T>
deque<T>& deque<T>::operator=(deque<T>& op2)
{
	if (!op2.size)
	{
		cout << "������ ����" << endl;
		system("pause");
		return *this;
	}
	size = op2.size;
	El<T>* current = op2.getHead();
	El<T>* ptr = new El<T>;
	ptr->setData(current->getData());
	setHead(ptr);
	current = current->getLink();
	while (current != nullptr)
	{
		ptr->setLink(new El<T>);
		ptr = ptr->getLink();
		ptr->setData(current->getData());
		current = current->getLink();
	}
	setTail(ptr);
	return *this;
}

template<typename T>
bool deque<T>::operator<(deque<T>& op2)
{
	El<T>* ptr1 = getHead();
	El<T>* ptr2 = op2.getHead();
	for (int i = 0; i < size; i++)
	{
		if (ptr1->getData() > ptr2->getData()) 
		{
			cout << "� ������ ���� ����� ��� ������� " << i + 1 << " ������ ��� � �� ������ ����" << endl;
			return true;
		}
	}
	cout << "��� ����� �� ������ ���� ������ ��� � ������" << endl;
	return false;
}

template<typename T>
ostream& operator<<(ostream& stream, deque<T>& op2)
{

	El<T>* ptr = op2.getHead();
	if (!ptr)
		stream << "������: ����";
	else
	{
		stream << "������: ";
		while (ptr)
		{
			stream << ptr->getData() << " ";
			ptr = ptr->getLink();
		}
	}
	cout << endl;
	return stream;
}

template <typename T>
istream& operator >>(istream& stream, deque<T>& op2)
{
	T buf;
	cout << "������� ����� >> ";
	El<T>* ptr = op2.getTail();
	if (!op2.getHead())
	{
		op2.setHead(new El<T>);
		op2.setTail(op2.getHead());
	}
	else
	{
		ptr = op2.getTail();
		ptr->setLink(new El<T>);
		ptr = ptr->getLink();
	}
	stream >> buf;
	ptr = op2.getTail();
	ptr->setData(buf);
	op2.setTail(ptr);
	op2.sizeEdit(1);
	return stream;
}
#endif
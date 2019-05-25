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
	if (head) // если указатель не нулевой
	{
		El<T>* current = head->getLink(); // то получаем его указатель на след элемент
		El<T>* buf;
		delete head; //удаляем первый элемент
		while (current) // проходимся циклом пока элементы не закончатся
		{
			buf = current->getLink(); // сдвигаем указатель
			delete current; // и удаляем элементы
			current = buf;
		}
	}
}


template<typename T>
deque<T>::deque(deque<T>& op2)
{
	if (!op2.size) // проверка на пустоту
	{
		cout << "Объект пуст" << endl;
		system("pause");
	}
	size = op2.size; // копируем количесво элементов
	El<T>* current = op2.getHead(); //получем указатель на первый элемент
	El<T>* ptr = new El<T>; // выделяем память под элемент
	ptr->setData(current->getData()); //копируем туда данные из первого элемента копируемого дека
	setHead(ptr); //устанавливаем этот элемент как первый в деке
	current = current->getLink(); // сдвигаем указатель
	while (current != nullptr) //далее все тоже самое пока не скопируем все элементы
	{
		ptr->setLink(new El<T>);
		ptr = ptr->getLink();
		ptr->setData(current->getData());
		current = current->getLink();
	}
	setTail(ptr); //указатель на последний элемент запоминаем как tail
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
	switch (size) //если размер 0, то он пуст
	{
	case 0:
		cout << "Дек пустой" << endl;
		break;
	case 1: // если 1, то мы его и удаляем
		delete head;
		head = nullptr;
		tail = nullptr;
		cout << "Элемент успешно извлечен" << endl;
		break;
		sizeEdit(-1);
	default: // Если любой другой, то удаляем последний
		ptr = head;
		while (ptr->getLink() != tail) //проходимся по деку, пока не находим предпоследний
		{
			ptr = ptr->getLink();
		}
		delete tail; //удаляем последний
		tail = ptr; // И запоминаем бывший предпоследний как последний :)
		tail->setLink(NULL);
		cout << "Элемент успешно извлечен" << endl;
		sizeEdit(-1); // уменьшаем количество элементов на 1
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
		cout << "Объект пуст" << endl;
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
	cout << "Деки успешно объеденены" << endl;
	system("pause");
	temp->setTail(ptr);
	return *temp;
}

template<typename T>
deque<T>& deque<T>::operator=(deque<T>& op2)
{
	if (!op2.size)
	{
		cout << "Объект пуст" << endl;
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
			cout << "В первом деке число под номером " << i + 1 << " больше чем в во втором деке" << endl;
			return true;
		}
	}
	cout << "Все числа во втором деке больше чем в первом" << endl;
	return false;
}

template<typename T>
ostream& operator<<(ostream& stream, deque<T>& op2)
{

	El<T>* ptr = op2.getHead();
	if (!ptr)
		stream << "Объект: пуст";
	else
	{
		stream << "Объект: ";
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
	cout << "Введите число >> ";
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

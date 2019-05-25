#ifndef FUNC_CPP
#define FUNC_CPP

#include <iostream>
#include "Func.h"
#include "El.cpp"
#include <fstream>

using namespace std;

template <typename T>
void worker(T) // в зависимости от того что мы передавали в эту функцию, T станет нужным типом 
{
	system("cls");
	int size = rand() % 30 + 1; // размер рандомно от 1 до 30
	int c = 0;

	cout << "Выберите пункт : " << endl
		<< "1. Приравнять Дек A к B" << endl
		<< "2. Вывести/ввести данные в дек" << endl
		<< "3. Извлечь последний элемент дека" << endl
		<< "4. Сложить элементы двух деков" << endl
		<< "5. Сравнить два дека" << endl;
	cin >> c; 
	deque<T> first_decue;
	deque<T> second_decue;
	deque<T> third_decue;
	system("cls");
	T buf;
	El<T>* ptr_head = first_decue.getHead(); // получаем указатели
	El<T>* ptr_tail = first_decue.getTail();
	for (int i = 0; i < size; i++) //заполняем дек
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
	first_decue.sizeEdit(size); // устанавливаем размер дека
	ptr_head = second_decue.getHead(); // тоже самое как и с первым
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
	if (c != 2) // во всех случаях кроме второго нужно вывести и показать исходные данные в деках
	{
		cout << "Массив А: " << first_decue;
		cout << "Массив B: " << second_decue;
		cout << endl;
	}
	switch (c)
	{
	case 1:
		first_decue = second_decue;  // сравниваем
		break;
	case 2:
		cin >> third_decue; //вводим число
		cout << third_decue; //выводим дек
		break;
	case 3:
		first_decue - 0; // убираем последний
		break;
	case 4:
		first_decue = first_decue + second_decue; //сложение деков
		break;
	case 5:
		first_decue < second_decue; // сравнение
		break;
	}
	if (c != 2) // также во всех кроме второго пункта показываем деки после изменений
	{
		cout << endl << "После изменений " << endl;
		cout << "Массив А: " << first_decue;
		cout << "Массив B: " << second_decue;
	}
	system("pause");
}

#endif

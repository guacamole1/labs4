#pragma once
#include <iostream>
#include "El.h"
#include <fstream>

using namespace std;

template <typename T>
class deque
{
	El<T>* head; // Указатель на первый элемент дека
	El<T>* tail; // Указатель на последний элемент дека
	int size; // Количество элементов
public:
	deque(); // Констуктор
	~deque(); // Деструктор
	deque(deque<T>& op2); //Конструктор копирования
	El<T>* getHead(); //Получение указателя на первый элемент
	void setHead(El<T>* newHead); //Установить указатель на первый элемент
	El<T>* getTail();//Получение указателя на последний элемент
	void setTail(El<T>* newTail);//Установить указатель на ппоследний элемент
	void sizeEdit(int num); //Изменить количество элементов
	deque<T>& operator-(int); // Перегрузка оператора - / вида a = b - 0
	deque<T>& operator+(const deque<T>& op2); // Перегрузка оператора +
	deque<T>& operator=(deque<T>& op2);// Перегрузка оператора =
	bool operator<(deque<T>& op2); // Перегрузка оператора <
	friend ostream& operator << <T>(ostream& stream, deque<T>& op2); // Перегрузка вывода
	friend istream& operator >> <T>(istream& stream, deque<T>& op2);// Перегрузка ввода
};


#include "deque.cpp"
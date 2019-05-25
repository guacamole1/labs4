#pragma once
#include <iostream>
template <typename T>
class El
{
private:
	T data; 
	El<T> *next; // указатель на след. элемент дека
public:
	T getData(); 
	void setData(T newData); // установить data
	El<T>* getLink(); //получить указатель на след. элемент
	void setLink(El<T>* link); //установить указатель на след. элемент
	El();
	~El();
};

#include "El.cpp"
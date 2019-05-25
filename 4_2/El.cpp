#ifndef EL
#define EL

#include "El.h"
#include <iostream>
#include <ctime>
#include <string>
using namespace std;

template<typename T>
T El<T>::getData()
{
	return data;
}

template<typename T>
void El<T>::setData(T newData)
{
	data = newData;
}

template<typename T>
El<T>* El<T>::getLink()
{
	return next;
}

template<typename T>
void El<T>::setLink(El<T>* link)
{
	next = link;
}

template<typename T>
inline El<T>::El()
{
	data = 0;
	next = NULL;
}

template<typename T>
inline El<T>::~El()
{
}
#endif
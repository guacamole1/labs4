#include <iostream>
#include <random>
#include <ctime>
#include <string>

using namespace std;
// вывод массива
template <typename T> 
void show(T* ptr, int size) {
	for (int i = 0; i < size; i++) {
		cout << ptr[i] << ' ';
	}
	cout << endl;
}

template <typename T>
float avVal(T* ptr, int size)
{
	cout << "Исходный массив: ";
	show(ptr, size);
	float sr = 0.0;
	for (int i = 0; i < size; i++)
	{
		sr += (float)ptr[i];
	}
	cout << "Среднее значение: " << sr/size << endl;
	return sr/size;
}

int main() {
	setlocale(LC_ALL, "Rus");

	srand(time(NULL));
	int size = rand() % 20 + 1;

	int* int_mass = new int[size];
	char* char_mass = new char[size];
	float* float_mass = new float[size];
	double* double_mass = new double[size];

	for (int i = 0; i < size; i++) {
		int_mass[i] = rand() % 50 + 50;
		char_mass[i] = rand() % 127 + 33;
		float_mass[i] = float(rand() % 50 + 50) / float(rand() % 50 + 50);
		double_mass[i] = (double(rand() % 50) + 50) / (double(rand() % 50) + 50);
	}

	int value;
	while (true) {
		system("cls");
		cout << "Меню выбора типа:" << endl
		 << "1. int" << endl
		 << "2. char" << endl
		 << "3. float" << endl
		 << "4. double" << endl
		 << "0. Выход" << endl
		 << "Ваш выбор: ";
		cin >> value;
		try
		{
			if (!(value >= 0 && value <= 4))
			{
				throw "Ошибка: Не верный выбор в меню";
			}
		}
		catch (const char *i)
		{
			cout << i << endl;
		}
		switch (value) {
		case 1: 
			avVal(int_mass, size); 
			break;
		case 2: 
			avVal(char_mass, size);
			break;
		case 3: 
			avVal(float_mass, size);
			break;
		case 4: 
			avVal(double_mass, size);
			break;
		case 0: 
			return 0;
		}
		system("pause");
	}
	delete[] int_mass;
	delete[] char_mass;
	delete[] float_mass;
	delete[] double_mass;
	return 0;
}
#include <iostream>
#include "Func.h"
#include "deque.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	int �; 
	while (true)
	{
		system("cls");
		cout << "���� ������ ���� ��������� ����:" << endl
			<< "1. int" << endl
			<< "2. char" << endl
			<< "3. float" << endl
			<< "4. double" << endl
			<< "5. �����" << endl;
		cin >> �; // �������� ������ ��� ��� ����
		switch (�) {
		case 1: 
			worker(1); // � ����������� �� ���� ������� �� �������, ���������� ����� �������� 
			break;
		case 2: 
			worker('c');
			break;
		case 3: 
			worker(1.0f);
			break;
		case 4: 
			worker(1.0);
			break;
		case 5:
			return 0;
		}
		system("pause");
	}
}

// BubbleSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int *array = new int[15];

void BubbleSort(int array[], unsigned int size)
{
	bool change = true;
	while (change == true)
	{
		change = false;
		for (int i = 0; i < size - 1; ++i)
		{
			if (array[i] > array[i + 1])
			{
				int a = array[i];
				array[i] = array[i + 1];
				array[i + 1] = a;
				change = true;
			}
		}
	}
}
int main()
{
	for (int i = 0; i < 15; i++)
		array[i] = 15 - i;
	BubbleSort(array, 15);
	for (int i = 0; i < 15; i++)
		std::cout << "Czarek to chuj x" << array[i] << "\n";
	delete[] array;
	int y;
	std::cin >> y;
	return 0;
}

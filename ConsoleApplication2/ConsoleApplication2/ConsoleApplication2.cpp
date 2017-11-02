// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

void InsertionSort(unsigned int array[], unsigned int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (array[i] < array[j])
			{
				int a = array[i];
				for (int k = i; k > j; k--)
				{
					array[k] = array[k - 1];
				}
				array[j] = a;
			}
		}
	}
}

int main()
{
	unsigned int tab[6] = { 2,1,3,5,1,0 };
	InsertionSort(tab, 6);
	for (int i = 0;i < 6;i++)
		std::cout << tab[i] << ", ";
	return 0;
}


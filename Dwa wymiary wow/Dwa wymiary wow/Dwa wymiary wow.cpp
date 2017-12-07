// Dwa wymiary wow.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

void PrintArray(int **array, int depth)
{
	int x = 1;
	for (int i = 0; i < depth; i++)
	{
		for (int j = 0; j < x; j++)
		{
			std::cout << *(*(array + i) + j) << " ";
			if (i < (depth / 2) - 1)
				x = x * 2;
			else if (i >= depth / 2)
			{
				x = x / 2;
			}
		}
		std::cout << "\n";
	}
}


void FillArray(int depth)
{	
	//alokacja
	int x = 1;
	int **array = new int*[depth];
	for (int i = 0; i < depth; i++)
	{
		array[i] = new int[x];
		if (i < (depth / 2) - 1)
			x = x * 2;
		else if (i >= depth / 2 && i<depth-1)
		{
			x = x / 2;
		}
	}
	//wype³nienie
	x = 1;
	int a = 1;
	for (int i = 0; i < depth; i++)
	{
		for (int j = 0; j < x; j++)
		{
			*(*(array + i) + j) = a;
			a++;
			if (i < (depth / 2) - 1)
				x = x * 2;
			else if (i >= depth / 2)
			{
				x = x / 2;
			}
		}
	}
	//wypisywanie
	PrintArray(array, depth);
	//dealokacja
	for (int i = 0; i < depth; i++)
	{
		delete[] array[i];
	}
	delete array;
}

int main()
{
	FillArray(6);
    return 0;
}


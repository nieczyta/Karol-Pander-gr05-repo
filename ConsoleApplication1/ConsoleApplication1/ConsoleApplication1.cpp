// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int FindSpan(int array[], unsigned int size)
{
	int min = array[0];
	int max = array[0];
	for (int i = 0; i < size; ++i)
	{
		if (array[i] > max)
			max = array[i];
		if (array[i] < min)
			min = array[i];
	}
	int span = max - min;
	return span;
}
int main()
{
	return 0;
}
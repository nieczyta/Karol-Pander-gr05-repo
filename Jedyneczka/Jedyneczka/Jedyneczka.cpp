// Jedyneczka.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

struct Point
{
	double x;
	double y;
};

struct Triangle
{
	Point p1;
	Point p2;
	Point p3;
}a, b, c, d;

void savet(Triangle array[], unsigned int size)
{
	std::ofstream file;
	file.open("jedyneczka.txt", std::ios::trunc | std::ios::app);
	file << "123";
}
void saveb(Triangle array[], unsigned int size)
{

}

int main()
{
	//a
	a.p1.x = 1;
	a.p1.y = 1;
	a.p2.x = 5;
	a.p2.y = 1;
	a.p3.x = 1;
	a.p3.y = 5;
	//b
	b.p1.x = -1;
	b.p1.y = 1;
	b.p2.x = -5;
	b.p2.y = 1;
	b.p3.x = -1;
	b.p3.y = 5;
	//c
	c.p1.x = -1;
	c.p1.y = -1;
	c.p2.x = -5;
	c.p2.y = -1;
	c.p3.x = -1;
	c.p3.y = -5;
	//d
	d.p1.x = 1;
	d.p1.y = -1;
	d.p2.x = 5;
	d.p2.y = -1;
	d.p3.x = 1;
	d.p3.y = -5;
	struct Triangle tab[4] = { a,b,c,d };
	save(tab, 4);
	return 0;
}


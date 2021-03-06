// Jedyneczka.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

char Forward(int a, char x)
{
	if (x + a > 126)
	{
		x = 32 + (x + a - 127);
	}
	else
	{
		x = x + a;
	}
	return x;
}

char Backward(int a, char x)
{
	if (x - a < 32)
	{
		x = 126 - (31-x+a);
	}
	else
	{
		x = x - a;
	}
	return x;
}

int main()
{		

		std::string code;
		std::cout << "Enter the five digit code: \n";
		getline(std::cin, code);
		int codeint[5];
		int len1 = code.length();
		if (len1 < 5)
		{
			for (int i = 0; i < 5 - len1; i++)
				codeint[len1+i] = 0;
		}
		for (int i = 0; i < len1; i++)
			codeint[i] = code[i]-48;
		for (int i = 0; i < 5; i++)
			std::cout << codeint[i];
		std::cout << "Press\n1. To code the file\n2. To decode the file\n";
		int wybor;
		std::cin >> wybor;
		std::string filename;
		std::cout << "Enter the file path: \n";
		std::cin >> filename;
		std::ifstream file(filename);
		if (file.good() == false)
		{
			std::cout << "Unable to open the file."; 
			exit(0);
		}
		std::string line;
		std::ofstream file2;
		std::string file2name;
		if (wybor==1)
			std::cout << "Enter the coded file path. \n";
		else if (wybor == 2)
			std::cout << "Enter the decoded file path. \n";
		std::cin >> file2name;
		file2.open(file2name.c_str(), std::ios::out);
		while (getline(file, line))
		{
				int len = line.length();
				if (wybor == 1)
				{
					for (int i = 0; i < len; ++i)
					{
						if (i % 5 == 0)
						{
							line[i] = Backward(codeint[0] + codeint[1] + 1, line[i]);
						}
						else if (i % 5 == 1)
						{
							line[i] = Forward(codeint[1] + codeint[2] + 2, line[i]);
						}
						else if (i % 5 == 2)
						{
							line[i] = Backward(codeint[2] + codeint[3] + 3, line[i]);
						}
						else if (i % 5 == 3)
						{
							line[i] = Forward(codeint[3] + codeint[4] + 4, line[i]);
						}
						else if (i % 5 == 4)
						{
							line[i] = Backward(codeint[4] + codeint[0] + 5, line[i]);
						}
					}
				}
				if (wybor == 2)
				{
					for (int i = 0; i < len; ++i)
					{
						if (i % 5 == 0)
						{
							line[i] = Forward(codeint[0] + codeint[1] + 1, line[i]);
						}
						else if (i % 5 == 1)
						{
							line[i] = Backward(codeint[1] + codeint[2] + 2, line[i]);
						}
						else if (i % 5 == 2)
						{
							line[i] = Forward(codeint[2] + codeint[3] + 3, line[i]);
						}
						else if (i % 5 == 3)
						{
							line[i] = Backward(codeint[3] + codeint[4] + 4, line[i]);
						}
						else if (i % 5 == 4)
						{
							line[i] = Forward(codeint[4] + codeint[0] + 5, line[i]);
						}
					}
					
				}
			
			file2 << line << "\n";
		}
		file.close();
		file2.close();
	
	return 0;
}
	





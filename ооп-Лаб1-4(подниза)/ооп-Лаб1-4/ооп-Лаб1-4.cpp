// ооп-Лаб1-4.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;


int main()
{
	int n;
	char niza[20];
	cin.getline(niza,20);

	int poz, dol,i,l;
	cin >> poz >> dol;//podniza od kaj do kaj

	l = strlen(niza);
	for (i = poz - 1; i < dol;i++)
	{
		cout << niza[i] << endl;
	}


    system("pause");
}


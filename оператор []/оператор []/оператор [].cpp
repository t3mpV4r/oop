// оператор [].cpp : Defines the entry point for the console application.
//


#include <iostream>
using namespace std;

class niza
{
	int pole[5];
public:
	niza() //default konstruktor
	{
		int i;
		for (i = 0; i < 5; i++)
			pole[i] = i; 
	}
	int operator[](int i) // int &operator[](int i)
	{
		return pole[i];
	}
};

int main()
{
	niza ob;
	int i;
	for (i = 0; i < 5; i++)
		cout << ob[i];
	//ako sakam ob[i]+10;

    system("pause");
}


// динамичка (fucked) алокација.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <stdlib.h>

using namespace std;

class dinamicna
{
	int *p;
public:
	int n;
	dinamicna() //default
	{
		p = new int;
		*p = 0;
	}
	dinamicna(int i) //preoptovaren
	{
		p = new int;
		*p = i;
	}
	dinamicna(dinamicna &ob)//copy
	{
		p = new int;
		*p = ob.get();

		n = ob.n;
	}
	int get() { return *p; }
	dinamicna operator=(dinamicna &ob)//dodeluvanje
	{
		if (&ob != this)
		{
			delete p;
			p = new int;
			*p = ob.get();
			n = ob.n;
			return *this;
		}
		if (&ob == this)
			return *this;
	}

	~dinamicna()//destruktor
	{
		cout <<n<< " " << *p <<" Osloboduvanje \n"; 
		delete p;
	}
};

int main()
{
	dinamicna ob1(10);//*p =10
	dinamicna ob2;//*p=0
	ob1.n = 1;   ob2.n = 2;
	ob2 = ob1;//*p na ob2 =10
	cout << ob1.get() << "\n";
	cout << ob2.get() << "\n";

	system("pause");
}
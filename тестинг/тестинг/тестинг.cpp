// тестинг.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
using namespace std;


int main()
{   
	char  a[3];
	char *a1;
	a1 = a;

	
	cin >> a;
	cout << "tekstualna niza:\n";
	cout << *a1<<endl;
	cout << a1<<endl;

	int b;
	int *b1 = &b;
	cin >> b;
	cout << "int: \n";
	cout << *b1 << endl;
	cout << b1 << endl;

	string c,*c1=&c;
	cin >> c;
	cout << "string: \n";
	cout << *c1 << endl;
	cout << c1 << endl; 

	int d[3],*d1=d,i;
	for ( i =0; i < 3; i++)
		cin >> d[i];
	cout << "int niza: \n";

	for (i = 0; i < 3; i++)
		cout << *(d1 + i);
	cout << endl;

	cout << ++(*d1)<<endl;//d[0]=1 ,d1=1+1 (zgolemuva vrednost ++(*p) )
	cout << *(++d1)<<endl;//d[1]=2,d1=2 (zgolemuva adresa *(++p) )
	cout << (*d1)++ << endl;//d[1]=3,d1=2 postinc,vrednost
	cout << *d1 << endl;//d[1]=3,d1=3 
/*
	int niza[5] = { 0,1,2,3,4 };
	int *levo=niza, *desno=&niza[4];

	while (levo < desno)//1 < 4
	{
		int p = *levo;//p=0;
		*levo++ = *desno;//1 = 4
		*desno-- = p; //4=0
	}
	for (int i = 0; i < 4; i++)
		cout << niza[i];
	*/


    system("pause");
}


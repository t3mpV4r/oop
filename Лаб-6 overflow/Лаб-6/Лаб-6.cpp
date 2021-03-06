// Лаб-6.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

class tocka
{

	int x, y, z;
public:
	tocka() { x = y = z = 1; }//default
	tocka(int a, int b, int c) { x = a; y = b; z = c; }//preoptovaren 
	tocka(tocka &t) { x = t.x; y = t.y; z = t.z; }//copy

	tocka operator+(tocka &t)//sobiranje
	{
		x = x + t.x;
		y = y + t.y;
		z = z + t.z;
		return *this;
	}
	tocka operator=(tocka &t)//dodeluvanje
	{
		x = t.x;
		y = t.y;
		z = t.z;
		return *this;
	}
	tocka operator++()// ++t
	{
		++x;
		++y;
		++z;
		return *this;
	}
	tocka operator--()// --t
	{
		--x;
		--y;
		--z;
		return *this;
	}
	tocka operator++(int)// t++
	{
		tocka temp(*this);
		x++;
		y++;
		return temp;

	}
	int operator==(tocka &t)//sporeduvanje
	{
		return (x == t.x) && (y == t.y);
	}
	/*
	//inc pre&post so friend:
	friend tocka operator++(tocka &t)// ++t
	{
		t.x++;
		t.y++;
		return t;
	}
	friend tocka operator++(tocka &t,int k)//t++
	{
		tocka temp = t; //pomoshna
		t.x++;
		t.y++;
		return temp; //vrakjam pomoshnata
	} 
	*/
    friend ostream& operator << (ostream& o, const tocka &t)
	{ return o << "(" << t.x << "," << t.y <<","<<t.z<<")"; }
	friend istream& operator >>(istream& o, tocka &t)
	{ return o >> t.x >> t.y >> t.z; }


};

int main()
{
	tocka t1(5,9,2), t2,t3;
	cout << "Koordinati na Tocka1:" << t1<<endl;
	t2 = t1;
	cout << "Koordinati na Tocka2:" << t2<<endl;

	cout << "Dekrementirani koor. na Tocka1" << --t1<<endl;
	cout << "Incrementirani koor. na Tocka2" << ++t2<<endl;
	t2++;
	cout << "Tocka2" << t2 << endl;
	t3 = t1 + t2;
	cout << "Zbirot na dvete koordinati:" << t3<<endl;

	if (!(t1 == t2))
		cout << "t1 i t2 se razlicni \n";
	tocka t4;
	cin >> t4;
	cout << t4;


    system("pause");
}


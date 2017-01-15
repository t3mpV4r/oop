// Лаб3-1.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

class Triagolnik
{
    public:
	int a, b, c;

    public:
	Triagolnik()
	{
		a = b = c = 3;
	}
	void set(int a1, int b1, int c1)
	{
		a = a1;
		b = b1;
		c = c1;
	}
	void geta()
	{
		cout<<a;
	}
	void getb()
	{
		cout << b;
	}
	void getc()
	{
		cout << c;
	}
	int Perimetar() { return a + b + c; }
	int Plostina() { return a*b*c; }
	void pecati()
	{
		cout << a << "," << b << "," << c << endl;
	}
};

int main()
{
	Triagolnik t1, t2;
	int L, P;
	cout << "Vnesi gi stranite na triagolnikot \n";
	cin >> t2.a >> t2.b >> t2.c;
	t1.pecati();
	cout << "Triagolnik so strani:\n";
	t2.pecati();
	L = t2.Perimetar();
	P = t2.Plostina();
	cout << "ima perimetar:" << L << ",Plostina:" << P<<endl;
	
	system("pause");
}


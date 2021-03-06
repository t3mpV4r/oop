#include <iostream>
#include <cmath>
using namespace std;

class pravoagolnik
{
	int a, b;
public:
	pravoagolnik()//default
	{
		a = 2;
		b = 3;
	}
	pravoagolnik(int a, int b)//preoptovaren
	{
		this->a = a;
		this->b = b;
	}
	pravoagolnik(const pravoagolnik &ob)//copy
	{
		a = ob.a;
		b = ob.b;
	}
	void setPodatoci(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	float pravoagolnikP()
	{
		int s = (a + b + b) / 2;
		return sqrt(s*(s - a)*(s - b)*(s - b));
	}
	int L()
	{
		return a + 2 * b;
	}
	int geta()
	{
		return a;
	}
	int getb()
	{
		return b;
	}
	void print()
	{
		cout << "Plostina na pravoagolnikot e:" << pravoagolnikP() << endl;
		cout << "Perimetar na pravoagolnikot e:" << L() << endl;
	}
};
class kvadar :public pravoagolnik
{
	int c;
public:
	kvadar(){}
	kvadar(int a1, int b1, int c) :pravoagolnik(a1, b1) //preoptovaren
	{

		this->c = c;
	}
	kvadar(const kvadar &k) :pravoagolnik(k)//copy
	{
		c = k.c;
	}
	int kvadarP()
	{
		return 2 * pravoagolnikP();
	}
	int volumen()
	{
		return geta() * getb() * c;
	}
	void print()
	{
		cout << "plostina na kvadarot:" << kvadarP() << endl;
		cout << "volumen na kvadarot:" << volumen() << endl;
	}

	friend ostream &operator <<(ostream &o, kvadar &k)
	{
		return o << k.geta() << " " << k.getb() << " " << k.c << endl;
	}	
	int operator>(kvadar &ob)
	{
		return ob.volumen() > this->volumen();
	}

};


int main()
{
	pravoagolnik ob1;
	kvadar ob2(10, 6, 8);
	ob1.print();
	ob2.print();

	//tret del:
	kvadar k[5] = {kvadar(4,5,3),kvadar(1,4,6),kvadar(5,4,8),kvadar(5,3,6),kvadar(8,2,5) };

	kvadar max;
	for (int i = 0; i < 5; i++)
	{
		for (int j = i; j < 5; j++)
		{
			if (k[i] > k[j])
			{
				max = k[i];
				k[i] = k[j];
				k[j] = max;
			}
		}
	}
	cout << endl;
	cout << "kvadar so strani:" << k[0] <<"ima najgolem volumen:"<< k[0].volumen()<<endl;
	

	system("pause");

}
/*// Лаб8-1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cmath>
using namespace std;
class pravoagolnik
{
	int a, b;
public:
	pravoagolnik() { a = 2; b = 3; }//default
	void set(int a, int b) { this->a = a; this->b = b; }
	int pravoagolnikP()
	{int s = (a + b + b) / 2; return sqrt(s*(s - a)*(s - b)*(s - b));}
	int L() { return a + 2*b; }
	int seta(int a) { this->a = a; }
	int setb(int b) { this->b = b; }
	int geta() { return a; }
	int getb() { return b; }
	void print()
	{
		cout << "Plostina na pravoagolnikot e:" << pravoagolnikP() << endl;
		cout << "Perimetar na pravoagolnikot e:" << L() << endl;
	}
};
class kvadar :public pravoagolnik
{
	int c;
public:
	kvadar() { seta(4); setb(5); c = 3; }//default
	kvadar(int a1,int b1,int c) //preoptovaren
	{
		set(a1, b1);
		this->c = c;
	};
	int kvadarP()
	{
		return 2 * pravoagolnikP();
	}
	int volumen() { return geta() * getb() * c; }
	void print()
	{
		cout << "plostina na kvadarot:" << kvadarP() << endl;
		cout << "volumen na kvadarot:" << volumen() << endl;
	}
	kvadar operator>(kvadar &ob)
	{
		if (ob.volumen() > this->volumen())
			return ob;
		else if (ob.volumen() < this->volumen())
			return *this;
	}

};
int main()
{
	pravoagolnik ob1;
	kvadar ob2(10, 6, 8);
	ob1.print();
	ob2.print();

    system("pause");
}*/
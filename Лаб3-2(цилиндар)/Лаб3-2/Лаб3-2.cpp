// Лаб3-2.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;
class cilindar
{
public:
	int r, H;
public:
	cilindar() { r = 1; H = 3; }
	cilindar(int r1, int H1) { r = r1; H = H1; }
	void getr() { cout << r; }
	void getH() { cout << H; }
	void Plostina()
	{
		int P = 2 * r*3.14*(r + H);
		cout << P<<endl;
	}
	void Volumen()
	{
		int V = r*r*3.14*H;
		cout << V<<endl;
	}
	void pecati() { cout << r<<" i "<< H<<endl; }
};


int main()
{
	cilindar c1, c2(10,5), c3;
	cout << "Vnesi go radiusot i visinata na prviot cilindar \n";
	cin >> c1.r >> c1.H;
	cout << "ova se vrednostite za trite cilindri: \n";
	c1.pecati();
	c2.pecati();
	c3.pecati();
	cout << "Plostinite i Volumenite za trite,soodvetno:\n";
	c1.Plostina();
	c1.Volumen();
	cout << endl;
	c2.Plostina();
	c2.Volumen();
	cout << endl;
	c3.Plostina();
	c3.Volumen();

	system("pause");
}


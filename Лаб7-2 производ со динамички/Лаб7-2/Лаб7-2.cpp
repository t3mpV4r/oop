// Лаб7-2.cpp : Defines the entry point for the console application.

#include <iostream>
#include <cctype>
#include <string.h>
using namespace std;

class proizvod
{
	char *ime, *sifra, *proizvoditel;
	float cena;
	static float marza;
public:
	proizvod() {};
	proizvod(char *ime, char *proizvoditel, char *sifra)
	{
		this->ime = new char[strlen(ime) + 1];
		this->ime = ime;

		this->proizvoditel = new char[strlen(proizvoditel) + 1];
		this->proizvoditel = proizvoditel;


		this->sifra=sifra;
	}

	//destruktor
	~proizvod() { delete[] ime;  delete[] proizvoditel;}
	//vnes za cena
	void neto_cenaSet(float cena)
	{
		this->cena = cena;
	}
	float presmetkaCena() { return marza + cena; }
	void print()
	{
		cout << ime << endl;
		cout << proizvoditel << endl;
		cout << sifra << endl;
		cout << presmetkaCena() << endl;
	}
};
float proizvod::marza = 18;

int main()
{
	proizvod ob("kifla", "011254", "astra");
	ob.neto_cenaSet(25);
	ob.print();

	cout << endl;

	proizvod *p = new proizvod("cokolada", "12254", "astra");
	p->neto_cenaSet(43);
	p->print();

	system("pause");
}
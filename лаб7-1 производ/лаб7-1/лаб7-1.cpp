// лаб7-1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
using namespace std;

class proizvod
{
	string ime, sifra, proizvoditel;
	float cena;
	static float marza;
public:
	void set(string ime,string sifra,string proizvoditel, float marza1)
	{
		this->ime = ime;
		this->sifra = sifra;
		this->proizvoditel = proizvoditel;
		marza = marza1;
	}
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
	static float promenaMarza() { return marza++; }
};
float proizvod::marza = 18;

int main()
{
	proizvod ob;
	ob.set("kifla", "011254", "astra", 20.0);
	ob.neto_cenaSet(25);
	ob.print();

	cout << endl;

	proizvod *p = new proizvod;
	p->set("cokolada", "12254", "astra", 15.0);
	p->neto_cenaSet(43);
	p->print();

    system("pause");
}



#include <iostream>
#include <cmath>
using namespace std;

class ravenka
{
	float a, b, c;
public:
	ravenka(){}
	ravenka(float a1,float b1,float c1)//preoptovaren konstruktor
	{
		a = a1;
		b = b1;
		c = c1;
	}

	void set()//vnes na koef. na ravenkata
	{
		cout<<"vnesete positivni vrednosti na koeficientite \n";
		cout << "a=";
		cin >> a;

		cout << "b=";
		cin >>b;

		cout << "c=";
		cin >> c;
		cout << endl;
	}

	void print(){cout << a << "x^2+" << b << "x+" << c <<"=0"<<endl;}
	void koreni()
	{ cout << sqrt(a) << "x^2+" <<sqrt( b) << "x+" << sqrt(c) << "=0" << endl; }
	friend ravenka kopija(ravenka d);//prototip

};
ravenka kopija(ravenka d)
{
	ravenka temp;
	temp.a = d.a / 7;
	temp.b = d.b / 7;
	temp.c = d.c / 7;
	return temp;
}

int main()
{
	ravenka object, *p = &object;//pokazuvac na objekt od ista klasa
	p->set();
	p->print();
	p->koreni();
	p = &kopija(object);//pokazuva na func koja e nadvor od klasata
	p->print();


    system("pause");
}


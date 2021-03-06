/*Да се креира класа Vraboten со атрибути ime, prezime, starost и bodovi, како и
статички атрибут vrednostBod. Атрибутите ime и prezime треба да бидат динамички
објекти. Класата треба да има методи: функција за поставување на атрибутите без
bodovi, функција за поставување на bodovi, функција за враќање на секој атрибут
посебно, функција PresmetkaPlata за пресметка на платата како vrednostBod* bodovi и
функција за печатење според редослед: ime bodovi plata. Во главната програма да се
креира еден динамички објект на кој сите потребни податоци ќе му се внесат преку
тастатура и на екран ќе се испечат со користење на функцијата за печатење.*/

#include <iostream>
#include <string>
using namespace std;
class vraboten
{
	char *ime, *prezime;
	int vozrast, bodovi;
	static int vrednostBod;
public:
	vraboten(){}
	vraboten(char *ime,char *prezime,int vozrast,int bodovi)
	{
		this->ime = new char[strlen(ime) + 1];
		this->ime = ime;

		this->prezime = new char[strlen(prezime) + 1];
		this->prezime = prezime;

		this->vozrast = vozrast;
		this->bodovi = bodovi;

	}
	~vraboten() { delete[] ime;  delete[] prezime; }
	int presmetkaPlata() { return vrednostBod*bodovi; }
	void pecati()
	{
		cout << ime << "," << bodovi << "," << presmetkaPlata() << endl;
	}

};
int vraboten::vrednostBod = 2;
int main()
{
	vraboten *p = new vraboten("sara","kostovska",20,100);
	p->pecati();

	system("pause");
}


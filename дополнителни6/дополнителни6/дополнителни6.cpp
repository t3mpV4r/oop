/*Да се дефинира класа Sportist со атрибути име, година на раѓање и годишна
заработувачка во евра. Од оваа класа да се изведат две нови класи Fudbaler и Kosarkar.
За класата Fudbaler дополнително се чува броjот на одиграни натпревари. За класата
Kosarkar дополнително се чува пол (машки или женски) и даночна стапка. За секоjа од
класите да се напише соодветен конструктор. Да се напишат функции за пресметување
данокот за секој спортист, така што за фудбалерот се пресметува како даночната
стапка*вкупната годишна заработувачка, а за кошаркарот се пресметува како 5% од
годишната. (пр. 10 000€ * 5% = 500€) Да се преоптовари операторот проследување на
излезен тек << за спортист коj ќе ги печати на екран името, годината на раѓање,
заработувачката, како и данокот што треба да го плати спортистот. Програмата да се
тестира за еден фудбалер и еден кошаркар.*/

#include <iostream>
#include <string>
using namespace std;
class sportist //osnovna
{
	string ime;
	int roden, zarabotuvacka;
public:
	sportist(){}
	sportist(string ime, int roden, int zarabotuvacka)
	{
		this->ime = ime;
		this->roden = roden;
		this->zarabotuvacka = zarabotuvacka;
	}
	string getime() { return ime; }
	int getroden() { return roden; }
	int getz() { return zarabotuvacka; }	
};
class fudbaler:public sportist
{
	int brojNatprevari,danocnaStapka;
	string pol;
public:
	fudbaler():sportist(){}
	fudbaler(string ime, int roden, int zarabotuvacka, int brojNatprevari,string pol,int danocnaStapka) :sportist(ime,roden,zarabotuvacka)
	{
		this->brojNatprevari = brojNatprevari;
		this->pol = pol;
		this->danocnaStapka = danocnaStapka;
	}
	int getDanok() { return danocnaStapka*getz(); }

	friend ostream& operator<<(ostream &o, fudbaler &v)
	{
		o << v.getime() << "," << v.getroden() << "," << v.getz() << v.getDanok() << endl;
		return o;
	}

};
class kosharkar :public sportist
{
	int brojNatprevari;
	static  float danocnaStapka;
	string pol;
public:
	kosharkar() :sportist() {}
	kosharkar(string ime, int roden, int zarabotuvacka, int brojNatprevari, string pol) :sportist(ime, roden, zarabotuvacka)
	{
		this->brojNatprevari = brojNatprevari;
		this->pol = pol;
	}
	float getDanok()
	{
		return danocnaStapka*getz();
	}
	friend ostream& operator<<(ostream &o, kosharkar v)
	{
		o << v.getime() << "," << v.getroden() << "," << v.getz() << v.getDanok() << endl;
		return o;
	}

};
float kosharkar::danocnaStapka = 0.05;
int main()
{
	fudbaler ob1("Petar",1989,10000,5,"mashki",0.5);
	kosharkar ob2("Stefan", 1990, 20000, 5,"mashki");
	cout << ob1;
	cout << ob2;


    system("pause");
}

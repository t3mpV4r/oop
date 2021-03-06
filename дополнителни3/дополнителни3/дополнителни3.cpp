#include<iostream>
#include<cstring>
using namespace std;

class Imot
{
private:
	char *lokacija;
	int povrsina;

public:
	Imot() {}

	Imot(char *lokacija, int povrsina)
	{
		this->lokacija = lokacija;
		this->povrsina = povrsina;
	}
	int getPovrsina()
	{
		return povrsina;
	}
	char *getLokacija()
	{
		return lokacija;
	}

};

class PrivatnaSopstvenost :public Imot
{
private:
	char *sopstvenik;
	double cenametar;
	double danocnastapka;

public:

	PrivatnaSopstvenost() :Imot() {}
	PrivatnaSopstvenost(char *sopstvenik, double cenametar, double danocnastapka, char *lokacija, int povrsina) :Imot(lokacija, povrsina)
	{
		this->sopstvenik = sopstvenik;
		this->cenametar = cenametar;
		this->danocnastapka = danocnastapka;
	}

	float DanokPS()
	{
		return (double)(getPovrsina()*cenametar*danocnastapka) / 100.0;
	}



};

class DrzavnaSopstvenost :public Imot
{
private:
	int godina;

public:

	DrzavnaSopstvenost() :Imot() {}
	DrzavnaSopstvenost(int godina, char *lokacija, int povrsina) :Imot(lokacija, povrsina)
	{
		this->godina = godina;
	}

	float DanokDZ()
	{
		return (double)getPovrsina() * 15.0;
	}

};
ostream &operator <<(ostream &o, DrzavnaSopstvenost x)
{
	o << x.getPovrsina() << " " << x.getLokacija() << " " << x.DanokDZ() << endl;
	return o;
}
int main()
{

	PrivatnaSopstvenost ps("Mile", 25, 5, "Strumica", 100);

	DrzavnaSopstvenost ds(2005, "Skopje", 120);

	cout << ds << endl;


	system("pause");


}
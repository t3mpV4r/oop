#include<iostream>
#include<string>

using namespace std;

class Artikal
{
private:
	string ime;
	int cena;

public:
	Artikal() {}
	Artikal(string ime, int cena)
	{
		this->ime = ime;
		this->cena = cena;
	}

	bool operator==( Artikal &x)
	{
		return (this->cena == x.cena) && (this->ime == x.ime);
	}
	~Artikal() {}
	friend ostream &operator<<(ostream &o, Artikal x)
	{
		o << x.ime << " " << x.cena << endl;;
		return o;
	}

};

int main()
{

	Artikal a1("smoki", 15);
	Artikal a2("smoki", 15);
	Artikal a3("leb", 25);

	cout << a1;
	cout << a2;
	cout << a3;

	if (!(a1 == a2))
		cout << "ne se isti" << endl;
	else
		cout << "isti se" << endl;

	system("pause");
	return 0;
}
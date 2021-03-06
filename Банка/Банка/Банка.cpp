// Банка.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string.h>
using namespace std;

class OutOfBoundException
{
public:
	void msg()
	{
		cout << "Specijalnite karticki mozat da imat najmnogu 4 dopolnitelni pinovi \n";
	}
};

class Karticka //polimorfna
{

protected:
	char trSmetka[15];
	int pin;
public:
	Karticka(char trSmetka[15] = "", int pin = 0)
	{
		strcpy_s(this->trSmetka, trSmetka);
		this->pin = pin;
	}
	virtual ~Karticka(){}
	char *getTrSmetka()
	{
		return this->trSmetka;
	}
	int getPin()
	{
		return this->pin;
	}
	virtual int tezinaProbivanje()
	{
		int pom_pin = this->pin;
		int count = 0;
		while (pom_pin)
		{
			count++;
			pom_pin /= 10;
		}
		return count;
	}
	//pecatenje na objekt
	friend ostream &operator<<(ostream &output, Karticka &k)
	{
		output << k.trSmetka << ": " << k.tezinaProbivanje() << endl;
		return output;
	}

};

class SpecijalnaKarticka :public Karticka
{
protected:
	int n; //broj na drugi pinovi
public:
	static  const int P = 4;
	SpecijalnaKarticka(char trSmetka[15] = "", int pin = 0, int n = 0) :Karticka(trSmetka, pin)
	{
		this->n = n;
	}
	int  getN()
	{
		return this->n;
	}
	//tezina na probivanje
	int tezinaProbivanje()
	{
		return Karticka::tezinaProbivanje() + n;
	}
	//pecatenje na objekt
	friend ostream &operator<<(ostream &output, SpecijalnaKarticka &k)
	{
		output << k.trSmetka << ": " << k.tezinaProbivanje() << endl;
		return output;
	}
};

class BezbednosnaKarticka :public Karticka
{
protected:
	char secure_pin[15];
public:
	BezbednosnaKarticka(char trSmetka[15] = "", char secure_pin[15] = "") :Karticka(trSmetka)
	{
		strcpy_s(this->secure_pin, secure_pin);
	}
	char *get_SecP()
	{
		return this->secure_pin;
	}
	int tezinaProbivanje()
	{
		int l = strlen(secure_pin);
		int count = 0;
		for (int i = 0; i < l; i++)
		{
			if (isascii(secure_pin[i]))
				count++;
		}
		return (count)* 2;
	}
	//pecatenje
	friend ostream &operator<<(ostream &output,BezbednosnaKarticka &k)
	{
		output << k.trSmetka << ": " << k.tezinaProbivanje() << endl;
		return output;
	}
};
class Banka
{
	char ime[20];
	Karticka  *karticki[20];
	int br_karticki; //kolku karticki
	static int Probivna;
public:
	Banka(char *ime, Karticka *karticki[20], int br_karticki)
	{
		strcpy_s(this->ime, ime);
		this->br_karticki = br_karticki;

		for (int i = 0; i<br_karticki; i++)
		{
			BezbednosnaKarticka *b = dynamic_cast<BezbednosnaKarticka*>(karticki[i]);


			if (b)
			{
				this->karticki[i] = new BezbednosnaKarticka(b->getTrSmetka(), b->get_SecP());
			}

			else if(b == NULL)
			{
				SpecijalnaKarticka *s = dynamic_cast<SpecijalnaKarticka*>(karticki[i]);

				if (s)
				this->karticki[i] = new SpecijalnaKarticka(s->getTrSmetka(),s->getPin(),s->getN());

				else
				this->karticki[i] = new Karticka(karticki[i]->getTrSmetka(), karticki[i]->getPin());
			}

		}
	}

	void pecatiProbivni()
	{
		cout << "Vo " << this->ime << " banka,lesno probivni karticki,so tezini se:" << endl;
		
		for (int i = 0; i<br_karticki; i++)
		{
			if (karticki[i]->tezinaProbivanje() <= Probivna)
				cout << *karticki[i];
		}

	}
};
int Banka::Probivna = 7;

int main()
{
	Karticka **niza;

	int n, i, k;
	int pin;
    char secure_pin[15];
	char smetka[15];
	int d_PIN;

	cout << "vnesete broj na karticki:";
	cin >> n;

	niza = new Karticka*[n];

	for (i = 0; i < n; i++)
	{
		cout << "Vnesete od kakov tip e vasata karticka: (0-Obicna,1-Bezbednosna,2-Specijalna) \n";
		cin >> k;
		switch (k)
		{
		case 0:
			cout << "smetka:";
			cin >> smetka;
			cout << "pin:";
			cin >> pin;
			niza[i] = new Karticka(smetka, pin);
			break;
		case 1:
			cout << "smetka:";
			cin >> smetka;
			cout << "bezbednosen pin:";
			cin >> secure_pin;
			niza[i] = new BezbednosnaKarticka(smetka, secure_pin);
			break;
			
		case 2:
			cout << "smetka:";
			cin >> smetka;
			cout << "pin:";
			cin >> pin;
			cout << "broj na dopolnitelni pinovi:";

			dopolnitelni: cin >> d_PIN;
			try
			{
				if (d_PIN > SpecijalnaKarticka::P)
					throw OutOfBoundException();
			}
			catch (OutOfBoundException e)
			{
			  e.msg();
			}
			while (d_PIN > SpecijalnaKarticka::P || cin.fail())
			{
				cin.clear();
				cin.ignore(4, '\n');
				cout << "vnesete povtorno:";
				goto dopolnitelni;
			}
			niza[i] = new SpecijalnaKarticka(smetka, pin, d_PIN);
			break;
		default:
			break;

		}
	}
	
	Banka siera("Siera", niza, n);
	siera.pecatiProbivni();

	for (int i = 0; i < n; i++)
		delete niza[i];
	delete[] niza;

	system("pause");
}
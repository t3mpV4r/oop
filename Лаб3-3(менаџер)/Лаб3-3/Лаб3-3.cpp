#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;
const int MAX = 50;

class Vraboten
{
public:
	string ime, prezime, pozicija;
	int plata;

public:
	void separator2()
	{
		cout << "\n__________________________________________________________________________\n" << endl;
	}

	void vnesi_zapis(Vraboten podatoci[], int n) 
	{

		separator2();
		cout << endl;
	IME:   cout << "Vnesete ime na vraboteniot: \n";
		   cin >> ime;

		for (int i = 0; i<ime.size(); i++)
		{
			if (!isalpha(ime[i]) || (ime.size()>15))
			{
				cout << "Vnesovte pogresen vnes. Obidete se povtorno" << endl;
				goto IME;
			}
		}
	PREZIME:   cout << "Vnesete prezime na vraboteniot: \n";
		       cin >> prezime;

		for (int i = 0; i<prezime.size(); i++)
		{
			if (!isalpha(prezime[i]) || (prezime.size()>15))
			{
				cout << "Vnesovte pogresen vnes. Obidete se povtorno" << endl;
				goto PREZIME;
			}
		}
	POZICIJA:  cout << "Vnesete rabotna pozicija: \n";
		       cin >> pozicija;

		if (pozicija != "menadzer" && pozicija != "gotvac" && pozicija != "kelner" && pozicija != "shanker")

		{
			cout << "Vnesete korektno,rabotnite pozicii se:menadzer,gotvac,kelner,shanker" << endl;
			goto POZICIJA;
		}

	PLATA:    cout << "Vnesete plata: \n";
		      cin >> plata;
		while (cin.fail() || plata <0)
		{
			cin.clear();
			cin.ignore(6, '\n');//propushta 6 cifri,
			cout << "Vnesete validen broj \n";
			cin >> plata;
		}

		//dodeluvanje na vrednosti 
		podatoci[n].ime = ime;
		podatoci[n].prezime = prezime;
		podatoci[n].pozicija = pozicija;
		podatoci[n].plata = plata;


		cout << endl;
		separator2();

	}
	void sortPlata(Vraboten podatoci[], int n)
	{
		separator2();
		Vraboten temp;
		
		int i, j;
		for (i = 0; i<n; i++)
		{
			for (j = i; j < n; j++)

				if (podatoci[i].plata < podatoci[j].plata)
				{
					temp = podatoci[i];
					podatoci[i] = podatoci[j];
					podatoci[j] = temp;
				}
		}
		for (i = 0; i < n; i++)
		{

			cout << podatoci[i].ime << endl;
			cout << podatoci[i].prezime << endl;
			cout << podatoci[i].pozicija << endl;
			cout << podatoci[i].plata << endl;
			cout << endl;

		}
		separator2();
	}

};

int main()
{
	Vraboten a[MAX];

	int i = 0;
	bool novZapis;
	do
	{
		a[i].vnesi_zapis(a, i);
		cout << "Dali sakate da vnesete nov zapis za vraboten? 0=NE 1=DA \n ";
		cin >> novZapis;
		i++;
		while (cin.fail() || novZapis > 1) // ako vnesot(novZapis) e pogreshen 
		{
			cin.clear(); //go brishe vnesot
			cin.ignore(1, '\n');//propushta,vnes na edna cifra,koga kje stisne Enter

			cout << "Vnesete validen broj \n"; //odnovo vnesuvanje
			cin >> novZapis;
		}

	} while (novZapis == 1);
	a[0].sortPlata(a, i);

	system("pause");
}
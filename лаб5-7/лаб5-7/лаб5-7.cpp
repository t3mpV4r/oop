// лаб5-7.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
using namespace std;

class natprevaruvac
{
	string ime, prezime,uciliste;
	int p1, p2, p3;// od  3 zadaci 
public:
	void separator()
	{
		cout << "___________________________________________________________\n";
	}
	void set()
	{
		separator();
		cout << "Ime na ucenikot:";
		cin >> ime;
		cout << "Prezime:";
		cin >> prezime;
		cout << "Ucilishte:";
		cin >> uciliste;
		cout << "Vnesete gi poenite od trite zadaci,redosledno: \n";
		cin >> p1 >> p2 >> p3;
		separator();
	}
	int psum(){return p1 + p2 + p3;}//vkupno od site reseni zadaci
	void pecati()
	{
		cout << "Ime:" << ime<<endl;
		cout << "Prezime:" << prezime << endl;
		cout << "Ucilishte:" << uciliste << endl;
		cout << "Vkupno poeni:" << psum() << endl;

	}
	friend void maxp(natprevaruvac niza[],int n);//object so najmnogu poeni
	friend void sort(natprevaruvac niza[],int n);//opagjacki redosled
};
void maxp(natprevaruvac niza[],int n)
{
	natprevaruvac max = niza[0];
	for (int i = 0; i < n; i++)
	{
		if (max.psum() < niza[i].psum())
			max = niza[i];
	}
	cout << "Ucenik so najmnogu osvoeno poeni po natprevarot e: \n";
	max.pecati();
}
void sort(natprevaruvac niza[],int n)
{
	int i, j;
	natprevaruvac temp;
	for (i = 0; i < n; i++)
		for (j = i; j < n; j++)
		{
			if (niza[i].psum() < niza[j].psum())
			{
				temp = niza[i];
				niza[i] = niza[j];
				niza[j] = temp;
			}


		}
	cout << endl;
	cout << "Lista na site natprevaruvaci: \n";
	for (i = 0; i < n; i++)
	{
		niza[i].pecati();
		cout << endl;
	}
}
int main()
{
	natprevaruvac ucenici[100];
	int n=0,i;//broj na vneseni ucenici i brojac "i"
	bool izbor = 0;
	do
	{
		ucenici[n].set();
		cout << "Dali sakate da vnesete podatoci za nov ucenik?(1=DA,0=NE)";
		cin >> izbor;
		n++;

	} while (izbor == 1);

	int counter = 0;//brojac za tie so imat nad 60
	for (i = 0; i < n; i++)
	{
		if (ucenici[i].psum() > 60)
			counter++;
	}

	ucenici[0].separator();

	if (counter)
		cout << "Ucenici koi imaat osvoeno nad 60 poeni:" << counter << endl;

	maxp(ucenici, n);//ucenik so najmnogu poeni
	ucenici[0].separator();
	sort(ucenici, n);//lista na ucenici


    system("pause");
}


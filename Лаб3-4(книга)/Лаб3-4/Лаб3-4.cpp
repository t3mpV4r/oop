// Лаб3-4.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
using namespace std;

class kniga
{
	string naslov,avtor;
	int br_str, br_primeroci, br_izdadeni;
public:

	void Postavi()
	{
		cout << "Naslov:";
		cin >> naslov;

		cout << "Avtor:";
		cin >> avtor;

		cout << "Broj na strani:";
		cin >> br_str;

		cout << "Broj na primeroci:";
		cin >> br_izdadeni;

		br_izdadeni = 0;
	}
	void Izdadi_primerok()
	{
		if (br_primeroci > 0)
			cout << br_primeroci - 1 << " neizdadeni primeroci \n";
		else
			cout << "Site primeroci se izdadeni \n";
	}
	void Pecati()
	{
		kniga temp;
		cout << naslov<<","<<avtor<<","<<br_str<<" strani,";
		
	}
};


int main()
{
	kniga pom;
	pom.Postavi();
	pom.Pecati();
	pom.Izdadi_primerok();

	system("pause");
}


// лаб5-5.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
using namespace std;

class fakultet
{

	string ime, adresa;
	int bS,bV,bP;//strudenti,vraboteni,predmeti
public:
	void separator()
	{
		cout << "________________________________________________________\n";
	}
	void set()
	{
		separator();
		cout << "Ime na fakultet:";
		cin >> ime;
		cout << "Adresa na fakultet:";
		cin >> adresa;
		cout << "Broj na studenti:";
		cin >> bS;
		cout << "Broj na vraboteni:";
		cin >> bV;
		cout << "Broj na predmeti:";
		cin >> bP;
		separator();

	}
	void pecati()
	{
		cout << "Fakultet:" << ime << endl;
		cout << "Adresa:" << adresa << endl;
		cout << "Studenti:" << bS << endl;
		cout << "Vraboteni:" << bV << endl;
		cout << "Predmeti:" << bP << endl;

	}
	int getV() { return bV; }
	void minSt(fakultet ob[])//najmalku studenti vo koj fakultet
	{
		int i;
		fakultet min = ob[0];
		for (i = 0; i < 3; i++)
		{
			if (min.bS > ob[i].bS)
				min = ob[i];
		}
		cout << "Fakultet koj ima najmal broj studenti e:" << min.ime<<endl;
		separator();
	}
	friend void sort(fakultet ob[]);//prototip
};
void sort(fakultet ob[])//opagjacki redosled i pecatenje
{
	int i, j;
	fakultet temp;
	for (i = 0; i < 3; i++)
		for (j = i; j < 3; j++)
		{
			if (ob[i].bS < ob[j].bS)
			{
				temp = ob[i];
				ob[i]= ob[j];
				ob[j]=temp;
			}

			    
		}
	cout << endl;
	for (i = 0; i < 3; i++)
	{
		ob[i].pecati();
		cout << endl;
	}
}
int main()
{
	int i,sumV=0;//vkupen broj na vraboteni
	fakultet ob[3];//3 objekti
	for (i = 0; i < 3; i++)
	{
		ob[i].set();
	}
	for (i = 0; i < 3; i++)
	{
		sumV += ob[i].getV();
	}
	ob[0].separator();
	cout <<"Vkupen broj na vraboteni:"<<sumV<<endl;
	ob[0].minSt(ob);//najmalku studenti vo koj fakultet
	sort(ob);
    system("pause");
}


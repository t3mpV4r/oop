
#include <iostream>
#include <string>
using namespace std;
class ordinacija
{
public:
	string ime, prezime, rp;
	float plata;
public:
	void separator()
	{
		cout << "_____________________________________________________________ \n";
	}
	//ako stavam vneso da bide u default,ke bara uste eden vnes nepotreben za temp
	ordinacija(){};
    void sort(ordinacija ob[]);//prototip
};
void ordinacija::sort(ordinacija ob[])//funkcija za sortiranje
{
	int i, j;
	ordinacija temp;
	for (i = 0; i < 3; i++)
		for (j = i; j < 3; j++)
		{
			if (ob[i].plata > ob[j].plata)//rastecki redosled
			{
				temp = ob[i];
				ob[i]= ob[j];
				ob[j]= temp;

			}
		}
	for (i = 0; i < 3; i++)//pecatenje
	{
		cout << ob[i].ime<<endl;
		cout << ob[i].prezime << endl;
		cout << ob[i].rp << endl;
		cout << ob[i].plata << endl;
		ob[i].separator();
	}
}
int main()
{
	ordinacija vraboteni[3];//3 objekti

	for (int i = 0; i < 3; i++)//vnesuvanje so validacija za rp
	{
		vraboteni[i].separator();

		cout << "Vnesete ime i prezime na vraboteniot \n";
		cin >> vraboteni[i].ime >> vraboteni[i].prezime;

		cout << "Vnesete rabotna pozicija \n";
	    RP:cin >> vraboteni[i].rp;

		if (vraboteni[i].rp != "doktor" && vraboteni[i].rp != "sestra" && vraboteni[i].rp != "laborant")
		{
			cout << "Vnesovte pogreshna rabotna pozicija \n";
			cout << "vnesete povtorno:";
			goto RP;

		}
		cout << "Vnesete visina na plata \n";
		cin >> vraboteni[i].plata;

		vraboteni[i].separator();
	}

	vraboteni[0].sort(vraboteni);//povik za sortirano pecatenje
	
	
    system("pause");
}


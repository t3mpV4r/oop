// лаб5-4.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
using namespace std;
class benzinskaPumpa
{
	string adresa;
	int benzin;
public:
	void separator()
	{
		cout << "_________________________________________________________\n";
	}
	benzinskaPumpa() { benzin = 500000; }//default
	void set()//vnesuvanje
	{
		separator();
		cout << "Adresa:";
		cin >> adresa;
		cout << "Tekovna kolicina na benzin:";
		cin >> benzin;
		separator();
	}
	void promenaBenzin()
	{
		int k;
		cout << "Vnesete kolku litri sakate da dodadete/odzemete:";
		cin >> k;

		if (k > 500000)
		{
			cout << "Onevozmozeno \n";
			separator();
			system("pause");
		}
		else if (k<500000 || k<0)
		{
			benzin += k;
			cout << "Adresa:" << adresa << endl;
			cout << "Benzin:" << benzin << endl;
		}
		separator();
	}
};
int main()
{
	benzinskaPumpa ob;
	ob.set();
	ob.promenaBenzin();
	
    system("pause");
}


// лаб5-6.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include<string>
using namespace std;
class predmet
{
	string ime,profesor;
	int krediti;
public:
	void separator()
	{
		cout << "____________________________________________________________________\n";
	}
	predmet()//default
	{
		separator();
		cout << "Ime na predmetot:";
		cin >> ime;
		cout << "Profesor:";
		cin >> profesor;
		cout << "Broj na krediti:";
		cin >> krediti;
		separator();
	}
	friend double ocena(double niza[]);//5
};
double ocena(double niza[])
{
	double sum=0.0;
	int i;
	for (i = 0; i < 5; i++)
	{
		sum += niza[i];
	}
	return sum;
}

int main()
{
	predmet object;
	double poeni[5];//rezultati

	//vnesuvanje na rezultati so validacija:
	cout << "Poeni od 1 kolokvium:";
	KOL1: cin >> poeni[0];
	while (cin.fail() || poeni[0] > 20 || poeni[0] < 0)
	{
		cin.clear();
		cin.ignore(2, '\n');
		cout << "Vnesete validen broj na poeni \n";
		goto KOL1;
	}

	    cout << "Poeni od 2 kolokvium:";
        KOL2: cin >> poeni[1];
		while (cin.fail() || poeni[1] > 20 || poeni[1] < 0)
		{
			cin.clear();
			cin.ignore(2, '\n');
			cout << "Vnesete validen broj na poeni \n";
			goto KOL2;
		}
		   
		   cout << "Poeni od laboratoriski vezbi:";
	       LAB: cin >> poeni[2];
		   while (cin.fail() || poeni[2] > 20 || poeni[2] < 0)
		   {
			   cin.clear();
			   cin.ignore(2, '\n');
			   cout << "Vnesete validen broj na poeni \n";
			   goto LAB;
		   }

		   cout << "Poeni od seminarska:";
	       SEM: cin >> poeni[3];
		   while (cin.fail() || poeni[3] > 10 || poeni[3] < 0)
		   {
			   cin.clear();
			   cin.ignore(2, '\n');
			   cout << "Vnesete validen broj na poeni \n";
			   goto SEM;
		   }
		      
		   cout << "Poeni od zavrshen ispit:";
	       ISPIT: cin >> poeni[4];
		   while (cin.fail() || poeni[4] > 30 || poeni[4] < 0)
		   {
			   cin.clear();
			   cin.ignore(2, '\n');
			   cout << "Vnesete validen broj na poeni \n";
			   goto ISPIT;
		   }

double vkupno = ocena(poeni);//inicijalizacija

 if (vkupno > 42)
	 {

		 if ((vkupno == 50 || vkupno > 51) && (vkupno < 60 || vkupno == 60))
			 cout << "Ocena:6 \n";

		 if ((vkupno == 61 || vkupno > 61) && (vkupno < 70 || vkupno == 70))
			 cout << "Ocena:7 \n";

		 if ((vkupno == 71 || vkupno > 71) && (vkupno < 80 || vkupno == 80))
			 cout << "Ocena:8 \n";

		 if ((vkupno == 81 || vkupno > 81) && (vkupno < 90 || vkupno == 90))
			 cout << "Ocena:9 \n";

		 if ((vkupno == 91 || vkupno > 91) && (vkupno < 100 || vkupno == 100))
			 cout << "Ocena:10 \n";
	 }
 else if (vkupno < 42)
   cout << "Ispitot ne e polozen \n";

   system("pause");
}


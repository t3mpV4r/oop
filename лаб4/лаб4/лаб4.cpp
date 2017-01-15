#include <iostream>
#include <cmath>

using namespace std;

class kocka
{
public:
	double a;

public:
	kocka(){a = 3.0;}//default
	kocka(double a1) { a = a1;}//so parametar
	kocka(const kocka &k) { a = k.a; }//copy,imam dodeluvanje
	void separator2()
	{
		cout << "\n__________________________________________________________________\n" << endl;
	}
	void prvdel()
	{
		cout << endl;
		cout << "**********PRV DEL*********" << endl;
		cout << endl;
	}
	void vtordel()
	{
		cout << endl;
		cout << "**********VTOR DEL*********" << endl;
		cout << endl;
	}
	double get() { return a; }
	double plostina() { return 6 * pow(a,2); }
	double volumen() { return pow(a,3); }
	double dijagonala() { return a*sqrt(3); }
	void maxD(kocka pom[]);//najgolema dijagonala


};

void kocka::maxD(kocka pom[])
{
	kocka max=pom[0];
	int i;
	for ( i = 0; i < 5; i++)
	{
			if (max.a < pom[i].a)
			{
				max = pom[i];
		
			}

	}
	cout << "Najgolema dijagonala ima kockata so strana "<<max.a;
	cout << " i dijagonala " << max.dijagonala()<<endl;
}
int main()
{
	int i;
	kocka k[5];//5 objekti
	k[0].prvdel();

	for (i = 0; i < 5; i++)//vnes na strani
	{
		cout << "vnesi strana na " << i + 1 << "-ta kocka \n";
		cin >> k[i].a;
	}

	k[0].separator2();

	double sumP =0.0;
	for (i = 0; i < 5; i++)//presmetka na vkupna plostina
	{
		sumP += k[i].plostina();
	}
	cout << "Zbirot na plostinite na kockite e:" << sumP;



	k[0].separator2();



	k[0].maxD(k);//povik za najgolema dijagonala
	k[0].separator2();




	k[0].vtordel();

	kocka k1[4] = { kocka(1),kocka(2),kocka(3),k1[0] };//4 objekti

	cout << "Prvicni vrednosti \n";
	for (int j = 0; j < 4; j++)
	{
		cout << "kocka " << j + 1 << " strana " << k1[j].get()<<endl;
	}
	cout << endl;

	cout << "Novi vrednosti \n";
	for (int j = 0; j < 4; j++)
	{
		cout << "kocka " << j + 1 << " strana " << 2*k1[j].get() << endl;
	}
	cout << endl;

	for (int j = 0; j < 4; j++)//volumen na izmnozenite novi vrednosti za stranite
	{
		cout <<"Volumenot na "<<j+1<<" kocka so strana a="<< 2 * k1[j].get()<< " e "<< 2 * k1[j].volumen()<<endl;
	}


    system("pause");
}


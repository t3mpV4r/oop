// дополнителни1.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;
class agol
{
	int stepeni, minuti, sekundi;
public:
	agol(){}
	void set()
	{
		cout << "vnesete stepeni:";
		cin >> stepeni;

		cout << "vnesete minuti:";
		cin >> minuti;
		while (cin.fail() || minuti > 60 || minuti < 0)
		{
			cin.clear();
			cin.ignore(2, '\n');
			cout << "Vnesete validen broj \n";
			cin >> minuti;
		}
		cout << "vnesete sekundi:";
		cin >> sekundi;
		while (cin.fail() || sekundi > 60 || sekundi < 0)
		{
			cin.clear();
			cin.ignore(2, '\n');
			cout << "Vnesete validen broj \n";
			cin >> sekundi;
		}
	}
	void agolVoSek()
	{
		stepeni = stepeni * 3600 + minuti * 60 + sekundi;
		cout << "vo sekundi:" << stepeni << endl;
	}
	void pecati()
	{
		cout << stepeni << " " << minuti << "'" << sekundi <<"''"<< endl;
	}

};


int main()
{
	agol ob;
	ob.set();
	ob.pecati();
	ob.agolVoSek();
	
    system("pause");
}


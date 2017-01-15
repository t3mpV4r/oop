// лаб5-1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cmath>
using namespace std;
class triagolnik
{
public:
	float a, b, c;
public:
	triagolnik()//default
	{
		cout << "vnesi gi stranite na triagolnikot\n";
		cin >> a;
		cin >> b;
		cin >> c;

	}
	void odredi()
	{
		if (!(a + b >= c || a + c >= b || b + c >= a))
		{
			cout << "ne se strani na triagilnik \n";
			system("pause");
		}
		//ramnostran
		if ((a == b) && (b == c) && (a == c))
			cout << "Vnesovte strani na ramnostran triagolnik \n";
		//ramnokrak
		else if (a == b || b == c || a == c)
			cout << "Vnesovte strani na ramnokrak triagolnik \n";
		//raznostran
		else
			cout << "Vnesovte strani na raznostran triagolnik \n";

	}
	void pecati()
	{
		cout << a << endl;
		cout << b << endl;
		cout << c << endl;
		cout <<"L="<< perimetar() << endl;
		cout <<"P="<< plostina() << endl;
	}
	float perimetar() { return a + b + c; }
	float plostina()
	{
		float s, p;
		s = (a + b + c)/2.0;
		p = sqrt(s*(s - a)*(s - b)*(s - c));
		return p;
	}
};

int main()
{
	triagolnik t;
	t.odredi();
	t.pecati();
    system("pause");
}


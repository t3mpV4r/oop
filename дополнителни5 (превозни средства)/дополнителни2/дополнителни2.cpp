#include <iostream>
using namespace std;

class prevoznoSredstvo
{
private:
	float maxTezina;
	int maxBrzina;
public:

	prevoznoSredstvo() {}
	prevoznoSredstvo(float maxTezina, int maxBrzina)
	{
		this->maxTezina = maxTezina;
		this->maxBrzina = maxBrzina;
	}
	float getMaxTezina()
	{
		return maxTezina;
	}
	int getMaxBrzina()
	{
		return maxBrzina;
	}

};
class Avtobus :public prevoznoSredstvo
{
private:
	int potrosuvackaGorivo;
	int cenaG;
public:

	Avtobus() :prevoznoSredstvo() {}
	Avtobus(int potrosuvackaGorivo, int cenaG, float maxTezina, int maxBrzina) :prevoznoSredstvo(maxTezina, maxBrzina)
	{
		this->potrosuvackaGorivo = potrosuvackaGorivo;
		this->cenaG = cenaG;
	}
	float transport()
	{
		return (float)(potrosuvackaGorivo*cenaG*getMaxBrzina());
	}
	friend ostream& operator<<(ostream &o, Avtobus &a)
	{
		o << a.getMaxTezina() << "," << a.getMaxBrzina() << "," << a.transport() << endl;
		return o;
	}
	
};
class Voz :public prevoznoSredstvo
{
private:
	int potrosuvackaStruja;
	int cenaS;

public:

	Voz() :prevoznoSredstvo() {}
	Voz(int potrosuvackaStruja, int cenaS, float maxTezina, int maxBrzina) :prevoznoSredstvo(maxTezina, maxBrzina)
	{
		this->potrosuvackaStruja = potrosuvackaStruja;
		this->cenaS = cenaS;
	}
	float transport()
	{
		return (float)(potrosuvackaStruja*cenaS*getMaxBrzina());
	}
	friend  ostream&  operator<<(ostream &o, Voz &x)
	{
		o << x.getMaxTezina() << "," << x.getMaxBrzina() << "," << x.transport() << endl;
		return o;
	}
	
}; 
int najeftin(int a, int b)
{
	if (a < b)
		return a;
	else return b;
}


int main()
{

	Avtobus ob1[2] = { {4,4,4,4},{ 3,3,3,3 } };
	Voz ob2[2] = { {2,2,2,2},{1,1,1,1} };

	int minA = najeftin(ob1[0].transport(), ob1[1].transport());
	int minV = najeftin(ob2[0].transport(), ob2[1].transport());

	if (minA < minV)
	{
		if (minA == ob1[0].transport())
		{
			cout << "prevozot so prviot avtobus e najeftin \n";
			cout << ob1[0];
		}
		if (minA == ob1[1].transport())
		{
			cout << "prevozot so vtoriot avtobus e najeftin \n";
			cout << ob1[1];
		}
			
	}
	else if (minA > minV)
	{
		if (minV == ob2[0].transport())
		{
			cout << "prevozot so prviot voz e najeftin \n";
			cout << ob2[0];
		}
			
		if (minV == ob2[1].transport())
		{
			cout << "prevozot so vtoriot voz e najeftin \n";
			cout << ob2[1];
		}
	}

	system("pause");
}
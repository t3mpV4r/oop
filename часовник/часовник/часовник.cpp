#include <iostream>
using namespace std;

struct vreme
{
	int cas;
	int minuta;
	int sekunda;
};
void promeni(vreme &t);
void prikazi(vreme &t);

void main()
{
	int i;
	struct vreme casovnik;

	casovnik.cas = 0;
	casovnik.minuta = 0;
	casovnik.sekunda = 0;
	do
	{
		for (i = 0; i < 500; i++)
			promeni(casovnik);
		prikazi(casovnik);

	} while (1);
}
void promeni(vreme &t)
{
	(t).sekunda++;
	if ((t).sekunda == 60)
	{
		(t).sekunda = 0;
		(t).minuta++;
	}
	if ((t).minuta == 60)
	{
		(t).minuta = 0;
		(t).cas++;
	}
	if ((t).cas == 24)
		(t).cas = 0;
}
void prikazi( vreme &t)
{
	cout << (t).cas;
	cout << " : " << (t).minuta;
	cout << " : " << (t).sekunda;
}

// ооп-Лаб1-1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#define PI 3.14
using namespace std;
struct  krug
{
	float r;
	float povrsinaKrug()
	{
		return r*r*PI;
	}
};

struct konus
{
	struct krug k; //object od krug
	float H;
	float volumenKonus()
	{
		return (k.povrsinaKrug()*H) / 3;
	}
};
int main()
{
	konus konus;
	//konus={{3},5};
	konus.k.r = 3;
	konus.H = 5;

	cout << "Volumenot na konusot iznesuva:"<<konus.volumenKonus()<<endl;

    system("pause");
}


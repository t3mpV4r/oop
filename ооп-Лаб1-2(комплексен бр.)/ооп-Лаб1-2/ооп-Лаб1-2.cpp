// ооп-Лаб1-2.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

struct kompleksen 
{
	double re;
	double img;

	double mod() 
	{
		return sqrt(re*re + img*img);
	}

	double inc() 
	{
		return re = re + 2;
	}

	void print() 
	{
		if (img>0)
			cout << re << "+" << img << "j";
		else if (img == 0)
			cout << re;
		else
			cout << re << img << "j";
	}

	void setRe(double x) 
	{
		re = x;
	}
	void setImg(double y) 
	{
		img = y;
	}
};

int main() {
	kompleksen k;//object

	k.setRe(2);//x=2
	k.setImg(-3);//y=-3
	k.inc();//x=x+2=4
	cout << "Presmetka na modul: " << k.mod() << endl;
	k.print();
	cout << endl;
    system("pause");
}


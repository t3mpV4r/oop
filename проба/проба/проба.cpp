// Example program
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Pravoagolnik {
protected:
	double a, b;
public:
	Pravoagolnik() { a = 2; b = 3; }
	void setStrani(double a1, double b1) {
		a = a1;
		b = b1;
	}
	double getStranaA() {
		return a;
	}
	double getStranaB() {
		return b;
	}
	double Plostina() {
		return a*b;
	}
	double Perimetar() {
		return (2 * a) + (2 * b);
	}
	void pecati() {
		cout << "Pravoagolnikot so strani " << getStranaA() << " i " << getStranaB() << " ima perimetar : " << Perimetar() << " i Plostina " << Plostina() << endl;
	}
};
class Kvadar :protected Pravoagolnik {
	double c;
public:
	Kvadar() { a = 4; b = 5; c = 3; }
	void setStraniK(double a1, double b1, double c1) {
		a = a1;
		b = b1;
		c = c1;
	}
	double getStranaA() {
		return a;
	}
	double getStranaB() {
		return b;
	}
	double getStranaC() {
		return c;
	}
	double Plostina() {
		return 2 * ((a*b) + (b*c) + (a*c));
	}
	double Volumen() {
		return a*(b*c);
	}
	void pecati() {
		cout << "Kvadarot so strani " << getStranaA() << ", " << getStranaB() << " i " << getStranaC() << " ima volumen : " << Volumen() << " i Plostina " << Plostina() << endl;
	}
};
int main()
{
	Pravoagolnik p;
	p.pecati();
	Kvadar k;
	k.pecati();
	system("pause");
}

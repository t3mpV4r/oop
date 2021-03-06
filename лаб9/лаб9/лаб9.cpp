#include <iostream>
using namespace std;
class figura //apstraktna
{
public:
	virtual float povrsina() { return  0.0; }
	virtual float perimetar() { return  0.0; }
	virtual void pecatiImeFigura() = 0;
	virtual void pecati() = 0;
};
class kvadrat :public figura
{
	float a;
public:
	kvadrat(float a)
	{

		this->a = a;
	}
	kvadrat() {}
	void seta(float a) { this->a = a; }
	float zemia() { return a; }
	virtual float povrsina()
	{
		return a*a;
	}
	virtual float perimetar()
	{
		return 4 * a;
	}
	virtual void pecatiImeFigura()
	{
		cout << "Kvadrat \n";
	}
	virtual void pecati()
	{
		cout << "Povrsina:" << povrsina() << ",perimetar:" << perimetar() << endl;
	}
};
class krug :public figura
{
	float r;
public:
	krug(float r)
	{

		this->r = r;
	}
	krug() {}
	void setr(float r) { this->r = r; }
	float zemir() { return r; }
	virtual float povrsina()
	{
		return r*r*3.14;
	}
	virtual float perimetar()
	{
		return 2 * 3.14*r;
	}
	virtual void pecatiImeFigura()
	{
		cout << "Krug \n";
	}
	virtual void pecati()
	{
		cout << "Povrsina:" << povrsina() << ",perimetar:" << perimetar() << endl;
	}
};
class kocka :public kvadrat
{
public:

	kocka(float a) :kvadrat(a) {}
	float povrsina()
	{
		return  6 * kvadrat::povrsina();
	}
	float volumen()
	{
		return zemia()*zemia()*zemia();
	}
	void pecatiImeFigura()
	{
		cout << "Kocka \n";
	}
	void pecati()
	{
		cout << "Povrsina:" << povrsina() << ",volumen:" << volumen() << endl;
	}
};
class cilindar :public krug
{
public:
	float h;

	cilindar(float h, int r) :krug(r)
	{
		this->h = h;
	}
	void seth(float h) { this->h = h; }
	float plostina()
	{
		return 2 * krug::povrsina() + 2 * 3.14*zemir()*h;
	}
	float volumen()
	{
		return krug::povrsina()*h;
	}
	void pecatiImeFigura()
	{
		cout << "Cilindar \n";
	}
	void pecati()
	{
		cout << "Plostina:" << plostina() << ",volumen:" << volumen() << endl;
	}

};
int main()
{
	kvadrat ob1;
	krug ob2;
	ob1.seta(4.0);
	ob1.pecatiImeFigura();
	ob1.pecati();
	cout << endl;

	ob2.setr(2.0);
	ob2.pecatiImeFigura();
	ob2.pecati();
	cout << endl;

	cilindar ob3(10.1, 5.2);
	kocka ob4(7);

	ob3.seth(1.5);
	ob3.pecatiImeFigura();
	ob3.pecati();
	cout << endl;

	ob4.pecatiImeFigura();
	ob4.pecati();
	cout << endl;

	system("pause");
}


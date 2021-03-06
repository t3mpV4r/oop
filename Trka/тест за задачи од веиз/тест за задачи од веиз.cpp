#include<iostream>
#include<string.h>
#include <stdlib.h>
using namespace std;


class F1Trka {
private:
	char ime[30];
	char *pobednik;
	float vreme;
	float rekord;
public:


	F1Trka() {}
	F1Trka(char *ime, char *pobednik, float vreme, float rekord) {
		strcpy_s(this->ime, ime);
		this->pobednik = new char[strlen(pobednik) + 1];
		strcpy(this->pobednik, pobednik);
		this->vreme = vreme;
		this->rekord = rekord;


	}
	F1Trka(const F1Trka &f1) {
		strcpy_s(this->ime, f1.ime);
		this->pobednik = new char[strlen(f1.pobednik) + 1];
		strcpy(this->pobednik, f1.pobednik);
		this->vreme = f1.vreme;
		this->rekord = f1.rekord;


	}


	F1Trka& operator=(const F1Trka &t) {
		if (this != &t) {
			delete[]pobednik;
			strcpy(this->ime, t.ime);
			this->pobednik = new char[strlen(t.pobednik) + 1];
			strcpy(this->pobednik, t.pobednik);
			this->vreme = t.vreme;
			this->rekord = t.rekord;


		}

		return *this;
	}




	~F1Trka() {

		delete[]pobednik;

	}
	void pecati() {

		cout << ime << ", " << pobednik << " " << vreme << endl;

	}
	float getVreme() {
		return vreme;
	}
	float getRekord() {

		return rekord;
	}

};

class F1Shampionat {
private:
	int godina;
	F1Trka *t;
	int brojtrki;

public:


	F1Shampionat() {}

	F1Shampionat(int godina) {

		this->godina = godina;
		t = NULL;
		brojtrki = 0;


	}
	F1Shampionat(const F1Shampionat &s1) {

		t = new F1Trka[s1.brojtrki];
		for (int i = 0; i<s1.brojtrki; i++) {
			t[i] = s1.t[i];

		}
		this->godina = s1.godina;
		this->brojtrki = s1.brojtrki;


	}

	~F1Shampionat() {
		delete[]t;


	}

	void dodadiTrka(F1Trka T) //prima argument od prethodnata klasa
	{
		t[brojtrki] = T;

		F1Trka *t1; //nov pokazuvac
		t1 = new F1Trka[brojtrki];//alociran 

		for (int i = 0; i<brojtrki; ++i) 
		{
			t1[i] = t[i]; //kopira gi podatocite

		}
		delete[]t;//brise mem. 

		t = new F1Trka[brojtrki + 1];//na stario se dodava nova m.lokacija

		for (int i = 0; i<brojtrki; ++i) 
		{
			t[i] = t1[i];//pa gi prekopira samo obratno

		}
		

		brojtrki++;
		// delete[]t1;
	}
	bool proveri(float vreme, float rekord) {
		if (vreme<rekord)
			return true;
		else return false;

	}
	void noviRekordi() {

		for (int i = 0; i<brojtrki; ++i) {
			if (proveri(t[i].getVreme(), t[i].getRekord()))
				t[i].pecati();

		}

	}

};

int main() {

	F1Shampionat f1(2015);
	int n;
	float vr, re;
	char ime[30];
	char pobednik[40];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ime;
		cin >> pobednik;
		cin >> vr;
		cin >> re;
		F1Trka t(ime, pobednik, vr, re);
		f1.dodadiTrka(t);
	}

	f1.noviRekordi();

	system("pause");

}


#include <iostream>
#include <string.h>
using namespace std;


int main()
{
	char lozinka[100];
	cin.getline(lozinka, 13);

	cout << "Confirm your pw \n";
	char confirm[100];
	cin.getline(confirm, 13);

	int i = 0;

	while (strcmp(lozinka, confirm) == 0 && i==3);
	{
		
		cout << "Try again \n";
		cin.getline(confirm, 13);
		i++;
	}

    system("pause");
}


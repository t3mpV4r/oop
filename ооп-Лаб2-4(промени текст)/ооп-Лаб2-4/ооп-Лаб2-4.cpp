#include <iostream>
#include <string.h>
#include <cctype>
using namespace std;

void promeni(char niza[])
{
	int i = 0, j = 1;
	char *p = niza;
	char nova[100];

	nova[0] = toupper(*(p + i));

	for (i = 1; niza[i]; i++)
	{
		if (isalpha(*(p + i)))
		{
			nova[j] = tolower(*(p + i));
			j++;
		}


	}
	nova[j] = '\0';
	cout << "Noviot tekst e: \n";
	cout << nova << endl;

}

int main()
{
	char tekst[100];
	cin.getline(tekst, 100);
	promeni(tekst);

	system("pause");
}
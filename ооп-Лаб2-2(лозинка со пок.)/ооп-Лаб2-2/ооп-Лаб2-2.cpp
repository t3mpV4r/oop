#include <iostream>
#include <string.h>
#include <cctype>

using namespace std;

int main()
{
	char lozinka[100];
	cout << "vnesete lozinka:";
	cin.getline(lozinka, 13);

	int l = strlen(lozinka);
	int counter1 = 0, counter2 = 0, counter3 = 0;
	char *p;
	p = lozinka;
	for (int i = 0; i < l; i++)
	{
		if (isalpha(*(p + i)))
			counter1++;
		if (isalnum(*(p + i)))
			counter2++;
		if (isdigit(*(p + i)))
			counter3++;
	}
	if (l > 3 && counter1 > 3 && counter2 > 2 && counter3 > 1)
		cout << "vashata lozinka e validna \n";
	 else
		cout << "vashata lozinka e nevalidna! \n";



	system("pause");
}
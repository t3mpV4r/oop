// ооп-Лаб2-5.cpp : Defines the entry point for the console application.
//

#include <iostream>
using  namespace std;
void promeni(int a[],int n)
{
	int b[10], i=0;


	int *p = a;//prvo pokazuva kon prvio clen od prvata niza

	for (i = 0; i < n; i++)
	{
		b[i] = *(p+i) + *(p + n - i - 1);//namesto a[i] imam *(p+i) 
	}

	int *p1 = b;
	for (i = 0; i < n; i++)
		cout << *(p1+i) << " ";
}
int main()
{
	int a[10],i,n;
	cin >> n;
	
	for (i = 0; i < n; i++)
	{
		cin >> a[i];//vnes na prvata niza
	}
	promeni(a,n);

    system("pause");
}


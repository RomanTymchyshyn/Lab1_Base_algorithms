/*#include <iostream>
#include <cmath>
#include"header.h"

using namespace std;

void methodOfFermat(int n);
void in(int & n);

int main()
{
	int n;
	in(n);
	methodOfFermat(n);
	system("pause");
	return 0;
}

void in(int & n)
{
	cout<<"This program carries factorization by Fermat method.\n";
	do
	{
		cout<<"Please, enter the number (>0) that you would like to expand into simple factors: ";
		cin>>n;
		if (n<=0) 
			{
				cout<<"\nYou have entered a number less than zero";
			}
	}
	while (n<=0);
	cout<<"\n n: ";
	return;
}

void methodOfFermat(int n)
{
	if (isSimple(n)) {
						cout<<n<<" ";
						return;
					 } 
	else if (n%2==0) {
					cout<<"2 ";
					n/=2;
					methodOfFermat(n);
					return;
				}
	
	int x, y, err;
	x= int( sqrt( double(n) ) )-1;
	do
	{	++x;
		y=int(sqrt(double(x*x-n)));
		err=x*x-y*y-n;
	}
	while(x<=(n+1)/2 && err);
	if ((x-y)==n || (x+y)==n) return;
	methodOfFermat(x-y);
	methodOfFermat(x+y);
}*/
/*#include <iostream>
#include <cmath>
#include"header.h"

using namespace std;

void methodOfPollard(int n);
void in(int & n);


int main()
{
	int n;
	in(n);
	methodOfPollard(n);
	system("pause");
	return 0;
}

void methodOfPollard(int n)
{
	if (isSimple(n)) {
						cout<<n<<" ";
						return;
					 };
	int a=2, b=2, c=1, d=0, t=n;
	for (int c=1;!(d>1 && d<n) ; ++c)
		for (int i=0; i<=t && !(d>1 && d<n); ++i)
			{
				a=(a*a+a+c)%n;
				b=(b*b+b+c)%n;
				b=(b*b+b+c)%n;
				d=GCD(abs(a-b),n);
			}
	methodOfPollard(d);
	methodOfPollard(n/d);
}

void in(int & n)
{
	cout<<"This program carries factorization by Pollard method.\n";
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
	cout<<"\n";
	return;
}*/
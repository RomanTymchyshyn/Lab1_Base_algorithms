/*#include <iostream>
#include<cmath>
#include<stdlib.h>
#include<ctime>
#include"header.h"

using namespace std;

int s=0;
const int N=1000;
const int T=10000;
int powers[T]={0};
int p[N]={0};

void methodOfFermat(int n);
int choose_g(int n);
int generator(int n, int order);
int order (int n);
bool generatorExistence(int order);

int main() 
{

	int n;
	cout<<"n=";
	cin>>n;
	methodOfFermat(n);
	int ord=order(n);
	if (!generatorExistence(n)) 
		{
			cout<<"No generators.\n";
			system("pause");
			return 0;
		}
	for (int i=0; p[i]!=0; ++i)
		{
			powers[p[i]]=0;
			p[i]=0;
		}
	s=0;

	methodOfFermat(ord);
	cout<<generator(n, ord)<<endl;
	system("pause");
	return 0;

}

void methodOfFermat(int n)
{
	if (isSimple(n)) {
						if (powers[n]==0) {
											p[s]=n;
											++s;
										  }
						++powers[n];
						return;
					 } 
	else if (n%2==0) {
						if (powers[2]==0) {
											p[s]=2;
											++s;
										  }
						++powers[2];
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
}

int choose_g(int n)
{
	int g;
	srand((unsigned) time (NULL));
	do
	{
		g=rand()%(n-1) + 2;
	}
	while (GCD(g, n)!=1);
	return g;
}

int generator(int n, int order)
{
	if (n==2) return 1;
	int g;
	int b=1;
	while(b==1)
	{
		g=choose_g(n);
		
		for (int i=0; i<s; ++i)
			{
				b=Ipow(g, order/p[i], n);
				if (b==1) break;
			}
		if (b!=1) return g;
	}
}

bool generatorExistence(int n)
{
	if (powers[2]==0 && isSimple(p[0]) && p[1]==0) return 1;
	if (powers[2]==1 && (p[1]==0 || (isSimple(p[1]) && p[2]==0))) return 1;
	if (powers[2]==2 && p[1]==0) return 1;
	return 0;
}

int order (int n)
{
	int order=n;
	for (int i=0; p[i]!=0; ++i)
		order=order-order/p[i];
	return order;
}*/
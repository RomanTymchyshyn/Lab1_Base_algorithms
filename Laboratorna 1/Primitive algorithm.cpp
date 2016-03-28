/*#include <iostream>
#include <cmath>
#include"header.h"

using namespace std;

int s=0;
const int N=1000;
int p[N]={0};
const int T=10000;
int powers[T]={0};

void inPut(int & n, int & b, int & g);
void outPut(int n, int b, int g);
void methodOfFermat(int n);
int order_g (int g, int n);
int order_G (int n);
bool is_g_generator(int g, int n);
bool is_b_in_reduced_system(int b, int n);
int primitiveAlgo(int g, int b, int n);

int main()
{
	int n;
	int g;
	int b;
	inPut(n, b, g);
	outPut(n, b, g);
	system("pause");
	return 0;
}

void inPut(int & n, int & b, int & g)
{
	cout<<"n:";
	cin>>n;
	cout<<"b:";
	cin>>b;
	cout<<"g:";
	cin>>g;
	return;
}

void outPut(int n, int b, int g)
{
	if (is_g_generator(g,n) && is_b_in_reduced_system(b, n)) cout<<"\n"<<primitiveAlgo(g,b,n)<<endl; else cout<<"No solutions of the equation\n";
	return;
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

int order_g (int g, int n)
{
	int order=1;
	int pow=g;
	while (g%n!=1)
	{
		g*=pow;
		++order;
	}
	return order;
}

int order_G (int n)
{
	methodOfFermat(n);
	int order=n;
	for (int i=0; p[i]!=0; ++i)
		order=order-order/p[i];
	return order;
}

bool is_g_generator(int g, int n)
{
	if (g>n) return 0;
	if (GCD(g,n)!=1) return 0;
	int ord_G=order_G(n);
	int ord_g=order_g(g,n);
	if ((g<n) && GCD(g,n)==1 && ord_g==ord_G) return 1; 
	return 0;
}

bool is_b_in_reduced_system(int b, int n)
{
	if (b>=n) return 0;
	if (GCD(b, n)!=1) return 0;
	return 1;
}

int primitiveAlgo(int g, int b, int n)
{
	int log=1;
	int pow=g;
	while(g%n!=b)
	{
		g*=pow;
		++log;
	}
	return log;
}*/
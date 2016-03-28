/*#include <iostream>
#include <cmath>
#include"header.h"

using namespace std;

int h=0;
const int N=1000;
const int T=10000;
int p[N]={0};
int powers[T]={0};


void inPut(int & n, int & b, int & g);
void outPut(int n, int b, int g);
void methodOfFermat(int n);
int order_g (int g, int n);
int order_G (int n);
bool is_g_generator(int g, int n);
bool is_b_in_reduced_system(int b, int n);
int Shanks(int n, int g, int b);

int main()
{
	int n;
	int g;
	int b;
	inPut(n, b, g);
	outPut(n, b, g);
	int x=Shanks(n,g,b);
	if (isSol(n, b, g, x)) cout<<"OK!!!"; else cout<<"ASSHOLE";
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
	if (is_g_generator(g,n) && is_b_in_reduced_system(b, n)) cout<<"\n"<<Shanks(n,g,b)<<endl; else cout<<"No solutions of the equation\n";
	return;
}

void methodOfFermat(int n)
{
	if (isSimple(n)) {
						if (powers[n]==0) {
											p[h]=n;
											++h;
										  }
						++powers[n];
						return;
					 } 
	else if (n%2==0) {
						if (powers[2]==0) {
											p[h]=2;
											++h;
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

int Shanks(int n, int g, int b)
{
	int a=int(ceil(sqrt(double(n))));
	int L1[N];
	L1[0]=1;
	int g1=Ipow(g,a,n);
	for (int i=1; i<=a; ++i)
		L1[i]=(L1[i-1]*g1)%n;
	int temp=b;
	for (int j=0; j<a; ++j)
		{
			for (int i=0; i<=a; ++i)
				if (temp==L1[i]) return (i*a-j);
			temp=(temp*g)%n;
		}
}*/
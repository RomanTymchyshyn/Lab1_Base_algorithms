/*#include<iostream>
#include<cmath>
#include"header.h"

using namespace std;

int s=0;
const int N=1000;
const int T=10000;
int p[N]={0};
int powers[T]={0};

void inPut(int & n, int & b, int & g);
void outPut(int n, int b, int g);
int order_g (int g, int n);
bool is_g_generator(int g, int n);
bool is_b_in_reduced_system(int b, int n);
void new_val(int & z, int & u, int & v, int b, int g, int n);
int PollardLog(int n, int b, int g);

int main()
{
	int n;
	int g;
	int b;
	inPut(n, b, g);
	outPut(n, b, g);
	system ("pause");
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
	if (isSimple(n) && is_g_generator(g,n) && is_b_in_reduced_system(b, n)) 
		{
			int x=PollardLog(n,b,g);
			if (x<=0||!isSol(n,b,g,x)) cout<<"We cannot find the solution of the equation.\n";
			else cout<<"\n"<<x<<endl;
		}
	else cout<<"No solutions of the equation\n";
	return;
}

int order_g (int g, int n)
{
	int order=1;
	int pow=g;
	while (g%n!=1)
	{
		g=(g*pow)%n;
		++order;
	}
	return order;
}

bool is_g_generator(int g, int n)
{
	if (g>n) return 0;
	if (GCD(g,n)!=1) return 0;
	int ord_g=order_g(g,n);
	if ((g<n) && GCD(g,n)==1 && ord_g==(n-1)) return 1; 
	return 0;
}

bool is_b_in_reduced_system(int b, int n)
{
	if (b>=n) return 0;
	if (GCD(b, n)!=1) return 0;
	return 1;
}

int PollardLog(int n, int b, int g)
{
	int log;
	int u1=0, u2=u1;
	int v1=0, v2=v1;
	int z1=1, z2=z1;

	do
	{
		new_val(z1,u1,v1,b,g,n);
		new_val(z2,u2,v2,b,g,n);
		new_val(z2,u2,v2,b,g,n);

	}
	while (z1!=z2 || (u1-u2)==0);

	int r=abs(v1-v2);
	r=inversion(r, n);
	if (r==0) return -1;
	r=(abs(u2-u1)*r)%(n);
	return r;
}

void new_val(int & z, int & u, int & v, int b, int g, int n)
{
	switch (z%3)
		{
			case 0:
				{
					u=(2*u)%(n-1);
					v=(2*v)%(n-1);
					z=(z*z)%(n);
				}
				break;
			case 1:
				{
					
					u=(u+1)%(n-1);
					z=(z*g)%(n);
				}
				break;
			case 2:
				{
					v=(v+1)%(n-1);
					z=(z*b)%(n);
				}
				break;
		}
	return;
}*/
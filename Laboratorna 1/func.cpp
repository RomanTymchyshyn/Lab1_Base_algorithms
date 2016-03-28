#include<cmath>
#include"header.h"

bool isSimple(const int n)
{
	int r=1;
	for (int i=2; i<=sqrt(double(n)) && r; ++i)
		r=n%i;
	return (r!=0);
}
/*
int GCD (int a , int b)//greatest common divisor (найбільший спільний дільник); алгоритм Евкліда
{
	if (a<=0||b<=0) return 0;
	if (a==0) return b;
	while (b!=0)
		{
			if (a>b) 
				a=a-b; 
			else
				b=b-a;
		}
	return a;
}*/

// фукнция получения НОД
int GCD(int a, int b)
 {
	 if (a==0) return abs(b);
	 if (b==0) return abs(a);
	// поки числа не рівні 0
	while(a!=0 && b!=0)
	{
		if(a>=b) a=a%b;
		else b=b%a;
	}
	return a+b; // Одне - нуль
}

int Ipow(int a, int r, int n)
{
	int p=1;
	for(int i=0; i<32; i++)
	{ 
		if(r>>i & 0x1)
			p=(p*a)%n;
		a=(a*a)%n;
	}
	return p;
}

bool isSol(int n, int b, int g, int x)
{
	if (Ipow(g, x, n)==b) return 1; 
	else return 0;
}

int inversion(int a, int n)
{
	int d=GCD(a, n);
	if (d==n) return 0;
	if (d!=1) 
		{
			a/=d;
			n/=d;
		}
	int x=0; 
	while ((a*x)%n!=1)
		++x;
	return x;
}
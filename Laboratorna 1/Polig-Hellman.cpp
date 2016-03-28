/*#include<iostream>
#include<cmath>
#include"header.h"

using namespace std;

const int H=50;
int s=0;
const int N=1000;
const int T=10000;
int p[N]={0};
int powers[T]={0};

bool inPut(int & n, int & b, int & g);
void outPut(int n, int b, int g);
void methodOfFermat(int n);
int order_g (int g, int n);
bool is_g_generator(int g, int n);
bool is_b_in_reduced_system(int b, int n);
int PHlog(int n, int b, int g);

int main()
{
	int n;
	int g;
	int b;
	if (inPut(n, b, g)) outPut(n, b, g);
	system("pause");
	return 0;
}

bool inPut(int & n, int & b, int & g)
{
	cout<<"n:";
	cin>>n;
	methodOfFermat(n-1);
	if ( !isSimple(p[0]) || p[1]!=0 )
		{
			cout<<"This algorithm works only when order=pow(p,s), where p is simple.\n";
			return 0;
		}
	cout<<"b:";
	cin>>b;
	cout<<"g:";
	cin>>g;
	if (!is_g_generator(g,n) || !is_b_in_reduced_system(b, n))
		{
			cout<<"No solutions of the equation\n";
			return 0;
		}
	return 1;
}

void outPut(int n, int b, int g)
{
	cout<<"\n"<<PHlog(n,b,g)<<endl;
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
	if ((g<n) && GCD(g,n)==1 && ord_g==n-1) return 1; 
	return 0;
}

bool is_b_in_reduced_system(int b, int n)
{
	if (b>=n) return 0;
	if (GCD(b, n)!=1) return 0;
	return 1;
}

int PHlog(int n, int b, int g)
{
	int s=powers[p[0]];
	int p1=(n-1)/p[0];//ми порахували р в степені s-1
	int x[50]={0};
	int lhs=Ipow(b, p1, n);//b в степені р в сепені s-1
	if (lhs==1) x[0]=0;//бо ліва частина в нульовій степені буде 1
	int g1=Ipow(g, p1, n);
		
	int rhs=1;
	int y=0;
	while (y<p[0])//перебираємо до р-1, бо вже якшо взяти х=р, то буде g в степені p в степені s, що = 1, бо
									//g генератор, а р в степені s - порядок
	{
		if (rhs==lhs) {x[0]=y;break;} 
		++y;
		rhs=(rhs*g1)%n;
	}
	int g_1=inversion(g, n);
	int power1=1;//степінь g_1;
	int power2=p1/p[0];//степінь лівої частини(р в степені s-2) (p1-раніше оголошувася як р в степені s-1)
	p1=1;//тут ми будемо накопичувати степінь p
	int dob=b;//те що в дужках справа (до піднесення в степінь)
	int g3=1;
	for (int i=1; i<s; ++i)
	{
		power1=x[i-1]*p1;
		g3=Ipow(g_1, power1, n);
		dob=(dob*g3)%n;
		lhs=Ipow(dob, power2, n);
		rhs=1;
		y=0;
		while (y<p[0])
		{
			if (rhs==lhs) {x[i]=y;break;}
			++y;
			rhs=(rhs*g1)%n;
		}
		p1*=p[0];
		power2/=p[0];
	}

	int log=0;
	p1=1;//р в степені 0
	for(int i=0; i<s; ++i)
	{
		log+=x[i]*p1;
		p1*=p[0];
	}
	return log;
}*/
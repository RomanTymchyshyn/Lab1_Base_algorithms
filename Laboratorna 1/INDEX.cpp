#include<iostream>
#include<cmath>
#include"header.h"
#include<ctime>

using namespace std;


int s=0;
const int N=1000;
const int T=10000;
int p[N]={0};
int powers[T]={0};

int indеxAlgo(int n, int b, int g);
void inPut(int & n, int & b, int & g);
void outPut(int n, int b, int g);
int order_g (int g, int n);
bool is_g_generator(int g, int n);
bool is_b_in_reduced_system(int b, int n);
int indexAlgo(int n, int b, int g);
int EratosthenesSieve(int S[], const int N, int n);
bool factor_in_F(int F[N], int l[N], int b, int t);

int main()
{
	int n=0, b=0, g=0;
	inPut(n,b,g);
	outPut(n,b,g);
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
	if (isSimple(n) && is_g_generator(g,n) && is_b_in_reduced_system(b, n)) 
		{
			int x=indеxAlgo(n,b,g);
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

int EratosthenesSieve (int S[], const int N, int n)
{
	string sieve$="P";
	for (int i=1; i<N; ++i)
		sieve$+="P";
	int prime=2;
	for (int i=4; i<N; ++prime, i=prime*prime)
		{
			if (sieve$[i]=='P') 
				for (int j=i; j<N; j+=prime)
					if (sieve$[j]='P') sieve$[j]='N';
		}
	unsigned int i=0;
	for(unsigned int j=2; j<sieve$.length();j++)
		if (sieve$[j]=='P') {
								S[i]=j;
								++i;
							}
	return i;
}

bool factor_in_F(int F[N], int l[N], int b, int t)
{
	int j;
	if (b<0) {b*=-1; l[0]=1;}
	for (j=1; b!=1 && j<=t && F[j]!=0; ++j)//поки b не розклалось чи поки не закінчились елементи у нашій факторній базі
		{
			for ( ; (b%F[j])==0; )//поки b ділиться на j-те число з факторної бази, ділимо його на нього, щоб отримати степінь цього числа
				{
					b/=F[j];
					l[j]++;//сюди ми записуємо степінь j-ого числа з факторної бази
				}

		}
	if (b==1) return 1;
	else return 0;//це означає, що число не розкладається за факторною базою
}

void swap(int & a, int & b)
{
	int temp=0;
	temp=a;
	a=b;
	b=temp;
	return;
}

int gauss (int matrix[50][50], int r, int c, int *ans, int n)
{
	int wh[50]={-1};
	for (int col=0, row=0; col<c && row<r; ++col) 
	{
		int sel = row;
		for (int i=row; i<r; ++i)
			if (abs (matrix[i][col]) > abs (matrix[sel][col]))
				sel = i;
		if (matrix[sel][col]=0)
			continue;
		for (int i=col; i<=c; ++i)
			swap (matrix[sel][i], matrix[row][i]);
		wh[col] = row;
 
		for (int i=0; i<n; ++i)
			if (i != row) {
				int z = matrix[i][col]*inversion(matrix[row][col],n);
				for (int j=col; j<=c; ++j)
					matrix[i][j] = (matrix[i][j] - (matrix[row][j] * z)%n + n)%n;
			}
		++row;
	}
 
	for (int i=0; i<c; ++i)
		ans[i]=0;
	for (int i=0; i<c; ++i)
		if (wh[i] != -1)
			ans[i] = (matrix[wh[i]][c]*inversion(matrix[wh[i]][i],n))%n;
	for (int i=0; i<r; ++i) 
	{
		int sum = 0;
		for (int j=0; j<c; ++j)
			sum += ans[j] * matrix[i][j];
		if (sum - matrix[i][c]==0)
			return 0;
	}
 
	for (int i=0; i<c; ++i)
		if (wh[i] == -1)
			return -1111111;
	return 1;
}

int indexAlgo(int n, int b, int g)
{
	int F[N]={0};
	int t=EratosthenesSieve (F, N, n);//отримали факторну базу і кількіть елементів у ній
	int c=3;
	int k=1;
	int pows[50];
	int matrix[50][50]={0};
	int gk;
	srand((unsigned)time(NULL));
	for(int u=0; u<t+c; ++u)
	{
		k=rand()%n;
		gk=Ipow(g, k, n);
		if (factor_in_F(F, pows, gk, t))
			{
				for(int j=0; j<t+c; ++j)
					for(int i=0; i<t; ++i)
						matrix[j][i]=pows[i];
				++u;
			}
	}//склали ситему рівнянь

	int ans[50]={0};
	int ok=gauss(matrix, t, t+c, ans, n);
	if (ok!=1) return -1;

	for(int i=0; i<50; ++i)
		pows[i]=0;

	bool find=0;
	while(!find)
	{
		k=rand()%n;
		gk=Ipow(g, k, n);
		gk=(gk*b)%n;
		if (factor_in_F(F, pows, gk, t))
			find=1;
	}

	int sum=0;
	for(int i=0; i<=t; ++i)
		sum=(sum+(pows[i]*ans[i])%n)%n;
	return (sum-k)%n;
}

int indеxAlgo(int n, int b, int g)
{
	int log=1;
	int pow=g;
	while(g%n!=b)
	{
		g*=pow;
		++log;
	}
	return log;
}
/*#include <iostream>
#include <cmath>
#include"header.h"

using namespace std;
const int N=100;

int quadraticMethod (int n);
int multiplierBasis (int *F, int n);
void EratosthenesSieve (int simple[], const int N);
bool factor_in_F(int F[N], int l[N], int b, int t);

int main()
{	
	int n;
	cout<<"This program carries factorization by quadratic method.\n";
	cout<<"Please, enter the number (>0) that you would like to expand into simple factors: ";
	cin>>n;
	if (n<=0) {
				cout<<"\nYou have entered a number less than zero";
				system("pause");
				return 0;
			  };
	cout<<"\n n: ";
	cout<<"aaaaaaa______    "<<quadraticMethod(n)<<endl;
	system("pause");
	return 0;
}

int multiplierBasis (int *F, int n)
{
	int simple[N]={0};
	EratosthenesSieve(simple, N);//шукаємо прості числа від 2 до n
	F[0]=-1;
	int z;
	for (int i=0, j=1, x=1; simple[i]!=0 && simple[i]<n; ++i)
		{
			z=n%simple[i];//шукаємо остачу від ділення n на і-те просте число
			while(x<simple[i])
			{
				if ((x*x)%simple[i]==z)
					{
						F[j]=simple[i];
						++j;
						break;
					}
				++x;
			}
			//вцьому циклі шукаємо чи існує таке х, що в квадраті дорівнює n за модулем p-
													 //і-те просте число, якщо воно існує, то ми знайшли j-те просте число p, для 
													 //якого n є квадратичним лишком по модулю p
			x=1;//скидуємо значення x
		}
	for (int j=0; F[j]!=0; ++j)
		cout<<F[j]<<" ";
	int i=0;
	for (; F[i]!=0; ++i);
	return i;//кількість елементів у факторній базі
}

void EratosthenesSieve (int simple[], const int N)
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
	for(unsigned int i=0, j=2; j<sieve$.length();j++)
		if (sieve$[j]=='P') {
								simple[i]=j;
								++i;
							}
}

int quadraticMethod (int n)
{
	int F[N]={0};//факторна база
	int e[N][N]={0};//масив степенів у розкладі b і-ого по факторній базі (масив вектор степенів)
	int T[N]={0};//підмножина {1...t+1} така, що сума v[i], де і належить Т рівна 0
	bool v[N][N]={0};//тут ми записуємо "двійкову маску" вектор степенів
	int t = multiplierBasis (F, n);
	int m=int(sqrt(double (n)));
	int x=0;
	//перші два масиви, це масиви а і-тих і b і-тих
	int a[N]={0};
	int b[N]={0};
	int c=0;
	//знаходимо t+1 пару а і-тих b і-тих
	//заповнюємо масиви вектор степенів і двійкових масок вектор степенів
	for (int i=1; i<=t+1; ++i)
		{
			c = ((x+m)*(x+m) - n) % n;
			while (!factor_in_F(F,e[i],c,t))//розкладається
				{
					x = x<=0 ? -x+1 : -x;
					c = ((x+m)*(x+m) - n) % n;
				}
			a[i]=x+m;
			b[i]=c;
			for (int j=0; j<=t; ++j)
				v[i][j]=e[i][j]%2;
			x = x<=0 ? -x+1 : -x;
		}

	int y=1;
	int s=2;
	do
	{
		bool sum[N]={0};//тут ми будемо зберігати суму векторів
		for (int h=0; h<t+1; ++h)//обнуляєм, бо будемо шукати іншу підмножину
			T[h]=0;
		for ( ; s<=pow(2., t+1); ++s)//в булеані множини, яка складається з t+1 елементу, 2 в степені t+1 множина
			{
				for (int r=0; r<t+1; ++r)
					sum[r]=0;
				//ми беремо двійковий код числа і, якщо на і-ому місці 1, то ми додаємо і-ий вектор до суми
				for (int j=1; j<=t; ++j)
					{
						if (s>>j & 0x1)
							{
								for (int h=0; h<=t; ++h)
									sum[h]=(sum[h]+v[j][h])%2;
							}
					}

				bool ok=1;
				//якщо всі елементи у векторі-сумі 0, то ми знайшли потрібну підмножину
				for (int k=0; k<=t && ok; ++k)
					{
						if (sum[k]!=0) ok=0;
					}
				//якщо все добре, тобто сума векторів дорівнює 0=вектору і значення і у нас ше не оброблялось, то 
				//ми візьмемо двійковий код цього числа і, якщо на і-ому місці 1, то і записуємо у нашу підмножину
				if (ok) 
					{
						for (int j=1, k=0; j<=t; ++j)
							if (s>>j & 0x1)
								{
									T[k]=j;
									++k;
								}
						break;
					}
			}

		//обчислюємо  добуток а і-тих, де і належить Т
		for (int h=0; T[h]!=0; ++h)
			x=(x*a[T[h]])%n;
		if (x<0) x=n+x;
		int l[N]={0};
		int summa=0;
		//рахуємо l[j] - крок 6
		for (int j=1; j<=t; ++j)
			{
				//обчислюємо суму e[i][j], де i належить Т
				for (int h=0; T[h]!=0; ++h)
					summa+=e[T[h]][j];
				l[j]=(summa/2)%n;
				summa=0;
			}
		//крок 7
		for (int m=1; m<t; ++m)
			y=(y*Ipow(F[m],l[m],n))%n;
		if(!((x==y) || (x==(-y+n)%n) || ((-x+n)%n==y)))
			{
				int d=GCD(abs(x-y),n);
				if (d>1) return d;
			}
	}
	while(1);
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
}*/
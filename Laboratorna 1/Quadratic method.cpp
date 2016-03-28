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
	EratosthenesSieve(simple, N);//������ ����� ����� �� 2 �� n
	F[0]=-1;
	int z;
	for (int i=0, j=1, x=1; simple[i]!=0 && simple[i]<n; ++i)
		{
			z=n%simple[i];//������ ������ �� ������ n �� �-�� ������ �����
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
			//������ ���� ������ �� ���� ���� �, �� � ������� ������� n �� ������� p-
													 //�-�� ������ �����, ���� ���� ����, �� �� ������� j-�� ������ ����� p, ��� 
													 //����� n � ������������ ������ �� ������ p
			x=1;//������� �������� x
		}
	for (int j=0; F[j]!=0; ++j)
		cout<<F[j]<<" ";
	int i=0;
	for (; F[i]!=0; ++i);
	return i;//������� �������� � �������� ���
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
	int F[N]={0};//�������� ����
	int e[N][N]={0};//����� ������� � ������� b �-��� �� �������� ��� (����� ������ �������)
	int T[N]={0};//��������� {1...t+1} ����, �� ���� v[i], �� � �������� � ���� 0
	bool v[N][N]={0};//��� �� �������� "������� �����" ������ �������
	int t = multiplierBasis (F, n);
	int m=int(sqrt(double (n)));
	int x=0;
	//����� ��� ������, �� ������ � �-��� � b �-���
	int a[N]={0};
	int b[N]={0};
	int c=0;
	//��������� t+1 ���� � �-��� b �-���
	//���������� ������ ������ ������� � �������� ����� ������ �������
	for (int i=1; i<=t+1; ++i)
		{
			c = ((x+m)*(x+m) - n) % n;
			while (!factor_in_F(F,e[i],c,t))//������������
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
		bool sum[N]={0};//��� �� ������ �������� ���� �������
		for (int h=0; h<t+1; ++h)//��������, �� ������ ������ ���� ���������
			T[h]=0;
		for ( ; s<=pow(2., t+1); ++s)//� ������ �������, ��� ���������� � t+1 ��������, 2 � ������ t+1 �������
			{
				for (int r=0; r<t+1; ++r)
					sum[r]=0;
				//�� ������ �������� ��� ����� �, ���� �� �-��� ���� 1, �� �� ������ �-�� ������ �� ����
				for (int j=1; j<=t; ++j)
					{
						if (s>>j & 0x1)
							{
								for (int h=0; h<=t; ++h)
									sum[h]=(sum[h]+v[j][h])%2;
							}
					}

				bool ok=1;
				//���� �� �������� � ������-��� 0, �� �� ������� ������� ���������
				for (int k=0; k<=t && ok; ++k)
					{
						if (sum[k]!=0) ok=0;
					}
				//���� ��� �����, ����� ���� ������� ������� 0=������� � �������� � � ��� �� �� �����������, �� 
				//�� ������� �������� ��� ����� ����� �, ���� �� �-��� ���� 1, �� � �������� � ���� ���������
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

		//����������  ������� � �-���, �� � �������� �
		for (int h=0; T[h]!=0; ++h)
			x=(x*a[T[h]])%n;
		if (x<0) x=n+x;
		int l[N]={0};
		int summa=0;
		//������ l[j] - ���� 6
		for (int j=1; j<=t; ++j)
			{
				//���������� ���� e[i][j], �� i �������� �
				for (int h=0; T[h]!=0; ++h)
					summa+=e[T[h]][j];
				l[j]=(summa/2)%n;
				summa=0;
			}
		//���� 7
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
	for (j=1; b!=1 && j<=t && F[j]!=0; ++j)//���� b �� ���������� �� ���� �� ���������� �������� � ����� �������� ���
		{
			for ( ; (b%F[j])==0; )//���� b ������� �� j-�� ����� � �������� ����, ����� ���� �� �����, ��� �������� ������ ����� �����
				{
					b/=F[j];
					l[j]++;//���� �� �������� ������ j-��� ����� � �������� ����
				}

		}
	if (b==1) return 1;
	else return 0;//�� ������, �� ����� �� ������������ �� ��������� �����
}*/
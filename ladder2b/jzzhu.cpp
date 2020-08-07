#include <bits/stdc++.h>
#define sp 1000000007
using namespace std;
void mm(long long int a[2][2], long long int b[2][2])
{
	long long int c[2][2];
	for(long long int i=0;i<2;i++)
	{
		for(long long int j=0;j<2;j++)
		{
			long long int sum=0;
			for(long long int k=0;k<2;k++)
			{
				sum=(sum+(a[i][k]*b[k][j]+sp)%sp+sp)%sp;
			}
			c[i][j]=sum;
		}
	}
	for(long long int i=0;i<2;i++)
		for(long long int j=0;j<2;j++)
			a[i][j]=c[i][j];
}
void power(long long int A[2][2], long long int n)
{
	long long int y[2][2];
	y[0][0]=1;
	y[0][1]=0;
	y[1][0]=0;
	y[1][1]=1;
	while(n>0)
	{
		if(n%2==1)
			mm(y,A);
		mm(A,A);
		n=n/2;
	}
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			A[i][j]=y[i][j];
}
int main()
{
	long long int a[2][2];
    a[0][0]=1;
    a[0][1]=-1;
    a[1][0]=1;
    a[1][1]=0;
	long long int x,y,n;
    cin>>x>>y;
	cin>>n;
    if(n>2)
    {
	power(a,n-2);
	printf("%lld\n",((a[0][0]*y+sp)%sp+(a[0][1]*x+sp)%sp+sp)%sp);	
    }
    else
    {
        if(n==2)
            cout<<(y+sp)%sp<<endl;
        else
        {
            cout<<(x+sp)%sp<<endl;
        }
        
    }
    
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
ll fast_expo(ll a, ll n)
{
	ll ans=1;
	while(n>0)
	{
		if(n%2==1)
			ans=(ans*a)%M;
		a=(a*a)%M;
		n=n/2;
	}
	return ans;
}
int main()
{
    ll n,m;
    cin>>n>>m;
    ll dp1[max(n,m)+1];
    dp1[1]=2;
    dp1[2]=4;
    dp1[3]=6;
    for(ll i=4;i<=max(n,m);i++)
    {
        dp1[i]=((2*dp1[i-1])%M-dp1[i-3]+M)%M;
    }
    cout<<(dp1[n]+dp1[m]-2+M)%M<<endl;
}
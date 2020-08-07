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
 cin.tie(0);
ios::sync_with_stdio(0);
    string x;
    cin>>x;
    ll n=x.size();
    ll parity[n+1];
    memset(parity,0,(n+1)*sizeof(n+1));
    for(ll i=1;i<n+1;i++)
    {
        if(x[n-i]=='1')
            parity[i]=1;
    }
    ll dp[n+1];
    dp[0]=0;
    for(ll i=1;i<=n;i++)
    {
        dp[i]=(2*dp[i-1])%M;
        if(parity[i]==1)
            dp[i]=(fast_expo(2,2*(i-1))+dp[i])%M;
    }
    cout<<dp[n]<<endl;
}
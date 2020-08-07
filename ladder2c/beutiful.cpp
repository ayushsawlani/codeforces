#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
ll fac[1000001];
long long int fast_expo(ll a, ll n)
{
	ll ans=1;
	while(n>0)
	{
		if(n%2==1)
			ans=((ans*a)%M);
		a=((a*a)%M);
		n=n/2;
	}
	return ans;
}
ll n_c_r_mod_m(ll *fac,ll n, ll r)
{
    ll ans= ((fac[n]*fast_expo(fac[r],M-2))%M);
    ans=((ans*fast_expo(fac[n-r],M-2))%M);
    return ans;
}
ll checker(ll x, ll a, ll b)
{
    if (x==0)
        return 0;
    while(x>0)
    {
        if(((x%10)!=a)&&((x%10)!=b))
            return 0;
        x=x/10;
    }
    return 1;
}
int main()
{
    ll a,b,n;
    cin>>a>>b>>n;
    ll ans=0;
    fac[0]=1;
    //ll x;
    //cin>>x;
    for(ll i=1;i<=1000000;i++)
    {
        fac[i]=((fac[i-1]*i)%M);
    }
    for(ll i=0;i<=n;i++)
    {
        ll num_a=i;
        ll num_b=n-i;
        if(checker(num_a*a+num_b*b,a,b))
            ans=(ans+((n_c_r_mod_m(fac,n,i))))%M;
    }
    cout<<ans<<endl;
}
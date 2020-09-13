#include <bits/stdc++.h>
using namespace std;
#define M (ll)(1e9+7)
#define ll long long
ll fac[2009];
long long int fast_expo(ll a, ll n)
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
ll n_c_r_mod_m(ll n, ll r)
{
    if(n<r)
        return 0;
    ll ans= ((fac[n]*fast_expo(fac[r],M-2))%M);
    ans=((ans*fast_expo(fac[n-r],M-2))%M);
    return ans;
}
int main()
{
    int prime[2004];
    memset(prime,0,2004*sizeof(int));
    for(ll i=2;i<2004;i++)
    {
        for(ll j=i*i;j<2004;j=j+i)
            prime[j]=1;
    }
    fac[1]=1;
    fac[0]=1;
    for(int i=2;i<2009;i++)
    {
        fac[i]=(fac[i-1]*i)%M;
    }
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n,k;
       cin>>n>>k;
    ll dp[n+4];
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(prime[i]==1)
        {
            ll factorize[i+4];
            memset(factorize,0,(i+4)*sizeof(ll)); 
            int div=i;
            for(int f=2;f<=div;f++)
            {
                if(div%f==0)
                {
                    factorize[f]++;
                    div=div/f;
                    f--;
                }   
            }
            ll addition=1;
            for(int it=2;it<i+4;it++)
            {
                addition=(addition*n_c_r_mod_m(factorize[it]+k-1,factorize[it]))%M;
            }
            dp[i]=(dp[i-1]+addition)%M;
        }
        else
        {
            dp[i]=(dp[i-1]+k)%M;
            continue;
        }

        //cout<<dp[i]<<" "<<i<<endl;
    }
    cout<<dp[n]<<endl;
}
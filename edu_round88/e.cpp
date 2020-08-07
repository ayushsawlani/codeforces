#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long int
#define pb push_back
#define mod 998244353
#define inarr(i,arr,n); for(ll i=0;i<n;i++) cin >> arr[i];
#define outarr(i,arr,n); for(ll i=0;i<n;i++) cout<<arr[i]<<' ';
#define swap(a,b,t) {t=a;a=b;b=t;}
#define ve vector
#define sz(a) (int)((a).size())
#define fi first
#define se second
#define pa pair
#define fastio  {ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
#define ll long long int
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define frn(i, a, b) for (int i = a; i >= b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(i, vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//uncomment for accurate decimal precision.
//cout << fixed << setprecision(9);
ve <ll> fac(5*1e5+5);
ll fast_expo(ll a, ll n)
{
	int ans=1;
	while(n>0)
	{
		if(n%2==1)
			ans=(ans*a)%mod;
		a=(a*a)%mod;
		n=n/2;
	}
	return ans;
}
ll n_c_r_mod_m(ll n, ll r)
{
    if(n<r)
        return 0;
    ll ans= ((fac[n]*fast_expo(fac[r],mod-2))%mod);
    ans=((ans*fast_expo(fac[n-r],mod-2))%mod);
    return ans;
}
int main()
{
    //fastio
    fac[0]=1;
    fr(i, 1, 5*1e5+4)
    {
        fac[i]=fac[i-1]*i;
        fac[i]%=mod;
    }
    ll n, k;
    cin>>n>>k;
    ll ans=0;
    fr(i, 1, n)
    {
        ll x=n/i-1;
        ans+=n_c_r_mod_m(x, k-1);
        ans%=mod;
    }
    cout<<ans<<endl;
}
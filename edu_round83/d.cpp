#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long int
#define pb push_back
#define mod (ll)998244353
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
#define fr(i, a, b) for (int i = a; i < b; i++)
#define frn(i, a, b) for (int i = a; i > b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//cout << fixed << setprecision(9) << ans <<endl; for accurate decimal precision.
long long int fast_expo(ll a, ll n)
{
	ll ans=1;
	while(n>0)
	{
		if(n%2==1)
			ans=((ans*a)%mod);
		a=((a*a)%mod);
		n=n/2;
	}
	return ans;
}
ve <ll> fac;
ll n_c_r_mod_m(ll n, ll r)
{
    ll ans= ((fac[n]*fast_expo(fac[r],mod-2))%mod);
    ans=((ans*fast_expo(fac[n-r],mod-2))%mod);
    ans%=mod;
    return ans;
}
int main()
{
    //fastio
    ll m,n;
    cin>>n>>m;
    fac.resize(m+5);
    fac[0]=1;
    fr(i, 1, m+5)
    {
        fac[i]=(fac[i-1]*i)%mod;
        if(fac[i]<0)
            cout<<fac[i]<<endl;
    }
    ll ans=0;
    fr(j,1,n-1)
    {
        ans=ans + (((n_c_r_mod_m(m,n-1))*(((n-2)*(n_c_r_mod_m(n-3,j-1)))%mod))%mod);
        ans%=mod;
    }
    cout<<ans<<endl;
}
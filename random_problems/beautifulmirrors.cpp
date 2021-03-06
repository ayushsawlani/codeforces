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
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define frn(i, a, b) for (int i = a; i >= b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(i, vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//uncomment for accurate decimal precision.
//cout << fixed << setprecision(9);
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
ll inv(ll x)
{
    return fast_expo(x, mod-2);
}
int main()
{
    //fastio
    ll n;
    cin>>n;
    ve <ll>  in(n);
    inarr(i, in, n);
    fr(i, 0, n-1)
    {
        in[i]=(in[i]*inv(100))%mod;
    }
    ll ans=0;
    ll x=1;
    frn(i, n-1, 0)
    {
        x=(x*(inv(in[i])))%mod;
        ans+=x;
        ans%=mod;
    }
    cout<<ans<<endl;
}
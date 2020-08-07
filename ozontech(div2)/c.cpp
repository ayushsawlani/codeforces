#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ceil (ll)ceil
#define ll long long int
#define pb push_back
#define mod 1000000007
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
ll fast_expo(ll a, ll n, ll M)
{
	int ans=1;
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
    //fastio
    ll n, m;
    cin>>n>>m;
    ve <ll> in(n);
    inarr(i, in, n);
    ve <ll> carr(m, 0);
    ve <ll> mapp(m, -1);
    fr(i, 0, n-1)
    {
        carr[in[i]%m]++;
        mapp[in[i]%m]=in[i];
    }
    fr(i, 0, m-1)
    {
        if(carr[i]>1)
        {
            cout<<0<<endl;
            return 0;
        }
    }
    ll ans=1; 
    fr(i, 1, m-1)
    {
        frn(j, i-1, 0)
        {
            ll x=abs(mapp[j]-mapp[i]); 
            if((carr[i])&&(carr[j]))
                ans=ans*x;
            ans%=m;
        }
    }
    cout<<ans<<endl;
}
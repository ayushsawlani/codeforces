#include<iostream>
#include<bits/stdc++.h>
using namespace std;
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
#define fr(i, a, b); for (int i = a; i < b; i++)
#define frn(i, a, b); for (int i = a; i > b; i--)
#define mk make_pair
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 1e18;
ll fast_expo(ll a, ll n)
{
	int ans=1;
	while(n>0)
	{
		if(n%2==1)
			ans=(ans*a)%mod;
		a=(a*a)%mod;
		n=(n/2);
	}
	return ans;
}
int main()
{
    //fastio
    ll n,m,l,r;
    cin>>n>>m>>l>>r;
    ll x,y;
    x=(r-l+1)/2;
    y=(r-l+1)/2;
    if((r-l+1)%2)
    {
        if(l%2)
        {
            x++;
        }
        else
            y++;
    }
    ll ans=0;
    if((n*m)%2==0)
    {
        ans+=fast_expo(x+y,n*m);
        ans+=fast_expo(x-y,n*m);
        ans%=mod;
        ans*=fast_expo(2,mod-2);
        ans%=mod;
    }
    else
    {
        ans=fast_expo(x+y,n*m);
    }
    cout<<ans<<endl;
}
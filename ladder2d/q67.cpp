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
int main()
{
    //fastio
    ll n, h;
    cin>>n>>h;
    ve <pair <ll,ll>> in(n);
    fr(i, 0, n-1)
    {
        cin>>in[i].fi;
        in[i].se=i;
    }
    sort(all(in));
    ve <ll> ans(n, 1);
    ll x=in[n-1].fi+in[n-2].fi-in[0].fi-in[1].fi;
    if(max(in[n-1].fi+in[0].fi+h, in[n-1].fi+in[n-2].fi)-min(in[0].fi+in[1].fi+h, in[1].fi+(n>2?in[2].fi:in[0].fi+h))<in[n-1].fi+in[n-2].fi-in[0].fi-in[1].fi)
    {
        x=max(in[n-1].fi+in[0].fi+h, in[n-1].fi+in[n-2].fi)-min(in[0].fi+in[1].fi+h, in[1].fi+(n>2?in[2].fi:in[0].fi+h));
        ans[in[0].se]=2;
    }
    cout<<x<<endl;
    outarr(i, ans, n);
    cout<<endl;
}
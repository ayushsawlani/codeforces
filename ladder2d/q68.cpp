#include<iostream>
#include<bits/stdc++.h>
#include <cstdlib>
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
    ll n;
    cin>>n;
    ve <pair <ld, pair <ld,ld>>> in(n);
    fr(i, 0, n-1)
    {
        cin>>in[i].se.fi>>in[i].se.se;
        if(in[i].se.fi!=0)
            in[i].fi=(-(in[i].se.se)/in[i].se.fi);
        else
        {
            in[i].fi=-inf;
        }
    }
    sort(all(in));
    map<ld, ld> yes;
    fr(i, 0, n-1)
    {
        if(in[i].fi!=-inf)
        {
            if(yes.find(in[i].fi)==yes.end())
            {
                yes[in[i].fi]=abs(in[i].se.fi);
            }
            else
            {
                yes[in[i].fi]+=abs(in[i].se.fi);
            }
        }
    }
    ll ans=0;
    for(auto j:yes)
    {
        if(j.se!=0)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
}
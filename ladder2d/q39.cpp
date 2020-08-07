#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ld long double
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
#define fr(i, a, b) for (int i = a; i < b; i++)
#define frn(i, a, b) for (int i = a; i > b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//cout << fixed << setprecision(9) << ans <<endl; for accurate decimal precision.
int main()
{
    //fastio
    ll n;
    cin>>n;
    ve <ll> in(n);
    inarr(i, in, n);
    ll f=0;
    fr(i, 0, n-1)
    {
        if(in[i]>in[i+1])
            f=1;
    }
    if(f==0)
    {
        cout<<0<<endl;
        return 0;
    }
    fr(i, 0, n/2)
    {
        ll _temp;
        swap(in[i], in[n-i-1], _temp);
    }
    ve <ll> stac, day(sz(in), 1),dead(n, 0);
    ll i=0;
    stac.pb(0);
    i++;
    ll ans=1;
    while(i<sz(in))
    {
        ll m1=0;
        while(sz(stac)>0)
        {
            if(in[i]<=in[stac[sz(stac)-1]])
                break;
            day[stac[sz(stac)-1]]=max(m1+1,day[stac[sz(stac)-1]]);
            dead[stac[sz(stac)-1]]=1;
            m1=max(day[stac[sz(stac)-1]],m1);
            stac.pop_back();
        }
        if((sz(stac)>0))
            day[stac[sz(stac)-1]]=max(m1+1,day[stac[sz(stac)-1]]);
        stac.pb(i);
        i++;
    }
    fr(i, 0, sz(in))
        if(dead[i])
           ans=max(ans, day[i]);
    cout<<ans<<endl;
}
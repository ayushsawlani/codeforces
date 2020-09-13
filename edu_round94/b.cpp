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
    ll t;
    cin>>t;
    while(t--)
    {
        ll p, f, cs, cw, ws, ww;
        cin>>p>>f>>cs>>cw>>ws>>ww;
        if(p>f)
        {
            ll _t;
            swap(p, f, _t);
        }
        if(ws>ww)
        {
            ll _t;
            swap(ws, ww, _t);
            swap(cs, cw, _t);
        }
        ll minn=min(p/ws+f/ws, cs);
        ll ans=minn;
        fr(i, 0, minn)
        {
            if((i*ws<=p)&&((minn-i)*ws<=f))
            {
                ll _p=p-i*ws;
                ll _f=f-(minn-i)*ws;
                //cout<<_p<<" "<<_f<<endl;
                ll temp=min((_p/ww)+(_f/ww), cw);
                ans=max(ans, minn+temp);
            }
        } 
        cout<<ans<<endl;
    }
}
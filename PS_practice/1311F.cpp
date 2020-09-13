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
ll solve(ve <pair <ll,ll>> &yess)
{
    ll n=sz(yess);
    if(n>1)
    {
        ve <pair <ll,ll>> a, b;
        fr(i, 0, n/2-1)
        {
            a.pb(yess[i]);
        }
        fr(i, n/2, n-1)
        {
            b.pb(yess[i]);
        }
        //cout<<solve(a)<<endl;
        ll ans=solve(a)+solve(b);
        ve <ll> pre(sz(b));
        pre[sz(b)-1]=b[sz(b)-1].fi;
        frn(i, sz(b)-2, 0)
        {
            pre[i]=b[i].fi+pre[i+1];
        }
        ve <pair <ll,ll>> c;
        ll i=0, j=0;
        while((i<sz(a))&&(j<sz(b)))
        {
            if(a[i].se<=b[j].se)
            {
                ans+=(pre[j]-a[i].fi*(sz(b)-j));
                c.pb(a[i++]);
            }
            else
            {
                c.pb(b[j++]);
            }
            
        }
        while(i<sz(a))
        {
            c.pb(a[i++]);
        }
        while(j<sz(b))
        {
            c.pb(b[j++]);
        }
        yess=c;
        return ans;
    }
    else
    {
        return 0;   
    }
}
int main()
{
    //fastio
    ll n;
    cin>>n;
    ve <pair <ll, ll>> in(n);
    fr(i, 0, n-1)
    {
        cin>>in[i].fi;
    }
    fr(i, 0, n-1)
    {
        cin>>in[i].se;
    }
    sort(all(in));
    ve <ll> yess;
    fr(i, 0, n-1)
    {
        yess.pb(in[i].se);
    }
    cout<<solve(in)<<endl;
}
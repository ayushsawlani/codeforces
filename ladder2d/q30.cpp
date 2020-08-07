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
const ll inf = 1e18;
//cout << fixed << setprecision(9) << ans <<endl; for accurate decimal precision.
ve <ll> ans;
ve <pair <ll,ll>> merge(ve <pair <ll,ll>> a, ve <pair <ll,ll>> b)
{
    ve <pair <ll,ll>> ret;
    ve <ll> cum(sz(b));
    cum[0]=b[0].se;
    fr(i, 1, sz(b))
    {
        cum[i]=max(cum[i-1], b[i].se);
    }
    ll i=0;
    ll j=0;
    while((i<sz(a))&&(j<sz(b)))
    {
        if(a[i].fi>b[j].fi)
        {
            ret.pb(b[j++]);
        }
        else
        {
            if(j>0)
                ans[a[i].se]=max(ans[a[i].se],cum[j-1]-a[i].se-1);
            ret.pb(a[i++]);
        }
    }
    while(i<sz(a))
    {
            ans[a[i].se]=max(ans[a[i].se],cum[sz(b)-1]-a[i].se-1);
            ret.pb(a[i++]);
    }
    while(j<sz(b))
    {
            ret.pb(b[j++]);
    }
    return ret;
}
ve <pair <ll,ll>> sort(ve <pair <ll,ll>> a)
{
    if(sz(a)==1)
        return a;
    ve <pair <ll,ll>> m1,m2;
    ll i=0;
    while(i<sz(a)/2)
    {
        m1.pb(a[i++]);
    }
    while(i<sz(a))
    {
        m2.pb(a[i++]);
    }
    return merge(sort(m1),sort(m2));
}
int main()
{
    //fastio
    ll n;
    cin>>n;
    ve<ll> in(n);
    inarr(i,in,n);
    ans.resize(n);
    setvector(ans,-1,n);
    ve<pair <ll,ll>> util(n);
    fr(i,0,n)
    {
        util[i].fi=in[i];
        util[i].se=i;
    }
    sort(util);
    outarr(i,ans,n);
    cout<<endl;
}
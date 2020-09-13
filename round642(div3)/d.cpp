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
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define frn(i, a, b) for (int i = a; i >= b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(i, vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//uncomment for accurate decimal precision.
//cout << fixed << setprecision(9);
ll rec(ve <ve <ll>> &G,ll i,ll j)
{
   if(i<=j)
    {
        ll mid=(i+j)/2;
        ll lc=rec(G, i, mid-1);
        ll rc=rec(G, mid+1, j);
        if(lc!=-1)
        {
            G[mid].pb(lc);
        }
        if(rc!=-1)
        {
            G[mid].pb(rc);
        }
        return mid;
    }
    return -1;
}
void dfs(ve <ve <ll>> &G, ve <ll> &c, ve <ll> &child, ll seed)
{
    c[seed]=1;
    for(auto i:G[seed])
    {
        if(c[i]==0)
        {
            dfs(G, c, child, i);
        }
    }
    for(auto i: G[seed])
    {
        child[seed]+=child[i];
    }
}
int main()
{
    //fastio
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ve <ve <ll>> G(n, ve <ll>());
        rec(G, 0, n-1);
        ve <ll> c(n, 0), child(n, 1);
        dfs(G, c, child, (n-1)/2);
        ve <pair <ll,ll>> util;
        fr(i, 0, n-1)
        {
            util.pb(pair <ll,ll>(child[i], -i));
        }
        sort(util.begin(), util.end());
        ve <ll> ans(n);
        frn(i, n-1, 0)
        {
            ans[-util[i].se]=n-i;
        }
        outarr(i, ans, n);
        cout<<endl;
    }
    
}
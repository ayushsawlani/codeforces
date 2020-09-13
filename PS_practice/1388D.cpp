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
void dfs(ve <ve <ll>> &G, ve <ll> &c, ve <ll> &val, ll seed)
{
    c[seed]=1;
    for(auto chi:G[seed])
    {
        if(c[chi]==0)
        {
            dfs(G, c, val, chi);
        }
    }
    for(auto chi:G[seed])
    {
        if(val[chi]>0)
        {
            val[seed]+=val[chi];
        }
    }
}
void visit(ve <ve <ll>>&G, ve <ll> &val, ll seed)
{
    ve <ll> v1, v2;
    for(auto chi:G[seed])
    {
        if(val[chi]>0)
        {
            v1.pb(chi);
        }
        else
        {
            v2.pb(chi);
        }
    }
    for(auto it:v1)
    {
        visit(G, val, it);
    }
    cout<<seed+1<<" ";
    for(auto it:v2)
    {
        visit(G, val, it);
    }
}
int main()
{
    //fastio
    ll n;
    cin>>n;
    ve <ll> a(n), b(n);
    inarr(i, a, n);
    inarr(i, b, n);
    ve <ve <ll>> G(n);
    fr(i, 0, n-1)
    {
        if(b[i]!=-1)
            G[b[i]-1].pb(i);
    }
    
    ve <ll> col(n, 0);
    fr(i, 0, n-1)
    {
        if(col[i]==0)
        {
            dfs(G, col, a, i);
        }
    }
    ll sum=0;
    fr(i, 0, n-1)
    {
        sum+=a[i];
    }
    cout<<sum<<endl;
    fr(i, 0, n-1)
    {
        if(b[i]==-1)
        {
            visit(G, a, i);
        }
    }
    cout<<endl;
    //*/
}
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
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define frn(i, a, b) for (int i = a; i >= b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(i, vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//uncomment for accurate decimal precision.
//cout << fixed << setprecision(9);
void dfs1(ve <ve <ll>> &G, ve <ll> &c, ve <ll> &cost, ll seed)
{
    c[seed]=1;
    for(auto j:G[seed])
    {
        if(c[j]==0)
        {
            cost[j]=min(cost[j], cost[seed]);
            dfs1(G, c, cost, j);
        }
    }
}
ll dfs2(ve <ve <ll>> &G, ve <ll> &c, ve <ll> &pi, ve <ll> &cost, ve <ll> &co01, ve <ll> &co10, ve <ll> &indic, ll seed)
{
    ll ans=0;
    c[seed]=1;
    for(auto j:G[seed])
    {
        if(c[j]==0)
        {
            pi[j]=seed;
            ans+=dfs2(G, c, pi, cost, co01, co10, indic, j);
        }
    }
    for(auto chi:G[seed])
    {
        if(pi[seed]!=chi)
        {
            co01[seed]+=co01[chi];
            co10[seed]+=co10[chi];
        }
    }
    if(indic[seed]==1)
    {
        co10[seed]++;
    }
    if(indic[seed]==-1)
    {
        co01[seed]++;
    }
    ll x=min(co01[seed], co10[seed]);
    ans+=(x*2*cost[seed]);
    co01[seed]-=x;
    co10[seed]-=x;
    return ans;
}
int main()
{
    //fastio
    ll n;
    cin>>n;
    ve <ll> indic(n, 0);
    ve <ll> cost(n);
    ve <ve <ll>> G(n);
    fr(i, 0, n-1)
    {
        cin>>cost[i];
        ll t1, t2;
        cin>>t1>>t2;
        indic[i]=t1-t2;
    }
    fr(i, 0, n-2)
    {
        ll a, b;
        cin>>a>>b;
        a--;
        b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    ve <ll> c(n, 0), pi(n, -1), co01(n, 0), co10(n, 0);
    dfs1(G, c, cost, 0);
    setvector(i, c, 0, n);
    ll ans=dfs2(G, c, pi, cost, co01, co10, indic, 0);
    if(co10[0]!=co01[0])
    {
        cout<<-1<<endl;
        return 0;
    }
    cout<<ans<<endl;
}
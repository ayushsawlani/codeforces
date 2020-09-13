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
ve <ll> seedhadist, ultadist;
void dfs(ve <ve <ll>> &G,ve <ll> &c,ve <ll> &pi, int seed)
{
    c[seed]=1;
    for(auto i:G[seed])
    {
        if(c[i]==0)
        {
            pi[i]=seed;
            dfs(G, c, pi, i);
        }
    }
    ll m1=-inf;
    for(auto i:G[seed])
    {
        if(pi[seed]!=i)
        {
            m1=max(m1, seedhadist[i]) ;           
        }
    }
    if(m1!=-inf)
    {
        seedhadist[seed]=m1+1;
    }
}
void dfs2(ve <ve <ll>> &G,ve <ll> &c,ve <ll> &pi, int seed)
{
    c[seed]=1;
    ve <ll> child;
    for(auto i:G[seed])
    {
        if(i!=pi[seed])
        {
            child.pb(i);
        }
    }
    ll n=sz(child);
    if(n)
    {
        ve <ll> suf(n), pre(n);
        pre[0]=seedhadist[child[0]];
        suf[n-1]=seedhadist[child[n-1]];
        fr(i, 1, n-1)
        {
            pre[i]=max(seedhadist[child[i]], pre[i-1]);
            suf[n-i-1]=max(seedhadist[child[n-i-1]], suf[n-i]);
        }
        ll m1=-inf;
        fr(i, 0, n-1)
        {
            ll m1=max(i>0?pre[i-1]:-inf, i<n-1?suf[i+1]:-inf);
            if(m1!=-inf)
                ultadist[child[i]]=m1+2;
            if(ultadist[seed]!=-inf)
                ultadist[child[i]]=max(ultadist[child[i]],ultadist[seed]+1);
        }
    }
    for(auto i:child)
    {
        dfs2(G, c, pi, i);
    }
}
int main()
{
    //fastio
    ll n, _m, d;
    cin>>n>>_m>>d;
    ve <ll> sp(n, 0);
    fr(i, 0, _m-1)
    {
        ll _t;
        cin>>_t;
        _t--;
        sp[_t]=1;
    }
    ve <ve <ll>> G(n);
    fr(i, 0, n-2)
    {
        ll a, b;
        cin>>a>>b;
        a--;
        b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    ve <ll> c(n, 0), pi(n, -1);
    seedhadist.resize(n);
    ultadist.resize(n);
    setvector(i, seedhadist, -inf, n);
    setvector(i, ultadist, -inf, n);
    fr(i, 0, n-1)
    {
        if(sp[i])
        {
            seedhadist[i]=0;
            ultadist[i]=0;
        }
    }
    dfs(G, c, pi, 0);
    setvector(i, c, 0, n);
    dfs2(G, c, pi, 0);
    ll ans=0;
    fr(i, 0, n-1)
    {
        if(max(seedhadist[i], ultadist[i])<=d)
            ans++;
    }
    cout<<ans<<endl;
    //*/
}
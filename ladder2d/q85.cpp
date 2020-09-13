#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ceil (ll)ceil
#define ll long long int
#define pb push_back
#define mod 1000000007
#define inarr(i,arr,n); for(int i=0;i<n;i++) cin >> arr[i];
#define outarr(i,arr,n); for(int i=0;i<n;i++) cout<<arr[i]<<' ';
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
ll tim=0;
ll dsu_find(ll x,ve <ll> &c)
{
    return c[x];
}
void dsu_union(ll a, ll b, ve <ll> &c, ve <set <ll>> &s)
{
    ll max=b;
    ll min=a;
    if(s[a].size()>s[b].size())
    {
        max=a;
        min=b;
    }
    ll size_max=s[max].size();
    ll size_min=s[min].size();
    while(size_min>0)
    {
        auto i=s[min].begin();
        ll x=(*i);
        c[x]=max;
        s[max].insert(x);
        s[min].erase(i);
        size_min--;
        size_max++;
    }
}
void dfs(map <ll, set <ll>> &G, set <ll> &visited, map <ll, ll> &vistime, map <ll,ll> &low, map <ll,ll> &pi, ll seed)
{
    visited.insert(seed);
    vistime[seed]=tim++;
    low[seed]=vistime[seed];
    for(auto child: G[seed])
    {
        if (visited.find(child)==visited.end())
        {
            pi[child]=seed;
            dfs(G, visited, vistime, low, pi, child);
            low[seed]=min(low[seed], low[child]);
        }
        else if(pi[seed]!=child)
        {
            low[seed]=min(low[seed], vistime[child]);
        }
    }
    tim++;
}
int main()
{
    //fastio
    ll n;
    cin>>n;
    ll m;
    cin>>m;
    map <pair <ll,ll>, ll> assign;
    ve <pair <ll, pair <ll,ll>>> imp;
    fr(i, 0, m-1)
    {
        ll a, b, w;
        cin>>a;
        cin>>b;
        cin>>w;
        a--;
        b--;
        imp.pb(pair <ll, pair <ll,ll>>(w, pair <ll,ll>(a, b)));
        assign[pair<ll,ll>(a, b) ]=i;
    }
    sort(all(imp));
    ll i=0;
    ll _i=0;
    ve <ll> c(n);
    ve <set <ll>> s(n);
    fr(i, 0, n-1)
    {
        c[i]=i;
        s[i].insert(i);
    }
    ve <ll> ans(m, 0);
    ve <ve <pair <ll,ll>>> separate;
    separate.pb(ve <pair <ll, ll>>());
    separate[0].pb(imp[0].se);
    while(i<m-1)
    {
        if(imp[i].fi==imp[i+1].fi);
        else
        {
            separate.pb(ve <pair <ll, ll>>());
        }
        separate[sz(separate)-1].pb(imp[i+1].se); 
        i++;  
    }
    for(auto it:separate)
    {

       map <ll, set <ll>> G;
        for(auto edge:it)
        {
            if(c[edge.fi]!=c[edge.se])
            {
                if(G.find(c[edge.fi])==G.end())
                {
                    G[c[edge.fi]]=set <ll>();
                }
                if(G.find(c[edge.se])==G.end())
                {
                    G[c[edge.se]]=set <ll>();
                }
                G[c[edge.fi]].insert(c[edge.se]);
                G[c[edge.se]].insert(c[edge.fi]);
            }
        }
        set <ll> visited;
        map <ll,ll> vistime, low, pi;
        for(auto x:G)
        {
            if(visited.find(x.fi)==visited.end())
            {
                dfs(G, visited, vistime, low, pi, x.fi);
            }
        }
       map <pair <ll,ll> ,ll> cou;
        for(auto edge:it)
        {
            if(c[edge.fi]!=c[edge.se])
            {
                ll v=c[edge.fi], u=c[edge.se];
                if(pi[v]==u)
                {
                    u=c[edge.fi];
                    v=c[edge.se];
                }
                if(cou.find(pair <ll,ll>(min(v, u), max(v, u)))==cou.end())
                {
                    cou[pair <ll,ll>(min(v, u), max(v, u))]=0;
                }
                cou[pair <ll,ll>(min(v, u), max(v, u))]++;
                if(low[u]>vistime[v]);
                else
                {
                    ans[assign[edge]]=2;
                }                
            }
        }
        for(auto edge:it)
        {
            if(c[edge.fi]!=c[edge.se])
            {
                ans[assign[edge]]=max(ans[assign[edge]], cou[pair <ll,ll> (min(c[edge.fi], c[edge.se]),max(c[edge.fi], c[edge.se]))]);
            }
        }
        for(auto edge:it)
        {

            if(c[edge.fi]!=c[edge.se])
            {
                dsu_union(c[edge.fi], c[edge.se], c, s);
            }
        }
//*/
    }
    fr(i, 0, m-1)
    {
        if(ans[i]==0)
        {
            cout<<"none"<<endl;
        }
        else if(ans[i]==1)
        {
            cout<<"any"<<endl;
        }
        else
        {
            cout<<"at least one"<<endl;
        }
    }
    //*/
}
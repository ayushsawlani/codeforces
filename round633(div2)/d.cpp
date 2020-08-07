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
ll m2=0,m1=0;
void dfs1(vector <vector <ll>> &G,ve <ll> &dist,vector <ll> &c,vector <ll> &pi, ll seed)
{
    c[seed]=1;
    for(auto i=G[seed].begin();i!=G[seed].end();i++)
    {
        if(pi[seed]!=(*i))
            pi[(*i)]=seed;
        if(!(c[(*i)]))
        {
            dist[*i]=dist[seed]+1;
            dfs1(G,dist,c,pi,(*i));
        }   
    }
}
void dfs2(vector <vector <ll>> &G,ve <ll> &del,vector <ll> &c,vector <ll> &pi, ll seed)
{
    c[seed]=1;
    ll flag=0;
    for(auto i=G[seed].begin();i!=G[seed].end();i++)
    {
        if(pi[seed]!=(*i))
            pi[(*i)]=seed;
        if(!(c[(*i)])&&(del[*i]==0))
        {
            dfs2(G,del,c,pi,(*i));
        }
        if(del[*i]==1)
            flag=1;
    }
    if(flag)
        m2++;    
}
int main()
{
    //fastio
    ll n,m;
    cin>>n;
    m=n-1;
    vector <vector <ll>> G;
    for(ll i=0;i<n;i++)
    {
        vector <ll> temp;
        G.push_back(temp);
    }
    for(ll i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    ve <ll> leaf,c(n,0), pi(n,-1),dist(n,0),del(n,0);
    ll node=-1;
    fr(i, 0, n)
    {
        if(sz(G[i])==1)
        {
            leaf.pb(i);
            del[i]=1;
        }
        else
        {
            node=i;
        }
        
    }
    dfs1(G, dist, c, pi , leaf[0]);
    ll m1=1;
    fr(i, 1, sz(leaf))
    {
        if(dist[leaf[i]]%2)
            m1=3;
    }
    m2=n-1;
    m2-=sz(leaf);
    setvector(c,0,n);
    setvector(pi,-1,n);
    dfs2(G,del, c, pi, node);
    cout<<m1<<" "<<m2<<endl;
}
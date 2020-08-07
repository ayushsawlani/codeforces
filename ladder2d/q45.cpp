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
#define setvector(itname,vname,value,size); for(int itname=0;itname<size;itname++)vname[itname]=value;
const ll inf = 9e18;
//cout << fixed << setprecision(9) << ans <<endl; for accurate decimal precision.
void dfs(vector <vector <ll>> &G,vector <ll> &dist,vector <ll> &c,vector <ll> &pi, ll seed)
{
    c[seed]=1;
    for(auto i=G[seed].begin();i!=G[seed].end();i++)
    {
        if(pi[seed]!=(*i))
            pi[(*i)]=seed;
        if(!(c[(*i)]))
        {
            dist[*i]=dist[seed]+1;
            dfs(G,dist,c,pi,(*i));
        }   
    }
}
void dfs1(vector <vector <ll>> &G,vector <ll> &dist,ve <ll> &maxdist ,vector <ll> &c,vector <ll> &pi, ll seed, ve <ll> &clan)
{
    clan.pb(seed);
    c[seed]=1;
    for(auto i=G[seed].begin();i!=G[seed].end();i++)
    {
        if(pi[seed]!=(*i))
            pi[(*i)]=seed;
        if(!(c[(*i)]))
        {
            dist[*i]=dist[seed]+1;
            dfs1(G, dist, maxdist, c, pi, (*i), clan);
        }   
    }
    for(auto i: G[seed])
    {
        if(i!=pi[seed])
        {
            if(dist[maxdist[i]]>dist[maxdist[seed]])
            {
                //cout<<"x"<<endl;
                maxdist[seed]=maxdist[i];
            }
        }
    }
    maxdist[seed];
}
void mark(ve <ll> &c,ve <ll> &pi, ll seed, ll start)
{
    
    c[seed]=1;
    if(seed!=start)
    {
        mark(c, pi, pi[seed], start);
    }
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
    ll ans=0;
    fr(i, 0, n-2)
    {
        fr(j, i+1,n-1)
        {
            ll util;
            ve <ll> c(n,0), pi(n, -1), dist(n, 0), maxdist(n);
            fr(k, 0, n-1)
            {
                maxdist[k]=k;
            }
            dfs(G, dist, c, pi, i);
            util=dist[j];
            setvector(k,c, 0, n);
            mark(c,pi, j, i);
            setvector(k,dist, 0, n);
            setvector(k,pi, -1, n);
            fr(k, 0, n-1)
            {
                if(c[k]==0)
                {
                    ve <ll> clan;
                    dfs1(G, dist, maxdist, c, pi, k, clan);
                    ll x=maxdist[k];
                    fr(l, 0, sz(clan)-1)
                    {
                        c[clan[l]]=0;
                        pi[clan[l]]=-1;
                        dist[clan[l]]=0;
                    }
                    dfs(G, dist, c, pi, x);
                    fr(l, 0, sz(clan)-1)
                    {
                        ans=max(ans, util*dist[clan[l]]);
                    }
                    //*/
                }
            }
            //*/
        }
    }
    cout<<ans<<endl;
}